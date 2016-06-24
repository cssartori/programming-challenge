//11827 - Maximum GCD	-	Carlo Sartori

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <sstream>

#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;

int gcd(int p, int q) {
	if (q > p) 
		return gcd(q,p);
	if (q == 0) 
		return p;

	return gcd(q, p % q);
}

int main(){
	int N;
	cin >> N;
	string line;
	getline(cin, line); 
	for(int n=0;n<N;n++){
		vi ints;

		getline(cin, line); 
		//printf("LINE:  %s\n", line.c_str());
		istringstream sline(line);
		do{
        	string inp;
        	sline >> inp;
			if(inp == "")
				break;
        	ints.pb(atoi(inp.c_str()));
    	}while(sline);
		
		int maxd = 1;
		for(int i=0;i<ints.size();i++){
			//printf("%i, ", ints[i]);
			for(int j=i+1;j<ints.size();j++){
				//if( i == j) continue;
				//printf("gcd(%i, %i) = %i\n", ints[i], ints[j], gcd(ints[i], ints[j]));
				maxd = max(maxd, gcd(ints[i], ints[j]));
			}
		}

		printf("%i\n", maxd);
	}

	return 0;
}
