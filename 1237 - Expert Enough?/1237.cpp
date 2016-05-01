//1237 - Expert Enough? - Carlo Sartori (218326)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <math.h>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	for(int t=0;t<T;t++){
		int D;
		cin >> D;
		map<int, vector<int> > mapminv;
		vector<int> minv(D);
		vector<int> maxv(D);
		vector<string> names(D);
		
		for(int d=0;d<D;d++){
			int tempmin, tempmax;
			string tempname;
			cin >> names[d] >> minv[d] >> maxv[d];
			if(mapminv.count(minv[d]) == 0){
				vector<int> v;
				v.push_back(d);
				mapminv[minv[d]] = v;
			}
			else{
				mapminv[minv[d]].push_back(d);
			}				
		}

		int Q;
		cin >> Q;

		for(int q=0;q<Q;q++){
			int P;
			cin >> P;
			vector<string> ops;

			for (map< int, vector<int> >::iterator it = mapminv.begin(); it != mapminv.end(); it++){
				if(P >= it->first){
					for(int j=0;j<it->second.size();j++){
						if(P <= maxv[it->second[j]])
							ops.push_back(names[it->second[j]]);
					} 
				}
			}

			/*for(int i=0;i<minv.size();i++){
				if(P >= minv[i]){
					for(int j=0;j<mapminv[minv[i]].size();j++){
						if(P <= maxv[mapminv[minv[i]][j]])
							ops.push_back(names[mapminv[minv[i]][j]]);
					} 
				}
			}*/
			if(ops.size() > 1 || ops.size() == 0){
				cout << "UNDETERMINED" << endl;
			}else
				cout << ops[0] << endl;
		}
		if(t != T-1)
			cout << endl;
	}

	return 0;

}
