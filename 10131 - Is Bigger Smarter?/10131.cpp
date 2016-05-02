//10131 - Is BIgger Smarter?	-	Carlo Sulzbach Sartori
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool comp(ii p, ii q){
	return p.first < q.first;
}

int main(){
	vi s;
	vii w;
	int n=0;
	int st, wt;
	
	while(cin >> wt >> st){
		s.pb(st);
		w.pb(ii(wt, n));
		n++;
	}	
	
	sort(w.begin(), w.end(), comp);

	mi lism(n, vi(2,0));
	int maxi = 0;
	for(int i=0;i<n;i++){
		int maxj = i;
		int maxs = lism[i][0]+1;
		
		for(int j=0;j<i;j++){
			if(w[j].first < w[i].first){
				if(s[w[j].second] > s[w[i].second]){
					int s = lism[j][0]+1;
					if(maxs < s){
						maxs = s;
						maxj = j;
					}
				}
			}		
		}

		lism[i][0] = maxs;
		lism[i][1] = maxj;
		if(lism[i][0] > lism[maxi][0])
			maxi = i;
	}

	cout << lism[maxi][0] << endl;

	bool end = false;
	stack<int> q;
	while(!end){
		q.push(w[maxi].second);
		if(lism[maxi][1] == maxi)
			end = true;
		maxi = lism[maxi][1];
	}

	while(!q.empty()){
		cout << q.top()+1<< endl;
		q.pop();
	}

	return 0;

}
