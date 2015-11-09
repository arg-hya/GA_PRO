// Gen_Pro1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenAlgo.h"
#include "Header.h"


/*************************************************************************/
/// <b>Function: GenAlgo constructor</b>
///
/// \remarks	Constructor.
/*************************************************************************/
GenAlgo::GenAlgo()
{

}

/*************************************************************************/
/// <b>Function: GenAlgo destructor</b>
///
/// \remarks	destructor.
/*************************************************************************/
GenAlgo::~GenAlgo()
{

}

/*************************************************************************/
/// <b>Function: ShowModal</b>
///
/// \param      hParent     HWND of the parent dialog.
/// \param      pCellData   pointer to the dialog specific cell data.
///
/// \remarks	Displays the GenAlgo dialog and hooks up 
/// 			the message proc for the dialog.
/*************************************************************************/
GenAlgo::Run():
{
	int nPopu, totGen = nGEN;
	bool rslt;

	rslt = InputParams();//INPUT PARAMS
	
	Initialize(); //INITIALIZE	

	do
	{
		nPopu = nPOPU;

		CalFitness();	//CALCUTATE INDIVIDUAL FITNESS 
		
		//avgFitness = GetAvgFitness(POPU);	//CALCULATE AVERAGE FITNESS OF POPULATION

		while ((nPopu -= 2) >= 0)
		{
			//SELECT PARENTS
			GetParents(POPU, Ps, &idx1, &idx2);

			//DO CROSSOVER
			GetChildren(child, POPU, Pc, idx1, idx2);

			//MUTATE
			MutateChildren(child);

			//CALCULATE FITNESS OF OFFSPRINGS
			CalChildrenFitness(child);

			//UPDATE POPULATION
			UpdatePopulation(POPU, child, idx1, idx2);
		}


	} while (--totGen);

	//ShowDude(POPU);
}