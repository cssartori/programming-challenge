//I can guess the Data Stucture - 	Carlo Sartori (218326)

#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

int main(){

	int N;


	while(cin >> N){
		if(N == 0)
			continue;
		
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		
		bool isQueue = true, isStack = true, isPriorityQ = true;

		for(int i=0;i<N;i++){
			int c, d;
			cin >> c >> d;

			if(c == 1){ //insertion
				q.push(d);
				s.push(d);
				pq.push(d);
			}else if(c == 2){ //removal
				int f, t, tp;
				if(!q.empty() && isQueue){
					f = q.front(); q.pop();
					if(f != d)	isQueue = false;
				}else if(q.empty()) isQueue = false;

				if(!s.empty() && isStack){
					t = s.top(); s.pop();
					if(t != d) isStack = false;
				}else if(s.empty()) isStack = false;

				if(!pq.empty() && isPriorityQ){
					tp = pq.top(); pq.pop();
					if(tp != d) isPriorityQ = false;
				}else if(pq.empty()) isPriorityQ = false;
			}
		}

		if(isQueue && !isStack && !isPriorityQ) cout << "queue" << endl;
		else if(!isQueue && isStack && !isPriorityQ) cout << "stack" << endl;
		else if(!isQueue && !isStack && isPriorityQ) cout << "priority queue" << endl;
		else if(!isQueue && !isStack && !isPriorityQ) cout << "impossible" << endl;
		else cout << "not sure" << endl;

	}

	return 0;
}

