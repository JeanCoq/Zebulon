/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Apr 5 23:05:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      44,   39,   11,   11, 0x0a,
      62,   11,   11,   11, 0x0a,
      90,   81,   11,   11, 0x0a,
     119,   11,   11,   11, 0x0a,
     139,   11,   11,   11, 0x0a,
     157,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0removeTimeSlot(QTimeSlot*)\0"
    "date\0changeDate(QDate)\0openEditTimeSlot()\0"
    "timeSlot\0openEditTimeSlot(QTimeSlot*)\0"
    "openAdministrator()\0tabIndexChanged()\0"
    "commit()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: removeTimeSlot((*reinterpret_cast< QTimeSlot*(*)>(_a[1]))); break;
        case 1: changeDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: openEditTimeSlot(); break;
        case 3: openEditTimeSlot((*reinterpret_cast< QTimeSlot*(*)>(_a[1]))); break;
        case 4: openAdministrator(); break;
        case 5: tabIndexChanged(); break;
        case 6: commit(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
