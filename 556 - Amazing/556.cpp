//Amazing

#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#define MAZE_WALL -1

#define DIR_EAST 0
#define DIR_NORTH 1
#define DIR_WEST 2
#define DIR_SOUTH 3

using namespace std;


bool isRobotBack(int robotX, int robotY, int startX, int startY){
	if(robotX == startX && robotY == startY)
		return true;

	return false;
}

int turn(int direction){
	return ((direction+1)%4);
}

bool step(vector< vector<int> > maze, int b, int w, int *robotX, int *robotY, int *direction){
	int rX = *robotX, rY = *robotY;
	int rightDiagX, rightDiagY, sX, sY, newDirection;

	switch(*direction){
		case DIR_EAST:
			rX++; 
			rightDiagX = rX-1;
			rightDiagY = rY+1;
			sX=rX;
			sY=rY+1;
			newDirection = DIR_SOUTH;
			break;
		case DIR_NORTH:
			rY--; 
			rightDiagX = rX+1;
			rightDiagY = rY+1;
			sX=rX+1;
			sY=rY;
			newDirection = DIR_EAST;
			break;
		case DIR_WEST:
			rX--; 
			rightDiagX = rX+1;
			rightDiagY = rY-1;
			sX=rX;
			sY=rY-1;
			newDirection = DIR_NORTH;
			break;
		case DIR_SOUTH:
			rY++; 
			rightDiagX = rX-1;
			rightDiagY = rY-1;
			sX=rX-1;
			sY=rY;
			newDirection = DIR_WEST;
			break;
	}

	if(maze[rY][rX] == MAZE_WALL){
		return false;
	}
	else{
		if(maze[sY][sX] != MAZE_WALL && maze[rightDiagY][rightDiagX] == MAZE_WALL){
			*direction = newDirection;
		}
		*robotX = rX;
		*robotY = rY;
		return true;
	}
}

void printResults(vector< vector<int> > maze, int b, int w){
	int zero = 0, once = 0, twice = 0, thrice = 0, fourtimes = 0;

	for(int i=1;i<b+1;i++){
		for(int j=1;j<w+1;j++){
			if(maze[i][j] == 0)
				zero++;
			else if(maze[i][j] == 1)
				once++;
			else if(maze[i][j] == 2)
				twice++;
			else if(maze[i][j] == 3)
				thrice++;
			else if(maze[i][j] == 4)
				fourtimes++;

		}
	}

	cout << right << setw(3) << zero << right << setw(3) << once << right << setw(3) << twice << right << setw(3) << thrice << right << setw(3) << fourtimes << endl;
}

void simulate(vector< vector<int> > maze, int b, int w){
	int startX = 1, startY=b; //Start points to which the robot should return

	int robotX = startX; //starts at column zero
	int robotY = startY; //Starts at last row
	int direction = DIR_EAST; //Robot starts going east

	while(!step(maze, b, w, &robotX, &robotY, &direction))
		direction = turn(direction);

	maze[robotY][robotX] += 1;

	while(!isRobotBack(robotX, robotY, startX, startY)){
		while(!step(maze, b, w, &robotX, &robotY, &direction))
			direction = turn(direction);

		maze[robotY][robotX] += 1;
	}

	printResults(maze, b, w);

}


int main(){

	int b, w;
	while(cin >> b >> w){
		if(b == 0 && w == 0) //End of input
			break;

		vector< vector<int> > maze(b+2, vector<int>(w+2));
		
		for(int i=1;i<b+1;i++){ //Read maze configuration
			for(int j=1;j<w+1;j++){
				char temp;
				cin >> temp;
				if(temp == '0')
					maze[i][j] = 0;
				else if(temp == '1')
					maze[i][j] = MAZE_WALL;
			}
		}

		for(int i=0;i<w+2;i++){ //Set upper and botom walls
			maze[0][i] = MAZE_WALL;
			maze[b+1][i] = MAZE_WALL;
		}

		for(int i=0;i<b+2;i++){ //Set left and right walls
			maze[i][0] = MAZE_WALL;
			maze[i][w+1] = MAZE_WALL;
		}

		simulate(maze, b, w);

	}

	return 0;
}