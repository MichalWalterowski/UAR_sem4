/****************************************************************************
** Meta object code from reading C++ file 'SerwerKonfiguracji.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SerwerKonfiguracji.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerwerKonfiguracji.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11MyTCPServerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN11MyTCPServerE = QtMocHelpers::stringData(
    "MyTCPServer",
    "newClientConnected",
    "",
    "adr",
    "clientDisconnected",
    "num",
    "odebranoKonfigPID",
    "kp",
    "ti",
    "td",
    "metoda",
    "odebranoKonfigARX",
    "std::vector<double>",
    "A",
    "B",
    "opoznienie",
    "szum",
    "umin",
    "umax",
    "ymin",
    "ymax",
    "ograniczenia",
    "odebranoKonfigGen",
    "amplituda",
    "okres",
    "interwal",
    "typ",
    "skladowa",
    "wypelnienie",
    "odebranoAkcjeSymulacji",
    "Akcja",
    "akcja",
    "parametr",
    "odebranoProbke",
    "wartosc",
    "slot_new_client",
    "slot_client_disconnected",
    "slot_newMsg"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN11MyTCPServerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    4,   80,    2, 0x06,    5 /* Public */,
      11,    9,   89,    2, 0x06,   10 /* Public */,
      22,    6,  108,    2, 0x06,   20 /* Public */,
      29,    2,  121,    2, 0x06,   27 /* Public */,
      33,    1,  126,    2, 0x06,   30 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      35,    0,  129,    2, 0x08,   32 /* Private */,
      36,    0,  130,    2, 0x08,   33 /* Private */,
      37,    0,  131,    2, 0x08,   34 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   13,   14,   15,   16,   17,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double,   23,   24,   25,   26,   27,   28,
    QMetaType::Void, 0x80000000 | 30, QMetaType::Int,   31,   32,
    QMetaType::Void, QMetaType::Double,   34,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyTCPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN11MyTCPServerE.offsetsAndSizes,
    qt_meta_data_ZN11MyTCPServerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN11MyTCPServerE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyTCPServer, std::true_type>,
        // method 'newClientConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clientDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'odebranoKonfigPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'odebranoKonfigARX'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'odebranoKonfigGen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'odebranoAkcjeSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Akcja, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'odebranoProbke'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'slot_new_client'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_client_disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_newMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MyTCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MyTCPServer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->newClientConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->odebranoKonfigPID((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 3: _t->odebranoKonfigARX((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9]))); break;
        case 4: _t->odebranoKonfigGen((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        case 5: _t->odebranoAkcjeSymulacji((*reinterpret_cast< std::add_pointer_t<Akcja>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->odebranoProbke((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->slot_new_client(); break;
        case 8: _t->slot_client_disconnected(); break;
        case 9: _t->slot_newMsg(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MyTCPServer::*)(QString );
            if (_q_method_type _q_method = &MyTCPServer::newClientConnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (MyTCPServer::*)(int );
            if (_q_method_type _q_method = &MyTCPServer::clientDisconnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (MyTCPServer::*)(double , double , double , int );
            if (_q_method_type _q_method = &MyTCPServer::odebranoKonfigPID; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (MyTCPServer::*)(std::vector<double> , std::vector<double> , int , double , double , double , double , double , bool );
            if (_q_method_type _q_method = &MyTCPServer::odebranoKonfigARX; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (MyTCPServer::*)(double , double , int , int , double , double );
            if (_q_method_type _q_method = &MyTCPServer::odebranoKonfigGen; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (MyTCPServer::*)(Akcja , int );
            if (_q_method_type _q_method = &MyTCPServer::odebranoAkcjeSymulacji; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (MyTCPServer::*)(double );
            if (_q_method_type _q_method = &MyTCPServer::odebranoProbke; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *MyTCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN11MyTCPServerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyTCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MyTCPServer::newClientConnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTCPServer::clientDisconnected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTCPServer::odebranoKonfigPID(double _t1, double _t2, double _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTCPServer::odebranoKonfigARX(std::vector<double> _t1, std::vector<double> _t2, int _t3, double _t4, double _t5, double _t6, double _t7, double _t8, bool _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTCPServer::odebranoKonfigGen(double _t1, double _t2, int _t3, int _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyTCPServer::odebranoAkcjeSymulacji(Akcja _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyTCPServer::odebranoProbke(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
