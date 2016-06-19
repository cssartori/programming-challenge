//11512 - GATTACA	-	Carlo Sartori

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>

#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;

char S[10010];
int LCP[10010];
int SA[10010];
int n;

bool cmp(int a, int b){ return strcmp(S + a, S + b) < 0; }

void computeLCP() {
    LCP[0] = 0;    
    for (int i = 1; i < n; i++) {
        int L = 0;
        while (S[SA[i] + L] == S[SA[i-1] + L]) L++;
        LCP[i] = L;
    } 
}


int main(){
    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> S;
        n = (int)strlen(S);
        S[n] = '$';
        S[n+1] = '\0';
        n++;       
        for(int i=0;i<n;i++) SA[i] = i;
        sort(SA, SA+n, cmp);
        
        computeLCP();
        int max = 0;
        for(int i=1;i<n;i++)
            if(LCP[max] < LCP[i])
                max = i;
            else if(LCP[max] == LCP[i])
                if(strcmp(S+SA[max], S+SA[i]) > 0)
                    max = i;
            
        if(LCP[max] > 0){
            char *str = S+SA[max];
            for(int i=0;i<LCP[max];i++)
                cout << str[i];
            
            int rep = 0;
            for(int i=0;i<n;i++){
                if(n - i < LCP[max]) break;
                bool found = true;
                for(int j=0;j<LCP[max];j++)
                    if(S[j+i] != str[j]){
                        found = false; break;
                    }
                if(found)
                    rep++;
            }

            cout << " " << rep << endl;
        }else{
            cout << "No repetitions found!" << endl;
        }

    }
        
}
