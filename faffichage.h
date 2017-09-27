/****************************************************************************
** Form interface generated from reading ui file 'faffichage.ui'
**
** Created: dim. déc. 4 20:50:19 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FAFFICHAGE_H
#define FAFFICHAGE_H

#include <qvariant.h>
#include <qdialog.h>

#include "CDataSource2D.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QFrame;

class FAffichage : public QDialog
{
	Q_OBJECT

	public:
		FAffichage(CDataSource2D*, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
		~FAffichage();

		QPushButton* ButtonTerminer;
		QPushButton* ButtonTracer;
		QPushButton* ButtonSelectionner;
		QPushButton* ButtonRafraichir;
		QFrame* frame3;
		
		void calculMinMax();

	public slots:
		virtual void Rafraichir();
		virtual void TracerLigne();
		virtual void Terminer();
		virtual void Selectionner();

	protected:
		virtual void mouseMoveEvent( QMouseEvent *e );
		virtual void mouseReleaseEvent( QMouseEvent * );
		virtual void mousePressEvent( QMouseEvent * );


	protected slots:
		virtual void languageChange();

	private:
		QPoint	PointDepart;
		QPoint	PointArrivee;
		bool	Marque;
		CData2D		D1;
		CData2D		D2;
		float   E1 ;
		float   E2 ;
		float   Max1,Max2,Min1,Min2;
		CDataSource2D*     DD;
};

#endif // FAFFICHAGE_H
