DV1435 Vt12 Lp4 Fördjupning i objektorienterade tekniker
==================
Rasmus Tilljander
Erik Hörlin
Kim Hansson
Calle Ketola
Andreas Nilsson
==================



Förslag till programmeringsstandarder
=====================================
Variabler
	Börja alltid med liten bokstav
	Vid flerord variabelsnamn så stor bokstav på varje nytt ord, ihopsatt utan delare så som "_".
	Medlemsvariabler: prefix 'm' (ex. int mLevel)
	Parameterlistor: prefix 'l'
	Lokalt skapade variabler: prefix 'l' eller 'temp'
	Konstanta variabler: Ingen prefix, stor bokstav i början (ex. const int WorldSize = 5;), alternativt 'g' eller 'c'

Funktioner
	Börja med stor bokstav
	Vid flerord funktionsnamn så stor bokstav på varje nytt ord, ihopsatt utan delare så som "_".
	Alla "get" funktioner bör vara konstanta (ex. int GetLevel() const;)
	Bra länk: http://vimeo.com/13702091