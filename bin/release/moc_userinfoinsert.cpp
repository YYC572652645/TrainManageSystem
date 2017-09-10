/****************************************************************************
** Meta object code from reading C++ file 'userinfoinsert.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userinfoinsert/userinfoinsert.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinfoinsert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserInfoInsert_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserInfoInsert_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserInfoInsert_t qt_meta_stringdata_UserInfoInsert = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserInfoInsert"
QT_MOC_LITERAL(1, 15, 10), // "insertData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "seatMoneyChange"
QT_MOC_LITERAL(4, 43, 5), // "value"
QT_MOC_LITERAL(5, 49, 16) // "seatNumberChange"

    },
    "UserInfoInsert\0insertData\0\0seatMoneyChange\0"
    "value\0seatNumberChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserInfoInsert[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void UserInfoInsert::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserInfoInsert *_t = static_cast<UserInfoInsert *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertData(); break;
        case 1: _t->seatMoneyChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->seatNumberChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UserInfoInsert::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserInfoInsert.data,
      qt_meta_data_UserInfoInsert,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserInfoInsert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserInfoInsert::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserInfoInsert.stringdata0))
        return static_cast<void*>(const_cast< UserInfoInsert*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserInfoInsert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
