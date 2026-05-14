/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../W_PREZENTACJI/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushStart_clicked",
    "",
    "on_pushStop_clicked",
    "on_pushResetSym_clicked",
    "aktualizujWykresy",
    "czas",
    "zadana",
    "wyjscie",
    "ster",
    "uchyb",
    "aktualizujParametryGeneratora",
    "aktualizujParametryPID",
    "on_spinInterwal_editingFinished",
    "on_pushConfigARX_clicked",
    "odbierzParametryARX",
    "std::vector<double>",
    "a",
    "b",
    "k",
    "szum",
    "umin",
    "umax",
    "ymin",
    "ymax",
    "ograniczenia",
    "on_pushSaveConfig_clicked",
    "on_pushLoadConfig_clicked",
    "on_pushResetPID_clicked",
    "on_pushPolaczSiec_clicked",
    "on_spinOknoObserwacji_editingFinished",
    "on_spinAmplituda_editingFinished",
    "on_spinOkres_editingFinished",
    "on_spinSkladowaStala_editingFinished",
    "on_spinWypelnienie_editingFinished",
    "on_spinPidKp_editingFinished",
    "on_spinPidTi_editingFinished",
    "on_spinPidTd_editingFinished",
    "on_comboTypSygnalu_currentIndexChanged",
    "index",
    "on_comboMetCalk_currentIndexChanged",
    "resetSymulacji",
    "naOdebranoKonfigPID",
    "kp",
    "ti",
    "td",
    "metoda",
    "naOdebranoKonfigARX",
    "A",
    "B",
    "opoznienie",
    "naOdebranoKonfigGen",
    "amplituda",
    "okres",
    "interwal",
    "typ",
    "skladowa",
    "wypelnienie",
    "naOdebranoAkcjeSymulacji",
    "Akcja",
    "akcja",
    "parametr",
    "aktualizujStatusRT",
    "ok",
    "naWyslijProbke",
    "val",
    "aktualizujPing",
    "pingMs"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  200,    2, 0x08,    1 /* Private */,
       3,    0,  201,    2, 0x08,    2 /* Private */,
       4,    0,  202,    2, 0x08,    3 /* Private */,
       5,    5,  203,    2, 0x08,    4 /* Private */,
      11,    0,  214,    2, 0x08,   10 /* Private */,
      12,    0,  215,    2, 0x08,   11 /* Private */,
      13,    0,  216,    2, 0x08,   12 /* Private */,
      14,    0,  217,    2, 0x08,   13 /* Private */,
      15,    9,  218,    2, 0x08,   14 /* Private */,
      26,    0,  237,    2, 0x08,   24 /* Private */,
      27,    0,  238,    2, 0x08,   25 /* Private */,
      28,    0,  239,    2, 0x08,   26 /* Private */,
      29,    0,  240,    2, 0x08,   27 /* Private */,
      30,    0,  241,    2, 0x08,   28 /* Private */,
      31,    0,  242,    2, 0x08,   29 /* Private */,
      32,    0,  243,    2, 0x08,   30 /* Private */,
      33,    0,  244,    2, 0x08,   31 /* Private */,
      34,    0,  245,    2, 0x08,   32 /* Private */,
      35,    0,  246,    2, 0x08,   33 /* Private */,
      36,    0,  247,    2, 0x08,   34 /* Private */,
      37,    0,  248,    2, 0x08,   35 /* Private */,
      38,    1,  249,    2, 0x08,   36 /* Private */,
      40,    1,  252,    2, 0x08,   38 /* Private */,
      41,    0,  255,    2, 0x08,   40 /* Private */,
      42,    4,  256,    2, 0x08,   41 /* Private */,
      47,    9,  265,    2, 0x08,   46 /* Private */,
      51,    6,  284,    2, 0x08,   56 /* Private */,
      58,    2,  297,    2, 0x08,   63 /* Private */,
      62,    1,  302,    2, 0x08,   66 /* Private */,
      64,    1,  305,    2, 0x08,   68 /* Private */,
      66,    1,  308,    2, 0x08,   70 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   17,   18,   19,   20,   21,   22,   23,   24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int,   43,   44,   45,   46,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   48,   49,   50,   20,   21,   22,   23,   24,   25,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double,   52,   53,   54,   55,   56,   57,
    QMetaType::Void, 0x80000000 | 59, QMetaType::Int,   60,   61,
    QMetaType::Void, QMetaType::Bool,   63,
    QMetaType::Void, QMetaType::Double,   65,
    QMetaType::Void, QMetaType::Int,   67,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushStart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushStop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushResetSym_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aktualizujWykresy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'aktualizujParametryGeneratora'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aktualizujParametryPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinInterwal_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushConfigARX_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'odbierzParametryARX'
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
        // method 'on_pushSaveConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushLoadConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushResetPID_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushPolaczSiec_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinOknoObserwacji_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinAmplituda_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinOkres_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinSkladowaStala_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinWypelnienie_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinPidKp_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinPidTi_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinPidTd_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboTypSygnalu_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_comboMetCalk_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'resetSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'naOdebranoKonfigPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'naOdebranoKonfigARX'
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
        // method 'naOdebranoKonfigGen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'naOdebranoAkcjeSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Akcja, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'aktualizujStatusRT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'naWyslijProbke'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'aktualizujPing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_pushStart_clicked(); break;
        case 1: _t->on_pushStop_clicked(); break;
        case 2: _t->on_pushResetSym_clicked(); break;
        case 3: _t->aktualizujWykresy((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5]))); break;
        case 4: _t->aktualizujParametryGeneratora(); break;
        case 5: _t->aktualizujParametryPID(); break;
        case 6: _t->on_spinInterwal_editingFinished(); break;
        case 7: _t->on_pushConfigARX_clicked(); break;
        case 8: _t->odbierzParametryARX((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9]))); break;
        case 9: _t->on_pushSaveConfig_clicked(); break;
        case 10: _t->on_pushLoadConfig_clicked(); break;
        case 11: _t->on_pushResetPID_clicked(); break;
        case 12: _t->on_pushPolaczSiec_clicked(); break;
        case 13: _t->on_spinOknoObserwacji_editingFinished(); break;
        case 14: _t->on_spinAmplituda_editingFinished(); break;
        case 15: _t->on_spinOkres_editingFinished(); break;
        case 16: _t->on_spinSkladowaStala_editingFinished(); break;
        case 17: _t->on_spinWypelnienie_editingFinished(); break;
        case 18: _t->on_spinPidKp_editingFinished(); break;
        case 19: _t->on_spinPidTi_editingFinished(); break;
        case 20: _t->on_spinPidTd_editingFinished(); break;
        case 21: _t->on_comboTypSygnalu_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_comboMetCalk_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->resetSymulacji(); break;
        case 24: _t->naOdebranoKonfigPID((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 25: _t->naOdebranoKonfigARX((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9]))); break;
        case 26: _t->naOdebranoKonfigGen((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        case 27: _t->naOdebranoAkcjeSymulacji((*reinterpret_cast< std::add_pointer_t<Akcja>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 28: _t->aktualizujStatusRT((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 29: _t->naWyslijProbke((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 30: _t->aktualizujPing((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP
