#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class GenAlgo
{
private:

	/*=================
	TYPE DEFINTIONS :
	=================*/
	struct indiv
	{
		char *fChromo;				//Chromosome String of each individual.
		float fFitness;				//Fittness of each individual.
	};
	typedef struct indiv INDIVIDUAL;
	typedef INDIVIDUAL *POPULATION;        /* array of individuals */
	typedef INDIVIDUAL CHILDREN;        /* array of individuals */

	/*=================
	GLOBAL VARIABLES :
	=================*/
	int	nVAR,						//Number of variables in the obj func.
		nGEN,						//Number of Generations to be run.
		nPOPU,						//Population size.
		lenChromo_var,				//Chromosome length of each variable.
		lenChromo_tot;				//Chromosome length of each individual :: (nVAR * lenChromo_var).
		//indx_f,						//Index of one parent.
		//indx_m;					    //Index of another parent.

	float	 *LW_BND,				//Lower Bound and Higher Bound of each variable.
			 *HG_BND,				//Lower Bound and Higher Bound of each variable.	
			  Pc ,					//Cross-Over Propability.
		      Pm ,					///Mutation Propability.
			  avgFITNESS,			//average fittness of population.
			  BASIC_SEED;			//basic seed for rand().

	POPULATION	POPU = NULL;
	POPULATION	Temp_popu = NULL;
	CHILDREN child3;

	/*=================
	FUNC PROTOTYPES :
	=================*/
	bool InputParams();
	bool Initialize();
	float CalculateFitness(INDIVIDUAL const &individual);
	bool GetParents(int *indx_f, int *indx_m);
	bool CreateChildren(INDIVIDUAL & child1, INDIVIDUAL & child2, const int *indx_f, const int *indx_m);
	bool MutateChildren(INDIVIDUAL & child1);
	bool IdentifyChilds(INDIVIDUAL const & child1, INDIVIDUAL const & child2, const int indx_f, const int indx_m, int const indx);
	bool CopyPopulation();

	int DecodeString(char * fChromo , const int i);

	bool ShowPopu();
	bool ShowDude();
	bool ShowIndividual(INDIVIDUAL const &individual);

public:
	GenAlgo();
	~GenAlgo();
	bool Run();
	float (*Objfunc)(const int *);
};