.SILENT :

DEP = CEchantillon.o \
		CDataSource.o \
		CDataSourceSerieDiscrete.o \
		CDataSourceSerieContinue.o \
		CDataSource2D.o \
		CListe.o \
		CListeTriee.o \
		CListeS.o \
		CData1D.o \
		CData2D.o \
		CSerieStatistique1D.o \
		CSerieStatistique2D.o \
		moc_faffichage.o \
		faffichage.o \
		InvalidBasicException.o \
		InvalidDataException.o \
		InvalidFileException.o \
		InvalidMemoryException.o
		
GPP = g++ -I /usr/local/qt/include -I /usr/local/qt/mkspec/default
main:	main.cxx $(DEP)
		echo Creation de main...
		$(GPP) -o main main.cxx $(DEP) -lqt -lpthread
		
CData1D.o:	CData1D.cxx CData1D.h CData.h
			echo Creation de CData1D.o...
			$(GPP) -c CData1D.cxx

CData2D.o:	CData2D.cxx CData2D.h CData.h
			echo Creation de CData2D.o...
			$(GPP) -c CData2D.cxx
				
CDataSource.o:	CDataSource.cxx CDataSource.h
				echo Creation de CDataSource.o...
				$(GPP) -c CDataSource.cxx
				
CDataSource2D.o:	CDataSource2D.cxx CDataSource2D.h
				echo Creation de CDataSource2D.o...
				$(GPP) -c CDataSource2D.cxx
				
CDataSourceSerieDiscrete.o:	CDataSourceSerieDiscrete.cxx CDataSourceSerieDiscrete.h
				echo Creation de CDataSourceSerieDiscrete.o...
				$(GPP) -c CDataSourceSerieDiscrete.cxx
				
CDataSourceSerieContinue.o:	CDataSourceSerieContinue.cxx CDataSourceSerieContinue.h
				echo Creation de CDataSourceSerieContinue.o...
				$(GPP) -c CDataSourceSerieContinue.cxx
				
CEchantillon.o:	CEchantillon.cxx CEchantillon.h
				echo Creation de CEchantillon.o...
				$(GPP) -c CEchantillon.cxx
				
CListe.o:	CListe.cxx CListe.h
			echo Creation de CListe.o...
			$(GPP) -c CListe.cxx
			
CListeS.o:	CListeS.cxx CListeS.h
			echo Creation de CListeS.o...
			$(GPP) -c CListeS.cxx
				
CListeTriee.o:	CListeTriee.cxx CListeTriee.h
				echo Creation de CListeTriee.o...
				$(GPP) -c CListeTriee.cxx

CSerieStatistique1D.o:	CSerieStatistique1D.cxx CSerieStatistique1D.h
						echo Creation de CSerieStatistique1D.o...
						$(GPP) -c CSerieStatistique1D.cxx

CSerieStatistique2D.o:	CSerieStatistique2D.cxx CSerieStatistique2D.h
						echo Creation de CSerieStatistique2D.o...
						$(GPP) -c CSerieStatistique2D.cxx

faffichage.o:	faffichage.cpp faffichage.h
				echo Creation de faffichage.o...
				$(GPP) -c faffichage.cpp
				
InvalidBasicException.o: InvalidBasicException.cxx InvalidBasicException.h
	echo Creation de InvalidBasicException.o ...
	$(GPP) InvalidBasicException.cxx -c
	
InvalidDataException.o: InvalidDataException.cxx InvalidDataException.h
	echo Creation de InvalidDataException.o ...
	$(GPP) InvalidDataException.cxx -c
	
InvalidFileException.o: InvalidFileException.cxx InvalidFileException.h
	echo Creation de InvalidFileException.o ...
	$(GPP) InvalidFileException.cxx -c
	
InvalidMemoryException.o: InvalidMemoryException.cxx InvalidMemoryException.h
	echo Creation de InvalidMemoryException.o ...
	$(GPP) InvalidMemoryException.cxx -c

#/usr/local/qt/bin/uic faffichage.ui -o faffichage.h
#/usr/local/qt/bin/uic faffichage.ui -i faffichage.h -o faffichage.cpp
#/usr/local/qt/bin/moc faffichage.h -o moc_faffichage.cpp

moc_faffichage.o: moc_faffichage.cpp
				echo Creation de moc_faffichage.o...
				$(GPP) -c moc_faffichage.cpp

clean:
	rm -f main *.o core
	
