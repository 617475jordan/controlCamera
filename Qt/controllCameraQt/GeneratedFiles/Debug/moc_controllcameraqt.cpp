/****************************************************************************
** Meta object code from reading C++ file 'controllcameraqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../controllcameraqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllcameraqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_controllCameraQt_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controllCameraQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controllCameraQt_t qt_meta_stringdata_controllCameraQt = {
    {
QT_MOC_LITERAL(0, 0, 16), // "controllCameraQt"
QT_MOC_LITERAL(1, 17, 10), // "Initialize"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "openClicked"
QT_MOC_LITERAL(4, 41, 12), // "closeClicked"
QT_MOC_LITERAL(5, 54, 11), // "currentTime"
QT_MOC_LITERAL(6, 66, 12), // "pushButton_3"
QT_MOC_LITERAL(7, 79, 12) // "pushButton_4"

    },
    "controllCameraQt\0Initialize\0\0openClicked\0"
    "closeClicked\0currentTime\0pushButton_3\0"
    "pushButton_4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controllCameraQt[] = {

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
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void controllCameraQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controllCameraQt *_t = static_cast<controllCameraQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Initialize(); break;
        case 1: _t->openClicked(); break;
        case 2: _t->closeClicked(); break;
        case 3: _t->currentTime(); break;
        case 4: _t->pushButton_3(); break;
        case 5: _t->pushButton_4(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject controllCameraQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_controllCameraQt.data,
      qt_meta_data_controllCameraQt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *controllCameraQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controllCameraQt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_controllCameraQt.stringdata0))
        return static_cast<void*>(const_cast< controllCameraQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int controllCameraQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
