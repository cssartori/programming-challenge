//10943 - How do you add?	-	Carlo Sulzbach Sartori

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

#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned int uint;

/*Matrix of ways to sum n with k numbers (NxK)*/
vector< vector<uint> > ways;

/*Count the number of ways to sum n with k numbers*/
uint countWays(int n, int k){
	if( k == 1 ) {ways[n][k] = 1; return 1;}
	if( ways[n][k] != 0) return ways[n][k];
	
	uint counter = 0;

	for(int i=0;i<=n;i++){
		counter = (counter + countWays(n-i, k-1));
	}
	counter = counter%1000000;
	ways[n][k] = counter;
	return counter;
}



int main(){
	int n, k;

	ways.assign(102, vector<uint>(102, 0));
	/*Pre calculate all possible combinations*/
	countWays(101, 101);

	while(cin >> n >> k){
		if(n == 0 && k == 0)
			break;

		cout << ways[n][k] << endl;
	}


	return 0;

}
