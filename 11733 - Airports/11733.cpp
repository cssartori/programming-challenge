//11733 - Airports	-	Carlo Sartori

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
typedef vector<vii> mii;

const int INF = 10000;

typedef struct {
	int x; //node 1
	int y; //node 2
	int w; //weight
} edge;

//compare two edges by weight
bool comp(edge e1, edge e2){
	return e1.w < e2.w;
}

vi root;

//get the root of a given node x
int getRoot(int x){
	if(root[x] == x) return x;

	while(root[x] != x)
		x = root[x];

	return x;
}

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N, M, A;
		cin >> N >> M >> A;
		
		vector<edge> edges;
		/*The root of each subtree*/
		root.assign(N*2, 0);
		for(int i=0;i<=N;i++)
			root[i] = i;

		for(int m=0;m<M;m++){
			int a, b, w;
			cin >> a >> b >> w;
			edge e; e.x = a;e.y = b; e.w = w;
			edges.pb(e);		
		}

		int cost = N*A; //all locations have airports
		int nairports = N;
		
		//sort edges by weight in increasing order
		sort(edges.begin(), edges.end(), comp);		
		
		for(int i=0;i<edges.size();i++){
			if(edges[i].w >= A) continue; //only insert edge if the cost is smaller than building an airport

			//if the roots of both vertices are different
			if(getRoot(edges[i].x) != getRoot(edges[i].y)){
				//update roots
				root[getRoot(edges[i].y)] = getRoot(edges[i].x);
				//remove an airport and add the edge
				cost += - A + edges[i].w;
				nairports--;
			}
		}

		cout << "Case #" << t+1 << ": " << cost << " " << nairports << endl;
	}

}

