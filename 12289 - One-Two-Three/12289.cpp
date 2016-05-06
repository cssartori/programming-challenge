//12289 -One-Two-Three	-	Carlo Sulzbach Sartori

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
	/*Number of words written*/
	int N;
	cin >> 	N;
	
	/*Vector of the words*/
	vector<string> words(N);
	for(int i=0;i<N;i++)
		cin >> words[i];

	/*Number corresponding to the word*/
	vi num(N);

	for(int i=0;i<N;i++){
		/*If word i has size greater than 3, it can only be "three"*/
		if(words[i].size() > 3)
			num[i] = 3;
		/*if a word starts with "on", it is "one"*/
		else if(words[i][0] == 'o' && words[i][1] == 'n')
			num[i] = 1;
		/*if a word ends with "ne", it is "one"*/
		else if(words[i][1] == 'n' && words[i][2] == 'e')
			num[i] = 1;
		/*if a word starts with "o" and ends with "e", it is "one"*/
		else if(words[i][0] == 'o' && words[i][2] == 'e')
			num[i] = 1;
		/*if a word starts with "tw", it is "two"*/
		else if(words[i][0] == 't' && words[i][1] == 'w')
			num[i] = 2;
		/*if a word ends with "wo", it is "two"*/
		else if(words[i][1] == 'w' && words[i][2] == 'o')
			num[i] = 2;
		/*if a word starts with "t" and ends with "o", it is "two"*/
		else if(words[i][0] == 't' && words[i][2] == 'o')
			num[i] = 2;

		cout << num[i] << endl;
	}

	return 0;

}
