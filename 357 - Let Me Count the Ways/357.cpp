//357 - Let me count the ways		-	Carlo S. Sartori (218326)
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

/*Coin values*/
int values[5] = {1, 5, 10, 25, 50};

int main(){
	int n;
	vector<int> input;
	/*The maximum value entered (starts with -1)*/
	int max = -1;
	/*First get all the input values*/
	while(cin >> n){
		input.push_back(n);
		/*Update maximum value if bigger*/
		if( n > max)
			max=n;
	}
	
	n = max;
	/*Number of possible combinations*/
	long unsigned int combinations = 1;
	/*Matrix (5xMax) of the number of possible combinations to reach each value, from 0 to max value.
	  Each line is a coin (there are 5 types of coins).
	*/
	vector< vector<long unsigned int> > coins(5, vector<long unsigned int>(n+1, 0));
	
	/*The line of coin 0 (value 1) is all 1*/
	for(int i=0;i<=n;i++)
		coins[0][i] = 1;
		
	/*Compute the number of combinations possible for each other coin (5, 10, 25 and 50) based on the previous coins*/	
	for(int i=1;i<5;i++){
		for(int k=0;k<=n;k++){
			if(values[i] > k)
				coins[i][k] += coins[i-1][k];
			else
				coins[i][k] +=  coins[i-1][k]+coins[i][k-values[i]];
		}	
	}
	
	/*For each input, get the number of possible combinations to reach input value*/
	for(int i=0;i<input.size();i++){
		combinations = coins[4][input[i]];		

		if( combinations == 1)
			cout << "There is only 1 way to produce " << input[i] << " cents change." << endl;
		else
			cout << "There are " << combinations << " ways to produce " << input[i] << " cents change." << endl;
	}
	
	return 0;
}
