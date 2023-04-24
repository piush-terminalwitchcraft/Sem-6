#include <bits/stdc++.h>
using namespace std;
map<char,vector<string>> prod; 
void removeLeftFact(char c){
    char C = c + 4;
    auto oldprod = prod[c];
    string common = oldprod[0];
    int len = common.size();
    vector<string> prodc, prodC; 
    for(auto it: oldprod){
        int idx = 0; 
        while(idx<common.size() and idx<it.size() and common[idx]==it[idx]) idx++;
        common = common.substr(0,idx);
    }
    len = common.size();
    if(len == 0) return;
    prodc.push_back(common + C);
    for(auto it: oldprod){
        string tmp = it.substr(len);
        if(tmp == "") tmp = "ε"; 
        prodC.push_back(tmp);
    }
    prod[c] = prodc, prod[C] = prodC;
}

int32_t main(){
    prod = {
        {'S',{"iEtS","iEtSeS"}},
        {'A',{"aB","abc"}},
    } ;
    for(auto it: prod)
        removeLeftFact(it.first); 
    cout << "After removing left factoring, grammar is - \n";
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

