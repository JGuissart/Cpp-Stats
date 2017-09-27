#include "CEchantillon.h"
#include "CSerieStatistique1D.h"
#include "CSerieStatistique2D.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <qapplication.h>
#include "faffichage.h"

FAffichage* F1; 
void *Graph2D(void* D);
int	Continue = 1;

int	Argc;
char**	Argv;
CEchantillon*	E1;

pthread_t	Hand;
pthread_cond_t Cond;
pthread_mutex_t Mutex;

float a, b, aMoyenne, aMediane, aEcartType;

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2 || argc > 4)
        {
            cout << "Le format de la ligne de commande doit etre le suivant: " << endl;
            cout << "\tExecutable nomFichier numCol1 (numCol2 si serie 2D)" << endl;
        }
        else
        {
            if (argc == 2)
            {
                cout << "Etude 1D" << endl;
                E1 = new CEchantillon(argv[1], 1);
                E1->Affiche();
                CSerieStatistique1D C1D(E1);
                C1D.AfficheRapport();
				exit(0);
            }
            if (argc == 3)
            {
                cout << "Etude 1D" << endl;
                E1 = new CEchantillon(argv[1], atoi(argv[2]));
                E1->Affiche();
                CSerieStatistique1D C1D(E1);
                C1D.AfficheRapport();
				exit(0);
            }
            if (argc == 4)
            {
                cout << "Etude 2D" << endl;
				E1 = new CEchantillon(argv[1],atoi(argv[2]),atoi(argv[3]));
				if ((errno = pthread_mutex_init(&Mutex,NULL)) != 0)
				{
					perror("Err. de pthread_mutex_init() : ");
					exit(1);
				}

				if ((errno = pthread_cond_init(&Cond,NULL)) != 0)
				{
					perror("Err. de pthread_cond_init() : ");
					exit(1);
				}

				CSerieStatistique2D C2D(E1);
				a = C2D.getA();
				b = C2D.getB();		

				pthread_create(&Hand, NULL, Graph2D, (void*)E1->getSource());

				pthread_mutex_lock(&Mutex);
				while(Continue == 1)
					pthread_cond_wait(&Cond, &Mutex);
				pthread_mutex_unlock(&Mutex);


				C2D.calculMoyenneVal1();
				C2D.calculMoyenneVal2();
				C2D.calculA();
				C2D.calculB();
				C2D.calculCorrelation();

				a = C2D.getA();
				b = C2D.getB();	

				C2D.Affiche();
				C2D.Prevision();
            }
        }
    }
    catch(InvalidFileException e)
    {
        cout << "InvalidFileException: " << e.getMessage() << endl;
    }
    catch(InvalidDataException e)
    {
        cout << "InvalidDataException: " << e.getMessage() << endl;
    }
    catch(InvalidMemoryException e)
    {
        cout << "InvalidMemoryException: " << e.getMessage() << endl;
    }
    catch(InvalidBasicException e)
    {
        cout << "InvalidBasicException: " << e.getMessage() << endl;
    }

	exit(0);
}

void *Graph2D(void* D)
{
	CDataSource2D* DD = (CDataSource2D*)D;
	QApplication a( Argc, Argv );
	F1 = new FAffichage(DD);
	F1->show();
	a.exec();
	return NULL;
}
