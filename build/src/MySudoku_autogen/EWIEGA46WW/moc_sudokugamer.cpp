/****************************************************************************
** Meta object code from reading C++ file 'sudokugamer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/sudokugamer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sudokugamer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SudokuGamer_t {
    QByteArrayData data[11];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SudokuGamer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SudokuGamer_t qt_meta_stringdata_SudokuGamer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SudokuGamer"
QT_MOC_LITERAL(1, 12, 6), // "makeit"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "m"
QT_MOC_LITERAL(4, 22, 6), // "answer"
QT_MOC_LITERAL(5, 29, 3), // "ans"
QT_MOC_LITERAL(6, 33, 11), // "on_checking"
QT_MOC_LITERAL(7, 45, 1), // "n"
QT_MOC_LITERAL(8, 47, 3), // "ind"
QT_MOC_LITERAL(9, 51, 11), // "on_set_diff"
QT_MOC_LITERAL(10, 63, 11) // "on_new_game"

    },
    "SudokuGamer\0makeit\0\0m\0answer\0ans\0"
    "on_checking\0n\0ind\0on_set_diff\0on_new_game"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SudokuGamer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   45,    2, 0x0a /* Public */,
       9,    1,   50,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void SudokuGamer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SudokuGamer *_t = static_cast<SudokuGamer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->makeit((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->answer((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->on_checking((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_set_diff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_new_game(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SudokuGamer::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SudokuGamer::makeit)) {
                *result = 0;
            }
        }
        {
            typedef void (SudokuGamer::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SudokuGamer::answer)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SudokuGamer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SudokuGamer.data,
      qt_meta_data_SudokuGamer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SudokuGamer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SudokuGamer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SudokuGamer.stringdata0))
        return static_cast<void*>(const_cast< SudokuGamer*>(this));
    return QObject::qt_metacast(_clname);
}

int SudokuGamer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SudokuGamer::makeit(QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SudokuGamer::answer(QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
