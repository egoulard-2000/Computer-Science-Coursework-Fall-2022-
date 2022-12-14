/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../a8-edu-app-akpse/EduApp/view.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_View_t {
    uint offsetsAndSizes[48];
    char stringdata0[5];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[12];
    char stringdata5[5];
    char stringdata6[14];
    char stringdata7[18];
    char stringdata8[6];
    char stringdata9[14];
    char stringdata10[20];
    char stringdata11[11];
    char stringdata12[16];
    char stringdata13[20];
    char stringdata14[12];
    char stringdata15[23];
    char stringdata16[6];
    char stringdata17[6];
    char stringdata18[10];
    char stringdata19[10];
    char stringdata20[19];
    char stringdata21[14];
    char stringdata22[17];
    char stringdata23[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_View_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
        QT_MOC_LITERAL(0, 4),  // "View"
        QT_MOC_LITERAL(5, 15),  // "loadLevelSignal"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 9),  // "levelName"
        QT_MOC_LITERAL(32, 11),  // "currentTime"
        QT_MOC_LITERAL(44, 4),  // "time"
        QT_MOC_LITERAL(49, 13),  // "openRulesPage"
        QT_MOC_LITERAL(63, 17),  // "processFormChange"
        QT_MOC_LITERAL(81, 5),  // "index"
        QT_MOC_LITERAL(87, 13),  // "goToChessForm"
        QT_MOC_LITERAL(101, 19),  // "updateDisplayedTurn"
        QT_MOC_LITERAL(121, 10),  // "playerTurn"
        QT_MOC_LITERAL(132, 15),  // "loadLeaderboard"
        QT_MOC_LITERAL(148, 19),  // "QMap<QTime,QString>"
        QT_MOC_LITERAL(168, 11),  // "leaderboard"
        QT_MOC_LITERAL(180, 22),  // "updateLeaderboardEntry"
        QT_MOC_LITERAL(203, 5),  // "Level"
        QT_MOC_LITERAL(209, 5),  // "level"
        QT_MOC_LITERAL(215, 9),  // "timeEntry"
        QT_MOC_LITERAL(225, 9),  // "nameEntry"
        QT_MOC_LITERAL(235, 18),  // "updateLevelTextGui"
        QT_MOC_LITERAL(254, 13),  // "levelTextInfo"
        QT_MOC_LITERAL(268, 16),  // "processWinOrLose"
        QT_MOC_LITERAL(285, 9)   // "winOrLose"
    },
    "View",
    "loadLevelSignal",
    "",
    "levelName",
    "currentTime",
    "time",
    "openRulesPage",
    "processFormChange",
    "index",
    "goToChessForm",
    "updateDisplayedTurn",
    "playerTurn",
    "loadLeaderboard",
    "QMap<QTime,QString>",
    "leaderboard",
    "updateLeaderboardEntry",
    "Level",
    "level",
    "timeEntry",
    "nameEntry",
    "updateLevelTextGui",
    "levelTextInfo",
    "processWinOrLose",
    "winOrLose"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_View[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   80,    2, 0x0a,    5 /* Public */,
       7,    1,   81,    2, 0x0a,    6 /* Public */,
       9,    0,   84,    2, 0x0a,    8 /* Public */,
      10,    1,   85,    2, 0x0a,    9 /* Public */,
      12,    2,   88,    2, 0x0a,   11 /* Public */,
      15,    3,   93,    2, 0x0a,   14 /* Public */,
      20,    1,  100,    2, 0x0a,   18 /* Public */,
      22,    1,  103,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QTime,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QTime, QMetaType::QString,   17,   18,   19,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

Q_CONSTINIT const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_View.offsetsAndSizes,
    qt_meta_data_View,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_View_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<View, std::true_type>,
        // method 'loadLevelSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'currentTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime, std::false_type>,
        // method 'openRulesPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processFormChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'goToChessForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDisplayedTurn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadLeaderboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QTime,QString> &, std::false_type>,
        // method 'updateLeaderboardEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Level, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'updateLevelTextGui'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'processWinOrLose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadLevelSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->currentTime((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 2: _t->openRulesPage(); break;
        case 3: _t->processFormChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->goToChessForm(); break;
        case 5: _t->updateDisplayedTurn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->loadLeaderboard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMap<QTime,QString>>>(_a[2]))); break;
        case 7: _t->updateLeaderboardEntry((*reinterpret_cast< std::add_pointer_t<Level>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: _t->updateLevelTextGui((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 9: _t->processWinOrLose((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (View::*)(QString );
            if (_t _q_method = &View::loadLevelSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (View::*)(const QTime );
            if (_t _q_method = &View::currentTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void View::loadLevelSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void View::currentTime(const QTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
