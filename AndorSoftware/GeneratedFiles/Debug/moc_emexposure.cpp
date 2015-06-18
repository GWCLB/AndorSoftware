/****************************************************************************
** Meta object code from reading C++ file 'emexposure.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../emexposure.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emexposure.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EMExposure_t {
    QByteArrayData data[13];
    char stringdata[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EMExposure_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EMExposure_t qt_meta_stringdata_EMExposure = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EMExposure"
QT_MOC_LITERAL(1, 11, 28), // "sendandorsoftwareEMableValue"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "sendEMabletoandorsoftware"
QT_MOC_LITERAL(4, 67, 19), // "setlineEdit_EMValue"
QT_MOC_LITERAL(5, 87, 25), // "setverticalSlider_EMValue"
QT_MOC_LITERAL(6, 113, 31), // "setverticalSlider_ExposureValue"
QT_MOC_LITERAL(7, 145, 24), // "on_pushButton_OK_clicked"
QT_MOC_LITERAL(8, 170, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(9, 199, 23), // "receiveemexposureEMable"
QT_MOC_LITERAL(10, 223, 28), // "receiveemexposureEMableValue"
QT_MOC_LITERAL(11, 252, 19), // "receiveEMValueRange"
QT_MOC_LITERAL(12, 272, 22) // "on_checkBox_EM_clicked"

    },
    "EMExposure\0sendandorsoftwareEMableValue\0"
    "\0sendEMabletoandorsoftware\0"
    "setlineEdit_EMValue\0setverticalSlider_EMValue\0"
    "setverticalSlider_ExposureValue\0"
    "on_pushButton_OK_clicked\0"
    "on_pushButton_Cancel_clicked\0"
    "receiveemexposureEMable\0"
    "receiveemexposureEMableValue\0"
    "receiveEMValueRange\0on_checkBox_EM_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EMExposure[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       6,    1,   89,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    1,   94,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      11,    2,  100,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void EMExposure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EMExposure *_t = static_cast<EMExposure *>(_o);
        switch (_id) {
        case 0: _t->sendandorsoftwareEMableValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendEMabletoandorsoftware((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setlineEdit_EMValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setverticalSlider_EMValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setverticalSlider_ExposureValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setverticalSlider_ExposureValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_OK_clicked(); break;
        case 7: _t->on_pushButton_Cancel_clicked(); break;
        case 8: _t->receiveemexposureEMable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->receiveemexposureEMableValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->receiveEMValueRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_checkBox_EM_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EMExposure::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EMExposure::sendandorsoftwareEMableValue)) {
                *result = 0;
            }
        }
        {
            typedef void (EMExposure::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EMExposure::sendEMabletoandorsoftware)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject EMExposure::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EMExposure.data,
      qt_meta_data_EMExposure,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EMExposure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EMExposure::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EMExposure.stringdata))
        return static_cast<void*>(const_cast< EMExposure*>(this));
    return QDialog::qt_metacast(_clname);
}

int EMExposure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void EMExposure::sendandorsoftwareEMableValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EMExposure::sendEMabletoandorsoftware(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
