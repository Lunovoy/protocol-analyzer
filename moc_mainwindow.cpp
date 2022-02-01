/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "file_opened"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 12), // "browse_files"
QT_MOC_LITERAL(37, 9), // "open_file"
QT_MOC_LITERAL(47, 5), // "FILE*"
QT_MOC_LITERAL(53, 6), // "Fname*"
QT_MOC_LITERAL(60, 7), // "capname"
QT_MOC_LITERAL(68, 14), // "check_filename"
QT_MOC_LITERAL(83, 14), // "show_main_info"
QT_MOC_LITERAL(98, 14), // "print_ip_count"
QT_MOC_LITERAL(113, 13), // "init_ip_count"
QT_MOC_LITERAL(127, 13), // "show_pkt_info"
QT_MOC_LITERAL(141, 13), // "print_ip_info"
QT_MOC_LITERAL(155, 14) // "show_more_info"

    },
    "MainWindow\0file_opened\0\0browse_files\0"
    "open_file\0FILE*\0Fname*\0capname\0"
    "check_filename\0show_main_info\0"
    "print_ip_count\0init_ip_count\0show_pkt_info\0"
    "print_ip_info\0show_more_info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   75,    2, 0x0a,    1 /* Public */,
       4,    1,   76,    2, 0x0a,    2 /* Public */,
       8,    0,   79,    2, 0x0a,    4 /* Public */,
       9,    0,   80,    2, 0x0a,    5 /* Public */,
      10,    0,   81,    2, 0x0a,    6 /* Public */,
      11,    1,   82,    2, 0x0a,    7 /* Public */,
      12,    0,   85,    2, 0x0a,    9 /* Public */,
      13,    1,   86,    2, 0x0a,   10 /* Public */,
      14,    0,   89,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 5, 0x80000000 | 6,    7,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->file_opened(); break;
        case 1: _t->browse_files(); break;
        case 2: { FILE* _r = _t->open_file((*reinterpret_cast< Fname*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< FILE**>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->check_filename();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->show_main_info(); break;
        case 5: _t->print_ip_count(); break;
        case 6: _t->init_ip_count((*reinterpret_cast< Fname*(*)>(_a[1]))); break;
        case 7: _t->show_pkt_info(); break;
        case 8: _t->print_ip_info((*reinterpret_cast< Fname*(*)>(_a[1]))); break;
        case 9: _t->show_more_info(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::file_opened)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FILE *, std::false_type>, QtPrivate::TypeAndForceComplete<Fname *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Fname *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Fname *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::file_opened()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
