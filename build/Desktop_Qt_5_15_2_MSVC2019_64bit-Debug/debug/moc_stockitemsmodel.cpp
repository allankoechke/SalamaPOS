/****************************************************************************
** Meta object code from reading C++ file 'stockitemsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/stockitemsmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockitemsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StockItemsModel_t {
    QByteArrayData data[53];
    char stringdata0[662];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockItemsModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockItemsModel_t qt_meta_stringdata_StockItemsModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "StockItemsModel"
QT_MOC_LITERAL(1, 16, 18), // "itemUpdatedChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "state"
QT_MOC_LITERAL(4, 42, 16), // "itemAddedChanged"
QT_MOC_LITERAL(5, 59, 18), // "itemDeletedChanged"
QT_MOC_LITERAL(6, 78, 16), // "itemStockChanged"
QT_MOC_LITERAL(7, 95, 25), // "itemStockAfterSaleChanged"
QT_MOC_LITERAL(8, 121, 17), // "itemAddingChanged"
QT_MOC_LITERAL(9, 139, 15), // "itemDataChanged"
QT_MOC_LITERAL(10, 155, 6), // "status"
QT_MOC_LITERAL(11, 162, 4), // "json"
QT_MOC_LITERAL(12, 167, 23), // "itemStockWarningChanged"
QT_MOC_LITERAL(13, 191, 20), // "categoryNamesChanged"
QT_MOC_LITERAL(14, 212, 14), // "QList<QString>"
QT_MOC_LITERAL(15, 227, 13), // "categoryNames"
QT_MOC_LITERAL(16, 241, 17), // "categoryIdChanged"
QT_MOC_LITERAL(17, 259, 10), // "categoryId"
QT_MOC_LITERAL(18, 270, 14), // "logDataChanged"
QT_MOC_LITERAL(19, 285, 5), // "level"
QT_MOC_LITERAL(20, 291, 4), // "info"
QT_MOC_LITERAL(21, 296, 10), // "addNewItem"
QT_MOC_LITERAL(22, 307, 7), // "barcode"
QT_MOC_LITERAL(23, 315, 4), // "name"
QT_MOC_LITERAL(24, 320, 4), // "unit"
QT_MOC_LITERAL(25, 325, 2), // "bp"
QT_MOC_LITERAL(26, 328, 2), // "sp"
QT_MOC_LITERAL(27, 331, 3), // "qty"
QT_MOC_LITERAL(28, 335, 7), // "company"
QT_MOC_LITERAL(29, 343, 4), // "date"
QT_MOC_LITERAL(30, 348, 8), // "category"
QT_MOC_LITERAL(31, 357, 10), // "updateItem"
QT_MOC_LITERAL(32, 368, 12), // "orig_barcode"
QT_MOC_LITERAL(33, 381, 5), // "index"
QT_MOC_LITERAL(34, 387, 10), // "deleteItem"
QT_MOC_LITERAL(35, 398, 11), // "updateStock"
QT_MOC_LITERAL(36, 410, 18), // "updateStockHistory"
QT_MOC_LITERAL(37, 429, 16), // "stock_qty_before"
QT_MOC_LITERAL(38, 446, 15), // "stock_qty_added"
QT_MOC_LITERAL(39, 462, 12), // "date_updated"
QT_MOC_LITERAL(40, 475, 11), // "who_updated"
QT_MOC_LITERAL(41, 487, 9), // "is_adding"
QT_MOC_LITERAL(42, 497, 17), // "updateStockOnSale"
QT_MOC_LITERAL(43, 515, 5), // "bcode"
QT_MOC_LITERAL(44, 521, 21), // "initializeStockFromDb"
QT_MOC_LITERAL(45, 543, 17), // "generatePriceList"
QT_MOC_LITERAL(46, 561, 12), // "getItemStock"
QT_MOC_LITERAL(47, 574, 11), // "getItemData"
QT_MOC_LITERAL(48, 586, 17), // "getItemCategories"
QT_MOC_LITERAL(49, 604, 15), // "addItemCategory"
QT_MOC_LITERAL(50, 620, 14), // "getCategryList"
QT_MOC_LITERAL(51, 635, 11), // "loadHistory"
QT_MOC_LITERAL(52, 647, 14) // "getCurrentTime"

    },
    "StockItemsModel\0itemUpdatedChanged\0\0"
    "state\0itemAddedChanged\0itemDeletedChanged\0"
    "itemStockChanged\0itemStockAfterSaleChanged\0"
    "itemAddingChanged\0itemDataChanged\0"
    "status\0json\0itemStockWarningChanged\0"
    "categoryNamesChanged\0QList<QString>\0"
    "categoryNames\0categoryIdChanged\0"
    "categoryId\0logDataChanged\0level\0info\0"
    "addNewItem\0barcode\0name\0unit\0bp\0sp\0"
    "qty\0company\0date\0category\0updateItem\0"
    "orig_barcode\0index\0deleteItem\0updateStock\0"
    "updateStockHistory\0stock_qty_before\0"
    "stock_qty_added\0date_updated\0who_updated\0"
    "is_adding\0updateStockOnSale\0bcode\0"
    "initializeStockFromDb\0generatePriceList\0"
    "getItemStock\0getItemData\0getItemCategories\0"
    "addItemCategory\0getCategryList\0"
    "loadHistory\0getCurrentTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockItemsModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       2,  264, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,
       4,    1,  147,    2, 0x06 /* Public */,
       5,    1,  150,    2, 0x06 /* Public */,
       6,    1,  153,    2, 0x06 /* Public */,
       7,    1,  156,    2, 0x06 /* Public */,
       8,    1,  159,    2, 0x06 /* Public */,
       9,    2,  162,    2, 0x06 /* Public */,
      12,    0,  167,    2, 0x06 /* Public */,
      13,    1,  168,    2, 0x06 /* Public */,
      16,    1,  171,    2, 0x06 /* Public */,
      18,    2,  174,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      21,    9,  179,    2, 0x02 /* Public */,
      31,    9,  198,    2, 0x02 /* Public */,
      34,    1,  217,    2, 0x02 /* Public */,
      35,    4,  220,    2, 0x02 /* Public */,
      36,    6,  229,    2, 0x02 /* Public */,
      42,    2,  242,    2, 0x02 /* Public */,
      44,    0,  247,    2, 0x02 /* Public */,
      45,    0,  248,    2, 0x02 /* Public */,
      46,    1,  249,    2, 0x02 /* Public */,
      47,    1,  252,    2, 0x02 /* Public */,
      48,    0,  255,    2, 0x02 /* Public */,
      49,    1,  256,    2, 0x02 /* Public */,
      50,    0,  259,    2, 0x02 /* Public */,
      51,    1,  260,    2, 0x02 /* Public */,
      52,    0,  263,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QJsonObject,   10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   22,   23,   24,   25,   26,   27,   28,   29,   30,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   22,   23,   24,   25,   26,   28,   30,   32,   33,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   22,   27,   29,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   22,   37,   38,   39,   40,   41,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Int,   43,   27,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Int, QMetaType::QVariant,   22,
    QMetaType::QJsonObject, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,
    0x80000000 | 14,
    QMetaType::QVariantMap, QMetaType::QString,   22,
    QMetaType::QString,

 // properties: name, type, flags
      15, 0x80000000 | 14, 0x0049510b,
      17, 0x80000000 | 14, 0x0049510b,

 // properties: notify_signal_id
       8,
       9,

       0        // eod
};

void StockItemsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StockItemsModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemUpdatedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->itemAddedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->itemDeletedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->itemStockChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->itemStockAfterSaleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->itemAddingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->itemDataChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 7: _t->itemStockWarningChanged(); break;
        case 8: _t->categoryNamesChanged((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 9: _t->categoryIdChanged((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 10: _t->logDataChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->addNewItem((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QVariant(*)>(_a[5])),(*reinterpret_cast< const QVariant(*)>(_a[6])),(*reinterpret_cast< const QVariant(*)>(_a[7])),(*reinterpret_cast< const QVariant(*)>(_a[8])),(*reinterpret_cast< const QVariant(*)>(_a[9]))); break;
        case 12: _t->updateItem((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QVariant(*)>(_a[5])),(*reinterpret_cast< const QVariant(*)>(_a[6])),(*reinterpret_cast< const QVariant(*)>(_a[7])),(*reinterpret_cast< const QVariant(*)>(_a[8])),(*reinterpret_cast< const QVariant(*)>(_a[9]))); break;
        case 13: _t->deleteItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->updateStock((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4]))); break;
        case 15: _t->updateStockHistory((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const bool(*)>(_a[6]))); break;
        case 16: _t->updateStockOnSale((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 17: _t->initializeStockFromDb(); break;
        case 18: { QString _r = _t->generatePriceList();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->getItemStock((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: { QJsonObject _r = _t->getItemData((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->getItemCategories(); break;
        case 22: _t->addItemCategory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: { QList<QString> _r = _t->getCategryList();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 24: { QVariantMap _r = _t->loadHistory((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->getCurrentTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StockItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemUpdatedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemAddedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemDeletedChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemStockChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemStockAfterSaleChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemAddingChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(bool , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemDataChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::itemStockWarningChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::categoryNamesChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::categoryIdChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (StockItemsModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItemsModel::logDataChanged)) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<StockItemsModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->categoryNames(); break;
        case 1: *reinterpret_cast< QList<QString>*>(_v) = _t->categoryId(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<StockItemsModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCategoryNames(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 1: _t->setCategoryId(*reinterpret_cast< QList<QString>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject StockItemsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_StockItemsModel.data,
    qt_meta_data_StockItemsModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StockItemsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockItemsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StockItemsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int StockItemsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
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
void StockItemsModel::itemUpdatedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StockItemsModel::itemAddedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StockItemsModel::itemDeletedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StockItemsModel::itemStockChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StockItemsModel::itemStockAfterSaleChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StockItemsModel::itemAddingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void StockItemsModel::itemDataChanged(bool _t1, QJsonObject _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void StockItemsModel::itemStockWarningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void StockItemsModel::categoryNamesChanged(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void StockItemsModel::categoryIdChanged(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void StockItemsModel::logDataChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
