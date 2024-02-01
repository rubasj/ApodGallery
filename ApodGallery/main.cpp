#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "imageelement.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QList<QObject*> images;

    images.append(new ImageElement("Butterfly", "qrc:/ApodGallery/img/img3.jpg"));
    images.append(new ImageElement("Tree", "qrc:/ApodGallery/img/img1.jpg"));
    images.append(new ImageElement("Smoke", "qrc:/ApodGallery/img/img0.jpg"));



    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/ApodGallery/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("images", QVariant::fromValue(images));
    engine.load(url);

    return app.exec();
}
