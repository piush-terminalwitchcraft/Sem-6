#include <bits/stdc++.h>
using namespace std;
map<char,vector<string>> prod;
map<char,vector<char>> first, visited, follow, visitedFollow, term; 
map<pair<char,char>,vector<string>> lltable; 
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
        {'S',{"(L)","a"}},
        {'L',{"SM"}},
        {'M',{",SM","#"}}
    };
    term = { 
        {'(',{'1'}}, {')',{'1'}},
        {'$',{'1'}}, {'a',{'1'}},
        {',',{'1'}}
    };
    for(auto it: prod){
        if(!isVisited(it.first))
            findFirst(it.first);
    }
    follow['S'].push_back('$');
    for(auto it: prod){
        if(!isVisitedFollow(it.first)) findFollow(it.first);
    }
    for(auto it: prod){
        char nonTerminal = it.first; 
        for(auto it2: it.second){
            if(it2[0] == '#') {
                // if null , add follow to the lltable 
                for(auto terminal: follow[nonTerminal])
                    lltable[{nonTerminal,terminal}].push_back(it2);
            } else if(isNonTerminal(it2[0])){
                // add first of non terminal 
                for(auto terminal: first[nonTerminal])
                    lltable[{nonTerminal,terminal}].push_back(it2);
            } else{
                lltable[{nonTerminal,it2[0]}].push_back(it2);
            }
        }
    }
    cout << "LL parser table is - \n";
    for(auto it: term) cout << " \t" << it.first; cout << endl;
    for(auto it: prod){
        // print non-terminal and all respective mapping in LL table 
        char nonTerminal = it.first;
        cout << it.first << "\t";
        for(auto it2: term){
            char terminal = it2.first;
            if(lltable.find({nonTerminal,terminal}) ==lltable.end() ){
                cout << "-\t";
            } else{
                string prod = lltable[{nonTerminal,terminal}][0];
                cout<<nonTerminal<<"->"<< prod << "\t";
            }
        }
        cout << endl;
    }
    return 0;
}


