//10935 - Throwing cards away I		- 	Carlo Sartori (218326)
#include <iostream>
#include <queue>

using namespace std;


int main(){

	int N;

	while(cin >> N){
		if(N == 0)
			break;

		queue<int> q;
		vector<int> removed_cards;	
	
		//populate queue with ordered numers 1..N
		for(int i=0;i<N;i++)
			q.push(i+1);

		while(q.size() > 1){
			int r = q.front(); //gets the removed card
			q.pop(); //remove top element
			removed_cards.push_back(r);
			int tb = q.front(); //gets the new top element to insert at bottom
			q.pop(); //removes the top element from the top
			q.push(tb); //inserts the top element in the bottom
		}
			
		cout << "Discarded cards:";
		if(removed_cards.size() > 0){
			int i=0;
			for(i=0;i<removed_cards.size()-1;i++){
				cout << " " << removed_cards[i] << ",";
			}
			cout << " " << removed_cards[i];
		}

		cout << endl;

		cout << "Remaining card: " << q.front() << endl;
	}

	return 0;

}
