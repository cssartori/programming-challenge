//10172 - The Lonesome Cargo Distributor	- 	Carlo Sartori (218326)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int travel_minutes = 2;
const int carry_minutes = 1;

int main() {
	
	int SETS;
	cin >> SETS;

	while(SETS > 0){
		int N, S, Q;

		cin >> N >> S >> Q;

		stack<int> s; //stack of my truck
		vector< queue<int> > bqueue(N); //queues of the B platforms
		int totalCargo = 0; //total cargo in the airport
		int totalTime = 0; //total time to deliver all cargoes

		for(int i=0;i<N;i++){ //read the cargoes at each platform
			int qi;
			cin >> qi;
			totalCargo += qi;

			for(int j=0;j<qi;j++){ //populate the queue at platform i
				int temp;
				cin >> temp;
				bqueue[i].push(temp);
			}
	
		}	

		int station = 0; //first station
		while(totalCargo > 0){ //while there is still cargo to be carried	
			
			//Unload operation						
			while(s.size() > 0 && (s.top()-1 == station || bqueue[station].size() < Q)){ //while there are cargoes to unload and B queue has space
				if(station == s.top()-1){ //if its tagged to this station, unload to platform A				
					s.pop();
					totalCargo--; //one cargo delivered
					 
				}else{
					bqueue[station].push(s.top());
					s.pop();
				}
				totalTime += carry_minutes;
			}
			
			//load operation
			while(s.size() < S &&  bqueue[station].size() > 0){
				s.push(bqueue[station].front());
				bqueue[station].pop();
				totalTime += carry_minutes;
			}
			
			//circular behaviour
			station++;
			if(station == N)
				station = station%N;
			
			//travel time from station to station
			if(totalCargo != 0)
				totalTime += travel_minutes;
		}	

		cout << totalTime << endl;

		SETS--;
		
	}	

	return 0;
}
