/****************************************************************************
** Meta object code from reading C++ file 'chessboardview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../a8-edu-app-akpse/EduApp/chessboardview.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessboardview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ChessBoardView_t {
    uint offsetsAndSizes[22];
    char stringdata0[15];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[6];
    char stringdata5[13];
    char stringdata6[32];
    char stringdata7[6];
    char stringdata8[23];
    char stringdata9[21];
    char stringdata10[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ChessBoardView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ChessBoardView_t qt_meta_stringdata_ChessBoardView = {
    {
        QT_MOC_LITERAL(0, 14),  // "ChessBoardView"
        QT_MOC_LITERAL(15, 16),  // "getBoardPosition"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 13),  // "ChessPosition"
        QT_MOC_LITERAL(47, 5),  // "point"
        QT_MOC_LITERAL(53, 12),  // "updatePieces"
        QT_MOC_LITERAL(66, 31),  // "QMap<ChessPosition,ChessPiece*>"
        QT_MOC_LITERAL(98, 5),  // "board"
        QT_MOC_LITERAL(104, 22),  // "updateHighlightedMoves"
        QT_MOC_LITERAL(127, 20),  // "QList<ChessPosition>"
        QT_MOC_LITERAL(148, 5)   // "moves"
    },
    "ChessBoardView",
    "getBoardPosition",
    "",
    "ChessPosition",
    "point",
    "updatePieces",
    "QMap<ChessPosition,ChessPiece*>",
    "board",
    "updateHighlightedMoves",
    "QList<ChessPosition>",
    "moves"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ChessBoardView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   35,    2, 0x0a,    3 /* Public */,
       8,    1,   38,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject ChessBoardView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_ChessBoardView.offsetsAndSizes,
    qt_meta_data_ChessBoardView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ChessBoardView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChessBoardView, std::true_type>,
        // method 'getBoardPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ChessPosition, std::false_type>,
        // method 'updatePieces'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<ChessPosition,ChessPiece*>, std::false_type>,
        // method 'updateHighlightedMoves'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<ChessPosition>, std::false_type>
    >,
    nullptr
} };

void ChessBoardView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessBoardView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getBoardPosition((*reinterpret_cast< std::add_pointer_t<ChessPosition>>(_a[1]))); break;
        case 1: _t->updatePieces((*reinterpret_cast< std::add_pointer_t<QMap<ChessPosition,ChessPiece*>>>(_a[1]))); break;
        case 2: _t->updateHighlightedMoves((*reinterpret_cast< std::add_pointer_t<QList<ChessPosition>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChessBoardView::*)(ChessPosition );
            if (_t _q_method = &ChessBoardView::getBoardPosition; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ChessBoardView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessBoardView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChessBoardView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int ChessBoardView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ChessBoardView::getBoardPosition(ChessPosition _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
