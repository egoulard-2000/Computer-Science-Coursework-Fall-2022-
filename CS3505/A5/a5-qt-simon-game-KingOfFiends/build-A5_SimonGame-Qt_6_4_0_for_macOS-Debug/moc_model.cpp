/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../A5_SimonGame/model.h"
#include <QtCore/qmetatype.h>
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
    uint offsetsAndSizes[48];
    char stringdata0[6];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[16];
    char stringdata5[17];
    char stringdata6[15];
    char stringdata7[16];
    char stringdata8[16];
    char stringdata9[4];
    char stringdata10[16];
    char stringdata11[15];
    char stringdata12[18];
    char stringdata13[9];
    char stringdata14[6];
    char stringdata15[25];
    char stringdata16[7];
    char stringdata17[10];
    char stringdata18[10];
    char stringdata19[9];
    char stringdata20[16];
    char stringdata21[6];
    char stringdata22[17];
    char stringdata23[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Model_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
        QT_MOC_LITERAL(0, 5),  // "Model"
        QT_MOC_LITERAL(6, 13),  // "showHighScore"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 9),  // "isVisible"
        QT_MOC_LITERAL(31, 15),  // "showProgressBar"
        QT_MOC_LITERAL(47, 16),  // "showSimonButtons"
        QT_MOC_LITERAL(64, 14),  // "showLoseScreen"
        QT_MOC_LITERAL(79, 15),  // "showStartButton"
        QT_MOC_LITERAL(95, 15),  // "updateHighScore"
        QT_MOC_LITERAL(111, 3),  // "val"
        QT_MOC_LITERAL(115, 15),  // "progressChanged"
        QT_MOC_LITERAL(131, 14),  // "playerProgress"
        QT_MOC_LITERAL(146, 17),  // "increaseGameSpeed"
        QT_MOC_LITERAL(164, 8),  // "gameTime"
        QT_MOC_LITERAL(173, 5),  // "click"
        QT_MOC_LITERAL(179, 24),  // "std::vector<std::string>"
        QT_MOC_LITERAL(204, 6),  // "colors"
        QT_MOC_LITERAL(211, 9),  // "startGame"
        QT_MOC_LITERAL(221, 9),  // "gameMoves"
        QT_MOC_LITERAL(231, 8),  // "endMoves"
        QT_MOC_LITERAL(240, 15),  // "isPlayerCorrect"
        QT_MOC_LITERAL(256, 5),  // "index"
        QT_MOC_LITERAL(262, 16),  // "redButtonClicked"
        QT_MOC_LITERAL(279, 17)   // "blueButtonClicked"
    },
    "Model",
    "showHighScore",
    "",
    "isVisible",
    "showProgressBar",
    "showSimonButtons",
    "showLoseScreen",
    "showStartButton",
    "updateHighScore",
    "val",
    "progressChanged",
    "playerProgress",
    "increaseGameSpeed",
    "gameTime",
    "click",
    "std::vector<std::string>",
    "colors",
    "startGame",
    "gameMoves",
    "endMoves",
    "isPlayerCorrect",
    "index",
    "redButtonClicked",
    "blueButtonClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Model[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,
       5,    1,  110,    2, 0x06,    5 /* Public */,
       6,    1,  113,    2, 0x06,    7 /* Public */,
       7,    1,  116,    2, 0x06,    9 /* Public */,
       8,    1,  119,    2, 0x06,   11 /* Public */,
      10,    1,  122,    2, 0x06,   13 /* Public */,
      12,    1,  125,    2, 0x06,   15 /* Public */,
      14,    1,  128,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  131,    2, 0x0a,   19 /* Public */,
      18,    0,  132,    2, 0x0a,   20 /* Public */,
      19,    0,  133,    2, 0x0a,   21 /* Public */,
      20,    1,  134,    2, 0x0a,   22 /* Public */,
      22,    0,  137,    2, 0x0a,   24 /* Public */,
      23,    0,  138,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'showHighScore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'showProgressBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'showSimonButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'showLoseScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'showStartButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateHighScore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'progressChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'increaseGameSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'click'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>,
        // method 'startGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameMoves'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'endMoves'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isPlayerCorrect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'redButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'blueButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showHighScore((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->showProgressBar((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->showSimonButtons((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->showLoseScreen((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->showStartButton((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->updateHighScore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->progressChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->increaseGameSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->click((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 9: _t->startGame(); break;
        case 10: _t->gameMoves(); break;
        case 11: _t->endMoves(); break;
        case 12: _t->isPlayerCorrect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->redButtonClicked(); break;
        case 14: _t->blueButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(bool );
            if (_t _q_method = &Model::showHighScore; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(bool );
            if (_t _q_method = &Model::showProgressBar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(bool );
            if (_t _q_method = &Model::showSimonButtons; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)(bool );
            if (_t _q_method = &Model::showLoseScreen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)(bool );
            if (_t _q_method = &Model::showStartButton; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Model::*)(QString );
            if (_t _q_method = &Model::updateHighScore; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Model::*)(double );
            if (_t _q_method = &Model::progressChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Model::*)(int );
            if (_t _q_method = &Model::increaseGameSpeed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Model::*)(std::vector<std::string> );
            if (_t _q_method = &Model::click; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Model::showHighScore(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::showProgressBar(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::showSimonButtons(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::showLoseScreen(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::showStartButton(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Model::updateHighScore(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Model::progressChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Model::increaseGameSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Model::click(std::vector<std::string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
