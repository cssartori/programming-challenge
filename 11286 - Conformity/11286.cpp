//Conformity	- Carlo Sartori (218326)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int N;

	while(cin >> N){
		if(N == 0)
			break;

		map< vector<int>, int > combinations;
		
		for(int i=0;i<N;i++){ //Read combinations
			int read;
			vector<int> comb(5);
			
			for(int j=0;j<5;j++){
				cin >> comb[j];
			}

			sort(comb.begin(), comb.end());
			combinations[comb]++;
		}

		int qt = 0;
		int mp = 0;

		for (map< vector<int>, int>::iterator it = combinations.begin(); it != combinations.end(); it++){
			if(it->second > mp){
				mp = it->second;
				qt = mp;
			}
			else if(it->second == mp){
				qt+=mp;
			}
		}
    			
		cout << qt << endl;
	}


	return 0;
}
