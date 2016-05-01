//10276 -  Hanoi Tower Troubles Again! - Carlo Sartori (218326)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <math.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	for(int t=0;t<T;t++){
		int N;
		cin >> N;
		vector< stack<int> > pegs(N, stack<int>());
		bool failed = false;
		int ball = 1;
		while(!failed){
			int i;
			for(i=0;i<N;i++){
				if(pegs[i].empty()){
					pegs[i].push(ball);
					break;
				}else if(pow((int)sqrt(pegs[i].top()+ball),2) == pegs[i].top()+ball){
					//cout << "Inserindo " << ball << " com " << pegs[i].top() << " em " << i+1 << endl;
					pegs[i].push(ball);
					break;
				}
			}
			if(i == N){
				failed = true;
			}else{
				ball++;
			}
		}
		cout << ball-1 << endl;
	}

	return 0;

}
