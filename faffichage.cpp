/****************************************************************************
** Form implementation generated from reading ui file 'faffichage.ui'
**
** Created: dim. déc. 4 20:55:04 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "faffichage.h"

#include <qvariant.h>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <cmath>

extern float a,b;
#include <pthread.h>
extern pthread_cond_t Cond;
extern pthread_mutex_t Mutex;
extern int Continue;
extern int errno;

using namespace std;

/*
 *  Constructs a FAffichage as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FAffichage::FAffichage(CDataSource2D* D, QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FAffichage" );

    ButtonTerminer = new QPushButton( this, "ButtonTerminer" );
    ButtonTerminer->setGeometry( QRect( 360, 280, 100, 29 ) );
    ButtonTerminer->setAutoDefault( FALSE );

    ButtonTracer = new QPushButton( this, "ButtonTracer" );
    ButtonTracer->setGeometry( QRect( 240, 280, 100, 29 ) );
    ButtonTracer->setAutoDefault( FALSE );

    ButtonSelectionner = new QPushButton( this, "ButtonSelectionner" );
    ButtonSelectionner->setGeometry( QRect( 130, 280, 100, 29 ) );
    ButtonSelectionner->setAutoDefault( FALSE );

    ButtonRafraichir = new QPushButton( this, "ButtonRafraichir" );
    ButtonRafraichir->setGeometry( QRect( 10, 280, 100, 29 ) );
    ButtonRafraichir->setAutoDefault( FALSE );

    frame3 = new QFrame( this, "frame3" );
    frame3->setGeometry( QRect( 20, 20, 440, 240 ) );
    frame3->setFrameShape( QFrame::StyledPanel );
    frame3->setFrameShadow( QFrame::Raised );
    languageChange();
    resize( QSize(475, 327).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( ButtonRafraichir, SIGNAL( clicked() ), this, SLOT( Rafraichir() ) );
    connect( ButtonTerminer, SIGNAL( clicked() ), this, SLOT( Terminer() ) );
    connect( ButtonTracer, SIGNAL( clicked() ), this, SLOT( TracerLigne() ) );
    connect( ButtonSelectionner, SIGNAL( clicked() ), this, SLOT( Selectionner() ) );
	
	printf("Debut de affichage\n");

	DD = D;

	calculMinMax();
}

void FAffichage::calculMinMax()
{
	Min1 = DD->getXi(0);
	Max1 = DD->getXi(0);
	Min2 = DD->getYi(0);
	Max2 = DD->getYi(0);

	for(int i = 1; i < DD->getL()->getTaille(); i++)
	{
		float fTemp;
		fTemp = DD->getXi(i);
		if(fTemp < Min1)
			Min1 = fTemp;
		if(fTemp > Max1)
			Max1 = fTemp;

		fTemp = DD->getYi(i);
		if(fTemp < Min2)
			Min2 = fTemp;
		if(fTemp > Max2)
			Max2 = fTemp;
	}
	E1 = Max1 - Min1;
	E2 = Max2 - Min2;
}

/*
 *  Destroys the object and frees any allocated resources
 */
