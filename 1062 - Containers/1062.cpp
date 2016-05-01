//1062 - Containers - Carlo Sartori (218326)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;


int getStack(vector< stack<char> > stacks, char c){
	for(int i=0;i<stacks.size();i++){
		if(stacks[i].top() >= c)
			return i;
	}

	return -1;
}


int main(){
	string input;
	int cas=0;

	while(cin >> input){
		cas++;
		if(!input.compare("end")){
			break;
		}

		vector< stack<char> > stacks;

		for(int i=0;i<input.length();i++){
			int index = getStack(stacks, input[i]);
			if(index == -1){
				stack<char> ns;
				ns.push(input[i]);
				stacks.push_back(ns);
			}else{
				stacks[index].push(input[i]);
			}
		}
		
		cout << "Case " << cas << ": " << stacks.size() << endl;
	}

}
