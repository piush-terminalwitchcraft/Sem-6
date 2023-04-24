#include <bits/stdc++.h>
using namespace std;
map<char,vector<string>> prod;
map<char,vector<char>> first, visited, follow, visitedFollow; 
// # => null
bool isNonTerminal(char c){
    return isupper(c);
}
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
bool doesGiveNull(char c){
    return first.find('#') == first.end();
}
bool isVisitedFollow(char c){
    return visitedFollow.find(c) != visitedFollow.end();
}
void findFollow(char c){
    cout << "Finding follow of " << c << "\n";
    map<char,int> ans;
    for(auto it: prod){
        for(auto str: it.second){
            int n = str.size();
            for(int i = 0; i < n; i++){
                if(str[i] == c){
                    // if terminal , add in ans directly 
                    if(i+1<n and !isNonTerminal(str[i+1])) {

                        ans[str[i+1]] = 1;
                        continue;
                    }
                    int idx = i+1, flag = 1;
                    while(idx < n and isNonTerminal(str[idx])){
                        // add first of non-terminal to ans 
                        for(auto it2: first[str[idx]]) ans[it2] = 1;
                        if(!doesGiveNull(str[idx])) {
                            flag = 0; break;
                        } idx++;
                    }
                    if(idx == n and flag and it.first != c){
                        if(!isVisitedFollow(it.first)) findFollow(it.first);
                        for(auto it2: follow[it.first]) ans[it2] = 1;
                    }
                }
            }
        }
    }
    visitedFollow[c] = {'1'};
    if(ans.find('#') != ans.end()) ans.erase('#');
    for(auto it: ans) follow[c].push_back(it.first);
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
    follow['S'].push_back('$');
    for(auto it: prod){
        if(!isVisitedFollow(it.first)) findFollow(it.first);
    }
    cout << "non-terminal \t Follow  \n";
    for(auto it: follow){
        cout << it.first << "\t\t|\t";
        for(int i = 0; i < it.second.size(); i++){
            cout << it.second[i];
            if(i != it.second.size()-1) cout << ",";
        }
        cout << endl;
    }
    return 0;
}

