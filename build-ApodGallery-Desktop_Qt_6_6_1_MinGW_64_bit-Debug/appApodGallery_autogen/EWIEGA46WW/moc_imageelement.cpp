/****************************************************************************
** Meta object code from reading C++ file 'imageelement.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ApodGallery/imageelement.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSImageElementENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSImageElementENDCLASS = QtMocHelpers::stringData(
    "ImageElement",
    "QML.Element",
    "auto",
    "nameChanged",
    "",
    "urlChanged",
    "favouriteChanged",
    "loginfo",
    "logMessage",
    "msg",
    "name",
    "url"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSImageElementENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[13];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[12];
    char stringdata4[1];
    char stringdata5[11];
    char stringdata6[17];
    char stringdata7[8];
    char stringdata8[11];
    char stringdata9[4];
    char stringdata10[5];
    char stringdata11[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSImageElementENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSImageElementENDCLASS_t qt_meta_stringdata_CLASSImageElementENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ImageElement"
        QT_MOC_LITERAL(13, 11),  // "QML.Element"
        QT_MOC_LITERAL(25, 4),  // "auto"
        QT_MOC_LITERAL(30, 11),  // "nameChanged"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 10),  // "urlChanged"
        QT_MOC_LITERAL(54, 16),  // "favouriteChanged"
        QT_MOC_LITERAL(71, 7),  // "loginfo"
        QT_MOC_LITERAL(79, 10),  // "logMessage"
        QT_MOC_LITERAL(90, 3),  // "msg"
        QT_MOC_LITERAL(94, 4),  // "name"
        QT_MOC_LITERAL(99, 3)   // "url"
    },
    "ImageElement",
    "QML.Element",
    "auto",
    "nameChanged",
    "",
    "urlChanged",
    "favouriteChanged",
    "loginfo",
    "logMessage",
    "msg",
    "name",
    "url"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSImageElementENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       5,   16, // methods
       2,   53, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   46,    4, 0x06,    3 /* Public */,
       5,    0,   47,    4, 0x06,    4 /* Public */,
       6,    0,   48,    4, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   49,    4, 0x0a,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   50,    4, 0x02,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    9,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00015903, uint(0), 0,
      11, QMetaType::QString, 0x00015903, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ImageElement::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSImageElementENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSImageElementENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'name'
        QString,
        // property 'url'
        QString,
        // Q_OBJECT / Q_GADGET
        ImageElement,
        // method 'nameChanged'
        void,
        // method 'urlChanged'
        void,
        // method 'favouriteChanged'
        void,
        // method 'loginfo'
        void,
        // method 'logMessage'
        void,
        QString
    >,
    nullptr
} };

void ImageElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageElement *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->urlChanged(); break;
        case 2: _t->favouriteChanged(); break;
        case 3: _t->loginfo(); break;
        case 4: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageElement::*)();
            if (_t _q_method = &ImageElement::nameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImageElement::*)();
            if (_t _q_method = &ImageElement::urlChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImageElement::*)();
            if (_t _q_method = &ImageElement::favouriteChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ImageElement *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->url(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ImageElement *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setUrl(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ImageElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSImageElementENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImageElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ImageElement::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ImageElement::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ImageElement::favouriteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
