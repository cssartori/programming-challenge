//507 - Jill Rides Again	-	Carlo Sulzbach Sartori
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int b;
	cin >> b;
	int r=1;
	while(r <= b){
		int s;
		cin >> s;
		int assessment;
		int ans = 0;
		int sum = 0;
		int im = 0;
		int ic = 0;	
		int jm = 0;
		bool updti = true;

		for(int i=0;i<s-1;i++){
			cin >> assessment;
			sum += assessment;
			//cout << "sum " << sum << endl;
			if(sum > ans){
				ans = sum;
				jm = i;
				if(updti){ im = ic; updti = false;}
			}else if(sum == ans){
				if(i - ic > jm - im){
					im = ic;
					jm = i;
				}
			}

			if(sum < 0){ sum = 0; ic = i+1; updti = true;}
		}
		

		if(ans <= 0)
			cout << "Route " << r << " has no nice parts" << endl;
		else
			cout << "The nicest part of route " << r << " is between stops " << im+1 << " and " << jm+2 << endl;

		r++;
	}
	
	return 0;
}
