/****************************************************************************
** Meta object code from reading C++ file 'timer.hpp'
**
** Created: Tue Dec 11 22:03:04 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/game_objects/timer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game__Timer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   22,   22,   22, 0x05,
      23,   22,   22,   22, 0x05,
      33,   22,   22,   22, 0x05,
      43,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_game__Timer[] = {
    "game::Timer\0_single()\0\0_double()\0"
    "_triple()\0_quadruple()\0controller()\0"
};

void game::Timer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Timer *_t = static_cast<Timer *>(_o);
        switch (_id) {
        case 0: _t->_single(); break;
        case 1: _t->_double(); break;
        case 2: _t->_triple(); break;
        case 3: _t->_quadruple(); break;
        case 4: _t->controller(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData game::Timer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game::Timer::staticMetaObject = {
    { &QTimer::staticMetaObject, qt_meta_stringdata_game__Timer,
      qt_meta_data_game__Timer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game::Timer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game::Timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game::Timer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game__Timer))
        return static_cast<void*>(const_cast< Timer*>(this));
    return QTimer::qt_metacast(_clname);
}

int game::Timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void game::Timer::_single()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void game::Timer::_double()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void game::Timer::_triple()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void game::Timer::_quadruple()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
