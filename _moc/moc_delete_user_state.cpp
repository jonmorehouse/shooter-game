/****************************************************************************
** Meta object code from reading C++ file 'delete_user_state.hpp'
**
** Created: Tue Dec 11 22:02:35 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/user_states/delete_user_state.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delete_user_state.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Delete_user_state[] = {

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
      18,   35,   43,   43, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Delete_user_state[] = {
    "Delete_user_state\0process(QString)\0"
    "message\0\0"
};

void Delete_user_state::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Delete_user_state *_t = static_cast<Delete_user_state *>(_o);
        switch (_id) {
        case 0: _t->process((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Delete_user_state::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Delete_user_state::staticMetaObject = {
    { &Base_user_management::staticMetaObject, qt_meta_stringdata_Delete_user_state,
      qt_meta_data_Delete_user_state, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Delete_user_state::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Delete_user_state::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Delete_user_state::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Delete_user_state))
        return static_cast<void*>(const_cast< Delete_user_state*>(this));
    return Base_user_management::qt_metacast(_clname);
}

int Delete_user_state::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Base_user_management::qt_metacall(_c, _id, _a);
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
