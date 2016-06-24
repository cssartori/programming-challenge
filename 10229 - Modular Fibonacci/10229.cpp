//10229 - Modular Fibonacci	-	Carlo Sartori

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

typedef vector<long unsigned int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;

long unsigned int d;


mi powm(mi m, long unsigned int n){
	if(n == 1) return m;
	mi r(2, vi(2, 0));
	if(n == 2){
		r[0][0] = m[0][0]*m[0][0] + m[0][1]*m[1][0];
		r[0][1] = m[0][0]*m[0][1] + m[0][1]*m[1][1];
		r[1][0] = m[1][0]*m[0][0] + m[1][1]*m[1][0];
		r[1][1] = m[1][0]*m[0][1] + m[1][1]*m[1][1];
		return r;
	}
	if(n % 2 != 0){
		mi mn1 = powm(m, n-1);
		r[0][0] = m[0][0]*mn1[0][0] + m[0][1]*mn1[1][0];
		r[0][1] = m[0][0]*mn1[0][1] + m[0][1]*mn1[1][1];
		r[1][0] = m[1][0]*mn1[0][0] + m[1][1]*mn1[1][0];
		r[1][1] = m[1][0]*mn1[0][1] + m[1][1]*mn1[1][1];
		return r;
	}
	
	return powm(powm(m, n/2), 2);
}

long unsigned int fibn(long unsigned int n){
	
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;
	
	mi b(2, vi(2, 0));
	b[0][1] = 1;
	b[1][0] = 1;
	b[1][1] = 1;

	b = powm(b, n);

	return b[0][1];
}


int main(){
	long unsigned int n;
	long unsigned int m;

	while(cin >> n >> m){
		d = (long unsigned int)powl(2, m);
		//printf("div = %li\n", d);
		printf("%li\n", fibn(n) % d);
	}

	return 0;
}
