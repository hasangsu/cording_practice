#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // engine is single qml file lode.
    QQmlApplicationEngine engine;

    // specify the path of the qml file.
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    // connect siganl & slot (lamda).
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    // engine.load -> loadUrl() -> finishLoad() :: Ready -> emit signal.
    engine.load(url);

    // run app.
    return app.exec();
}
