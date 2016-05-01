//562 - Dividing Coins		-	Carlo S. Sartori (218326)
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

/**
	For this problem, solved with Dynamic Programming, we use a vector of booleans with size 0...TOTAL, where TOTAL is the 
	total ammount of money in the bag.

	This way, for a bag with coins: 2, 3 and 5
	Total: 10
	Vector:
	Value		0 1 2 3 4 5 6 7 8 9 10
	Boolean		0 0 1 1 0 1 0 1 1 0 1

	As you can see, each value has its value considering if its possible to reach the given value with the coins available.
	For example, values 2, 3 and 5 are reachable because those are the values of the coins. Value 7 is 2+5. Value 8 3+5.
	Value 10 is 2+3+5.

	Given one of this values (value of person 1) we can get the value for the other person (person 2) as following: TOTAL-value1
	With the value o person 2 we can check which value gives the least difference between values 1 and 2.	

*/

int main(){
	
	int N;
	/*Number of test cases*/
	cin >> N;
	
	/*For each test case in the input file*/
	for(int n=0;n<N;n++){
		int M;
		/*Number of coins in the bag*/
		cin >> M;
		vector<int> coin(M);
		/*Total ammount of money in the bag*/
		int total = 0;
		/*Read the value of each coin and update the total value*/
		for(int m=0;m<M;m++){
			cin >> coin[m];
			total += coin[m];
		}
		
		/*Vector representing if a given value (fom 0 to total) is possible to reach with the coins available*/
		vector< bool > combinations(total+1, false);
		
		/*Minimum difference between the ammounts person 1 and person 2 receive. It can't be bigger than total.*/
		int minimum_difference = total;
		
		/*Fill the vector of possibilites*/		
		for(int i=0;i<M;i++){
			for(int j=total-coin[i];j>=0;j--){
				if(combinations[j] == true){
				/*Set the value reached by coin i as reacheable*/
					combinations[j+coin[i]] = true;
					/*Check if this difference is not better than the current one*/
					int diff = abs(total-2*(coin[i]+j));
					if(diff < minimum_difference)
						minimum_difference = diff;
				}
			}
			/*A coin will always reach its own value*/
			combinations[coin[i]] = true;
			/*Check if the coin i itself does not guarantee a better difference*/
			if(abs(total-2*coin[i]) < minimum_difference)
				minimum_difference = abs(total-2*coin[i]);
		
		}
		/*Display the minimum difference found*/
		cout << minimum_difference << endl;
	}


}
