> **First-fit greedy, turn by turn**
>
> Source: https://github.com/nicolas-gaillard/SatellitePlusPlus
>
> Method overview:
> 1. Reads the input and drops a fixed share of the collections, using thresholds written in the code (`DataReceiver(filename, 10, 100)`). Its README says the results depend on these.
> 2. For each satellite, turn by turn, goes through the collections open at that turn and takes each image in range that the camera can still reach from its last picture.
> 3. Runs the satellites in threads. The score did not change between runs.
>
> In our runs: **68,495** on `weekend` and **91,222** on `constellation`, first on both, and 43,328 on `forever_alone`. Its output on `overlap` is invalid. ([scores](../../output/per_turn_first_fit_greedy/scores.md)).



# SatellitePlusPlus


Projet c++ pour répondre au challenge google

##### Remarques :
Nos résultats de score dépendent entièrement de données de seuillage écrite en dur dans notre programme d'où la non correspondance entre les fichiers de résultats postés et la version de l'exécutable présente dans master car nous adaptons les données de seuillage à chaque jeu de données (ce qui nous forcerait à avoir 4 executables pour chaque jeu).


L'arbitrage fonctionne partiellement sous Linux et pas du tout sur Windows.


##### Etat actuel des choses :

1. StructData.h contient la structure des différents conteneurs de données



```cpp



struct Satelite
{
	long la;
	long lo;
	int speed;
	int speedRot;
	int maxRot;
};


struct Image
{
	long la;
	long lo;

};

struct TimeStamp {
	int minTime;
	int maxTime;
};

struct Collection
{
	int nbImg;
	int nbPts;
	int nbTimeSt;
	TimeStamp * listTimeSt;
	Image * listImg;

};

```


Chaque collection contient :
  - la liste des images
  - la liste des timeStamp disponibles

Le reste est explicite


Ces structures de données sont instanciées et utilisées à partir de la classe SimulationData

```cpp
#pragma once

#include "StructData.h"

class SimulationData
{

public:
	SimulationData();
	~SimulationData();


	inline long getNbCollection() { return nbCollection; };
	inline long getDuration() { return duration; };
	inline long getNbSatelite() { return nbSatelite; };
	inline Satelite * getArraySat() { return arraySat; };
	inline Collection * getArrayCol() { return arrayCol; };

	inline void setNbCollection(int nb) { this->nbCollection = nb; };
	inline void setDuration(long d) { this->duration = d; };
	inline void setNbSatelite(int nb) { this->nbSatelite = nb; };
	inline void setArraySat(Satelite * s) { this->arraySat = s; };
	inline void setArrayCol(Collection * c) { this->arrayCol = c; };

private :
	long duration;
	int nbSatelite;
	int nbCollection;
	Satelite * arraySat;
	Collection * arrayCol;
};

```


Ces données sont extraites par la classe DataReceiver

cette dernière s'instancie de cette façon


```cpp
DataReceiver(std::string filename);
```

La string est donnée comme attribut afin de ne pas avoir à passer sans cesse le ifstream entre les différentes méthodes "étapes" de l'extraction
L'extraction est lancée par la méthode

```cpp

SimulationData extractData();

```
