/****************************************************************************
** Meta object code from reading C++ file 'base_user_display.hpp'
**
** Created: Tue Dec 11 22:02:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/user_states/base_user_display.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'base_user_display.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Base_user_display[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Base_user_display[] = {
    "Base_user_display\0"
};

void Base_user_display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Base_user_display::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Base_user_display::staticMetaObject = {
    { &Base_user_state::staticMetaObject, qt_meta_stringdata_Base_user_display,
      qt_meta_data_Base_user_display, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Base_user_display::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Base_user_display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Base_user_display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Base_user_display))
        return static_cast<void*>(const_cast< Base_user_display*>(this));
    return Base_user_state::qt_metacast(_clname);
}

int Base_user_display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Base_user_state::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
