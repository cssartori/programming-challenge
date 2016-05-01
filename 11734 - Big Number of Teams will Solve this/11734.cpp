//11734 - Big Number of Teams will Solve This - Carlo Sartori (218326)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
	int t;
	cin >> t;
	string ttt;
	getline(cin, ttt);

	for(int i=0;i<t;i++){
		string teamOutput;
		string judgeOutput;

		getline(cin, teamOutput);
		getline(cin, judgeOutput);
		
		//cout << "T: " << teamOutput << endl;
		//cout << "J: " << judgeOutput << endl;

		int ti=0, ji=0;
		bool outError = false;
		bool wa = false;
		bool correct = true;

		for(ti=0;ti<teamOutput.length();ti++){
			if(teamOutput[ti] == ' '){
				outError = true;
			}
			else if(teamOutput[ti] == judgeOutput[ji]){
				ji++;
				continue;
			}
			else{
				correct = false;
				wa = true;
				break;
			}	
		}
		
		if(outError && correct && ji == judgeOutput.length()){
			cout << "Case " << i+1 << ": " << "Output Format Error" << endl;
		}
		else if(correct && !outError){
			cout << "Case " << i+1 << ": " << "Yes" << endl;
		}
		else{
			cout << "Case " << i+1 << ": " << "Wrong Answer" << endl;
		}
		
	}

}
