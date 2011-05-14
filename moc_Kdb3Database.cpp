/****************************************************************************
** Meta object code from reading C++ file 'Kdb3Database.h'
**
** Created: Tue May 10 13:47:44 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Kdb3Database.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Kdb3Database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ICustomIcons[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ICustomIcons[] = {
    "ICustomIcons\0\0iconsModified()\0"
};

const QMetaObject ICustomIcons::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ICustomIcons,
      qt_meta_data_ICustomIcons, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ICustomIcons::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ICustomIcons::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ICustomIcons::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ICustomIcons))
        return static_cast<void*>(const_cast< ICustomIcons*>(this));
    return QObject::qt_metacast(_clname);
}

int ICustomIcons::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: iconsModified(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ICustomIcons::iconsModified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_Kdb3Database[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Kdb3Database[] = {
    "Kdb3Database\0"
};

const QMetaObject Kdb3Database::staticMetaObject = {
    { &ICustomIcons::staticMetaObject, qt_meta_stringdata_Kdb3Database,
      qt_meta_data_Kdb3Database, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Kdb3Database::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Kdb3Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Kdb3Database::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Kdb3Database))
        return static_cast<void*>(const_cast< Kdb3Database*>(this));
    if (!strcmp(_clname, "IDatabase"))
        return static_cast< IDatabase*>(const_cast< Kdb3Database*>(this));
    if (!strcmp(_clname, "IKdbSettings"))
        return static_cast< IKdbSettings*>(const_cast< Kdb3Database*>(this));
    return ICustomIcons::qt_metacast(_clname);
}

int Kdb3Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ICustomIcons::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KeyTransform[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KeyTransform[] = {
    "KeyTransform\0"
};

const QMetaObject KeyTransform::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_KeyTransform,
      qt_meta_data_KeyTransform, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyTransform::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyTransform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyTransform::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyTransform))
        return static_cast<void*>(const_cast< KeyTransform*>(this));
    return QThread::qt_metacast(_clname);
}

int KeyTransform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KeyTransformBenchmark[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KeyTransformBenchmark[] = {
    "KeyTransformBenchmark\0"
};

const QMetaObject KeyTransformBenchmark::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_KeyTransformBenchmark,
      qt_meta_data_KeyTransformBenchmark, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyTransformBenchmark::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyTransformBenchmark::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyTransformBenchmark::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyTransformBenchmark))
        return static_cast<void*>(const_cast< KeyTransformBenchmark*>(this));
    return QThread::qt_metacast(_clname);
}

int KeyTransformBenchmark::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
