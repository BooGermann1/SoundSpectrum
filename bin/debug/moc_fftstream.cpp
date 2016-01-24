/****************************************************************************
** Meta object code from reading C++ file 'fftstream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fftstream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fftstream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FFTStream_t {
    QByteArrayData data[6];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FFTStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FFTStream_t qt_meta_stringdata_FFTStream = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FFTStream"
QT_MOC_LITERAL(1, 10, 8), // "stop_fft"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "QVector<double>*"
QT_MOC_LITERAL(4, 37, 9), // "start_fft"
QT_MOC_LITERAL(5, 47, 8) // "QBuffer*"

    },
    "FFTStream\0stop_fft\0\0QVector<double>*\0"
    "start_fft\0QBuffer*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FFTStream[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       1,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3,    2,
    QMetaType::Int,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 5,    2,

       0        // eod
};

void FFTStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FFTStream *_t = static_cast<FFTStream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->stop_fft((*reinterpret_cast< QVector<double>*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->stop_fft();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->start_fft((*reinterpret_cast< QBuffer*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBuffer* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (FFTStream::*_t)(QVector<double> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FFTStream::stop_fft)) {
                *result = 0;
            }
        }
        {
            typedef int (FFTStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FFTStream::stop_fft)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FFTStream::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FFTStream.data,
      qt_meta_data_FFTStream,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FFTStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FFTStream::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FFTStream.stringdata0))
        return static_cast<void*>(const_cast< FFTStream*>(this));
    return QObject::qt_metacast(_clname);
}

int FFTStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
int FFTStream::stop_fft(QVector<double> * _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int FFTStream::stop_fft()
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
