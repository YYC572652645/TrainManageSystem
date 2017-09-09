/****************************************************************************
** Meta object code from reading C++ file 'traininfoselect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../traininfoselect/traininfoselect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'traininfoselect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TrainInfoSelect_t {
    QByteArrayData data[9];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrainInfoSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrainInfoSelect_t qt_meta_stringdata_TrainInfoSelect = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TrainInfoSelect"
QT_MOC_LITERAL(1, 16, 11), // "updateMovie"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "updateData"
QT_MOC_LITERAL(4, 40, 10), // "dataDelete"
QT_MOC_LITERAL(5, 51, 28), // "on_pushButtonRefresh_clicked"
QT_MOC_LITERAL(6, 80, 22), // "on_tableWidget_clicked"
QT_MOC_LITERAL(7, 103, 5), // "index"
QT_MOC_LITERAL(8, 109, 25) // "on_pushButtonFind_clicked"

    },
    "TrainInfoSelect\0updateMovie\0\0updateData\0"
    "dataDelete\0on_pushButtonRefresh_clicked\0"
    "on_tableWidget_clicked\0index\0"
    "on_pushButtonFind_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainInfoSelect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,

       0        // eod
};

void TrainInfoSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrainInfoSelect *_t = static_cast<TrainInfoSelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMovie(); break;
        case 1: _t->updateData(); break;
        case 2: _t->dataDelete(); break;
        case 3: _t->on_pushButtonRefresh_clicked(); break;
        case 4: _t->on_tableWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButtonFind_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject TrainInfoSelect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrainInfoSelect.data,
      qt_meta_data_TrainInfoSelect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrainInfoSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainInfoSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrainInfoSelect.stringdata0))
        return static_cast<void*>(const_cast< TrainInfoSelect*>(this));
    return QWidget::qt_metacast(_clname);
}

int TrainInfoSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
