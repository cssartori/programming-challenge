//10252 - Common Permutation	-	Carlo Sartori

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

int main(){
	string s1;
	string s2;

	while(getline(cin, s1) && getline(cin, s2)){
		vi c1(26, 0);
		vi c2(26, 0);
		
		for(int i=0;i<s1.size();i++)
			c1[s1[i]-'a'] += 1;

		for(int i=0;i<s2.size();i++)
			c2[s2[i]-'a'] += 1;
		
		vector<char> x;
		for(int i=0;i<26;i++){
			int n = min(c1[i], c2[i]);
			for(int j=0;j<n;j++){
				cout << (char)(i+'a');
				x.pb(i+'a');
			}
		}
		
		cout << endl;
	}	
	

	return 0;
}


