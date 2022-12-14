/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../a7-sprite-editor-f22-Stefan-Mada/view.h"
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
    uint offsetsAndSizes[120];
    char stringdata0[5];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[17];
    char stringdata5[13];
    char stringdata6[16];
    char stringdata7[11];
    char stringdata8[14];
    char stringdata9[14];
    char stringdata10[8];
    char stringdata11[8];
    char stringdata12[14];
    char stringdata13[6];
    char stringdata14[13];
    char stringdata15[11];
    char stringdata16[7];
    char stringdata17[9];
    char stringdata18[13];
    char stringdata19[17];
    char stringdata20[9];
    char stringdata21[16];
    char stringdata22[6];
    char stringdata23[7];
    char stringdata24[13];
    char stringdata25[16];
    char stringdata26[13];
    char stringdata27[11];
    char stringdata28[4];
    char stringdata29[17];
    char stringdata30[16];
    char stringdata31[16];
    char stringdata32[27];
    char stringdata33[16];
    char stringdata34[15];
    char stringdata35[11];
    char stringdata36[6];
    char stringdata37[13];
    char stringdata38[13];
    char stringdata39[20];
    char stringdata40[18];
    char stringdata41[9];
    char stringdata42[8];
    char stringdata43[12];
    char stringdata44[14];
    char stringdata45[18];
    char stringdata46[21];
    char stringdata47[18];
    char stringdata48[14];
    char stringdata49[10];
    char stringdata50[15];
    char stringdata51[17];
    char stringdata52[12];
    char stringdata53[13];
    char stringdata54[17];
    char stringdata55[20];
    char stringdata56[25];
    char stringdata57[24];
    char stringdata58[18];
    char stringdata59[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_View_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
        QT_MOC_LITERAL(0, 4),  // "View"
        QT_MOC_LITERAL(5, 18),  // "changeWorkingFrame"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 10),  // "frameIndex"
        QT_MOC_LITERAL(36, 16),  // "getPreviousFrame"
        QT_MOC_LITERAL(53, 12),  // "getNextFrame"
        QT_MOC_LITERAL(66, 15),  // "getCurrentFrame"
        QT_MOC_LITERAL(82, 10),  // "swapFrames"
        QT_MOC_LITERAL(93, 13),  // "frameIndexOne"
        QT_MOC_LITERAL(107, 13),  // "frameIndexTwo"
        QT_MOC_LITERAL(121, 7),  // "setGrid"
        QT_MOC_LITERAL(129, 7),  // "setting"
        QT_MOC_LITERAL(137, 13),  // "setImagePixel"
        QT_MOC_LITERAL(151, 5),  // "point"
        QT_MOC_LITERAL(157, 12),  // "mousePressed"
        QT_MOC_LITERAL(170, 10),  // "saveToFile"
        QT_MOC_LITERAL(181, 6),  // "QFile&"
        QT_MOC_LITERAL(188, 8),  // "fileName"
        QT_MOC_LITERAL(197, 12),  // "loadfromFile"
        QT_MOC_LITERAL(210, 16),  // "updateModelColor"
        QT_MOC_LITERAL(227, 8),  // "newColor"
        QT_MOC_LITERAL(236, 15),  // "getNewAnimation"
        QT_MOC_LITERAL(252, 5),  // "width"
        QT_MOC_LITERAL(258, 6),  // "height"
        QT_MOC_LITERAL(265, 12),  // "updateCanvas"
        QT_MOC_LITERAL(278, 15),  // "newWorkingImage"
        QT_MOC_LITERAL(294, 12),  // "currentFrame"
        QT_MOC_LITERAL(307, 10),  // "getToolPos"
        QT_MOC_LITERAL(318, 3),  // "pos"
        QT_MOC_LITERAL(322, 16),  // "updateCurrentPos"
        QT_MOC_LITERAL(339, 15),  // "getSaveFileName"
        QT_MOC_LITERAL(355, 15),  // "getLoadFileName"
        QT_MOC_LITERAL(371, 26),  // "onChooseColorButtonPressed"
        QT_MOC_LITERAL(398, 15),  // "createNewButton"
        QT_MOC_LITERAL(414, 14),  // "setButtonImage"
        QT_MOC_LITERAL(429, 10),  // "frameImage"
        QT_MOC_LITERAL(440, 5),  // "index"
        QT_MOC_LITERAL(446, 12),  // "displayError"
        QT_MOC_LITERAL(459, 12),  // "errorMessage"
        QT_MOC_LITERAL(472, 19),  // "processNewAnimation"
        QT_MOC_LITERAL(492, 17),  // "showPreviewWindow"
        QT_MOC_LITERAL(510, 8),  // "showGrid"
        QT_MOC_LITERAL(519, 7),  // "toggled"
        QT_MOC_LITERAL(527, 11),  // "moveFrameUp"
        QT_MOC_LITERAL(539, 13),  // "moveFrameDown"
        QT_MOC_LITERAL(553, 17),  // "deleteFrameButton"
        QT_MOC_LITERAL(571, 20),  // "switchToClickedFrame"
        QT_MOC_LITERAL(592, 17),  // "bulkRefreshFrames"
        QT_MOC_LITERAL(610, 13),  // "QList<QImage>"
        QT_MOC_LITERAL(624, 9),  // "newFrames"
        QT_MOC_LITERAL(634, 14),  // "successfulLoad"
        QT_MOC_LITERAL(649, 16),  // "animationIsEmpty"
        QT_MOC_LITERAL(666, 11),  // "processSave"
        QT_MOC_LITERAL(678, 12),  // "showHelpMenu"
        QT_MOC_LITERAL(691, 16),  // "setCursorIconPen"
        QT_MOC_LITERAL(708, 19),  // "setCursorIconEraser"
        QT_MOC_LITERAL(728, 24),  // "setCursorIconClearCanvas"
        QT_MOC_LITERAL(753, 23),  // "setCursorIconBucketFill"
        QT_MOC_LITERAL(777, 17),  // "setCursorIconTint"
        QT_MOC_LITERAL(795, 18)   // "setCursorIconShade"
    },
    "View",
    "changeWorkingFrame",
    "",
    "frameIndex",
    "getPreviousFrame",
    "getNextFrame",
    "getCurrentFrame",
    "swapFrames",
    "frameIndexOne",
    "frameIndexTwo",
    "setGrid",
    "setting",
    "setImagePixel",
    "point",
    "mousePressed",
    "saveToFile",
    "QFile&",
    "fileName",
    "loadfromFile",
    "updateModelColor",
    "newColor",
    "getNewAnimation",
    "width",
    "height",
    "updateCanvas",
    "newWorkingImage",
    "currentFrame",
    "getToolPos",
    "pos",
    "updateCurrentPos",
    "getSaveFileName",
    "getLoadFileName",
    "onChooseColorButtonPressed",
    "createNewButton",
    "setButtonImage",
    "frameImage",
    "index",
    "displayError",
    "errorMessage",
    "processNewAnimation",
    "showPreviewWindow",
    "showGrid",
    "toggled",
    "moveFrameUp",
    "moveFrameDown",
    "deleteFrameButton",
    "switchToClickedFrame",
    "bulkRefreshFrames",
    "QList<QImage>",
    "newFrames",
    "successfulLoad",
    "animationIsEmpty",
    "processSave",
    "showHelpMenu",
    "setCursorIconPen",
    "setCursorIconEraser",
    "setCursorIconClearCanvas",
    "setCursorIconBucketFill",
    "setCursorIconTint",
    "setCursorIconShade"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_View[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  236,    2, 0x06,    1 /* Public */,
       4,    0,  239,    2, 0x06,    3 /* Public */,
       5,    0,  240,    2, 0x06,    4 /* Public */,
       6,    1,  241,    2, 0x06,    5 /* Public */,
       7,    2,  244,    2, 0x06,    7 /* Public */,
      10,    1,  249,    2, 0x06,   10 /* Public */,
      12,    2,  252,    2, 0x06,   12 /* Public */,
      15,    1,  257,    2, 0x06,   15 /* Public */,
      18,    1,  260,    2, 0x06,   17 /* Public */,
      19,    1,  263,    2, 0x06,   19 /* Public */,
      21,    2,  266,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      24,    2,  271,    2, 0x08,   24 /* Private */,
      27,    2,  276,    2, 0x08,   27 /* Private */,
      29,    1,  281,    2, 0x08,   30 /* Private */,
      30,    0,  284,    2, 0x08,   32 /* Private */,
      31,    0,  285,    2, 0x08,   33 /* Private */,
      32,    0,  286,    2, 0x08,   34 /* Private */,
      33,    0,  287,    2, 0x08,   35 /* Private */,
      34,    2,  288,    2, 0x08,   36 /* Private */,
      37,    1,  293,    2, 0x08,   39 /* Private */,
      39,    0,  296,    2, 0x08,   41 /* Private */,
      40,    0,  297,    2, 0x08,   42 /* Private */,
      41,    1,  298,    2, 0x08,   43 /* Private */,
      43,    0,  301,    2, 0x08,   45 /* Private */,
      44,    0,  302,    2, 0x08,   46 /* Private */,
      45,    0,  303,    2, 0x08,   47 /* Private */,
      46,    0,  304,    2, 0x08,   48 /* Private */,
      47,    1,  305,    2, 0x08,   49 /* Private */,
      50,    2,  308,    2, 0x08,   51 /* Private */,
      52,    0,  313,    2, 0x08,   54 /* Private */,
      53,    0,  314,    2, 0x08,   55 /* Private */,
      54,    0,  315,    2, 0x08,   56 /* Private */,
      55,    0,  316,    2, 0x08,   57 /* Private */,
      56,    0,  317,    2, 0x08,   58 /* Private */,
      57,    0,  318,    2, 0x08,   59 /* Private */,
      58,    0,  319,    2, 0x08,   60 /* Private */,
      59,    0,  320,    2, 0x08,   61 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Bool,   13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QColor,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,   25,   26,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Bool,   28,   14,
    QMetaType::Void, QMetaType::QPoint,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,   35,   36,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 48,   49,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   51,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'changeWorkingFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getPreviousFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getNextFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getCurrentFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'swapFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setImagePixel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveToFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFile &, std::false_type>,
        // method 'loadfromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFile &, std::false_type>,
        // method 'updateModelColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor, std::false_type>,
        // method 'getNewAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'updateCanvas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'getToolPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateCurrentPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'getSaveFileName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getLoadFileName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onChooseColorButtonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createNewButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setButtonImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'displayError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'processNewAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showPreviewWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'moveFrameUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveFrameDown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteFrameButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToClickedFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bulkRefreshFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QImage>, std::false_type>,
        // method 'successfulLoad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'processSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showHelpMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCursorIconPen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCursorIconEraser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCursorIconClearCanvas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCursorIconBucketFill'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCursorIconTint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCursorIconShade'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeWorkingFrame((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->getPreviousFrame(); break;
        case 2: _t->getNextFrame(); break;
        case 3: _t->getCurrentFrame((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->swapFrames((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->setGrid((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->setImagePixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 7: _t->saveToFile((*reinterpret_cast< std::add_pointer_t<QFile&>>(_a[1]))); break;
        case 8: _t->loadfromFile((*reinterpret_cast< std::add_pointer_t<QFile&>>(_a[1]))); break;
        case 9: _t->updateModelColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 10: _t->getNewAnimation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->updateCanvas((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->getToolPos((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 13: _t->updateCurrentPos((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 14: _t->getSaveFileName(); break;
        case 15: _t->getLoadFileName(); break;
        case 16: _t->onChooseColorButtonPressed(); break;
        case 17: _t->createNewButton(); break;
        case 18: _t->setButtonImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 19: _t->displayError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->processNewAnimation(); break;
        case 21: _t->showPreviewWindow(); break;
        case 22: _t->showGrid((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->moveFrameUp(); break;
        case 24: _t->moveFrameDown(); break;
        case 25: _t->deleteFrameButton(); break;
        case 26: _t->switchToClickedFrame(); break;
        case 27: _t->bulkRefreshFrames((*reinterpret_cast< std::add_pointer_t<QList<QImage>>>(_a[1]))); break;
        case 28: _t->successfulLoad((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 29: _t->processSave(); break;
        case 30: _t->showHelpMenu(); break;
        case 31: _t->setCursorIconPen(); break;
        case 32: _t->setCursorIconEraser(); break;
        case 33: _t->setCursorIconClearCanvas(); break;
        case 34: _t->setCursorIconBucketFill(); break;
        case 35: _t->setCursorIconTint(); break;
        case 36: _t->setCursorIconShade(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 27:
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
            using _t = void (View::*)(int );
            if (_t _q_method = &View::changeWorkingFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (_t _q_method = &View::getPreviousFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (_t _q_method = &View::getNextFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (View::*)(const int );
            if (_t _q_method = &View::getCurrentFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (View::*)(int , int );
            if (_t _q_method = &View::swapFrames; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (View::*)(bool );
            if (_t _q_method = &View::setGrid; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (View::*)(const QPoint & , bool );
            if (_t _q_method = &View::setImagePixel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (View::*)(QFile & );
            if (_t _q_method = &View::saveToFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (View::*)(QFile & );
            if (_t _q_method = &View::loadfromFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (View::*)(const QColor );
            if (_t _q_method = &View::updateModelColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (View::*)(const int , const int );
            if (_t _q_method = &View::getNewAnimation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
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
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void View::changeWorkingFrame(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void View::getPreviousFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void View::getNextFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void View::getCurrentFrame(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void View::swapFrames(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void View::setGrid(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void View::setImagePixel(const QPoint & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void View::saveToFile(QFile & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void View::loadfromFile(QFile & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void View::updateModelColor(const QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void View::getNewAnimation(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
