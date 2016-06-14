//10008 - What's Cryptanalysis?	-	Carlo Sartori

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
typedef vector<vii> mii;

const int INF = 10000;

bool comp(pair<char, int> c1, pair<char, int> c2){
	if(c1.second > c2.second)
		return true;
	else if(c1.second == c2.second && c1.first < c2.first)
		return true;

	return false;
}

int main(){
	int t;
	cin >> t;
	int i=0;
	vector< pair<char, int> > letters(26, pair<char, int>(0,0));
	char c;
	while(cin >> c){
		if(c >= 'A' && c <= 'Z')
			i++;
		else{
			c = toupper(c);
			if(c < 'A' || c > 'Z')
				continue;
		}

		letters[c-65].first = c;
		letters[c-65].second +=1;
	}
	
	sort(letters.begin(), letters.end(), comp);
	
	for(int i=0;i<letters.size();i++){
		if(letters[i].first > 0 && letters[i].second > 0)
			cout << letters[i].first << " " << letters[i].second << endl;
		else
			break;
	}
 
	return 0;
}
