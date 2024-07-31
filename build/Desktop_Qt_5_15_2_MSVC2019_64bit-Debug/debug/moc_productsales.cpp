/****************************************************************************
** Meta object code from reading C++ file 'productsales.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/src/productsales.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productsales.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductSales_t {
    QByteArrayData data[18];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductSales_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductSales_t qt_meta_stringdata_ProductSales = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ProductSales"
QT_MOC_LITERAL(1, 13, 20), // "productSaleIdChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "productSaleId"
QT_MOC_LITERAL(4, 49, 21), // "productBarcodeChanged"
QT_MOC_LITERAL(5, 71, 14), // "productBarcode"
QT_MOC_LITERAL(6, 86, 18), // "productNameChanged"
QT_MOC_LITERAL(7, 105, 11), // "productName"
QT_MOC_LITERAL(8, 117, 18), // "productUnitChanged"
QT_MOC_LITERAL(9, 136, 11), // "productUnit"
QT_MOC_LITERAL(10, 148, 17), // "productQtyChanged"
QT_MOC_LITERAL(11, 166, 10), // "productQty"
QT_MOC_LITERAL(12, 177, 16), // "productBpChanged"
QT_MOC_LITERAL(13, 194, 9), // "productBp"
QT_MOC_LITERAL(14, 204, 16), // "productSpChanged"
QT_MOC_LITERAL(15, 221, 9), // "productSp"
QT_MOC_LITERAL(16, 231, 21), // "productPaymentChanged"
QT_MOC_LITERAL(17, 253, 14) // "productPayment"

    },
    "ProductSales\0productSaleIdChanged\0\0"
    "productSaleId\0productBarcodeChanged\0"
    "productBarcode\0productNameChanged\0"
    "productName\0productUnitChanged\0"
    "productUnit\0productQtyChanged\0productQty\0"
    "productBpChanged\0productBp\0productSpChanged\0"
    "productSp\0productPaymentChanged\0"
    "productPayment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductSales[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,
      10,    1,   66,    2, 0x06 /* Public */,
      12,    1,   69,    2, 0x06 /* Public */,
      14,    1,   72,    2, 0x06 /* Public */,
      16,    1,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QJsonObject,   17,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      11, QMetaType::Int, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      17, QMetaType::QJsonObject, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void ProductSales::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductSales *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->productSaleIdChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->productBarcodeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->productNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->productUnitChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->productQtyChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->productBpChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->productSpChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->productPaymentChanged((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProductSales::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productSaleIdChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productBarcodeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productNameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productUnitChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productQtyChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productBpChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productSpChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ProductSales::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductSales::productPaymentChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ProductSales *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->productSaleId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->productBarcode(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->productName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->productUnit(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->productQty(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->productBp(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->productSp(); break;
        case 7: *reinterpret_cast< QJsonObject*>(_v) = _t->productPayment(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ProductSales *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setProductSaleId(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setProductBarcode(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setProductName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setProductUnit(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setProductQty(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setProductBp(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setProductSp(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setProductPayment(*reinterpret_cast< QJsonObject*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ProductSales::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProductSales.data,
    qt_meta_data_ProductSales,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProductSales::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductSales::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductSales.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProductSales::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProductSales::productSaleIdChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProductSales::productBarcodeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProductSales::productNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProductSales::productUnitChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProductSales::productQtyChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ProductSales::productBpChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ProductSales::productSpChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ProductSales::productPaymentChanged(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
