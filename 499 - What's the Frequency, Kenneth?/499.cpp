//499 - What's the frequency	-	Carlo Sartori

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

bool comp(ii c1, ii c2){

	if(c1.second > c2.second)
		return true;
	else if(c2.second > c1.second)
		return false;
	else
		if('A' <= c1.first && c1.first <= 'Z')
			if('A' <= c2.first && c2.first <= 'Z')
				return c1.first < c2.first;
			else
				return true;		
		else
			if('A' <= c2.first && c2.first <= 'Z')
				return false;
			else
				return c1.first < c2.first;
	

}


int main(){
	string inp;
	while(getline(cin, inp)){
		if(inp.size() == 0 )
			continue;

		vii freq(52, ii(0,0));
		for(int i=0;i<52;i++){
			if(i < 26)
				freq[i] = make_pair(i+'A', 0);
			else
				freq[i] = make_pair(i-26+'a', 0);
		}

		for(int i=0;i<inp.size();i++){
			char l = inp[i];
			if('A' <= l && l <= 'Z')
				freq[l-'A'].second = freq[l-'A'].second+1;
			else if( 'a' <= l && l <= 'z')
				freq[l-'a'+26].second = freq[l-'a'+26].second+1;
		}

		sort(freq.begin(), freq.end(), comp);

		int mf = freq[0].second;
		cout << (char)freq[0].first;
		for(int i=1;i<52;i++){
			if(freq[i].second == mf)
				cout << (char)freq[i].first;
		}

		cout << " " << mf << endl;

	}

	return 0;
}
