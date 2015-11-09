// Gen_Pro1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenAlgo.h"


int main(int argc, _TCHAR* argv[])
{
	GenAlgo *a = new GenAlgo();

	a->Objfunc();		//Passes the objective function

	a->Run();			//Runs it


	return 0;
}

