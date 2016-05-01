//Snakes and ladders

#include <cstdio>
#include <iostream>

using namespace std;

int main(){

	int numGames;
	cin >> numGames; //number of games to be read
	int g=0;

	while(g < numGames){ //for each game
		int board[100];
		for(int i=0;i<100;i++){
			board[i]=-1;
		}
		
		int a, b, c;
		
		cin >> a >> b >> c;

		int position[a];
		for(int i=0;i<a;i++)
			position[i]=0;

		for(int k = 0; k<b;k++){ //populate the board with snakes and ladders
			int m,t; //mouth and tail of the snake
			cin >> m >> t;
			board[m-1] = t-1;
		}
		int player = 0;
		bool winner = false; //if there is a winner
		int d;
		for(d=0;d<c;d++){ //for each die roll d
			int roll;
			cin >> roll;
			
			position[player] += roll;

			if(position[player] >= 99){
				position[player] = 99;
				winner = true;
				break;
			}
			else if(board[position[player]] != -1){
				position[player] = board[position[player]];
				
				if(position[player] >= 99){
					position[player] = 99;
					winner = true;
					break;
				}
			}

			player++;
			player = player%a;				
		}

		
		for(int i=0;i<a;i++){
			cout << "Position of player " << i+1 << " is " << position[i]+1 << "." << endl;
		}

		if(d<c-1){
			int temp;
			for(;d<c-1;d++){
				cin >> temp;
			}
		}

		g++;
	}

	return 0;		

}

