#include <bits/stdc++.h>
using namespace std; 

map<char,int> term, nterm; 
map<char,vector<string>> prod; 
map<char,vector<char>> first,follow; 

vector<char> recFirst(char nterm){
	if(first.find(nterm) != first.end()) return first[nterm];
	if(prod.find(nterm) == prod.end()) return {'e'};
	vector<char> ans; 
	for(auto ch: prod[nterm]){
		if( term.find(nterm) != term.end() ) ans.push_back(ch[0]);
		else{
			auto ff = recFirst(nterm);

		}
	}
}

int main(){
	string tmp ;
	cout << "Enter non terminals \n";
	cin >> tmp; 
	for(char c: tmp ) nterm[c]=1;
	cout << "Enter non terminals \n";
    cin >> tmp;
    for(char c: tmp ) term[c]=1;

	int cnt  = 0; 
	cout << "Enter no of production \n";
	cin >> cnt; 
	for(int i = 0; i < cnt; i++){
		cout << "Enter the production in form X->Y\n";
		cin >> tmp ;
		char f = tmp[0];
		string g = tmp.substr(3);
		prod[f].push_back(g);
	}
	for(char c: nterm){

	}
	return 0;
}
