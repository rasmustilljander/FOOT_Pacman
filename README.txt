DV1435 Vt12 Lp4 F�rdjupning i objektorienterade tekniker
==================
Rasmus Tilljander
Erik H�rlin
Kim Hansson
Calle Ketola
Andreas Nilsson
==================

F�rslag till programmeringsstandarder
=====================================
Allm�nna saker
	Mellanrum mellan kodrader som ej �r direkt sammanl�nkade
	Ett mellanrum mellan funktioner
	Kommentarer ovanf�r funktioner i .cpp och brevid i .h
	Parameterlistor ska delas upp p� nya rader ifall de inneh�ller
		fler �n fyra parametrar
	M�svingar raden under ett statement
	Inga m�svingar om man inte m�ste ha
	Deklarationer skall vara "aligned" (s� gott det g�r)
		ex
		int a 		= 5;
		double b 	= 5.5;
	
Headerfiler
	En klass per header
	Ordning p� variabler/funktiner
		public funktioner			
		private funktioner
		private variabler
		protected funktioner
		protected variabler
	Get/setfunktioner skrivs direkt i header filen och l�ggs sist
	Get funktioner skall vara "const"
	
Variabler
	B�rja alltid med liten bokstav
	Vid flerord variabelsnamn s� stor bokstav p� varje nytt ord
		ihopsatt utan delare s� som "_".
	Medlemsvariabler: prefix 'm' (ex. int mLevel)
	Parameterlistor: prefix 'l'
	Lokalt skapade variabler: prefix 'l' eller 'temp'
	Konstanta variabler: Ingen prefix, stor bokstav i b�rjan 
		ex. const int WorldSize = 5;), alternativt 'g' eller 'c'

Funktioner
	B�rja med stor bokstav
	Vid flerord funktionsnamn s� stor bokstav p� varje nytt ord, 
		ihopsatt utan delare s� som "_".
	Alla "get" funktioner b�r vara konstanta (ex. int GetLevel() const;)
	Bra l�nk: http://vimeo.com/13702091


=====================================
Om ascii art skall vara med s� m�ste den vara hemmagjord.

=====================================
Att göra till nästa gång!
Scenarios
Och classuppbyggnad
Humma UML sånger (lära sig UML pilar)
