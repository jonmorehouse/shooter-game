/****************************************************************************
** Meta object code from reading C++ file 'character.hpp'
**
** Created: Tue Dec 11 22:03:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/game_objects/character.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'character.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game__Character[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   38,   46,   46, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   46,   46,   46, 0x0a,
      55,   81,   46,   46, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_game__Character[] = {
    "game::Character\0create_bullet(QPoint)\0"
    "current\0\0reset()\0keyPressEvent(QKeyEvent*)\0"
    "event\0"
};

void game::Character::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Character *_t = static_cast<Character *>(_o);
        switch (_id) {
        case 0: _t->create_bullet((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->reset(); break;
        case 2: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData game::Character::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game::Character::staticMetaObject = {
    { &Base_animated_object::staticMetaObject, qt_meta_stringdata_game__Character,
      qt_meta_data_game__Character, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game::Character::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game::Character::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game::Character::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game__Character))
        return static_cast<void*>(const_cast< Character*>(this));
    return Base_animated_object::qt_metacast(_clname);
}

int game::Character::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Base_animated_object::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void game::Character::create_bullet(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
