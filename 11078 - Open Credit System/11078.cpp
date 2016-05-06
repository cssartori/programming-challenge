//11078 - Open Credit System	-	Carlo Sulzbach Sartori

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
	/*Number of test cases*/
	int T;
	cin >> T;
	/*For each test case t*/
	for(int t=0;t<T;t++){
		/*Number of students*/
		int n;
		cin >> n;
		/*QI of each student*/
		vi qi(n);
		/*Maximum difference*/
		int maxd = -100000;
		
		/*Reads QIs*/
		for(int i=0;i<n;i++){
			cin >> qi[i];
		}
		/*k is the index of the biggest QI found so far*/
		int k = 0;
		maxd = qi[0]-qi[1];

		for(int i=1;i<n;i++){
			/*The maximum difference is itself or the difference between the current biggest QI and the current student i*/
			maxd = max(maxd, qi[k]-qi[i]);
			/*If the current student i has a bigger QI than student k*/
			if(qi[i] > qi[k]){
				/*Update k*/
				k = i;
			}
		}
		/*Print the answer*/
		cout << maxd << endl;
	}

	return 0;
}
