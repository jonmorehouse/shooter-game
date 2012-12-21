/****************************************************************************
** Meta object code from reading C++ file 'base_object.hpp'
**
** Created: Tue Dec 11 22:02:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/game_objects/base_object.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'base_object.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game__Base_object[] = {

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
      18,   30,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x0a,
      57,   82,   30,   30, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_game__Base_object[] = {
    "game::Base_object\0collision()\0\0"
    "keyPressEvent(QKeyEvent*)\0"
    "paintEvent(QPaintEvent*)\0event\0"
};

void game::Base_object::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Base_object *_t = static_cast<Base_object *>(_o);
        switch (_id) {
        case 0: _t->collision(); break;
        case 1: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData game::Base_object::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game::Base_object::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_game__Base_object,
      qt_meta_data_game__Base_object, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game::Base_object::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game::Base_object::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game::Base_object::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game__Base_object))
        return static_cast<void*>(const_cast< Base_object*>(this));
    return QWidget::qt_metacast(_clname);
}

int game::Base_object::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void game::Base_object::collision()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
