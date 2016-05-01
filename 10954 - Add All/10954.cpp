//Add all	- Carlo Sartori (218326)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		if(N == 0)
			break;

		vector<int> input(N);

		for(int i=0;i<N;i++){
			cin >> input[i];
		}

		sort (input.rbegin(), input.rend());
		
		int cost = 0;

		for(int i=N-1;i>0;i--){
			input[i-1] = input[i] + input[i-1];
			cost += input[i-1];
			input.pop_back();
			sort (input.rbegin(), input.rend());
		}

		cout << cost << endl;
	}

	return 0;

}

