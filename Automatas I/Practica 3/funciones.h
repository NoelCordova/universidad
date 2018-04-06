#ifndef _funciones.h_
#define _funciones.h_
#include <vector>
#include <string>

using namespace std;

typedef struct{
	int header;
	int former;
	int latter;
}rule;

typedef std::vector<rule> grammar;

//------------------------

void grammar_generate();

bool CYK(grammar &, string &);

#endif
