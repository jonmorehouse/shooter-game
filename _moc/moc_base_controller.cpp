/****************************************************************************
** Meta object code from reading C++ file 'base_controller.hpp'
**
** Created: Tue Dec 11 22:02:05 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/controllers/base_controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'base_controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Base_controller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   37,   43,   43, 0x05,
      44,   43,   43,   43, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   37,   43,   43, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Base_controller[] = {
    "Base_controller\0keyPress(QKeyEvent*)\0"
    "event\0\0application_update()\0"
    "keyPressEvent(QKeyEvent*)\0"
};

void Base_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Base_controller *_t = static_cast<Base_controller *>(_o);
        switch (_id) {
        case 0: _t->keyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->application_update(); break;
        case 2: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Base_controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Base_controller::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Base_controller,
      qt_meta_data_Base_controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Base_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Base_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Base_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Base_controller))
        return static_cast<void*>(const_cast< Base_controller*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Base_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void Base_controller::keyPress(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Base_controller::application_update()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
