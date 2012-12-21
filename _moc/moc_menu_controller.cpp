/****************************************************************************
** Meta object code from reading C++ file 'menu_controller.hpp'
**
** Created: Tue Dec 11 22:02:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/controllers/menu_controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Menu_controller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   41,   48,   48, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Menu_controller[] = {
    "Menu_controller\0set_menu_option(QString)\0"
    "option\0\0"
};

void Menu_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Menu_controller *_t = static_cast<Menu_controller *>(_o);
        switch (_id) {
        case 0: _t->set_menu_option((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Menu_controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Menu_controller::staticMetaObject = {
    { &Base_controller::staticMetaObject, qt_meta_stringdata_Menu_controller,
      qt_meta_data_Menu_controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Menu_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Menu_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Menu_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Menu_controller))
        return static_cast<void*>(const_cast< Menu_controller*>(this));
    return Base_controller::qt_metacast(_clname);
}

int Menu_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Base_controller::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
