#include <QGuiApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "imageelement.h"


void loadfavouriteUrls(QList<QString*>& favourites) {
    // Open the text file
    QFile file("qrc:/ApodGallery/img/favourite/favourite.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading";
        return;
    }

    // Read the file line by line and add each line to the favourites list
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        favourites.append(new QString(line)); // Store each line as a new QString*
    }

    // Close the file
    file.close();
}

void fillImagesList(QList<QObject*>& images, QList<QString*>& favourites) {
    loadfavouriteUrls(favourites);

    images.append(new ImageElement("Butterfly", "qrc:/ApodGallery/img/img3.jpg", false));
    images.append(new ImageElement("Tree", "qrc:/ApodGallery/img/img1.jpg", false));
    images.append(new ImageElement("Smoke", "qrc:/ApodGallery/img/img0.jpg", false));

    foreach (QObject* obj, images) {
        ImageElement* img = qobject_cast<ImageElement*>(obj);
        if (img) {
            // Check if the URL of the current image matches any URL in the favourites list
            foreach (QString* fav, favourites) {
                if (*fav == img->url()) {
                    // URL match found, do something
                    img->setfavourite(true);
                    break;
                }
            }
        }
    }
}

void savefavouriteImageUrls(const QList<QObject*>& images) {
    QFile file("qrc:/ApodGallery/img/favourite/favourite.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for writing";
        return;
    }

    QTextStream out(&file);
    foreach (QObject* obj, images) {
        ImageElement* img = qobject_cast<ImageElement*>(obj);
        if (img && img->isfavourite()) {
            out << img->url() << "\n";
        }
    }

    file.close();
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QList<QObject*> images;
    QList<QString*> favourites;
    fillImagesList(images, favourites);


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
    // Save image URLs before quitting
    QObject::connect(&app, &QGuiApplication::aboutToQuit, [&images]() { savefavouriteImageUrls(images); });


    return app.exec();
}
