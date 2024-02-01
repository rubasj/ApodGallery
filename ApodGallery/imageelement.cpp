#include "ImageElement.h"


ImageElement::ImageElement(QObject *parent) : QObject(parent), _favourite(false) {}

ImageElement::ImageElement(QString name, QString url, bool favourite, QObject *parent)
    : QObject(parent), _name(name), _url(url), _favourite(favourite) {}

QString ImageElement::name() const {
    return _name;
}

void ImageElement::setName(const QString &name) {
    if (_name != name) {
        _name = name;
        emit nameChanged();
    }
}

QString ImageElement::url() const {
    return _url;
}

void ImageElement::setUrl(const QString &url) {
    if (_url != url) {
        _url = url;
        emit urlChanged();
    }
}

bool ImageElement::isfavourite() const {
    return _favourite;
}

void ImageElement::setfavourite(bool favourite) {
    if (_favourite != favourite) {
        _favourite = favourite;
        emit favouriteChanged();
    }
}

