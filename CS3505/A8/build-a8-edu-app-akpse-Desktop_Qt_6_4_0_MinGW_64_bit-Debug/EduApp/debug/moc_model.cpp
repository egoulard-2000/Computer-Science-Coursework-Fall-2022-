/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../a8-edu-app-akpse/EduApp/model.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Model_t {
    uint offsetsAndSizes[66];
    char stringdata0[6];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[6];
    char stringdata5[23];
    char stringdata6[21];
    char stringdata7[6];
    char stringdata8[18];
    char stringdata9[10];
    char stringdata10[20];
    char stringdata11[12];
    char stringdata12[23];
    char stringdata13[6];
    char stringdata14[6];
    char stringdata15[10];
    char stringdata16[10];
    char stringdata17[10];
    char stringdata18[10];
    char stringdata19[20];
    char stringdata20[11];
    char stringdata21[19];
    char stringdata22[14];
    char stringdata23[10];
    char stringdata24[17];
    char stringdata25[14];
    char stringdata26[9];
    char stringdata27[23];
    char stringdata28[16];
    char stringdata29[12];
    char stringdata30[13];
    char stringdata31[19];
    char stringdata32[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Model_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
        QT_MOC_LITERAL(0, 5),  // "Model"
        QT_MOC_LITERAL(6, 12),  // "updatePieces"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 31),  // "QMap<ChessPosition,ChessPiece*>"
        QT_MOC_LITERAL(52, 5),  // "board"
        QT_MOC_LITERAL(58, 22),  // "updateHighlightedMoves"
        QT_MOC_LITERAL(81, 20),  // "QList<ChessPosition>"
        QT_MOC_LITERAL(102, 5),  // "moves"
        QT_MOC_LITERAL(108, 17),  // "updateLeaderboard"
        QT_MOC_LITERAL(126, 9),  // "levelName"
        QT_MOC_LITERAL(136, 19),  // "QMap<QTime,QString>"
        QT_MOC_LITERAL(156, 11),  // "leaderboard"
        QT_MOC_LITERAL(168, 22),  // "updateLeaderboardEntry"
        QT_MOC_LITERAL(191, 5),  // "Level"
        QT_MOC_LITERAL(197, 5),  // "level"
        QT_MOC_LITERAL(203, 9),  // "timeEntry"
        QT_MOC_LITERAL(213, 9),  // "nameEntry"
        QT_MOC_LITERAL(223, 9),  // "endOfGame"
        QT_MOC_LITERAL(233, 9),  // "winOrLose"
        QT_MOC_LITERAL(243, 19),  // "updateDisplayedTurn"
        QT_MOC_LITERAL(263, 10),  // "playerTurn"
        QT_MOC_LITERAL(274, 18),  // "updateLevelTextGui"
        QT_MOC_LITERAL(293, 13),  // "levelTextInfo"
        QT_MOC_LITERAL(307, 9),  // "loadLevel"
        QT_MOC_LITERAL(317, 16),  // "getBoardPosition"
        QT_MOC_LITERAL(334, 13),  // "ChessPosition"
        QT_MOC_LITERAL(348, 8),  // "position"
        QT_MOC_LITERAL(357, 22),  // "updateDisplayFromLevel"
        QT_MOC_LITERAL(380, 15),  // "loadLeaderboard"
        QT_MOC_LITERAL(396, 11),  // "processHint"
        QT_MOC_LITERAL(408, 12),  // "processRetry"
        QT_MOC_LITERAL(421, 18),  // "processLeaderboard"
        QT_MOC_LITERAL(440, 4)   // "time"
    },
    "Model",
    "updatePieces",
    "",
    "QMap<ChessPosition,ChessPiece*>",
    "board",
    "updateHighlightedMoves",
    "QList<ChessPosition>",
    "moves",
    "updateLeaderboard",
    "levelName",
    "QMap<QTime,QString>",
    "leaderboard",
    "updateLeaderboardEntry",
    "Level",
    "level",
    "timeEntry",
    "nameEntry",
    "endOfGame",
    "winOrLose",
    "updateDisplayedTurn",
    "playerTurn",
    "updateLevelTextGui",
    "levelTextInfo",
    "loadLevel",
    "getBoardPosition",
    "ChessPosition",
    "position",
    "updateDisplayFromLevel",
    "loadLeaderboard",
    "processHint",
    "processRetry",
    "processLeaderboard",
    "time"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Model[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       5,    1,  101,    2, 0x06,    3 /* Public */,
       8,    2,  104,    2, 0x06,    5 /* Public */,
      12,    3,  109,    2, 0x06,    8 /* Public */,
      17,    1,  116,    2, 0x06,   12 /* Public */,
      19,    1,  119,    2, 0x06,   14 /* Public */,
      21,    1,  122,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      23,    1,  125,    2, 0x0a,   18 /* Public */,
      24,    1,  128,    2, 0x0a,   20 /* Public */,
      27,    0,  131,    2, 0x0a,   22 /* Public */,
      28,    0,  132,    2, 0x0a,   23 /* Public */,
      29,    0,  133,    2, 0x0a,   24 /* Public */,
      30,    0,  134,    2, 0x0a,   25 /* Public */,
      31,    1,  135,    2, 0x0a,   26 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QTime, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::QStringList,   22,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   32,

       0        // eod
};

Q_CONSTINIT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Model.offsetsAndSizes,
    qt_meta_data_Model,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Model_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Model, std::true_type>,
        // method 'updatePieces'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<ChessPosition,ChessPiece*>, std::false_type>,
        // method 'updateHighlightedMoves'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<ChessPosition>, std::false_type>,
        // method 'updateLeaderboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QTime,QString>, std::false_type>,
        // method 'updateLeaderboardEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Level, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'endOfGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateDisplayedTurn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateLevelTextGui'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'loadLevel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getBoardPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ChessPosition, std::false_type>,
        // method 'updateDisplayFromLevel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadLeaderboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processHint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processRetry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processLeaderboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime &, std::false_type>
    >,
    nullptr
} };

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatePieces((*reinterpret_cast< std::add_pointer_t<QMap<ChessPosition,ChessPiece*>>>(_a[1]))); break;
        case 1: _t->updateHighlightedMoves((*reinterpret_cast< std::add_pointer_t<QList<ChessPosition>>>(_a[1]))); break;
        case 2: _t->updateLeaderboard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMap<QTime,QString>>>(_a[2]))); break;
        case 3: _t->updateLeaderboardEntry((*reinterpret_cast< std::add_pointer_t<Level>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 4: _t->endOfGame((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->updateDisplayedTurn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->updateLevelTextGui((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 7: _t->loadLevel((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->getBoardPosition((*reinterpret_cast< std::add_pointer_t<ChessPosition>>(_a[1]))); break;
        case 9: _t->updateDisplayFromLevel(); break;
        case 10: _t->loadLeaderboard(); break;
        case 11: _t->processHint(); break;
        case 12: _t->processRetry(); break;
        case 13: _t->processLeaderboard((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(QMap<ChessPosition,ChessPiece*> );
            if (_t _q_method = &Model::updatePieces; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(QVector<ChessPosition> );
            if (_t _q_method = &Model::updateHighlightedMoves; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(QString , QMap<QTime,QString> );
            if (_t _q_method = &Model::updateLeaderboard; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)(Level , QTime , QString );
            if (_t _q_method = &Model::updateLeaderboardEntry; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)(QString );
            if (_t _q_method = &Model::endOfGame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Model::*)(bool );
            if (_t _q_method = &Model::updateDisplayedTurn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Model::*)(QVector<QString> );
            if (_t _q_method = &Model::updateLevelTextGui; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Model::updatePieces(QMap<ChessPosition,ChessPiece*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::updateHighlightedMoves(QVector<ChessPosition> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::updateLeaderboard(QString _t1, QMap<QTime,QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::updateLeaderboardEntry(Level _t1, QTime _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::endOfGame(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Model::updateDisplayedTurn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Model::updateLevelTextGui(QVector<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
