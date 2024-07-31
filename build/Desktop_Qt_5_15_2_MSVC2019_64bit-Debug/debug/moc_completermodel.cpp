/****************************************************************************
** Meta object code from reading C++ file 'completermodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/completermodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'completermodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CompleterModel_t {
    QByteArrayData data[14];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CompleterModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CompleterModel_t qt_meta_stringdata_CompleterModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CompleterModel"
QT_MOC_LITERAL(1, 15, 14), // "logDataChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "level"
QT_MOC_LITERAL(4, 37, 4), // "info"
QT_MOC_LITERAL(5, 42, 20), // "completerSizeChanged"
QT_MOC_LITERAL(6, 63, 13), // "completerSize"
QT_MOC_LITERAL(7, 77, 17), // "addCompleterItems"
QT_MOC_LITERAL(8, 95, 3), // "str"
QT_MOC_LITERAL(9, 99, 19), // "removeCompleterItem"
QT_MOC_LITERAL(10, 119, 4), // "size"
QT_MOC_LITERAL(11, 124, 6), // "getKey"
QT_MOC_LITERAL(12, 131, 5), // "index"
QT_MOC_LITERAL(13, 137, 7) // "getData"

    },
    "CompleterModel\0logDataChanged\0\0level\0"
    "info\0completerSizeChanged\0completerSize\0"
    "addCompleterItems\0str\0removeCompleterItem\0"
    "size\0getKey\0index\0getData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompleterModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x02 /* Public */,
       9,    1,   60,    2, 0x02 /* Public */,
      10,    0,   63,    2, 0x02 /* Public */,
      11,    1,   64,    2, 0x02 /* Public */,
      13,    1,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariant,    8,
    QMetaType::Void, QMetaType::QVariant,    8,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   12,
    QMetaType::QVariantMap, QMetaType::Int,   12,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void CompleterModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CompleterModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logDataChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->completerSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->addCompleterItems((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 3: _t->removeCompleterItem((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 4: { int _r = _t->size();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getKey((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantMap _r = _t->getData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CompleterModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompleterModel::logDataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CompleterModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompleterModel::completerSizeChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CompleterModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->completerSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CompleterModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCompleterSize(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CompleterModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CompleterModel.data,
    qt_meta_data_CompleterModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CompleterModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompleterModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CompleterModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int CompleterModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CompleterModel::logDataChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CompleterModel::completerSizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
