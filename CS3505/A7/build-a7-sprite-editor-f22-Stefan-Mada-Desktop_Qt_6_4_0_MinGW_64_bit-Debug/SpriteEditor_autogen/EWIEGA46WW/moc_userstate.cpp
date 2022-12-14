/****************************************************************************
** Meta object code from reading C++ file 'userstate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../a7-sprite-editor-f22-Stefan-Mada/userstate.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userstate.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_UserState_t {
    uint offsetsAndSizes[34];
    char stringdata0[10];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[11];
    char stringdata5[10];
    char stringdata6[6];
    char stringdata7[11];
    char stringdata8[13];
    char stringdata9[11];
    char stringdata10[14];
    char stringdata11[19];
    char stringdata12[18];
    char stringdata13[12];
    char stringdata14[13];
    char stringdata15[9];
    char stringdata16[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_UserState_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_UserState_t qt_meta_stringdata_UserState = {
    {
        QT_MOC_LITERAL(0, 9),  // "UserState"
        QT_MOC_LITERAL(10, 20),  // "saveCurrentAnimation"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 14),  // "useCurrentTool"
        QT_MOC_LITERAL(47, 10),  // "Animation&"
        QT_MOC_LITERAL(58, 9),  // "animation"
        QT_MOC_LITERAL(68, 5),  // "point"
        QT_MOC_LITERAL(74, 10),  // "frameIndex"
        QT_MOC_LITERAL(85, 12),  // "mousePressed"
        QT_MOC_LITERAL(98, 10),  // "setPenTool"
        QT_MOC_LITERAL(109, 13),  // "setEraserTool"
        QT_MOC_LITERAL(123, 18),  // "setClearCanvasTool"
        QT_MOC_LITERAL(142, 17),  // "setBucketFillTool"
        QT_MOC_LITERAL(160, 11),  // "setTintTool"
        QT_MOC_LITERAL(172, 12),  // "setShadeTool"
        QT_MOC_LITERAL(185, 8),  // "setColor"
        QT_MOC_LITERAL(194, 5)   // "color"
    },
    "UserState",
    "saveCurrentAnimation",
    "",
    "useCurrentTool",
    "Animation&",
    "animation",
    "point",
    "frameIndex",
    "mousePressed",
    "setPenTool",
    "setEraserTool",
    "setClearCanvasTool",
    "setBucketFillTool",
    "setTintTool",
    "setShadeTool",
    "setColor",
    "color"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_UserState[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    4,   69,    2, 0x0a,    2 /* Public */,
       9,    0,   78,    2, 0x0a,    7 /* Public */,
      10,    0,   79,    2, 0x0a,    8 /* Public */,
      11,    0,   80,    2, 0x0a,    9 /* Public */,
      12,    0,   81,    2, 0x0a,   10 /* Public */,
      13,    0,   82,    2, 0x0a,   11 /* Public */,
      14,    0,   83,    2, 0x0a,   12 /* Public */,
      15,    1,   84,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::QPoint, QMetaType::Int, QMetaType::Bool,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UserState.offsetsAndSizes,
    qt_meta_data_UserState,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_UserState_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserState, std::true_type>,
        // method 'saveCurrentAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'useCurrentTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Animation &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setPenTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setEraserTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setClearCanvasTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setBucketFillTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTintTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setShadeTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor, std::false_type>
    >,
    nullptr
} };

void UserState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserState *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveCurrentAnimation(); break;
        case 1: _t->useCurrentTool((*reinterpret_cast< std::add_pointer_t<Animation&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 2: _t->setPenTool(); break;
        case 3: _t->setEraserTool(); break;
        case 4: _t->setClearCanvasTool(); break;
        case 5: _t->setBucketFillTool(); break;
        case 6: _t->setTintTool(); break;
        case 7: _t->setShadeTool(); break;
        case 8: _t->setColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserState::*)();
            if (_t _q_method = &UserState::saveCurrentAnimation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *UserState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserState.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void UserState::saveCurrentAnimation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
