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
    QByteArrayData data[8];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem_t qt_meta_stringdata_BoilerFeedPowderOnLineMonitoringSystem = {
    {
QT_MOC_LITERAL(0, 0, 38), // "BoilerFeedPowderOnLineMonitor..."
QT_MOC_LITERAL(1, 39, 11), // "quitSignals"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 10), // "stopThread"
QT_MOC_LITERAL(4, 63, 4), // "quit"
QT_MOC_LITERAL(5, 68, 19), // "fromWelToMianScreen"
QT_MOC_LITERAL(6, 88, 11), // "processData"
QT_MOC_LITERAL(7, 100, 4) // "Task"

    },
    "BoilerFeedPowderOnLineMonitoringSystem\0"
    "quitSignals\0\0stopThread\0quit\0"
    "fromWelToMianScreen\0processData\0Task"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoilerFeedPowderOnLineMonitoringSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x09 /* Protected */,
       5,    0,   42,    2, 0x09 /* Protected */,
       6,    1,   43,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void BoilerFeedPowderOnLineMonitoringSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BoilerFeedPowderOnLineMonitoringSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quitSignals(); break;
        case 1: _t->stopThread(); break;
        case 2: _t->quit(); break;
        case 3: _t->fromWelToMianScreen(); break;
        case 4: _t->processData((*reinterpret_cast< Task(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BoilerFeedPowderOnLineMonitoringSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BoilerFeedPowderOnLineMonitoringSystem::quitSignals)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BoilerFeedPowderOnLineMonitoringSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BoilerFeedPowderOnLineMonitoringSystem::stopThread)) {
                *result = 1;
                return;
            }
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
void BoilerFeedPowderOnLineMonitoringSystem::quitSignals()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BoilerFeedPowderOnLineMonitoringSystem::stopThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
