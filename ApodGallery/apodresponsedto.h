#ifndef APODRESPONSEDTO_H
#define APODRESPONSEDTO_H

#include <QString>

class ApodResponseDto
{
public:
    ApodResponseDto();
    ApodResponseDto(QString date, QString explanation, QString hdurl, QString media_type,
                    QString service_version, QString title, QString url);

    QString getDate() const;
    void setDate(const QString &date);

    QString getExplanation() const;
    void setExplanation(const QString &explanation);

    QString getHdUrl() const;
    void setHdUrl(const QString &hdUrl);

    QString getMediaType() const;
    void setMediaType(const QString &mediaType);

    QString getServiceVersion() const;
    void setServiceVersion(const QString &serviceVersion);

    QString getTitle() const;
    void setTitle(const QString &title);

    QString getUrl() const;
    void setUrl(const QString &url);

private:
    QString date;
    QString explanation;
    QString hdurl;
    QString media_type;
    QString service_version;
    QString title;
    QString url;
};

#endif // APODRESPONSEDTO_H
