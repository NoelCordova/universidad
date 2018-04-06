#include "funciones.h"
#include <vector>
#include <set>
#include <map>

typedef std::vector<rule> grammar;
grammar g;
rule DaRules;

typedef std::set<int> Set;
typedef std::map<int, Set> Row;
typedef std::map<int, Row> Table;

std::set<int>::iterator it1;
std::set<int>::iterator it2;

Table N;


bool CYK(grammar &g, string &w){
	//REGLA 1: S-> x
	DaRules.header= 'S';
	DaRules.former= 'x';
	DaRules.latter= 0;

	g.push_back(DaRules);

	//REGLA 2: S-> D1D2
	DaRules.header= 'S';
	DaRules.former= 201;
	DaRules.latter= 202;

	g.push_back(DaRules);

	//REGLA 3: D1-> l
	DaRules.header= 201;
	DaRules.former= 'l';
	DaRules.latter= 0;

	g.push_back(DaRules);

	//REGLA 4: D2-> SR
	DaRules.header= 202;
	DaRules.former= 'S';
	DaRules.latter= 'R';

	g.push_back(DaRules);

	//REGLA 5: R-> D3D2
	DaRules.header= 'R';
	DaRules.former= 203;
	DaRules.latter= 202;

	g.push_back(DaRules);

	//REGLA 6: D3-> c
	DaRules.header= 203;
	DaRules.former= 'c';
	DaRules.latter= 0;

	g.push_back(DaRules);

	//REGLA 7: R-> r
	DaRules.header= 'R';
	DaRules.former= 'r';
	DaRules.latter= 0;

	g.push_back(DaRules);

	//Variables para el algoritmo de CYK
	int n, i, j, k, comp, conG;

	n= w.length();

	for(i=1; i<=n; i++){
		for(comp=0; comp<=g.size(); comp++){
			if(w[i-1] == g[comp].former){
				N[i][1].insert(g[comp].header);
			}
		}
	}

	for(j=2; j<=n; j++){
		for(i=1; i<=n-j+1; i++){
			for(k=1; k<=j-1; k++){

				//--------------------------------------------------------------
				for(it1= N[i][k].begin(); it1!=N[i][k].end(); ++it1){

					for(it2= N[i+k][j-k].begin(); it2!=N[i+k][j-k].end(); ++it2){
						for(conG=0; conG<g.size(); conG++){
							/*Prueba de membres�a*/
							if((*it1==g[conG].former) && (*it2==g[conG].latter)){
								N[i][j].insert(g[conG].header);
							}
						}
					}
				}
				//--------------------------------------------------------------

			}
		}
	}

	it2= N[1][n].begin();

	if(*it2 == 'S') return true;
	else return false;
}
