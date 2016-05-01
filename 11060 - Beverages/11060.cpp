//11060 - Beverages	-	Carlo S. Sartori (218326)
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

int main(){
	int n;
	int c=1;
	while(cin >> n){
		map<string, int> names;
		vi sortBev;
		vector<string> vnames(n);
		for(int i=0;i<n;i++){
			string nn;
			cin >> nn;
			names[nn] = i;
			vnames[i] = nn;
		}

		int m;
		cin >> m;
		vector<vi> graph(n, vi(n, 0));
		vi backward(n, 0);

		for(int i=0;i<m;i++){
			string nn1, nn2;
			cin >> nn1 >> nn2;
			/*Avoid overcounting if the same relation appears twice in the input*/
			if(graph[names[nn1]][names[nn2]] == 0)
				backward[names[nn2]]++;
			graph[names[nn1]][names[nn2]] = 1;
			
		}

		vi visited(n, UNVISITED);

		priority_queue<int> q;

		for(int i=0;i<n;i++){
			if(backward[i] == 0){
				q.push(-1*i);
			}
		}
		
		while(!q.empty()){
			int v = -1*q.top(); q.pop();
			sortBev.push_back(v);
			visited[v] = VISITED;
			for(int i=0;i<graph[v].size();i++){
				if(graph[v][i] == 1){
					backward[i]--;
					if(backward[i] == 0)
						q.push(-1*i);
				}
			}
		}
		

		cout << "Case #" << c << ": Dilbert should drink beverages in this order:";
		for(int i=0;i<sortBev.size();i++){
			cout << " " << vnames[sortBev[i]];
		}
		cout << "." << endl << endl;

		c++;
	}
	return 0;
}
