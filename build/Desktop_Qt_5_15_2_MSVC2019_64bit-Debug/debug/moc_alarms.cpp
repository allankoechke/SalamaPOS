/****************************************************************************
** Meta object code from reading C++ file 'alarms.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/src/alarms.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarms.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Alarms_t {
    QByteArrayData data[10];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Alarms_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Alarms_t qt_meta_stringdata_Alarms = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Alarms"
QT_MOC_LITERAL(1, 7, 16), // "alarmTypeChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "alarmType"
QT_MOC_LITERAL(4, 35, 18), // "alarmStringChanged"
QT_MOC_LITERAL(5, 54, 11), // "alarmString"
QT_MOC_LITERAL(6, 66, 14), // "alarmIdChanged"
QT_MOC_LITERAL(7, 81, 7), // "alarmId"
QT_MOC_LITERAL(8, 89, 20), // "alarmIsActiveChanged"
QT_MOC_LITERAL(9, 110, 13) // "alarmIsActive"

    },
    "Alarms\0alarmTypeChanged\0\0alarmType\0"
    "alarmStringChanged\0alarmString\0"
    "alarmIdChanged\0alarmId\0alarmIsActiveChanged\0"
    "alarmIsActive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Alarms[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void Alarms::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Alarms *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alarmTypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->alarmStringChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->alarmIdChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->alarmIsActiveChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Alarms::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Alarms::alarmTypeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Alarms::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Alarms::alarmStringChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Alarms::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Alarms::alarmIdChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Alarms::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Alarms::alarmIsActiveChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Alarms *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->alarmType(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->alarmString(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->alarmId(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->alarmIsActive(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Alarms *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAlarmType(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setAlarmString(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setAlarmId(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setAlarmIsActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Alarms::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Alarms.data,
    qt_meta_data_Alarms,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Alarms::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Alarms::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Alarms.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Alarms::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Alarms::alarmTypeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Alarms::alarmStringChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Alarms::alarmIdChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Alarms::alarmIsActiveChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
