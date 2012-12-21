/****************************************************************************
** Meta object code from reading C++ file 'rock.hpp'
**
** Created: Wed Dec 12 02:36:25 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/game_objects/rock.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rock.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game__Rock[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   30,   33,   33, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   33,   33,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_game__Rock[] = {
    "game::Rock\0destroy_rock(uint)\0id\0\0"
    "animation_end()\0"
};

void game::Rock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Rock *_t = static_cast<Rock *>(_o);
        switch (_id) {
        case 0: _t->destroy_rock((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->animation_end(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData game::Rock::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game::Rock::staticMetaObject = {
    { &Base_qt_animated_object::staticMetaObject, qt_meta_stringdata_game__Rock,
      qt_meta_data_game__Rock, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game::Rock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game::Rock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game::Rock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game__Rock))
        return static_cast<void*>(const_cast< Rock*>(this));
    return Base_qt_animated_object::qt_metacast(_clname);
}

int game::Rock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Base_qt_animated_object::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void game::Rock::destroy_rock(unsigned int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
