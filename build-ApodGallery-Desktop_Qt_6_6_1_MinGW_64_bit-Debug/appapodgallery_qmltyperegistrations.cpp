/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <imageelement.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_ApodGallery()
{
    qmlRegisterTypesAndRevisions<ImageElement>("ApodGallery", 1);
    qmlRegisterModule("ApodGallery", 1, 0);
}

static const QQmlModuleRegistration registration("ApodGallery", qml_register_types_ApodGallery);
