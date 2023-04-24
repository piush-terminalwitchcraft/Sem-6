#include <bits/stdc++.h>
using namespace std;
map<char,vector<string>> prod;
map<char,vector<char>> first, visited; 
// # => null
bool isVisited(char c) {
    return visited.find(c) != visited.end();
}
void findFirst(char c){
    map<char,int> ans; 
    for(auto it: prod[c]){
        if(!isupper(it[0])) ans[it[0]] = 1;
        else {
            if(!isVisited(it[0])) findFirst(it[0]);
            vector<char> tmp = first[it[0]];
            for(auto it2: tmp) ans[it2] = 1;
            
        }
    }
    visited[c] = {'1'};
    for(auto it: ans) first[c].push_back(it.first);
}


int32_t main(){
    prod = {
        {'S',{"aSa","bSb","A"}},
        {'A',{"aBb"}},
        {'B',{"aB","bB","#"}}
    };
    for(auto it: prod){
        if(!isVisited(it.first))
            findFirst(it.first);
    }
    cout << "non-terminal \t First  \n";
    for(auto it: first){
        cout << it.first << "\t\t|\t";
        for(int i = 0; i < it.second.size(); i++){
            cout << it.second[i];
            if(i != it.second.size()-1) cout << ",";
        }
        cout << endl;
    }
    return 0;
}
