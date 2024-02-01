#include "apodresponsedto.h"

ApodResponseDto::ApodResponseDto()
{}

ApodResponseDto::ApodResponseDto(QString date, QString explanation, QString hdurl, QString media_type,
                                 QString service_version, QString title, QString url)
    : date(date),
    explanation(explanation),
    hdurl(hdurl),
    media_type(media_type),
    service_version(service_version),
    title(title),
    url(url)
{}

QString ApodResponseDto::getDate() const
{
    return date;
}

void ApodResponseDto::setDate(const QString &date)
{
    this->date = date;
}

QString ApodResponseDto::getExplanation() const
{
    return explanation;
}

void ApodResponseDto::setExplanation(const QString &explanation)
{
    this->explanation = explanation;
}

QString ApodResponseDto::getHdUrl() const
{
    return hdurl;
}

void ApodResponseDto::setHdUrl(const QString &hdUrl)
{
    this->hdurl = hdUrl;
}

QString ApodResponseDto::getMediaType() const
{
    return media_type;
}

void ApodResponseDto::setMediaType(const QString &mediaType)
{
    this->media_type = mediaType;
}

QString ApodResponseDto::getServiceVersion() const
{
    return service_version;
}

void ApodResponseDto::setServiceVersion(const QString &serviceVersion)
{
    this->service_version = serviceVersion;
}

QString ApodResponseDto::getTitle() const
{
    return title;
}

void ApodResponseDto::setTitle(const QString &title)
{
    this->title = title;
}

QString ApodResponseDto::getUrl() const
{
    return url;
}

void ApodResponseDto::setUrl(const QString &url)
{
    this->url = url;
}
