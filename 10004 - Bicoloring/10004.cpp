//10004 - Bicoloring	-	Carlo S. Sartori (218326)
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
    
typedef vector<int> vi;  

const int WHITE = 1;
const int BLACK = 2;
const int UNCOLORED = 3;

vector<vi> graph;
vi colors;

bool dfs(int v, int color){
	if(colors[v] == color)
		return false;
	
	colors[v] = color;
	vi nv = graph[v];
	bool bicolorable = true;
	for(int i=0;i<nv.size();i++){
		if(colors[nv[i]] == color)
			return false;
		else if(colors[nv[i]] == UNCOLORED){
			if(color == WHITE)
				bicolorable = dfs(nv[i], BLACK);
			else
				bicolorable = dfs(nv[i], WHITE);

			if(bicolorable == false)
				return false;
		}
	}

	return bicolorable;
}

int main(){
	int n;
	while (cin >> n){
		if(n == 0)
			break;

		graph.assign(n, vi());
		colors.assign(n, UNCOLORED);

		int l;
		cin >> l;
		for(int i=0;i<l;i++){
			int n1, n2;
			cin >> n1 >> n2;
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}
		bool bicolorable = dfs(0, WHITE);
		
		if(bicolorable){
			cout << "BICOLORABLE." << endl;
		}else{
			cout << "NOT BICOLORABLE." << endl;
		}
	}

}
