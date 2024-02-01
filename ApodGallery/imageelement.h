#ifndef IMAGEELEMENT_H
#define IMAGEELEMENT_H

#include <iostream>
#include <QObject>
#include <QQmlEngine>

class ImageElement : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged FINAL)

public:
    explicit ImageElement(QObject *parent = nullptr);
    ImageElement(QString name, QString url, QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    QString url() const;
    void setUrl(const QString &url);


    Q_INVOKABLE void logMessage(QString msg) {
        std::cout << "Image: " << msg.toStdString() << std::endl;
    }

public slots:
    void loginfo() {
        std::cout << "Image: " << _name.toStdString()<< std::endl;
    }

signals:
    void nameChanged();
    void urlChanged();

private:
    QString _name;
    QString _url;


};

#endif // IMAGEELEMENT_H
