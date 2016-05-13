//10405 - Longest Common Subsequence	-	Carlo Sulzbach Sartori

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

int main(){
	string sa;
	string sb;
	
	/*Reads the pair of strings, must use getline() because some strings may be empty*/
	while(getline(cin, sa) && getline(cin, sb)){
		/*Add a virtual character at the beggining so that the string starts at index 1, not 0*/
		sa = "_"+sa;
		sb = "_"+sb;
		
		/*Matrix of subsequence lenghts*/
		mi sl(sa.length(), vi(sb.length(), 0));
		
		for(int i=1;i<sa.length();i++){
			for(int j=1;j<sb.length();j++){
				if(sa[i] == sb[j])
					sl[i][j] = sl[i-1][j-1]+1;
				else
					sl[i][j] = max(sl[i-1][j], sl[i][j-1]);
			}
		}

		cout << sl[sa.length()-1][sb.length()-1] << endl;
		
	}
	return 0;

}
