//572 - Oil Deposits	-	Carlo Sulzbach Sartori

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

const int VISITED = 1;
const int UNVISITED = 0;

int main(){
	int m, n;
	while(cin >> m >> n){
		if(m == 0)
			break;
		
		vector< string > matrix(m);

		for(int i=0;i<m;i++){
   			cin >> matrix[i];
		}
		
		mi state(m, vi(n, UNVISITED));
		
		int oils = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j] == '*' || state[i][j] == VISITED) continue;

				queue<ii> q;	
				q.push(ii(i,j));
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if(state[x][y] == VISITED) continue;
					state[x][y] = VISITED;
					if(x < m-1 && matrix[x+1][y] == '@' && state[x+1][y] == UNVISITED)
						q.push(ii(x+1, y));
					if(x > 0 && matrix[x-1][y] == '@' && state[x-1][y] == UNVISITED)
						q.push(ii(x-1, y));
					if(y < n-1 && matrix[x][y+1] == '@' && state[x][y+1] == UNVISITED)
						q.push(ii(x, y+1));
					if(y > 0 && matrix[x][y-1] == '@' && state[x][y-1] == UNVISITED)
						q.push(ii(x, y-1));
					if(x < m-1 && y < n-1 && matrix[x+1][y+1] == '@' && state[x+1][y+1] == UNVISITED)
						q.push(ii(x+1, y+1));
					if(x < m-1 && y > 0 && matrix[x+1][y-1] == '@' && state[x+1][y-1] == UNVISITED)
						q.push(ii(x+1, y-1));
					if(x > 0 && y > 0 && matrix[x-1][y-1] == '@' && state[x-1][y-1] == UNVISITED)
						q.push(ii(x-1, y-1));
					if(x > 0 && y < n-1 && matrix[x-1][y+1] == '@' && state[x-1][y+1] == UNVISITED)
						q.push(ii(x-1, y+1));
				}
				oils++;
			}
		}

		cout << oils << endl;

	}
}
