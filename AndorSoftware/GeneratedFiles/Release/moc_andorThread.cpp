/****************************************************************************
** Meta object code from reading C++ file 'andorThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../andorThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'andorThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tempratureThread_t {
    QByteArrayData data[7];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tempratureThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tempratureThread_t qt_meta_stringdata_tempratureThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "tempratureThread"
QT_MOC_LITERAL(1, 17, 24), // "sentTempatureSettingInfo"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 3), // "str"
QT_MOC_LITERAL(4, 47, 25), // "recieveTemperatureSetting"
QT_MOC_LITERAL(5, 73, 4), // "temp"
QT_MOC_LITERAL(6, 78, 11) // "coolerOnOff"

    },
    "tempratureThread\0sentTempatureSettingInfo\0"
    "\0str\0recieveTemperatureSetting\0temp\0"
    "coolerOnOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tempratureThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,    6,

       0        // eod
};

void tempratureThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tempratureThread *_t = static_cast<tempratureThread *>(_o);
        switch (_id) {
        case 0: _t->sentTempatureSettingInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->recieveTemperatureSetting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tempratureThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tempratureThread::sentTempatureSettingInfo)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject tempratureThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_tempratureThread.data,
      qt_meta_data_tempratureThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tempratureThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tempratureThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tempratureThread.stringdata))
        return static_cast<void*>(const_cast< tempratureThread*>(this));
    return QThread::qt_metacast(_clname);
}

int tempratureThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void tempratureThread::sentTempatureSettingInfo(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_acqThread_t {
    QByteArrayData data[4];
    char stringdata[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_acqThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_acqThread_t qt_meta_stringdata_acqThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "acqThread"
QT_MOC_LITERAL(1, 10, 25), // "sendAquisitionSettingInfo"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19) // "receiveSingleSignal"

    },
    "acqThread\0sendAquisitionSettingInfo\0"
    "\0receiveSingleSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_acqThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,

       0        // eod
};

void acqThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        acqThread *_t = static_cast<acqThread *>(_o);
        switch (_id) {
        case 0: _t->sendAquisitionSettingInfo((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->receiveSingleSignal((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (acqThread::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acqThread::sendAquisitionSettingInfo)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject acqThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_acqThread.data,
      qt_meta_data_acqThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *acqThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *acqThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_acqThread.stringdata))
        return static_cast<void*>(const_cast< acqThread*>(this));
    return QThread::qt_metacast(_clname);
}

int acqThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void acqThread::sendAquisitionSettingInfo(unsigned int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_KineticThread_t {
    QByteArrayData data[4];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KineticThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KineticThread_t qt_meta_stringdata_KineticThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "KineticThread"
QT_MOC_LITERAL(1, 14, 22), // "sendKineticsettingInfo"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20) // "receiveKineticSignal"

    },
    "KineticThread\0sendKineticsettingInfo\0"
    "\0receiveKineticSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KineticThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,

       0        // eod
};

void KineticThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KineticThread *_t = static_cast<KineticThread *>(_o);
        switch (_id) {
        case 0: _t->sendKineticsettingInfo((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->receiveKineticSignal((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KineticThread::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KineticThread::sendKineticsettingInfo)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject KineticThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_KineticThread.data,
      qt_meta_data_KineticThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KineticThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KineticThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KineticThread.stringdata))
        return static_cast<void*>(const_cast< KineticThread*>(this));
    return QThread::qt_metacast(_clname);
}

int KineticThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KineticThread::sendKineticsettingInfo(unsigned int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_VideoThread_t {
    QByteArrayData data[4];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoThread_t qt_meta_stringdata_VideoThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoThread"
QT_MOC_LITERAL(1, 12, 20), // "sendVideoSettingInfo"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18) // "receiveVideoSignal"

    },
    "VideoThread\0sendVideoSettingInfo\0\0"
    "receiveVideoSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,

       0        // eod
};

void VideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoThread *_t = static_cast<VideoThread *>(_o);
        switch (_id) {
        case 0: _t->sendVideoSettingInfo((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->receiveVideoSignal((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoThread::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoThread::sendVideoSettingInfo)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject VideoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VideoThread.data,
      qt_meta_data_VideoThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoThread.stringdata))
        return static_cast<void*>(const_cast< VideoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int VideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void VideoThread::sendVideoSettingInfo(unsigned int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