FAffichage::~FAffichage()
{
    // no need to delete child widgets, Qt does it all for us
printf("dans destructeur FAffiche\n");
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FAffichage::languageChange()
{
    setCaption( tr( "Affichage des donnees" ) );
    ButtonTerminer->setText( tr( "Terminer" ) );
    ButtonTracer->setText( tr( "Tracer ligne" ) );
    ButtonSelectionner->setText( tr( "Selectionner" ) );
    ButtonRafraichir->setText( tr( "Rafraichir" ) );
}

void FAffichage::Rafraichir()
{
    qWarning( "FAffichage::Rafraichir()" );
	QPainter paint(frame3);
	paint.setPen(Qt::red);
	
	paint.eraseRect(1, 1, 438, 238);

	int x, y;
	for(int i = 0; i < DD->getL()->getTaille(); i++)
	{
		x = ((int)((DD->getXi(i) - Min1) * 400 / E1) + 20) - 4;
		y = (240 - ((int)((DD->getYi(i) - Min2) * 200 / E2) + 20)) + 4;
		paint.drawText(x, y, "X");
	}
}

void FAffichage::TracerLigne()
{
    qWarning( "FAffichage::TracerLigne()" );
	QPainter paint(frame3);
	
	float  C1, C2;

	C1 = 220 - 200 * (a * Min1 + b - Min2) / (Max2 - Min2);
	C2 = 220 - 200 * (a * Max1 + b - Min2) / (Max2 - Min2);
	
	paint.drawLine(20, (int)C1, 420, (int)C2);
}

void FAffichage::Terminer()
{
    qWarning( "FAffichage::Terminer()");
	
	pthread_mutex_lock(&Mutex);
	Continue = 0;
	pthread_mutex_unlock(&Mutex);
	pthread_cond_signal(&Cond);
	close();
	pthread_exit(0);
}

void FAffichage::Selectionner()
{
    qWarning( "FAffichage::Selectionner() " );
	
	QPainter paint( frame3 );
	paint.setPen(Qt::black);
	paint.drawRect(PointDepart.x(), PointDepart.y(), PointArrivee.x() - PointDepart.x(), PointArrivee.y() - PointDepart.y()); // x, y, largeur, hauteur
	
	float fDepartX, fDepartY, fArriveeX, fArriveeY;

	if(PointDepart.x() > PointArrivee.x())
	{
		fDepartX = PointArrivee.x();
		fArriveeX = PointDepart.x();
	}
	else
	{
		fDepartX = PointDepart.x();
		fArriveeX = PointArrivee.x();
	}

	if(PointDepart.y() < PointArrivee.y())
	{
		fDepartY = PointArrivee.y();
		fArriveeY = PointDepart.y();
	}
	else
	{
		fDepartY = PointDepart.y();
		fArriveeY = PointArrivee.y();
	}
	
	float fDepartXReel, fDepartYReel, fArriveeXReel, fArriveeYReel;

	fDepartXReel = ((fDepartX - 20) * E1 / 400) + Min1;
	fDepartYReel = ((-fDepartY - 20 + 240) * E2 / 200) + Min2;
	
	fArriveeXReel = ((fArriveeX - 20) * E1 / 400) + Min1;
	fArriveeYReel = ((-fArriveeY - 20 + 240) * E2 / 200) + Min2;
	
	CListeS<CData2D>* lTemp;
	lTemp = (CListeS<CData2D>*)(DD->getL());

	CData2D CDDep(fDepartXReel, fDepartYReel);
	CData2D CDArr(fArriveeXReel, fArriveeYReel);
	
	for (int i = 0; i < DD->getL()->getTaille(); i++)
	{
		if (CDDep < *lTemp->getElement(i) && CDArr > *lTemp->getElement(i))
		{
			lTemp->supprimer(*lTemp->getElement(i));
			break; // On ne permet la suppression que D'UN point à la fois !
		}
	}
}

void FAffichage::mouseMoveEvent(QMouseEvent* e)
{

}

void FAffichage::mouseReleaseEvent(QMouseEvent* e)
{
	QPainter paint( frame3 );
	if (Marque)
	{
		PointArrivee = e->pos() ;
		PointArrivee.setX(PointArrivee.x() - 20);
		PointArrivee.setY(PointArrivee.y() - 20);
		paint.drawText(PointArrivee.x() - 4, PointArrivee.y() + 4, "x");
		Marque = false;
	}
	cout << "Depart : " << PointDepart.x() << " - " << PointDepart.y()<< endl;
	cout << "Arrivee : " << PointArrivee.x() << " - " << PointArrivee.y()<< endl;
}

void FAffichage::mousePressEvent(QMouseEvent* e)
{
	QPainter paint( frame3 );
	if (!Marque)
	{
		PointDepart = e->pos();
		PointDepart.setX(PointDepart.x() - 20);
		PointDepart.setY(PointDepart.y() - 20);
		paint.drawText(PointDepart.x() - 4, PointDepart.y() + 4, "x");
		Marque = true;
	}
}
