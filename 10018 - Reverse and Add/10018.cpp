//10018 - Reverse and Add	-	Carlo Sartori

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
#include <string>
#include <stdlib.h>

#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;


int main(){
	int N;
	cin >> N;
	for(int n=0;n<N;n++){
		string nums;
		cin >> nums;
		int i=0;		
		while(1){
			i++;
			long int num = stol(nums);
			reverse(nums.begin(), nums.end());
			long int numr = stol(nums);

			long int sum = num+numr;

			string result = to_string(sum);
		
			if(result == string(result.rbegin(), result.rend())){
				cout << i << " " << result << endl;
				break;
			}
			nums = result;
		}
	}	
	
	return 0;
}
