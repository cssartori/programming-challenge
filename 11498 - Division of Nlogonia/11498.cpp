//11498 - Division of Nlogonia	- Carlo Sartori (218326)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int K;
	int N, M;
	
	while(cin >> K){
		if(K == 0)
			break;
		
		cin >> N >> M;

		vector<int> X;
		vector<int> Y;

		for(int i=0;i<K;i++){
			int tempX, tempY;
			cin >> tempX >> tempY;
			X.push_back(tempX);
			Y.push_back(tempY);
		}

		for(int i=0;i<K;i++){
			if(X[i] == N || Y[i] == M)
				cout << "divisa" << endl;
			else if(X[i] < N) { //east
				if(Y[i] < M)
					cout << "SO" << endl;
				else
					cout << "NO" << endl;
			}
			else{
				if(Y[i] < M)
					cout << "SE" << endl;
				else
					cout << "NE" << endl;
			}

		}

	}

	return 0;

}
