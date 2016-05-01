//10074 - Take the Land	-	Carlo S. Sartori (218326)
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;

int const MINVAL = -10000;

int main(){
	int m, n;
	while(cin >> m >> n){
		if(m == 0 && n==0)
			break;

		mi matrix(m, vi(n, 0));
		int max = -1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				int mij;
				cin >> mij;
				if(i==0){
					if(j==0) matrix[i][j] = mij*MINVAL + (1-mij)*1;
					else matrix[i][j] = matrix[i][j-1] + mij*MINVAL + (1-mij)*1;				
				}else{
					if(j==0) matrix[i][j] = matrix[i-1][j] + mij*MINVAL + (1-mij)*1;
					else matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + mij*MINVAL + (1-mij)*1;
				}
				if(max > matrix[i][j])
					max = matrix[i][j];
			}
		}

		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				for(int k=i+1;k<=m;k++){
					for(int l=j+1;l<=n;l++){
						int area;
						if(i==0){
							if(j==0) area = matrix[k-1][l-1];
							else area = matrix[k-1][l-1] - matrix[k-1][j-1];
						}else{
							if(j==0) area = matrix[k-1][l-1] - matrix[i-1][l-1];
							else area = matrix[k-1][l-1] - matrix[i-1][l-1] - matrix[k-1][j-1] + matrix[i-1][j-1];
						}
						if(area > max)
							max = area;
					}
				}
			}
		}
		if(max < 0)
			max = 0;
		cout << max << endl;
	}

	return 0;
}
