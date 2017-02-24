#include <QGuiApplication>
#include <QQuickView>
#include <QCommandLineParser>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QQmlContext>
#include <QProcess>

#include "tweet.h"

QList<QObject*> loadTweets(QGuiApplication& app);

int main(int argc, char* argv[])
{
    QGuiApplication app(argc,argv);
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    QCommandLineParser parser;
    parser.setApplicationDescription("QML Donny twitter demo");
    parser.addHelpOption();

    // QCommandLineOption hostOption(QStringList() << "d" << "destination", "destination ip", "host", "127.0.0.1");
    // parser.addOption(hostOption);
    //
    // QCommandLineOption portOption(QStringList() << "p" << "port", "destination port", "port", "6000");
    // parser.addOption(portOption);

    parser.process(app);

    QList<QObject*> tweetList = loadTweets(app);

    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("tweetModel", QVariant::fromValue(tweetList));
    view.setSource(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + QLatin1String("/donny_twitter.qml")));

    view.show();

    return app.exec();
}

QList<QObject*> loadTweets(QGuiApplication& app)
{
    QProcess process;
    process.start("twurl \"/1.1/statuses/user_timeline.json?screen_name=realDonaldTrump&count=5\"");
    process.waitForFinished();
    QString val(process.readAllStandardOutput());

    qWarning() << val;
    QJsonArray tweetslist = QJsonDocument::fromJson(val.toUtf8()).array();
    QList<QObject*> tweetList;
    foreach (QJsonValue tweet, tweetslist) {
        qInfo() << "================================================";
        auto tmp = new Tweet(&app, tweet.toObject());
        qInfo() << "QJsonObject of description: " << tmp->getDate();
        qInfo() << "QJsonObject of description: " << tmp->getText();
        qInfo() << "QJsonObject of description: " << tmp->getFavoriteCount();
        qInfo() << "QJsonObject of description: " << tmp->getRetweetCount();
        tweetList.append(tmp);
    }

    return tweetList;
}
