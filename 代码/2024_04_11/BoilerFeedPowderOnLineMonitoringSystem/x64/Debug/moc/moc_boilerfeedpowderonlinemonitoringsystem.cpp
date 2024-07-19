/****************************************************************************
** Meta object code from reading C++ file 'boilerfeedpowderonlinemonitoringsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../boilerfeedpowderonlinemonitoringsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boilerfeedpowderonlinemonitoringsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem_t {
    QByteArrayData data[6];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem_t qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem = {
    {
QT_MOC_LITERAL(0, 0, 38), // "BoilerFeedPowderOnLineMonitor..."
QT_MOC_LITERAL(1, 39, 11), // "processData"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 4), // "Task"
QT_MOC_LITERAL(4, 57, 16), // "processConfigure"
QT_MOC_LITERAL(5, 74, 43) // "std::unordered_map<std::strin..."

    },
    "BoilerFeedPowderOnLineMonitoringSystem\0"
    "processData\0\0Task\0processConfigure\0"
    "std::unordered_map<std::string,std::string>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoilerFeedPowderOnLineMonitoringSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x09 /* Protected */,
       4,    1,   27,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void BoilerFeedPowderOnLineMonitoringSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BoilerFeedPowderOnLineMonitoringSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processData((*reinterpret_cast< Task(*)>(_a[1]))); break;
        case 1: _t->processConfigure((*reinterpret_cast< std::unordered_map<std::string,std::string>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BoilerFeedPowderOnLineMonitoringSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem.data,
    qt_meta_data_BoilerFeedPowderOnLineMonitoringSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BoilerFeedPowderOnLineMonitoringSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoilerFeedPowderOnLineMonitoringSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BoilerFeedPowderOnLineMonitoringSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
