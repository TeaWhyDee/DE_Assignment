/****************************************************************************
** Meta object code from reading C++ file 'View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View_t {
    QByteArrayData data[16];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
QT_MOC_LITERAL(0, 0, 4), // "View"
QT_MOC_LITERAL(1, 5, 9), // "update_x0"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "val"
QT_MOC_LITERAL(4, 20, 9), // "update_y0"
QT_MOC_LITERAL(5, 30, 8), // "update_X"
QT_MOC_LITERAL(6, 39, 8), // "update_N"
QT_MOC_LITERAL(7, 48, 12), // "toggle_exact"
QT_MOC_LITERAL(8, 61, 5), // "state"
QT_MOC_LITERAL(9, 67, 12), // "toggle_euler"
QT_MOC_LITERAL(10, 80, 13), // "toggle_ieuler"
QT_MOC_LITERAL(11, 94, 9), // "toggle_rk"
QT_MOC_LITERAL(12, 104, 13), // "enable_graphs"
QT_MOC_LITERAL(13, 118, 1), // "_"
QT_MOC_LITERAL(14, 120, 13), // "enable_errors"
QT_MOC_LITERAL(15, 134, 15) // "enable_errors_n"

    },
    "View\0update_x0\0\0val\0update_y0\0update_X\0"
    "update_N\0toggle_exact\0state\0toggle_euler\0"
    "toggle_ieuler\0toggle_rk\0enable_graphs\0"
    "_\0enable_errors\0enable_errors_n"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    1,   72,    2, 0x0a /* Public */,
       5,    1,   75,    2, 0x0a /* Public */,
       6,    1,   78,    2, 0x0a /* Public */,
       7,    1,   81,    2, 0x0a /* Public */,
       9,    1,   84,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      14,    1,   96,    2, 0x0a /* Public */,
      15,    1,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->update_x0((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->update_y0((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->update_X((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->update_N((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->toggle_exact((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->toggle_euler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->toggle_ieuler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->toggle_rk((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->enable_graphs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->enable_errors((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->enable_errors_n((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_View.data,
    qt_meta_data_View,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
