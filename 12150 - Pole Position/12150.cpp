//12150 - Pole Position	-	Carlo Sartori

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

#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;

char S[10010];

bool cmp(int a, int b) { return strcmp(S + a, S + b) < 0; 

int main(){
	
	int N;
	bool first = true;
	while(cin >> N){
		if( N == 0)
			break;
		
		vi grid(100000, -1);
		bool cantfind = false;

		for(int n=0;n<N;n++){
			int c, p;
			cin >> c >> p;

			if(!cantfind){
				int k = n+p;

				if(k < 0 || k >= N || grid[k] != -1){
					cantfind = true;
					continue;
				}
				grid[k] = c;
			}
		}
		
		if(cantfind)
			cout << -1;
		else{
			int k = 0;
			for(int i=0;i<100000;i++)
				if(grid[i] != -1){
					k++;
					cout << grid[i];
					if(k == N) break;
					cout << " ";
				}
		}
		
		cout << endl;
	}

	return 0;
}
