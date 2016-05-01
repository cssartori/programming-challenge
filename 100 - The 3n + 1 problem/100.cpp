//100 - The 3n + 1 problem
#include <cstdio>
#include <iostream>

using namespace std;
int main(){
	
	unsigned int i, j;
	
	while(cin >> i >> j){
		
		unsigned int min = i, maxi = j;
		if(i > j) {min = j; maxi = i;}
		unsigned int max = 0;
		unsigned int n=min, temp = min;
		
		while(n <= maxi){
			unsigned int iter = 0;

			while(n != 1){
				iter++;
				if(n%2 != 0) n = 3*n+1;
				else n = n/2;		
			}

			n=temp+1; temp=n;

			if(iter > max) max = iter;
		}

		cout << i << " " << j << " "<< max+1 << endl; //Sum +1 because of the printed "1" that is not taken into account

	}

	return 0;

}
