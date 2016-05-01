//11496 - Musical Loop	- Carlo Sartori (218326)
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

		vector<int> samples;
		
		//populate array
		for(int i=0;i<N;i++){
			int temp;
			cin >> temp;
			samples.push_back(temp);
		}
		
		int peak = 0;
		if(samples[N-1] < samples[0] && samples[1] < samples[0]){ //0 is local max
			peak++;
		}
		else if(samples[N-1] > samples[0] && samples[1] > samples[0]){
			peak++;
		}

		if(samples[0] < samples[N-1] && samples[N-2] < samples[N-1]){
			peak++;
		}
		else if(samples[0] > samples[N-1] && samples[N-2] > samples[N-1]){
			peak++;
		}


		for(int i=1;i<N-1;i++){
			if(samples[i-1] < samples[i] && samples[i+1] < samples[i]){
				peak++;
			}
			else if(samples[i-1] > samples[i] && samples[i+1] > samples[i]){
				peak++;
			}				

		}

		cout << peak << endl;
		
		
	}

	return 0;

}
