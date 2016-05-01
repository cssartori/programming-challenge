//108 - Maximum Sum		-	Carlo S. Sartori (218326)
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

/**
	This problem is solved by the principle given in the book Competitive Programming 3, Steven and Felix.
	We have the original matrix m, with the input values for it. We also have a matrix m' (here called ml)
	with the sum of the areas to the left and up of the point being considered. That is:
	 _______ _______ 
	|		|		|
	|	A	|	B	|
	|_______o1_____o2
	|		|		|
	|	C	|	D	|
	|_______o3_____o4

	In the above matrix, we have 4 points (o1, o2, o3, o4). Their values in m' are:
	o1 = A;
	o2 = A+B;
	o3 = A+C;
	o4 = A+B+C+D;
	Being A, B, C and D submatrix of m.
	
	Then, the value of D can be found as follows:
	 A+B+C+D		(o4)	
 	-A-B			(o2)
	-A	-C			(o3)
	+A				(o1)
	--------------------
	= D				
*/



int main(){
	int n;
	while(cin >> n){
		vector< vector<int> > m(n, vector<int>(n)); //matrix m
		vector< vector<int> > ml(n, vector<int>(n)); //matrix with the sum of areas in m (m')
		
		int max_sum = -127*n*n; //the minimum value possible in any matrix (defined in the problem description)
		
		/*Read the input matrix m and calculate values for ml*/
		for(int i=0;i<n;i++){ 
			for(int j=0;j<n;j++){
				cin >> m[i][j];
				if(i == 0){
					if(j == 0)
						ml[i][j] = m[i][j];
					else
						ml[i][j] = m[i][j] + ml[i][j-1];
				}else if(j==0){
						ml[i][j] = m[i][j] + ml[i-1][j];
				}else{
					ml[i][j] = m[i][j] + ml[i-1][j] + ml[i][j-1] - ml[i-1][j-1];
				}
			}
		}
		

		/*For 4 given points in m', get the value of the submatrix and check if its sum is bigger than the current*/
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=i;k<n;k++){
					for(int l=j;l<n;l++){
						int sum = 0;
						if(i==0){
							if(j==0)
								sum = ml[k][l];
							else
								sum = ml[k][l] - ml[k][j-1];
						}else if(j==0){
							sum = ml[k][l] - ml[i-1][l];
						}else{
							sum = ml[k][l] - ml[i-1][l] - ml[k][j-1] + ml[i-1][j-1];
						}
						/*Is the sum bigger than the current?*/
						if(sum > max_sum)
							max_sum = sum;
					}
				}
			}
		}
		
		/*Print the biggest sum found*/
		cout << max_sum << endl;

	}

}
