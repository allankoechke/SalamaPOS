/****************************************************************************
** Meta object code from reading C++ file 'checkoutitemsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/checkoutitemsmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkoutitemsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CheckoutItemsModel_t {
    QByteArrayData data[27];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CheckoutItemsModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CheckoutItemsModel_t qt_meta_stringdata_CheckoutItemsModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CheckoutItemsModel"
QT_MOC_LITERAL(1, 19, 17), // "sellTotalsChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 10), // "sellTotals"
QT_MOC_LITERAL(4, 49, 14), // "saleQtyChanged"
QT_MOC_LITERAL(5, 64, 5), // "state"
QT_MOC_LITERAL(6, 70, 24), // "checkoutModelSizeChanged"
QT_MOC_LITERAL(7, 95, 17), // "checkoutModelSize"
QT_MOC_LITERAL(8, 113, 14), // "logDataChanged"
QT_MOC_LITERAL(9, 128, 5), // "level"
QT_MOC_LITERAL(10, 134, 4), // "info"
QT_MOC_LITERAL(11, 139, 14), // "removeSellItem"
QT_MOC_LITERAL(12, 154, 5), // "index"
QT_MOC_LITERAL(13, 160, 11), // "addSellItem"
QT_MOC_LITERAL(14, 172, 11), // "sellBarcode"
QT_MOC_LITERAL(15, 184, 12), // "sellItemName"
QT_MOC_LITERAL(16, 197, 12), // "sellItemUnit"
QT_MOC_LITERAL(17, 210, 11), // "buyingPrice"
QT_MOC_LITERAL(18, 222, 12), // "sellingPrice"
QT_MOC_LITERAL(19, 235, 7), // "sellQty"
QT_MOC_LITERAL(20, 243, 15), // "changeSellStock"
QT_MOC_LITERAL(21, 259, 3), // "qty"
QT_MOC_LITERAL(22, 263, 7), // "barcode"
QT_MOC_LITERAL(23, 271, 13), // "startANewSell"
QT_MOC_LITERAL(24, 285, 10), // "findTotals"
QT_MOC_LITERAL(25, 296, 12), // "getBarcodeAt"
QT_MOC_LITERAL(26, 309, 12) // "getSellQtyAt"

    },
    "CheckoutItemsModel\0sellTotalsChanged\0"
    "\0sellTotals\0saleQtyChanged\0state\0"
    "checkoutModelSizeChanged\0checkoutModelSize\0"
    "logDataChanged\0level\0info\0removeSellItem\0"
    "index\0addSellItem\0sellBarcode\0"
    "sellItemName\0sellItemUnit\0buyingPrice\0"
    "sellingPrice\0sellQty\0changeSellStock\0"
    "qty\0barcode\0startANewSell\0findTotals\0"
    "getBarcodeAt\0getSellQtyAt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckoutItemsModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       2,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       8,    2,   78,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    1,   83,    2, 0x02 /* Public */,
      13,    6,   86,    2, 0x02 /* Public */,
      20,    2,   99,    2, 0x02 /* Public */,
      23,    0,  104,    2, 0x02 /* Public */,
      24,    0,  105,    2, 0x02 /* Public */,
      25,    1,  106,    2, 0x02 /* Public */,
      26,    1,  109,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   14,   15,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,   21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,   12,
    QMetaType::Int, QMetaType::Int,   12,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
       7, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       2,

       0        // eod
};

void CheckoutItemsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CheckoutItemsModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sellTotalsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->saleQtyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->checkoutModelSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->logDataChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->removeSellItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->addSellItem((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QVariant(*)>(_a[5])),(*reinterpret_cast< const QVariant(*)>(_a[6]))); break;
        case 6: _t->changeSellStock((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 7: _t->startANewSell(); break;
        case 8: _t->findTotals(); break;
        case 9: { QString _r = _t->getBarcodeAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->getSellQtyAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CheckoutItemsModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItemsModel::sellTotalsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CheckoutItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItemsModel::saleQtyChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CheckoutItemsModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItemsModel::checkoutModelSizeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CheckoutItemsModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItemsModel::logDataChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CheckoutItemsModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->sellTotals(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->checkoutModelSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CheckoutItemsModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSellTotals(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCheckoutModelSize(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CheckoutItemsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CheckoutItemsModel.data,
    qt_meta_data_CheckoutItemsModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CheckoutItemsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckoutItemsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CheckoutItemsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int CheckoutItemsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CheckoutItemsModel::sellTotalsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CheckoutItemsModel::saleQtyChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CheckoutItemsModel::checkoutModelSizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CheckoutItemsModel::logDataChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
