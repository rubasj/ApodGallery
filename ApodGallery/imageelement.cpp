#include "imageelement.h"

ImageElement::ImageElement(QObject *parent)
    : QObject(parent)
{}

ImageElement::ImageElement(QString name, QString url, QObject *parent)
    : QObject(parent), _name(name), _url(url)
{

}

QString ImageElement::name() const
{
    return _name;
}

void ImageElement::setName(const QString &name)
{
    if (_name != name) {
        _name = name;
        emit nameChanged();
    }
}

QString ImageElement::url() const
{
    return _url;
}

void ImageElement::setUrl(const QString &url)
{
    if (_url != url) {
        _url = url;
        emit urlChanged();
    }
}
