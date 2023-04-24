#include <bits/stdc++.h>
using namespace std;
map<char,vector<string>> prod; 
bool chkLeftRecursion(char c){
    for(auto it: prod[c]){
        if(it[0]==c) return 1;
    } return 0;
}
void removeLeftRec(char c){
    char C = c + 4;
    auto oldprod = prod[c]; 
    prod.erase(c);
    vector<string> prodc, prodC; 
    prodC.push_back("ε");
    for(auto it: oldprod){
        if(it[0]==c){
            string lft = it.substr(1);
            prodC.push_back(lft+C);
        } else prodc.push_back(it+C);
    }
    prod[c] = prodc, prod[C] = prodC;
}

int32_t main(){
    prod = {
        {'S',{"ABC"}},
        {'A',{"Aa","Ad","b"}},
        {'B',{"Bb","e"}}
    } ;
    for(auto it: prod)
        if(chkLeftRecursion(it.first)) removeLeftRec(it.first); 
    cout << "After removing left recursion, grammar is - \n";
    for(auto it: prod){
        cout << it.first << "-> ";
        for(int i = 0; i < it.second.size(); i++){
            cout << it.second[i];
            if(i != it.second.size()-1) cout << "|";
        }
        cout << endl;
    }
    return 0;
}
