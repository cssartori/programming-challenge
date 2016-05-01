//11559 - Event Planning
#include <cstdio>
#include <iostream>

using namespace std;

int main(){

	int N, B, H, W;
	

	while(cin >> N >> B >> H >> W){ //Read First line

	int bestPrice = 600000; //bigger than the max budget
	bool hotelAvaliable = false; //there is no hotel available at the begining
		
	for(int h=0;h<H;h++){//for each hotel, read its details
			int p, a[W];
			cin >> p;
			bool enoughBeds = false; //if there is enough beds for all the participants

			for(int i=0;i<W;i++){
				cin >> a[i];
				if(a[i] >= N){ //At least one weekend has enough beds
					enoughBeds = true;
				}
				
			}
			if(!enoughBeds){ //If there is NOT enough beds, they can't stay at the hotel
				continue;
			}
		
			int price = N*p;

			if(price < bestPrice && price <= B){
				bestPrice = price;
				hotelAvaliable = true;
			}					
			
		}

		if(hotelAvaliable){
			cout << bestPrice << endl;
		}
		else{
			cout << "stay home" << endl;
		}
	}

	return 0;
}
