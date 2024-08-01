/****************************************************************************
** Meta object code from reading C++ file 'useraccountsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpp/models/useraccountsmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'useraccountsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserAccountsModel_t {
    QByteArrayData data[47];
    char stringdata0[707];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserAccountsModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserAccountsModel_t qt_meta_stringdata_UserAccountsModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "UserAccountsModel"
QT_MOC_LITERAL(1, 18, 16), // "userAddedChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "status"
QT_MOC_LITERAL(4, 43, 18), // "userRemovedChanged"
QT_MOC_LITERAL(5, 62, 18), // "userUpdatedChanged"
QT_MOC_LITERAL(6, 81, 22), // "userPriviledgesChanged"
QT_MOC_LITERAL(7, 104, 19), // "userPasswordChanged"
QT_MOC_LITERAL(8, 124, 23), // "userPasswordChangeError"
QT_MOC_LITERAL(9, 148, 6), // "reason"
QT_MOC_LITERAL(10, 155, 22), // "toDeleteAccountChanged"
QT_MOC_LITERAL(11, 178, 19), // "loggedInUserChanged"
QT_MOC_LITERAL(12, 198, 12), // "loggedInUser"
QT_MOC_LITERAL(13, 211, 20), // "logged_inUserChanged"
QT_MOC_LITERAL(14, 232, 23), // "loggingInUsernameStatus"
QT_MOC_LITERAL(15, 256, 23), // "loggingInPasswordStatus"
QT_MOC_LITERAL(16, 280, 18), // "userAccountsLoaded"
QT_MOC_LITERAL(17, 299, 21), // "usernameExistsChanged"
QT_MOC_LITERAL(18, 321, 14), // "logDataChanged"
QT_MOC_LITERAL(19, 336, 5), // "level"
QT_MOC_LITERAL(20, 342, 4), // "info"
QT_MOC_LITERAL(21, 347, 17), // "addNewUserAccount"
QT_MOC_LITERAL(22, 365, 13), // "userFirstname"
QT_MOC_LITERAL(23, 379, 12), // "userLastname"
QT_MOC_LITERAL(24, 392, 12), // "userUsername"
QT_MOC_LITERAL(25, 405, 12), // "userPassword"
QT_MOC_LITERAL(26, 418, 11), // "userPhoneNo"
QT_MOC_LITERAL(27, 430, 13), // "userDateAdded"
QT_MOC_LITERAL(28, 444, 14), // "updatePassword"
QT_MOC_LITERAL(29, 459, 17), // "removeUserAccount"
QT_MOC_LITERAL(30, 477, 5), // "index"
QT_MOC_LITERAL(31, 483, 17), // "updateUserAccount"
QT_MOC_LITERAL(32, 501, 13), // "orig_username"
QT_MOC_LITERAL(33, 515, 11), // "canAddUsers"
QT_MOC_LITERAL(34, 527, 14), // "canRemoveUsers"
QT_MOC_LITERAL(35, 542, 11), // "canAddItems"
QT_MOC_LITERAL(36, 554, 14), // "canRemoveItems"
QT_MOC_LITERAL(37, 569, 11), // "canAddStock"
QT_MOC_LITERAL(38, 581, 14), // "canRemoveStock"
QT_MOC_LITERAL(39, 596, 12), // "canUndoSales"
QT_MOC_LITERAL(40, 609, 11), // "canBackupDb"
QT_MOC_LITERAL(41, 621, 22), // "markAccountForDeleting"
QT_MOC_LITERAL(42, 644, 19), // "loadAllUserAccounts"
QT_MOC_LITERAL(43, 664, 9), // "loginUser"
QT_MOC_LITERAL(44, 674, 5), // "uname"
QT_MOC_LITERAL(45, 680, 4), // "pswd"
QT_MOC_LITERAL(46, 685, 21) // "getUpdatedPriviledges"

    },
    "UserAccountsModel\0userAddedChanged\0\0"
    "status\0userRemovedChanged\0userUpdatedChanged\0"
    "userPriviledgesChanged\0userPasswordChanged\0"
    "userPasswordChangeError\0reason\0"
    "toDeleteAccountChanged\0loggedInUserChanged\0"
    "loggedInUser\0logged_inUserChanged\0"
    "loggingInUsernameStatus\0loggingInPasswordStatus\0"
    "userAccountsLoaded\0usernameExistsChanged\0"
    "logDataChanged\0level\0info\0addNewUserAccount\0"
    "userFirstname\0userLastname\0userUsername\0"
    "userPassword\0userPhoneNo\0userDateAdded\0"
    "updatePassword\0removeUserAccount\0index\0"
    "updateUserAccount\0orig_username\0"
    "canAddUsers\0canRemoveUsers\0canAddItems\0"
    "canRemoveItems\0canAddStock\0canRemoveStock\0"
    "canUndoSales\0canBackupDb\0"
    "markAccountForDeleting\0loadAllUserAccounts\0"
    "loginUser\0uname\0pswd\0getUpdatedPriviledges"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserAccountsModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       1,  254, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       4,    1,  137,    2, 0x06 /* Public */,
       5,    1,  140,    2, 0x06 /* Public */,
       6,    1,  143,    2, 0x06 /* Public */,
       7,    1,  146,    2, 0x06 /* Public */,
       8,    1,  149,    2, 0x06 /* Public */,
      10,    1,  152,    2, 0x06 /* Public */,
      11,    1,  155,    2, 0x06 /* Public */,
      13,    0,  158,    2, 0x06 /* Public */,
      14,    1,  159,    2, 0x06 /* Public */,
      15,    1,  162,    2, 0x06 /* Public */,
      16,    1,  165,    2, 0x06 /* Public */,
      17,    1,  168,    2, 0x06 /* Public */,
      18,    2,  171,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      21,    6,  176,    2, 0x02 /* Public */,
      21,    5,  189,    2, 0x22 /* Public | MethodCloned */,
      28,    3,  200,    2, 0x02 /* Public */,
      29,    2,  207,    2, 0x02 /* Public */,
      31,    5,  212,    2, 0x02 /* Public */,
      31,    9,  223,    2, 0x02 /* Public */,
      41,    1,  242,    2, 0x02 /* Public */,
      42,    0,  245,    2, 0x02 /* Public */,
      43,    2,  246,    2, 0x02 /* Public */,
      46,    1,  251,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QJsonObject,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   22,   23,   24,   25,   26,   27,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   22,   23,   24,   25,   26,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   24,    2,    2,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,   24,   30,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   22,   23,   24,   26,   32,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   24,   33,   34,   35,   36,   37,   38,   39,   40,
    QMetaType::Void, QMetaType::QVariant,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,   44,   45,
    QMetaType::QJsonObject, QMetaType::Int,   30,

 // properties: name, type, flags
      12, QMetaType::QJsonObject, 0x00495103,

 // properties: notify_signal_id
       7,

       0        // eod
};

void UserAccountsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserAccountsModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userAddedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->userRemovedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->userUpdatedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->userPriviledgesChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->userPasswordChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->userPasswordChangeError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->toDeleteAccountChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->loggedInUserChanged((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 8: _t->logged_inUserChanged(); break;
        case 9: _t->loggingInUsernameStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->loggingInPasswordStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->userAccountsLoaded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->usernameExistsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->logDataChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->addNewUserAccount((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QVariant(*)>(_a[5])),(*reinterpret_cast< const QVariant(*)>(_a[6]))); break;
        case 15: _t->addNewUserAccount((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QVariant(*)>(_a[5]))); break;
        case 16: _t->updatePassword((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 17: _t->removeUserAccount((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 18: _t->updateUserAccount((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QVariant(*)>(_a[5]))); break;
        case 19: _t->updateUserAccount((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3])),(*reinterpret_cast< const bool(*)>(_a[4])),(*reinterpret_cast< const bool(*)>(_a[5])),(*reinterpret_cast< const bool(*)>(_a[6])),(*reinterpret_cast< const bool(*)>(_a[7])),(*reinterpret_cast< const bool(*)>(_a[8])),(*reinterpret_cast< const bool(*)>(_a[9]))); break;
        case 20: _t->markAccountForDeleting((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 21: _t->loadAllUserAccounts(); break;
        case 22: _t->loginUser((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 23: { QJsonObject _r = _t->getUpdatedPriviledges((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userAddedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userRemovedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userUpdatedChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userPriviledgesChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userPasswordChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userPasswordChangeError)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::toDeleteAccountChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::loggedInUserChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::logged_inUserChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::loggingInUsernameStatus)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::loggingInPasswordStatus)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::userAccountsLoaded)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::usernameExistsChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (UserAccountsModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccountsModel::logDataChanged)) {
                *result = 13;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UserAccountsModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QJsonObject*>(_v) = _t->loggedInUser(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UserAccountsModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLoggedInUser(*reinterpret_cast< QJsonObject*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UserAccountsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_UserAccountsModel.data,
    qt_meta_data_UserAccountsModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserAccountsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserAccountsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserAccountsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int UserAccountsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
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
void UserAccountsModel::userAddedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserAccountsModel::userRemovedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserAccountsModel::userUpdatedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserAccountsModel::userPriviledgesChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UserAccountsModel::userPasswordChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void UserAccountsModel::userPasswordChangeError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void UserAccountsModel::toDeleteAccountChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void UserAccountsModel::loggedInUserChanged(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void UserAccountsModel::logged_inUserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void UserAccountsModel::loggingInUsernameStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void UserAccountsModel::loggingInPasswordStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void UserAccountsModel::userAccountsLoaded(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void UserAccountsModel::usernameExistsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void UserAccountsModel::logDataChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
