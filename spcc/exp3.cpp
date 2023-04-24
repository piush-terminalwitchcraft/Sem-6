#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;
char tmp;
typedef long long ll;
unordered_map<char,int> term, nterm, vis, nullprd;
unordered_map<char,vector<string>> productions;
unordered_map<char,vector<char>> first;
unordered_map<char,set<char>> follow;
bool checkTerminal(char c){return term[c] or (c=='@');}
void findFirst(char c){
    vector<char> ans; vis[c]=1;
    for(auto it: productions[c]){
        if(checkTerminal(it[0])) ans.push_back(it[0]);
        else{
            if(!vis[it[0]]){findFirst(it[0]);}
            for(auto it2: first[it[0]]){
                ans.push_back(it2);
            }
        }
    }
    first[c] = ans;
}
void findFollow(char c){
    set<char> st; vis[c]=1;
    for(auto it: productions){
        for(auto it2: it.second){
            int n = it2.size();
            for(int i = 0; i < n; i++){
                if(it2[i]==c){
                    int j = i+1;
                    if(j<n and checkTerminal(it2[j])){
                        follow[c].insert(it2[j]);
                        continue;
                    }
                    while(j<n and nullprd[it2[j]]){
                        follow[c].insert(first[it2[j]].begin(), first[it2[j]].end());
                        j++;
                    }
                    if(j==n and it.first!= c){
                        if(!vis[it.first]) findFollow(it.first);
                        follow[c].insert(follow[it.first].begin(),follow[it.first].end());
                    }
                    else{
                        follow[c].insert(first[it2[j]].begin(),first[it2[j]].end());
                    }
                }
            }
        }
    }
}
int32_t main() {
    cout << "Enter the number of terminals and non-terminals respectively: ";
    int n, m; cin >> n >> m; 
    cout << "Enter all the terminals: ";
    for (int  i = 0; i < n ; i++) {
        cin >> tmp; term[tmp]=1;
    }
    cout << "Enter all the non-terminals: ";
    for (int  i = 0; i < m; i++) {
        cin >> tmp; nterm[tmp]=1;
    }
    cout << "Enter start symbol: ";
    cin >> tmp; follow[tmp].insert('$');
    cout << "Enter the number of productions: ";
    int prd; cin >> prd; 
    cout << "Enter all the productions in the format A->BCD.... \n";
    for (int  i = 0; i < prd ; i++) {
        string tmpprd; cin >> tmpprd;
        productions[tmpprd[0]].push_back(tmpprd.substr(tmpprd.find("->")+2));
        if(tmpprd.substr(tmpprd.find("->")+2) == "@") nullprd[tmpprd[0]]=1;
    }
    for(auto it: nterm){
        if(!vis[it.first]) findFirst(it.first);
    }
    freopen("output.txt","w",stdout);
    for (auto it : nterm) {
        cout << "First of " << it.first << " is {";
        for (auto it2 : first[it.first]) {
            cout << it2 << ",";
        }
        cout << "}\n";
    }
    vis.clear();
    for(auto it: nterm){
        if(!vis[it.first]) findFollow(it.first);
    }
    for (auto it : nterm) {
        cout << "Follow of " << it.first << " is {";
        for (auto it2 : follow[it.first]) {
            if(it2 != '@')
            cout << it2 << ",";
        }
        cout << "}\n";
    }
    fclose(stdout);
}
