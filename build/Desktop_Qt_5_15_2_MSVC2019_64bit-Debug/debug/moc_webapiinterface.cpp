/****************************************************************************
** Meta object code from reading C++ file 'webapiinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/webapiinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webapiinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebApiInterface_t {
    QByteArrayData data[14];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebApiInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebApiInterface_t qt_meta_stringdata_WebApiInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "WebApiInterface"
QT_MOC_LITERAL(1, 16, 19), // "newVersionAvailable"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "json"
QT_MOC_LITERAL(4, 42, 17), // "onCheckForUpdates"
QT_MOC_LITERAL(5, 60, 8), // "cVersion"
QT_MOC_LITERAL(6, 69, 16), // "onDownloadUpdate"
QT_MOC_LITERAL(7, 86, 15), // "onInstallUpdate"
QT_MOC_LITERAL(8, 102, 21), // "onWebRunnableFinished"
QT_MOC_LITERAL(9, 124, 3), // "str"
QT_MOC_LITERAL(10, 128, 11), // "connect2Web"
QT_MOC_LITERAL(11, 140, 5), // "state"
QT_MOC_LITERAL(12, 146, 4), // "data"
QT_MOC_LITERAL(13, 151, 31) // "onCheckConnectivityTimerTimeout"

    },
    "WebApiInterface\0newVersionAvailable\0"
    "\0json\0onCheckForUpdates\0cVersion\0"
    "onDownloadUpdate\0onInstallUpdate\0"
    "onWebRunnableFinished\0str\0connect2Web\0"
    "state\0data\0onCheckConnectivityTimerTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebApiInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
      10,    2,   60,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,   11,   12,
    QMetaType::Void,

       0        // eod
};

void WebApiInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebApiInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newVersionAvailable((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->onCheckForUpdates((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->onDownloadUpdate(); break;
        case 3: _t->onInstallUpdate(); break;
        case 4: _t->onWebRunnableFinished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->connect2Web((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 6: _t->onCheckConnectivityTimerTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebApiInterface::*)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebApiInterface::newVersionAvailable)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WebApiInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WebApiInterface.data,
    qt_meta_data_WebApiInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WebApiInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebApiInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebApiInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebApiInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WebApiInterface::newVersionAvailable(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_WebInterfaceRunnable_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebInterfaceRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebInterfaceRunnable_t qt_meta_stringdata_WebInterfaceRunnable = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WebInterfaceRunnable"
QT_MOC_LITERAL(1, 21, 8), // "finished"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5) // "reply"

    },
    "WebInterfaceRunnable\0finished\0\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebInterfaceRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void WebInterfaceRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebInterfaceRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebInterfaceRunnable::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebInterfaceRunnable::finished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WebInterfaceRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WebInterfaceRunnable.data,
    qt_meta_data_WebInterfaceRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WebInterfaceRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebInterfaceRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebInterfaceRunnable.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int WebInterfaceRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void WebInterfaceRunnable::finished(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
