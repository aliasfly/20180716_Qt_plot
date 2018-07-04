/****************************************************************************
** Meta object code from reading C++ file 'dataStore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dataStore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataStore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataStore_t {
    QByteArrayData data[13];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataStore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataStore_t qt_meta_stringdata_DataStore = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DataStore"
QT_MOC_LITERAL(1, 10, 10), // "strChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "str"
QT_MOC_LITERAL(4, 26, 11), // "str2Changed"
QT_MOC_LITERAL(5, 38, 4), // "str2"
QT_MOC_LITERAL(6, 43, 11), // "str3Changed"
QT_MOC_LITERAL(7, 55, 4), // "str3"
QT_MOC_LITERAL(8, 60, 6), // "getstr"
QT_MOC_LITERAL(9, 67, 9), // "xMaxValue"
QT_MOC_LITERAL(10, 77, 9), // "xMinValue"
QT_MOC_LITERAL(11, 87, 9), // "yMaxValue"
QT_MOC_LITERAL(12, 97, 9) // "yMinValue"

    },
    "DataStore\0strChanged\0\0str\0str2Changed\0"
    "str2\0str3Changed\0str3\0getstr\0xMaxValue\0"
    "xMinValue\0yMaxValue\0yMinValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataStore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       7,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
       5, QMetaType::Int, 0x00495103,
       7, QMetaType::Int, 0x00495103,
       9, QMetaType::Double, 0x00095401,
      10, QMetaType::Double, 0x00095401,
      11, QMetaType::Double, 0x00095401,
      12, QMetaType::Double, 0x00095401,

 // properties: notify_signal_id
       0,
       1,
       2,
       0,
       0,
       0,
       0,

       0        // eod
};

void DataStore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataStore *_t = static_cast<DataStore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->strChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->str2Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->str3Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->getstr((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DataStore::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataStore::strChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataStore::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataStore::str2Changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataStore::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataStore::str3Changed)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DataStore *_t = static_cast<DataStore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->str(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->str2(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->str3(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->xMaxValue(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->xMinValue(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->yMaxValue(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->yMinValue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DataStore *_t = static_cast<DataStore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStr(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setStr2(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setStr3(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject DataStore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataStore.data,
      qt_meta_data_DataStore,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataStore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataStore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataStore.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataStore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataStore::strChanged(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataStore::str2Changed(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataStore::str3Changed(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
