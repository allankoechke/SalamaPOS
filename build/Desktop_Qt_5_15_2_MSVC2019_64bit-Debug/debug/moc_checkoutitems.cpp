/****************************************************************************
** Meta object code from reading C++ file 'checkoutitems.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/src/checkoutitems.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkoutitems.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CheckoutItems_t {
    QByteArrayData data[14];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CheckoutItems_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CheckoutItems_t qt_meta_stringdata_CheckoutItems = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CheckoutItems"
QT_MOC_LITERAL(1, 14, 18), // "sellBarcodeChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "sellBarcode"
QT_MOC_LITERAL(4, 46, 19), // "sellItemNameChanged"
QT_MOC_LITERAL(5, 66, 12), // "sellItemName"
QT_MOC_LITERAL(6, 79, 19), // "sellItemUnitChanged"
QT_MOC_LITERAL(7, 99, 12), // "sellItemUnit"
QT_MOC_LITERAL(8, 112, 19), // "sellingPriceChanged"
QT_MOC_LITERAL(9, 132, 12), // "sellingPrice"
QT_MOC_LITERAL(10, 145, 18), // "buyingPriceChanged"
QT_MOC_LITERAL(11, 164, 11), // "buyingPrice"
QT_MOC_LITERAL(12, 176, 14), // "sellQtyChanged"
QT_MOC_LITERAL(13, 191, 7) // "sellQty"

    },
    "CheckoutItems\0sellBarcodeChanged\0\0"
    "sellBarcode\0sellItemNameChanged\0"
    "sellItemName\0sellItemUnitChanged\0"
    "sellItemUnit\0sellingPriceChanged\0"
    "sellingPrice\0buyingPriceChanged\0"
    "buyingPrice\0sellQtyChanged\0sellQty"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckoutItems[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    1,   53,    2, 0x06 /* Public */,
      10,    1,   56,    2, 0x06 /* Public */,
      12,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void, QMetaType::Int,   13,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
      11, QMetaType::Float, 0x00495103,
       9, QMetaType::Float, 0x00495103,
      13, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       4,
       3,
       5,

       0        // eod
};

void CheckoutItems::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CheckoutItems *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sellBarcodeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sellItemNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sellItemUnitChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sellingPriceChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->buyingPriceChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->sellQtyChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CheckoutItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItems::sellBarcodeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CheckoutItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItems::sellItemNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CheckoutItems::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItems::sellItemUnitChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CheckoutItems::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItems::sellingPriceChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CheckoutItems::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItems::buyingPriceChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CheckoutItems::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutItems::sellQtyChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CheckoutItems *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sellBarcode(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->sellItemName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->sellItemUnit(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->buyingPrice(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->sellingPrice(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->sellQty(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CheckoutItems *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSellBarcode(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setSellItemName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSellItemUnit(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setBuyingPrice(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->setSellingPrice(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setSellQty(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CheckoutItems::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CheckoutItems.data,
    qt_meta_data_CheckoutItems,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CheckoutItems::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckoutItems::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CheckoutItems.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CheckoutItems::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CheckoutItems::sellBarcodeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CheckoutItems::sellItemNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CheckoutItems::sellItemUnitChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CheckoutItems::sellingPriceChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CheckoutItems::buyingPriceChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CheckoutItems::sellQtyChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
