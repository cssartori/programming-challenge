//10047 - Monocycle	-	Carlo S. Sartori (218326)
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
    
typedef vector<int> vi; 

const int VISITED = 1;
const int UNVISITED = 2;

const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

const int INF = 100000;

const int GREEN = 0;
const int BLACK = 1;
const int RED = 2;
const int BLUE = 3;
const int WHITE = 4;


int main(){
	int m, n, c=1;
	while(cin >> m >> n){
		if(m==0 && n==0)
			break;
		
		vector<string> matrix(m);
		int si, sj;
		int ti, tj;
		for(int i=0;i<m;i++){
			cin >> matrix[i];
			for(int j=0;j<n;j++){
				if(matrix[i][j] == 'S'){ si=i; sj=j;}
				else if(matrix[i][j] == 'T'){ ti=i; tj=j;}
			}
		}
		
		map<vi, int> dist_s;
		
		vi istate(4);
		istate[0] = si; istate[1] = sj; istate[2] = N; istate[3] = GREEN;
		queue<vi> q;
		queue<int> dp;
		q.push(istate);
		dp.push(0);
		
		while(!q.empty()){
			vi state = q.front(); q.pop();
			int d = dp.front(); dp.pop();
			if(dist_s.count(state) > 0 && dist_s[state] <= d+1) continue;
			dist_s[state] = d+1;
			if(state[0] == ti && state[1] == tj && state[3] == GREEN) continue;
			//try the neighbors neighbors
			if(state[2] == N){
				vi nstate(4);
				/*tries to go forward*/
				if(state[0] > 0 && matrix[state[0]-1][state[1]] != '#'){
					nstate[0] = state[0]-1; nstate[1] = state[1]; nstate[2] = N; nstate[3] = (state[3]+1)%5;
					q.push(nstate); dp.push(dist_s[state]);
				}
				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = W; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = E; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

			}else if(state[2] == E){
				vi nstate(4);
				/*tries to go forward*/
				if(state[1] < n-1 && matrix[state[0]][state[1]+1] != '#'){
					nstate[0] = state[0]; nstate[1] = state[1]+1; nstate[2] = E; nstate[3] = (state[3]+1)%5;
					q.push(nstate); dp.push(dist_s[state]);
				}
				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = N; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = S; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

			}else if(state[2] == S){
				vi nstate(4);
				/*tries to go forward*/
				if(state[0] < m-1 && matrix[state[0]+1][state[1]] != '#'){
					nstate[0] = state[0]+1; nstate[1] = state[1]; nstate[2] = S; nstate[3] = (state[3]+1)%5;
					q.push(nstate); dp.push(dist_s[state]);
				}
				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = W; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);
			
				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = E; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

			}else if(state[2] == W){
				vi nstate(4);
				/*tries to go forward*/
				if(state[1] > 0 && matrix[state[0]][state[1]-1] != '#'){
					nstate[0] = state[0]; nstate[1] = state[1]-1; nstate[2] = W; nstate[3] = (state[3]+1)%5;
					q.push(nstate); dp.push(dist_s[state]);
				}
				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = N; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

				nstate[0] = state[0]; nstate[1] = state[1]; nstate[2] = S; nstate[3] = state[3];
				q.push(nstate); dp.push(dist_s[state]);

			}	
		}

		int min = INF;
		vi fstate(4);
		fstate[0] = ti; fstate[1] = tj; fstate[3] = GREEN;
		for(int i=0;i<4;i++){
			fstate[2] = i;
			if(dist_s.count(fstate) > 0){
				if(dist_s[fstate] < min)
					min = dist_s[fstate];
			}
		}
		
		if(c != 1)
			cout << endl;

		if(min == INF)
			cout << "Case #" << c << endl << "destination not reachable" << endl;
		else
			cout << "Case #" << c << endl << "minimum time = " << min-1 << " sec" << endl;
		
		c++;

	}	

	return 0;
}
