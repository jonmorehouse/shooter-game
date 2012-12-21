/****************************************************************************
** Meta object code from reading C++ file 'game_base_controller.hpp'
**
** Created: Tue Dec 11 22:02:42 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/game_controllers/game_base_controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_base_controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game__Game_base_controller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   48,   48,   48, 0x05,
      49,   48,   48,   48, 0x05,
      60,   48,   48,   48, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   98,   48,   48, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_game__Game_base_controller[] = {
    "game::Game_base_controller\0"
    "keyPress(QKeyEvent*)\0\0level_up()\0"
    "lose_life()\0keyPressEvent(QKeyEvent*)\0"
    "event\0"
};

void game::Game_base_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Game_base_controller *_t = static_cast<Game_base_controller *>(_o);
        switch (_id) {
        case 0: _t->keyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->level_up(); break;
        case 2: _t->lose_life(); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData game::Game_base_controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game::Game_base_controller::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_game__Game_base_controller,
      qt_meta_data_game__Game_base_controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game::Game_base_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game::Game_base_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game::Game_base_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game__Game_base_controller))
        return static_cast<void*>(const_cast< Game_base_controller*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int game::Game_base_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void game::Game_base_controller::keyPress(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void game::Game_base_controller::level_up()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void game::Game_base_controller::lose_life()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
