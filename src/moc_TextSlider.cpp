/****************************************************************************
** Meta object code from reading C++ file 'TextSlider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "TextSlider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextSlider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextSlider_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextSlider_t qt_meta_stringdata_TextSlider = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextSlider"
QT_MOC_LITERAL(1, 11, 9), // "new_value"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "val"
QT_MOC_LITERAL(4, 26, 15), // "updateval_float"
QT_MOC_LITERAL(5, 42, 16) // "updateval_string"

    },
    "TextSlider\0new_value\0\0val\0updateval_float\0"
    "updateval_string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextSlider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void TextSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextSlider *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->new_value((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->updateval_float((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->updateval_string((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TextSlider::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextSlider::new_value)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TextSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QHBoxLayout::staticMetaObject>(),
    qt_meta_stringdata_TextSlider.data,
    qt_meta_data_TextSlider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextSlider.stringdata0))
        return static_cast<void*>(this);
    return QHBoxLayout::qt_metacast(_clname);
}

int TextSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHBoxLayout::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TextSlider::new_value(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
