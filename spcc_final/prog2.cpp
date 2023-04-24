#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct MN{
    int MDTindex; 
    string macroName; 
};
vector<string> MDT;
vector<char> ALA; 
vector<MN*> MNT; 

string getMacroName(string s){
    string ans = ""; 
    for(auto it: s){
        if(it == ' ') break;
        ans += it;
    }
    return ans; 
}

void updateALA(string s){
    int i = 0; while(i<s.size() and s[i]!=' ') i++;
    if(i == s.size()) return;
    i++; 
    s+="%";
    for(; i+3 < s.size(); i+=3){
        cout << s[i+1] << s[i+1] << s[i+2] ;
        if(find(ALA.begin(),ALA.end(),s[i+1]) != ALA.end()) continue;
        ALA.push_back(s[i+1]);
    } cout << endl;
}

char getIdx(char c){
    int i = 0; 
    for(auto it: ALA){
        if(it == c) return i+'0'; 
        i++;
    }
    return '@';
}
string processed(string s){
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '&') {
            ans += '#'; ans += getIdx(s[i+1]);
            i++;
        } else ans+=s[i];
    }
    return ans;
}

int32_t main(){
    ifstream file("assembly.txt");
    vector<string> lines; 
    if(file.is_open()){
        string line; 
        while(getline(file,line)){
            lines.push_back(line);
        }
        file.close();
    }
    int index = 0;
    for(int i = 0; i < lines.size(); i++){
        if(lines[i].substr(0,5) == "MACRO"){
            i++;
            string macroname = getMacroName(lines[i]);
            updateALA(lines[i]);
            MN *mn = new MN();
            mn->macroName = macroname;
            mn->MDTindex = index; 
            MNT.push_back(mn);
            i++; 
            while(lines[i].substr(0,4)!="MEND"){
                MDT.push_back(processed(lines[i])); i++; index++;
            }
            MDT.push_back(lines[i]); index++;
        }
    }
    index = 0;
    cout << "\t\t\tMACRO DEFINITION TABLE(MDT)\n"; 
    cout << "INDEX\tOPCODE\n";
    for(auto it: MDT){
        cout << index << "\t" << it << "\n";
        index++;
    }
    index = 0; 
    cout << "\t\t\tMACRO NAMING TABLE(MNT)\n"; 
    cout << "MACRO\tMDT index\n";
    for(auto it: MNT){
        cout << it->macroName << "\t" << it->MDTindex << "\n";
    }

    cout << "\t\t\tARGUMENT LIST ARRAY(ALA)\n"; 
    cout << "INDEX\tPARAMETER\n";
    for(auto it: ALA){
        cout << index << "\t" << it << "bbbbbbb\n";
    }
    return 0;
}
