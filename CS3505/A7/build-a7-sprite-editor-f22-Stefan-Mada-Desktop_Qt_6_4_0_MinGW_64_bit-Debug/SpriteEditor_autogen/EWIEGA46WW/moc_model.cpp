/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../a7-sprite-editor-f22-Stefan-Mada/model.h"
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
    uint offsetsAndSizes[94];
    char stringdata0[6];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[20];
    char stringdata5[13];
    char stringdata6[20];
    char stringdata7[14];
    char stringdata8[10];
    char stringdata9[17];
    char stringdata10[8];
    char stringdata11[15];
    char stringdata12[17];
    char stringdata13[9];
    char stringdata14[21];
    char stringdata15[11];
    char stringdata16[19];
    char stringdata17[23];
    char stringdata18[9];
    char stringdata19[12];
    char stringdata20[11];
    char stringdata21[14];
    char stringdata22[14];
    char stringdata23[24];
    char stringdata24[10];
    char stringdata25[4];
    char stringdata26[11];
    char stringdata27[14];
    char stringdata28[19];
    char stringdata29[18];
    char stringdata30[12];
    char stringdata31[13];
    char stringdata32[15];
    char stringdata33[6];
    char stringdata34[13];
    char stringdata35[11];
    char stringdata36[7];
    char stringdata37[5];
    char stringdata38[13];
    char stringdata39[18];
    char stringdata40[9];
    char stringdata41[19];
    char stringdata42[6];
    char stringdata43[7];
    char stringdata44[20];
    char stringdata45[11];
    char stringdata46[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Model_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
        QT_MOC_LITERAL(0, 5),  // "Model"
        QT_MOC_LITERAL(6, 11),  // "changeColor"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 12),  // "updateCanvas"
        QT_MOC_LITERAL(32, 19),  // "currentWorkingImage"
        QT_MOC_LITERAL(52, 12),  // "currentFrame"
        QT_MOC_LITERAL(65, 19),  // "bulkUpdateAnimation"
        QT_MOC_LITERAL(85, 13),  // "QList<QImage>"
        QT_MOC_LITERAL(99, 9),  // "newFrames"
        QT_MOC_LITERAL(109, 16),  // "sendErrorMessage"
        QT_MOC_LITERAL(126, 7),  // "message"
        QT_MOC_LITERAL(134, 14),  // "successfulLoad"
        QT_MOC_LITERAL(149, 16),  // "animationIsEmpty"
        QT_MOC_LITERAL(166, 8),  // "fileName"
        QT_MOC_LITERAL(175, 20),  // "requestedFrameChange"
        QT_MOC_LITERAL(196, 10),  // "frameIndex"
        QT_MOC_LITERAL(207, 18),  // "requestedNextFrame"
        QT_MOC_LITERAL(226, 22),  // "requestedPreviousFrame"
        QT_MOC_LITERAL(249, 8),  // "addFrame"
        QT_MOC_LITERAL(258, 11),  // "removeFrame"
        QT_MOC_LITERAL(270, 10),  // "swapFrames"
        QT_MOC_LITERAL(281, 13),  // "frameIndexOne"
        QT_MOC_LITERAL(295, 13),  // "frameIndexTwo"
        QT_MOC_LITERAL(309, 23),  // "toggleAnimationPlayback"
        QT_MOC_LITERAL(333, 9),  // "updateFPS"
        QT_MOC_LITERAL(343, 3),  // "fps"
        QT_MOC_LITERAL(347, 10),  // "setPenTool"
        QT_MOC_LITERAL(358, 13),  // "setEraserTool"
        QT_MOC_LITERAL(372, 18),  // "setClearCanvasTool"
        QT_MOC_LITERAL(391, 17),  // "setBucketFillTool"
        QT_MOC_LITERAL(409, 11),  // "setTintTool"
        QT_MOC_LITERAL(421, 12),  // "setShadeTool"
        QT_MOC_LITERAL(434, 14),  // "useCurrentTool"
        QT_MOC_LITERAL(449, 5),  // "point"
        QT_MOC_LITERAL(455, 12),  // "mousePressed"
        QT_MOC_LITERAL(468, 10),  // "saveToFile"
        QT_MOC_LITERAL(479, 6),  // "QFile&"
        QT_MOC_LITERAL(486, 4),  // "file"
        QT_MOC_LITERAL(491, 12),  // "loadFromFile"
        QT_MOC_LITERAL(504, 17),  // "updateStoredColor"
        QT_MOC_LITERAL(522, 8),  // "newColor"
        QT_MOC_LITERAL(531, 18),  // "createNewAnimation"
        QT_MOC_LITERAL(550, 5),  // "width"
        QT_MOC_LITERAL(556, 6),  // "height"
        QT_MOC_LITERAL(563, 19),  // "saveFramesToHistory"
        QT_MOC_LITERAL(583, 10),  // "undoAction"
        QT_MOC_LITERAL(594, 10)   // "redoAction"
    },
    "Model",
    "changeColor",
    "",
    "updateCanvas",
    "currentWorkingImage",
    "currentFrame",
    "bulkUpdateAnimation",
    "QList<QImage>",
    "newFrames",
    "sendErrorMessage",
    "message",
    "successfulLoad",
    "animationIsEmpty",
    "fileName",
    "requestedFrameChange",
    "frameIndex",
    "requestedNextFrame",
    "requestedPreviousFrame",
    "addFrame",
    "removeFrame",
    "swapFrames",
    "frameIndexOne",
    "frameIndexTwo",
    "toggleAnimationPlayback",
    "updateFPS",
    "fps",
    "setPenTool",
    "setEraserTool",
    "setClearCanvasTool",
    "setBucketFillTool",
    "setTintTool",
    "setShadeTool",
    "useCurrentTool",
    "point",
    "mousePressed",
    "saveToFile",
    "QFile&",
    "file",
    "loadFromFile",
    "updateStoredColor",
    "newColor",
    "createNewAnimation",
    "width",
    "height",
    "saveFramesToHistory",
    "undoAction",
    "redoAction"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Model[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  176,    2, 0x06,    1 /* Public */,
       3,    2,  179,    2, 0x06,    3 /* Public */,
       6,    1,  184,    2, 0x06,    6 /* Public */,
       9,    1,  187,    2, 0x06,    8 /* Public */,
      11,    2,  190,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  195,    2, 0x0a,   13 /* Public */,
      16,    0,  198,    2, 0x0a,   15 /* Public */,
      17,    0,  199,    2, 0x0a,   16 /* Public */,
      18,    0,  200,    2, 0x0a,   17 /* Public */,
      19,    0,  201,    2, 0x0a,   18 /* Public */,
      20,    2,  202,    2, 0x0a,   19 /* Public */,
      23,    0,  207,    2, 0x0a,   22 /* Public */,
      24,    1,  208,    2, 0x0a,   23 /* Public */,
      26,    0,  211,    2, 0x0a,   25 /* Public */,
      27,    0,  212,    2, 0x0a,   26 /* Public */,
      28,    0,  213,    2, 0x0a,   27 /* Public */,
      29,    0,  214,    2, 0x0a,   28 /* Public */,
      30,    0,  215,    2, 0x0a,   29 /* Public */,
      31,    0,  216,    2, 0x0a,   30 /* Public */,
      32,    2,  217,    2, 0x0a,   31 /* Public */,
      35,    1,  222,    2, 0x0a,   34 /* Public */,
      38,    1,  225,    2, 0x0a,   36 /* Public */,
      39,    1,  228,    2, 0x0a,   38 /* Public */,
      41,    2,  231,    2, 0x0a,   40 /* Public */,
      44,    0,  236,    2, 0x0a,   43 /* Public */,
      45,    0,  237,    2, 0x0a,   44 /* Public */,
      46,    0,  238,    2, 0x0a,   45 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   21,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Bool,   33,   34,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, QMetaType::QColor,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   42,   43,
    QMetaType::Void,
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
        // method 'changeColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor, std::false_type>,
        // method 'updateCanvas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'bulkUpdateAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QImage>, std::false_type>,
        // method 'sendErrorMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'successfulLoad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestedFrameChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'requestedNextFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestedPreviousFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'swapFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'toggleAnimationPlayback'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateFPS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'useCurrentTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveToFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFile &, std::false_type>,
        // method 'loadFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFile &, std::false_type>,
        // method 'updateStoredColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'createNewAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'saveFramesToHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'undoAction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'redoAction'
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
        case 0: _t->changeColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 1: _t->updateCanvas((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->bulkUpdateAnimation((*reinterpret_cast< std::add_pointer_t<QList<QImage>>>(_a[1]))); break;
        case 3: _t->sendErrorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->successfulLoad((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->requestedFrameChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->requestedNextFrame(); break;
        case 7: _t->requestedPreviousFrame(); break;
        case 8: _t->addFrame(); break;
        case 9: _t->removeFrame(); break;
        case 10: _t->swapFrames((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->toggleAnimationPlayback(); break;
        case 12: _t->updateFPS((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->setPenTool(); break;
        case 14: _t->setEraserTool(); break;
        case 15: _t->setClearCanvasTool(); break;
        case 16: _t->setBucketFillTool(); break;
        case 17: _t->setTintTool(); break;
        case 18: _t->setShadeTool(); break;
        case 19: _t->useCurrentTool((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 20: _t->saveToFile((*reinterpret_cast< std::add_pointer_t<QFile&>>(_a[1]))); break;
        case 21: _t->loadFromFile((*reinterpret_cast< std::add_pointer_t<QFile&>>(_a[1]))); break;
        case 22: _t->updateStoredColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 23: _t->createNewAnimation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 24: _t->saveFramesToHistory(); break;
        case 25: _t->undoAction(); break;
        case 26: _t->redoAction(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QImage> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(const QColor );
            if (_t _q_method = &Model::changeColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(const QImage & , const int );
            if (_t _q_method = &Model::updateCanvas; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(const QVector<QImage> );
            if (_t _q_method = &Model::bulkUpdateAnimation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)(const QString & );
            if (_t _q_method = &Model::sendErrorMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)(bool , const QString );
            if (_t _q_method = &Model::successfulLoad; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
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
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Model::changeColor(const QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::updateCanvas(const QImage & _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::bulkUpdateAnimation(const QVector<QImage> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::sendErrorMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::successfulLoad(bool _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
