/****************************************************************************
** Meta object code from reading C++ file 'c4.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../c4.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'c4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSC4ENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSC4ENDCLASS = QtMocHelpers::stringData(
    "C4",
    "exploded",
    "",
    "defused",
    "updateProgress",
    "checkPlayerNear",
    "checkTotalTime"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSC4ENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[3];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[15];
    char stringdata5[16];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSC4ENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSC4ENDCLASS_t qt_meta_stringdata_CLASSC4ENDCLASS = {
    {
        QT_MOC_LITERAL(0, 2),  // "C4"
        QT_MOC_LITERAL(3, 8),  // "exploded"
        QT_MOC_LITERAL(12, 0),  // ""
        QT_MOC_LITERAL(13, 7),  // "defused"
        QT_MOC_LITERAL(21, 14),  // "updateProgress"
        QT_MOC_LITERAL(36, 15),  // "checkPlayerNear"
        QT_MOC_LITERAL(52, 14)   // "checkTotalTime"
    },
    "C4",
    "exploded",
    "",
    "defused",
    "updateProgress",
    "checkPlayerNear",
    "checkTotalTime"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSC4ENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,
       4,    1,   46,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   49,    2, 0x08,    5 /* Private */,
       6,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject C4::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSC4ENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSC4ENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSC4ENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<C4, std::true_type>,
        // method 'exploded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'defused'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'checkPlayerNear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkTotalTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void C4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<C4 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->exploded(); break;
        case 1: _t->defused(); break;
        case 2: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->checkPlayerNear(); break;
        case 4: _t->checkTotalTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (C4::*)();
            if (_t _q_method = &C4::exploded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (C4::*)();
            if (_t _q_method = &C4::defused; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (C4::*)(float );
            if (_t _q_method = &C4::updateProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *C4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *C4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSC4ENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int C4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void C4::exploded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void C4::defused()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void C4::updateProgress(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
