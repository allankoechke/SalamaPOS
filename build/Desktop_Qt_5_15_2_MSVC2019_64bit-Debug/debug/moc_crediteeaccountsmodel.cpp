/****************************************************************************
** Meta object code from reading C++ file 'crediteeaccountsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/crediteeaccountsmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crediteeaccountsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CrediteeAccountsModel_t {
    QByteArrayData data[30];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CrediteeAccountsModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CrediteeAccountsModel_t qt_meta_stringdata_CrediteeAccountsModel = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CrediteeAccountsModel"
QT_MOC_LITERAL(1, 22, 13), // "crediteeAdded"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "status"
QT_MOC_LITERAL(4, 44, 15), // "crediteeUpdated"
QT_MOC_LITERAL(5, 60, 8), // "idExists"
QT_MOC_LITERAL(6, 69, 15), // "paymentReceived"
QT_MOC_LITERAL(7, 85, 4), // "date"
QT_MOC_LITERAL(8, 90, 4), // "paid"
QT_MOC_LITERAL(9, 95, 3), // "due"
QT_MOC_LITERAL(10, 99, 18), // "giveBalanceChanged"
QT_MOC_LITERAL(11, 118, 3), // "bal"
QT_MOC_LITERAL(12, 122, 14), // "logDataChanged"
QT_MOC_LITERAL(13, 137, 5), // "level"
QT_MOC_LITERAL(14, 143, 4), // "info"
QT_MOC_LITERAL(15, 148, 19), // "debRepaymentChanged"
QT_MOC_LITERAL(16, 168, 5), // "state"
QT_MOC_LITERAL(17, 174, 14), // "addNewCreditee"
QT_MOC_LITERAL(18, 189, 5), // "fname"
QT_MOC_LITERAL(19, 195, 5), // "lname"
QT_MOC_LITERAL(20, 201, 6), // "mobile"
QT_MOC_LITERAL(21, 208, 4), // "idNo"
QT_MOC_LITERAL(22, 213, 14), // "updateCreditee"
QT_MOC_LITERAL(23, 228, 7), // "orig_id"
QT_MOC_LITERAL(24, 236, 20), // "loadCrediteeAccounts"
QT_MOC_LITERAL(25, 257, 17), // "getPaymentHistory"
QT_MOC_LITERAL(26, 275, 9), // "repayDebt"
QT_MOC_LITERAL(27, 285, 10), // "crediteeId"
QT_MOC_LITERAL(28, 296, 4), // "debt"
QT_MOC_LITERAL(29, 301, 8) // "debtPaid"

    },
    "CrediteeAccountsModel\0crediteeAdded\0"
    "\0status\0crediteeUpdated\0idExists\0"
    "paymentReceived\0date\0paid\0due\0"
    "giveBalanceChanged\0bal\0logDataChanged\0"
    "level\0info\0debRepaymentChanged\0state\0"
    "addNewCreditee\0fname\0lname\0mobile\0"
    "idNo\0updateCreditee\0orig_id\0"
    "loadCrediteeAccounts\0getPaymentHistory\0"
    "repayDebt\0crediteeId\0debt\0debtPaid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CrediteeAccountsModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    0,   80,    2, 0x06 /* Public */,
       6,    3,   81,    2, 0x06 /* Public */,
      10,    1,   88,    2, 0x06 /* Public */,
      12,    2,   91,    2, 0x06 /* Public */,
      15,    1,   96,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    4,   99,    2, 0x02 /* Public */,
      22,    5,  108,    2, 0x02 /* Public */,
      24,    0,  119,    2, 0x02 /* Public */,
      25,    1,  120,    2, 0x02 /* Public */,
      26,    3,  123,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::Bool,   16,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,   21,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Int,   27,   28,   29,

       0        // eod
};

void CrediteeAccountsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CrediteeAccountsModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->crediteeAdded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->crediteeUpdated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->idExists(); break;
        case 3: _t->paymentReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->giveBalanceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->logDataChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->debRepaymentChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->addNewCreditee((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 8: _t->updateCreditee((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 9: _t->loadCrediteeAccounts(); break;
        case 10: _t->getPaymentHistory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: { bool _r = _t->repayDebt((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CrediteeAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::crediteeAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CrediteeAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::crediteeUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CrediteeAccountsModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::idExists)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CrediteeAccountsModel::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::paymentReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CrediteeAccountsModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::giveBalanceChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CrediteeAccountsModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::logDataChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CrediteeAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrediteeAccountsModel::debRepaymentChanged)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CrediteeAccountsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CrediteeAccountsModel.data,
    qt_meta_data_CrediteeAccountsModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CrediteeAccountsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CrediteeAccountsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CrediteeAccountsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int CrediteeAccountsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CrediteeAccountsModel::crediteeAdded(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CrediteeAccountsModel::crediteeUpdated(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CrediteeAccountsModel::idExists()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CrediteeAccountsModel::paymentReceived(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CrediteeAccountsModel::giveBalanceChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CrediteeAccountsModel::logDataChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CrediteeAccountsModel::debRepaymentChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
