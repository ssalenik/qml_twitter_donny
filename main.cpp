#include <QGuiApplication>
#include <QQuickView>
#include <QCommandLineParser>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

#include "tweet.h"

void readJson(QGuiApplication& app);

int main(int argc, char* argv[])
{
    QGuiApplication app(argc,argv);
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + QLatin1String("/donny_twitter.qml")));

    QCommandLineParser parser;
    parser.setApplicationDescription("QML Donny twitter demo");
    parser.addHelpOption();

    // QCommandLineOption hostOption(QStringList() << "d" << "destination", "destination ip", "host", "127.0.0.1");
    // parser.addOption(hostOption);
    //
    // QCommandLineOption portOption(QStringList() << "p" << "port", "destination port", "port", "6000");
    // parser.addOption(portOption);

    readJson(app);

    parser.process(app);

    view.show();

    return app.exec();
}

void readJson(QGuiApplication& app)
{
    QString val;
    QFile file;
    file.setFileName("donny.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonArray tweetslist = QJsonDocument::fromJson(val.toUtf8()).array();
    foreach (QJsonValue tweet, tweetslist) {
        qInfo() << "================================================";
        auto tmp = new Tweet(&app, tweet.toObject());
        qInfo() << "QJsonObject of description: " << tmp->getDate();
        qInfo() << "QJsonObject of description: " << tmp->getText();
        qInfo() << "QJsonObject of description: " << tmp->getFavoriteCount();
        qInfo() << "QJsonObject of description: " << tmp->getRetweetCount();
    }
}
