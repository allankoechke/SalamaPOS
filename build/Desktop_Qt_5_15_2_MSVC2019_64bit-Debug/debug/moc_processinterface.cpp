/****************************************************************************
** Meta object code from reading C++ file 'processinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/processinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProcessInterface_t {
    QByteArrayData data[20];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessInterface_t qt_meta_stringdata_ProcessInterface = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ProcessInterface"
QT_MOC_LITERAL(1, 17, 5), // "error"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "readyRead"
QT_MOC_LITERAL(4, 34, 4), // "data"
QT_MOC_LITERAL(5, 39, 8), // "finished"
QT_MOC_LITERAL(6, 48, 8), // "exitCode"
QT_MOC_LITERAL(7, 57, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(8, 78, 10), // "exitStatus"
QT_MOC_LITERAL(9, 89, 14), // "readyReadError"
QT_MOC_LITERAL(10, 104, 16), // "authorizeChanged"
QT_MOC_LITERAL(11, 121, 9), // "authorize"
QT_MOC_LITERAL(12, 131, 14), // "commandChanged"
QT_MOC_LITERAL(13, 146, 7), // "command"
QT_MOC_LITERAL(14, 154, 11), // "argsChanged"
QT_MOC_LITERAL(15, 166, 4), // "args"
QT_MOC_LITERAL(16, 171, 10), // "_readyRead"
QT_MOC_LITERAL(17, 182, 15), // "_readyReadError"
QT_MOC_LITERAL(18, 198, 7), // "execute"
QT_MOC_LITERAL(19, 206, 4) // "path"

    },
    "ProcessInterface\0error\0\0readyRead\0"
    "data\0finished\0exitCode\0QProcess::ExitStatus\0"
    "exitStatus\0readyReadError\0authorizeChanged\0"
    "authorize\0commandChanged\0command\0"
    "argsChanged\0args\0_readyRead\0_readyReadError\0"
    "execute\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       3,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       5,    2,   70,    2, 0x06 /* Public */,
       9,    1,   75,    2, 0x06 /* Public */,
      10,    1,   78,    2, 0x06 /* Public */,
      12,    1,   81,    2, 0x06 /* Public */,
      14,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,   87,    2, 0x08 /* Private */,
      17,    0,   88,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      18,    1,   89,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    1,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString,    1,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   19,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495003,
      13, QMetaType::QString, 0x00495003,
      15, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       4,
       5,
       6,

       0        // eod
};

void ProcessInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProcessInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->readyRead((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 3: _t->readyReadError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->authorizeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->commandChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->argsChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->_readyRead(); break;
        case 8: _t->_readyReadError(); break;
        case 9: _t->execute((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProcessInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProcessInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::readyRead)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProcessInterface::*)(int , QProcess::ExitStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::finished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProcessInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::readyReadError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ProcessInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::authorizeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ProcessInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::commandChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ProcessInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessInterface::argsChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ProcessInterface *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->m_authorize; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->m_command; break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->m_args; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ProcessInterface *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_authorize != *reinterpret_cast< QString*>(_v)) {
                _t->m_authorize = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->authorizeChanged(_t->m_authorize);
            }
            break;
        case 1:
            if (_t->m_command != *reinterpret_cast< QString*>(_v)) {
                _t->m_command = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->commandChanged(_t->m_command);
            }
            break;
        case 2:
            if (_t->m_args != *reinterpret_cast< QString*>(_v)) {
                _t->m_args = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->argsChanged(_t->m_args);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ProcessInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProcessInterface.data,
    qt_meta_data_ProcessInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProcessInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProcessInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProcessInterface::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProcessInterface::readyRead(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProcessInterface::finished(int _t1, QProcess::ExitStatus _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProcessInterface::readyReadError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProcessInterface::authorizeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ProcessInterface::commandChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ProcessInterface::argsChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
