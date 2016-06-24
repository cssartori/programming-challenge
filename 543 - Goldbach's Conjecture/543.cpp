//543 - Goldbach's Conjecture	-	Carlo Sartori

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
#include <sstream>

#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;


vi primes;

int is_prime(int x){
	if(x <= 1) return 0;
	if(x % 2 == 0) return 0;
	int i = 3;
	while(i <= sqrt(x)+1){
		if(x % i == 0) return 0;
		i += 2;
	}

	return 1;
}

void build_primes(){
	for(int i=3;i<1000000;i++){
		if(is_prime(i))
			primes.pb(i);
	}
}

int main(){
	build_primes();
	int n;
	while(cin >> n){
		if(n == 0)
			break;
		
		bool found = true;
		for(int i=0;i<primes.size();i++){
			if(primes[i] >= n){
				found = false;
				break;
			}

			int k = n - primes[i];
			if(is_prime(k)){
				int b = max(k, primes[i]);
				int a = min(k, primes[i]);
				printf("%i = %i + %i\n", n, a, b);
				break; 
			}
		}	

		if(!found){
			printf("Goldbach's conjecture is wrong.\n");
		}
	
	}	

	return 0;
}
