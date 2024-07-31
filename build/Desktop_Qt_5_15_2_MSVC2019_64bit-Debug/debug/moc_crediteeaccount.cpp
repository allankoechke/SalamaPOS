/****************************************************************************
** Meta object code from reading C++ file 'crediteeaccount.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/src/crediteeaccount.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crediteeaccount.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CrediteeAccount_t {
    QByteArrayData data[17];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CrediteeAccount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CrediteeAccount_t qt_meta_stringdata_CrediteeAccount = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CrediteeAccount"
QT_MOC_LITERAL(1, 16, 16), // "firstNameChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "firstName"
QT_MOC_LITERAL(4, 44, 15), // "lastNameChanged"
QT_MOC_LITERAL(5, 60, 8), // "lastName"
QT_MOC_LITERAL(6, 69, 15), // "mobileNoChanged"
QT_MOC_LITERAL(7, 85, 8), // "mobileNo"
QT_MOC_LITERAL(8, 94, 11), // "idNoChanged"
QT_MOC_LITERAL(9, 106, 4), // "idNo"
QT_MOC_LITERAL(10, 111, 17), // "debtAmountChanged"
QT_MOC_LITERAL(11, 129, 10), // "debtAmount"
QT_MOC_LITERAL(12, 140, 12), // "setFirstName"
QT_MOC_LITERAL(13, 153, 11), // "setLastName"
QT_MOC_LITERAL(14, 165, 11), // "setMobileNo"
QT_MOC_LITERAL(15, 177, 7), // "setIdNo"
QT_MOC_LITERAL(16, 185, 13) // "setDebtAmount"

    },
    "CrediteeAccount\0firstNameChanged\0\0"
    "firstName\0lastNameChanged\0lastName\0"
    "mobileNoChanged\0mobileNo\0idNoChanged\0"
    "idNo\0debtAmountChanged\0debtAmount\0"
    "setFirstName\0setLastName\0setMobileNo\0"
    "setIdNo\0setDebtAmount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CrediteeAccount[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
      10,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   79,    2, 0x0a /* Public */,
      13,    1,   82,    2, 0x0a /* Public */,
      14,    1,   85,    2, 0x0a /* Public */,
      15,    1,   88,    2, 0x0a /* Public */,
      16,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      11, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void CrediteeAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CrediteeAccount *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->lastNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->mobileNoChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->idNoChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->debtAmountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setFirstName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setLastName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setMobileNo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setIdNo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setDebtAmount((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CrediteeAccount::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccount::firstNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CrediteeAccount::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccount::lastNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CrediteeAccount::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccount::mobileNoChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CrediteeAccount::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccount::idNoChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CrediteeAccount::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccount::debtAmountChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CrediteeAccount *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->firstName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->lastName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->mobileNo(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->idNo(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->debtAmount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CrediteeAccount *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFirstName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLastName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setMobileNo(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setIdNo(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setDebtAmount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CrediteeAccount::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CrediteeAccount.data,
    qt_meta_data_CrediteeAccount,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CrediteeAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CrediteeAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CrediteeAccount.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CrediteeAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CrediteeAccount::firstNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CrediteeAccount::lastNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CrediteeAccount::mobileNoChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CrediteeAccount::idNoChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CrediteeAccount::debtAmountChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
