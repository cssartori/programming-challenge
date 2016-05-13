//10003 - Cutting Sticks	-	Carlo Sulzbach Sartori
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

/*Matrix (NxN) of the minimum cost to cut from point i, to j*/
mi minimumCosts;
vi cuts;

/*Calculates the minimum cost to cut from pointLeft to pointRight (two indexes of the cuts vector)*/
int cutCost(int pointLeft, int pointRight){
	/*Can't cut any further*/
	if(pointLeft+1 == pointRight) return 0;
	
	if(minimumCosts[pointLeft][pointRight] != -1) return minimumCosts[pointLeft][pointRight];
	
	int ans = 100000; /*Big number to minimize*/
	
	/*Try all possible cuts between left point and right point*/
	for(int i=pointLeft+1;i<pointRight;i++){
		int cc = cutCost(pointLeft, i) + cutCost(i, pointRight) + (cuts[pointRight]-cuts[pointLeft]);
		if(cc < ans)
			ans = cc;
	}

	minimumCosts[pointLeft][pointRight] = ans;

	return ans;
}

int main(){
    /*Length of the stick*/
	int l;

    while(cin >> l){
        if(l == 0)
            /*End of input*/
            break;

            /*Number of cuts to be made on the stick*/
            int n;
            cin >> n;
            
            /*Points of the cuts. n+2 to add 0 and l*/
            cuts.assign(n+2, 0);
			cuts[0] = 0;
			cuts[n+1] = l;
			minimumCosts.assign(n+2, vi(n+2, -1));				
			
			/*Read input*/
            for(int i=1;i<n+1;i++)
                cin >> cuts[i];	

        	cout << "The minimum cutting is " << cutCost(0, n+1) << "." << endl;
    }
	return 0;
}

