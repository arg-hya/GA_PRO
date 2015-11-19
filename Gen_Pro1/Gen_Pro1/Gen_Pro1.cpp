// Gen_Pro1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenAlgo.h"

#define square(x)  ((x)*(x))

float objective(int const *x)
{

	float term1, term2, term3;
	float g, penalty_coef;

	//if (x == NULL) error_ptr_null("x in objective()");


	term1 = (float)(x[0] + x[1]);
	term2 = (float)((x[0] + x[1] * x[1] - 7.0)*(x[0] + x[1] * x[1] - 7.0));
	term3 = term1 + term2;

	penalty_coef = 0.0;
	g = (float)((square(x[0] - 5.0) + square(x[1])) / 26.0 - 1.0);
	if (g < 0.0) term3 = term3 + penalty_coef * g * g;
	return (float)(term1);

}



int main(int argc, _TCHAR* argv[])
{
	GenAlgo *a = new GenAlgo();

	a->Objfunc = objective;		//Passes the objective function	

	a->Run();			//Runs it


	return 0;
}

