//10130 - Supersale	-	Carlo Sulzbach Sartori

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

/*Vector of items' values*/
vi V;
/*Vector of items' weights*/
vi W;
/*The backpack*/
mi backpack;
/*Number of items*/
int n;

int main(){
	/*Number of test cases*/
	int T;
	cin >> T;
	/*For each test case*/
	for(int t=0;t<T;t++){
		cin >> n;
		/*Allocate value and weight vectors*/
		V.assign(n+1, 0);
		W.assign(n+1,0);
		
		/*Reads value and weight for each item i*/
		for(int i=1;i<=n;i++){
			cin >> V[i] >> W[i];
		}
		
		/*Number of people in the group*/
		int g;
		cin >> g;
		/*vector of max weights each person i can carry*/
		vi w(g+1);
		/*Maximum weight a person can carry*/
		int maxw = 0;
		for(int i=1;i<=g;i++){
			cin >> w[i];
			maxw = max(maxw, w[i]);
		}
		/*Backpack for the n items with capacity of maximum weight a person can carry. Position [i][j] is the value maximum value carried by backpack of size j with items 1...i*/
		backpack.assign(n+1, vi(maxw+1, 0));
		
		/*For each item i, and each backpack with size j to max weight*/	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=maxw;j++){
				/*If the item can't be put in the backpack of size j*/
				if(W[i] > j) 
					/*Then, the maximum value a backpack with size j and items <= i can carry is the same as for the previous item i-1*/
					backpack[i][j] = backpack[i-1][j];
				else 
					/*Ohterwise, the value is the bigger between: 
						1) the value of the previous item 
						2) the value of i, V[i], plus the maximum value carried by a backpack with size j-W[i] (adding item i) and the previous item i-1*/
					backpack[i][j] = max(backpack[i-1][j], V[i]+backpack[i-1][j-W[i]]);
			}
		}
		
		/*The total price*/
		int maxp = 0;
		/*Sum all maximum values carried by each person i in group g*/
		for(int i=1;i<=g;i++){
			maxp+=backpack[n][w[i]];
		}
		
		cout << maxp << endl;
		V.clear();
		W.clear();
		backpack.clear();
	}

	return 0;
}
