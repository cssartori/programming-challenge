//11062 - Andy's Second Dictionary	- 	Carlo Sartori (218326)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


vector<string> split(string str) {
	vector<string> v;
	string s;
	int i=0;
  	for(i=0;i<str.size()-1;i++){
		if(str[i] == '-' || (str[i] >= 97 && str[i] <= 122)){
			s+=str[i];
		}
		else{
			if(s.size() > 0){
				v.push_back(s);
				s.clear();
			}
		}
	}

	if(str[i] == '-' || (str[i] >= 97 && str[i] <= 122)){
		s+=str[i];
		v.push_back(s);
	}else if(s.size() > 0){
		v.push_back(s);
	}
	
  
  return v;
}


int main(){
	
	set<string> strings;
	string read;

	while(cin >> read){
		
		if(read.back() == '-'){ //means the word continues on the next line
			read.erase(read.size()-1); //erase the '-'
			string rest;
			cin >> rest;
			
			while(rest.back() == '-'){
				rest.erase(rest.size()-1); //erase the '-'
				read+=rest;
				cin >> rest;
			}				
			
			read += rest;		
		}

		for(int i=0;i<read.size();i++){
			read[i] = tolower(read[i]);
		}

		vector<string> r = split(read);				
		
		for(string rr : r){
			strings.insert(rr);
		}
			
	}

	for (set<string>::iterator i = strings.begin(); i != strings.end(); i++) {
   		string s = *i;
		cout << s << endl;			
	}

	return 0;

}
