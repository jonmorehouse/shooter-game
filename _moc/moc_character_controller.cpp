/****************************************************************************
** Meta object code from reading C++ file 'character_controller.hpp'
**
** Created: Tue Dec 11 22:02:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/game_controllers/character_controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'character_controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game__Character_controller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   49,   49,   49, 0x0a,
      50,   72,   49,   49, 0x0a,
      80,  101,   49,   49, 0x0a,
     112,   49,   49,   49, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_game__Character_controller[] = {
    "game::Character_controller\0"
    "character_collision()\0\0create_bullet(QPoint)\0"
    "initial\0destroy_bullet(uint)\0identifier\0"
    "reset()\0"
};

void game::Character_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Character_controller *_t = static_cast<Character_controller *>(_o);
        switch (_id) {
        case 0: _t->character_collision(); break;
        case 1: _t->create_bullet((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->destroy_bullet((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData game::Character_controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game::Character_controller::staticMetaObject = {
    { &Game_base_controller::staticMetaObject, qt_meta_stringdata_game__Character_controller,
      qt_meta_data_game__Character_controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game::Character_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game::Character_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game::Character_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game__Character_controller))
        return static_cast<void*>(const_cast< Character_controller*>(this));
    return Game_base_controller::qt_metacast(_clname);
}

int game::Character_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Game_base_controller::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
