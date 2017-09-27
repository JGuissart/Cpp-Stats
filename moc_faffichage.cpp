/****************************************************************************
** FAffichage meta object code from reading C++ file 'faffichage.h'
**
** Created: Thu Dec 29 15:32:56 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "faffichage.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FAffichage::className() const
{
    return "FAffichage";
}

QMetaObject *FAffichage::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FAffichage( "FAffichage", &FAffichage::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FAffichage::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FAffichage", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FAffichage::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FAffichage", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FAffichage::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"Rafraichir", 0, 0 };
    static const QUMethod slot_1 = {"TracerLigne", 0, 0 };
    static const QUMethod slot_2 = {"Terminer", 0, 0 };
    static const QUMethod slot_3 = {"Selectionner", 0, 0 };
    static const QUMethod slot_4 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Rafraichir()", &slot_0, QMetaData::Public },
	{ "TracerLigne()", &slot_1, QMetaData::Public },
	{ "Terminer()", &slot_2, QMetaData::Public },
	{ "Selectionner()", &slot_3, QMetaData::Public },
	{ "languageChange()", &slot_4, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"FAffichage", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FAffichage.setMetaObject( metaObj );
    return metaObj;
}

void* FAffichage::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FAffichage" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool FAffichage::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Rafraichir(); break;
    case 1: TracerLigne(); break;
    case 2: Terminer(); break;
    case 3: Selectionner(); break;
    case 4: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FAffichage::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FAffichage::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool FAffichage::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
