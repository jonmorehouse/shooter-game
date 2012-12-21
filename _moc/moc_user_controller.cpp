/****************************************************************************
** Meta object code from reading C++ file 'user_controller.hpp'
**
** Created: Tue Dec 11 22:02:12 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/controllers/user_controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_User_controller[] = {

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
      16,   39,   39,   39, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_User_controller[] = {
    "User_controller\0process_state_change()\0"
    "\0"
};

void User_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        User_controller *_t = static_cast<User_controller *>(_o);
        switch (_id) {
        case 0: _t->process_state_change(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData User_controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject User_controller::staticMetaObject = {
    { &Base_controller::staticMetaObject, qt_meta_stringdata_User_controller,
      qt_meta_data_User_controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &User_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *User_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *User_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_User_controller))
        return static_cast<void*>(const_cast< User_controller*>(this));
    return Base_controller::qt_metacast(_clname);
}

int User_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
