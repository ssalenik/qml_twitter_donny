#include <QGuiApplication>
#include <QQuickView>
#include <QCommandLineParser>

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

    parser.process(app);

    view.show();

    return app.exec();
}
