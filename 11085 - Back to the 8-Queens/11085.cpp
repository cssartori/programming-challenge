//11085 - Back to the 8-Queens - Carlo Sartori (218326)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <math.h>

using namespace std;

bool queenOnLine(int line, int q, vector<int> v)
{
	for(int i=0;i<8;i++){
		if(i==q)
			continue;

		if(v[i] == line)
			return true;
	}

	return false;
}

bool queenOnDiagonal(int q, vector<int> v){
	for(int i=0;i<8;i++){
		if(abs(v[q]-v[i]) == abs(q-i))
			return true; 
	}


	return false;	
}


int checkBoard(vector<int> b){
	for(int i=0;i<8;i++){

	}
}


int main() {
	int first;
	int c = 1;
	while(cin >> first){
		vector<int> v(8);
		v[0] = first;

		for(int i=1;i<8;i++)
			cin >> v[i];
		int minm = 99999;
		for(int i=0;i<8;i++){
			vector<int> t = v;
			int q = i;
			int movements_made = 0;
			do{		
				int oldLine = t[q];
				bool movement = false;
				while(queenOnLine(t[q], q, t) || queenOnDiagonal(q, t)){
					//cout << "Trying queen " << i << endl;
					movement = true;
					t[q] += 1;
					if(t[q] == 9)
						t[q] = 1;
					if(t[q] == oldLine)
						break;
				}

				if(movement)
					movements_made++;
				q++;
				q = q%8;
			}while(q != i);

			if(movements_made < minm)
				minm = movements_made;
		}

		cout << "Case " << c <<": "<<minm-1 << endl;
		c++;
	}

	return 0;
}
