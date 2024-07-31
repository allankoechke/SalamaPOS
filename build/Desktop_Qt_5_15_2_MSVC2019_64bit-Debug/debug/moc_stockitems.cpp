/****************************************************************************
** Meta object code from reading C++ file 'stockitems.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/src/stockitems.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockitems.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StockItems_t {
    QByteArrayData data[20];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockItems_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockItems_t qt_meta_stringdata_StockItems = {
    {
QT_MOC_LITERAL(0, 0, 10), // "StockItems"
QT_MOC_LITERAL(1, 11, 14), // "barCodeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "barCode"
QT_MOC_LITERAL(4, 35, 15), // "itemNameChanged"
QT_MOC_LITERAL(5, 51, 8), // "itemName"
QT_MOC_LITERAL(6, 60, 15), // "itemUnitChanged"
QT_MOC_LITERAL(7, 76, 8), // "itemUnit"
QT_MOC_LITERAL(8, 85, 13), // "itemBpChanged"
QT_MOC_LITERAL(9, 99, 6), // "itemBp"
QT_MOC_LITERAL(10, 106, 13), // "itemSpChanged"
QT_MOC_LITERAL(11, 120, 6), // "itemSp"
QT_MOC_LITERAL(12, 127, 14), // "itemQtyChanged"
QT_MOC_LITERAL(13, 142, 7), // "itemQty"
QT_MOC_LITERAL(14, 150, 18), // "itemCompanyChanged"
QT_MOC_LITERAL(15, 169, 11), // "itemCompany"
QT_MOC_LITERAL(16, 181, 17), // "lastUpdateChanged"
QT_MOC_LITERAL(17, 199, 10), // "lastUpdate"
QT_MOC_LITERAL(18, 210, 19), // "itemCategoryChanged"
QT_MOC_LITERAL(19, 230, 12) // "itemCategory"

    },
    "StockItems\0barCodeChanged\0\0barCode\0"
    "itemNameChanged\0itemName\0itemUnitChanged\0"
    "itemUnit\0itemBpChanged\0itemBp\0"
    "itemSpChanged\0itemSp\0itemQtyChanged\0"
    "itemQty\0itemCompanyChanged\0itemCompany\0"
    "lastUpdateChanged\0lastUpdate\0"
    "itemCategoryChanged\0itemCategory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockItems[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       9,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,
      10,    1,   71,    2, 0x06 /* Public */,
      12,    1,   74,    2, 0x06 /* Public */,
      14,    1,   77,    2, 0x06 /* Public */,
      16,    1,   80,    2, 0x06 /* Public */,
      18,    1,   83,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::Float, 0x00495103,
      11, QMetaType::Float, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,

       0        // eod
};

void StockItems::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StockItems *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->barCodeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->itemNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->itemUnitChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->itemBpChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->itemSpChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->itemQtyChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->itemCompanyChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->lastUpdateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->itemCategoryChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StockItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::barCodeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemUnitChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemBpChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemSpChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemQtyChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemCompanyChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::lastUpdateChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (StockItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockItems::itemCategoryChanged)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<StockItems *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->barCode(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->itemName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->itemUnit(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->itemBp(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->itemSp(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->itemQty(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->itemCompany(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->lastUpdate(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->itemCategory(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<StockItems *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBarCode(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setItemName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setItemUnit(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setItemBp(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->setItemSp(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setItemQty(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setItemCompany(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setLastUpdate(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setItemCategory(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject StockItems::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StockItems.data,
    qt_meta_data_StockItems,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StockItems::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockItems::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StockItems.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StockItems::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void StockItems::barCodeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StockItems::itemNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StockItems::itemUnitChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StockItems::itemBpChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StockItems::itemSpChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StockItems::itemQtyChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void StockItems::itemCompanyChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void StockItems::lastUpdateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void StockItems::itemCategoryChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
