#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;


int main(){
	int n, a=0;
	cin >> n;
	string k;
	getline(cin, k); //read new line
	getline(cin, k); //read new line
	while(a<n){
		a++;
		vector<int> altitudes;
		
		while(getline(cin, k)){	
			if(k == "\0") break;
			altitudes.push_back(atoi(k.c_str()));			
		}

		int size = altitudes.size();
		vector< vector<int> > lism(size, vector<int>(2, 0));
		int maxi = 0;

		for(int i=0;i<size;i++){
			int maxj = i;
			int maxs = lism[i][0]+1;
			for(int j=0;j<i;j++){
				if(altitudes[j] < altitudes[i]){
					int s = lism[j][0]+1;
					if(s > maxs){
						maxs = s;
						maxj = j;
					}
				}

			}
			lism[i][0] = maxs;
			lism[i][1] = maxj;
			if(lism[i][0] > lism[maxi][0]) maxi = i;
		}	
		cout << "Max hits: " << lism[maxi][0] << endl;
		stack<int> out;
		bool end = false;
		while(!end){
			out.push(altitudes[maxi]);
			if(lism[maxi][1] == maxi)
				end = true;
			maxi = lism[maxi][1];
		}
		
		while(!out.empty()){
			cout << out.top() << endl;
			out.pop();
		}
		if(a!=n)
			cout << endl;
	}
	return 0;
}
