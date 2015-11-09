#pragma once

class GenAlgo
{
private:

	/*=================
	GLOBAL VARIABLES :
	=================*/
	int nVAR;											//Number of variables in the obj func.
	float *LW_BND, *HG_BND;					//Lower Bound and Higher Bound of each variable.
	int nGEN ;
	int nPOPU ;
	int Ps ;
	int Pc;
	float avgFITNESS;



	/*=================
	TYPE DEFINTIONS :
	=================*/
	struct indiv
	{
		float *fChromo;				//Chromosome String of each individual.
		float fFitness;				//Fittness of each individual.
	};
	typedef struct indiv INDIVIDUAL;
	typedef INDIVIDUAL *POPULATION;        /* array of individuals */

	/*=================
	FUNC PROTOTYPES :
	=================*/
	bool InputParams();
	bool Initialize();
	//int GetAvgFitness();
	void CalFitness();
	void GetParents(POPULATION &POPU, int Ps, int * idx1, int * idx2);
	void GetChildren(CHILDREN &child, POPULATION &POPU, int Pc, int idx1, int idx2);
	void CalChildrenFitness(CHILDREN &child);
	void UpdatePopulation(POPULATION &POPU, CHILDREN &child, int idx1, int idx2);
	//void ShowDude(POPULATION &POPU);

	void MutateChildren(CHILDREN &child);

	int GaussDist(int *fitness, int size);
	int UniDist(int *table, int max);

public:
	GenAlgo();
	~GenAlgo();
	bool Run;
};