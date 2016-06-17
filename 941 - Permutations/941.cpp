//941 - Permutations	-	Carlo Sartori

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

vector<long int> f(21,0);

void factorials(){
	long int res = 1;
	f[0] = 1;
	for(int i=1;i<21;i++){
		res *= i;
		f[i] = res;
	}
}

int main(){
	
	int t;
	cin >> t;
	factorials();
	while(t > 0){
		t--;
		string s;
		long int N;
		cin >> s;
		cin >> N;

		sort(s.begin(), s.end());
		vector<char> perm;

		bool found = false;
		long int k=0;
		long int j=0;
		while(!found){

			if(s.size() == 1){
				perm.pb(s[0]);
				found = true;
			}
			else if(N < ((f[s.size()-1])*(j+1))){
				N = N - ((f[s.size()-1])*(j));
				perm.pb(s[j]);
				s.erase(s.begin()+j);
				j=0;
			}
			else{
				j++;
			}
			
		}

		for(int i=0;i<perm.size();i++){
			cout << perm[i];
		}	
		cout << endl;
	}


	return 0;
}
