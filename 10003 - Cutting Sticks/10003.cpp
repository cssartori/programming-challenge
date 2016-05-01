//10003 - CUtting Sticks	-	Carlo Sulzbach Sartori
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;

mi memo;
vi cuts;

int cut(int left, int right){
	if(left +1 == right) return 0;
	if(memo[left][right] != -1) return memo[left][right];
	
	int ans = 100000;

	for(int i=left+1;i<right;i++){
		ans = min(ans, cut(left, i)+cut(i,right)+(cuts[right]-cuts[left]));
	}

	memo[left][right] = ans;
	return ans;
}

int main(){
    /*Length of the stick*/
	int l;

    while(cin >> l){
        if(l == 0)
            /*End of input*/
            break;

            /*Number of cuts to be made on the stick*/
            int n;
            cin >> n;
            
            /*Places of the cuts n+2 to add 0 and l*/
            cuts.assign(n+2, 0);
			cuts[0] = 0;
			cuts[n+1] = l;
			/*Read input*/
            for(int i=1;i<n+1;i++)
                cin >> cuts[i];
			
			memo.assign(n+2, vi(n+2, -1));

        	cout << "The minimum cutting is " << cut(0, n+1) << "." << endl;
    }
	return 0;
}

