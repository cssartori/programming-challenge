//10305 - Ordering Tasks	-	Carlo Sulzbach Sartori

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
	int m, n;
	while(cin >> n >> m){
		if(n == 0 && m == 0)
			break;
		
		/*Adjacency list*/
		mi adjl(n, vi());
		/*Number of nodes that arrive at node i*/
		vi backward(n, 0);
		
		/*Read task relations*/
		for(int i=0;i<m;i++){
			int a, b;
			cin >> a >> b;
			/*a is adjacent to b*/
			adjl[a-1].pb(b-1);
			/*node a arrives at node b*/
			backward[b-1]++;
		}
		
		/*queue of nodes to be visited*/
		queue<int> q;
		/*Array indicating if a node i has been already visited*/
		vi visited(n, 0);
		
		/*Get all nodes that don't have any node arriviing at it*/
		for(int i=0;i<n;i++){
			if(backward[i] == 0){
				q.push(i);

			}
		}
		
		/*Queue with the final order of the tasks*/
		queue<int> order;
		/*While there are nodes to be visited*/
		while(!q.empty()){
			int v = q.front(); q.pop();
			order.push(v);
			visited[v] = 1;
			/*Get all adjacent nodes to v*/
			for(int i=0;i<adjl[v].size();i++){
				/*Removes v*/
				backward[adjl[v][i]]--;
				/*If no node arrives at node i adjacent to v*/
				if(visited[adjl[v][i]] == 0 && backward[adjl[v][i]] == 0){
					q.push(adjl[v][i]);
				}
			}
		}
		
		/*Print solution*/
		while(!order.empty()){
			cout << order.front()+1 << " ";
			order.pop();
		}
		cout << endl;
	}	

	return 0;
}
