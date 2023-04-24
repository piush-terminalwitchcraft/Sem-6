// implement lexical analysis
#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <regex>
using namespace std;
typedef long long ll;
map<char,int> operators, punctuators;
map<string,int> keywords;
bool isPunctuation(char c){ return punctuators[c]; }
bool isValidIdentifier(string str){
    if(isdigit(str[0])) return false;
    for(auto it: str) {
        if(isPunctuation(it)) return false;
    }
    return true;
}
bool isOperator(char c){ return operators[c]; }
bool isKeywords(string str){ return keywords[str]; }
bool isNumber(string str){
    int decimal = 0; 
    for(int i = 0; i < (int)str.size(); i++){
        if(str[i] == '-' and i!=0) return false;
        if(str[i] == '.') decimal++;
        if( !isdigit(str[i]) ) return false;
    }
    return decimal <= 1;
}
std::string subString(std::string realStr, int l, int r) {
    int len = r - l + 1;
    return realStr.substr(l, len);
}

void parse(string str){
    int left = 0, right = 0, len = str.size() - 1;

    while(right <= len and left <= right){
        if( isPunctuation(str[right]) == false){
            right ++; 
        } 
        if( isPunctuation(str[right]) && left == right ){
            if( isOperator(str[right]) ){
                cout << str[right] << " is an operator\n";
            }
            right ++; 
            left = right;
        } else if( isPunctuation(str[right]) == true and left != right or (right ==len and left!= right )){
            string tmp = subString(str,left,right-1);

            if(isKeywords(tmp)){
                cout << tmp << " is a keyword\n"; 
            } else if(isNumber(tmp) ){
                cout << tmp << " is a number\n";
            } else if(isValidIdentifier(tmp) && isPunctuation(str[right-1]) == false){
                cout << tmp << " is a valid identifier\n";
            } else if(!isValidIdentifier(tmp) and isPunctuation(str[right-1])){
                cout << tmp << " is not valid identifier\n";
            }
            left = right; 
        }

    }
    return;
}

int32_t main(){
    
    punctuators = {
        {' ', 1}, {'+', 1}, {'-', 1}, {'/', 1}, {',', 1}, {';', 1}, 
        {'>', 1}, {'<', 1}, {'(', 1}, {')', 1}, {'[', 1}, {']', 1},
        {'{', 1}, {'}', 1}, {'&', 1}, {'|', 1}, {'*', 1}, {'=', 1} 
    };
    operators = {
        {'+', 1}, {'-', 1}, {'*', 1},
        {'/', 1}, {'<', 1}, {'>', 1},
        {'=', 1}, {'&', 1}, {'|', 1}
    };
    keywords = {
        {"if", 1}, {"else", 1}, {"while", 1}, {"do", 1}, {"break", 1},
        {"continue", 1}, {"int", 1}, {"double", 1}, {"float", 1}, {"return", 1},
        {"char", 1}, {"case", 1}, {"short", 1}, {"long", 1}, {"typedef", 1},
        {"switch", 1}, {"unsigned", 1}, {"void", 1}, {"static", 1}, {"struct", 1},
        {"sizeof", 1}, {"volatile", 1}, {"enum", 1}, {"const", 1}, {"union", 1},
        {"extern", 1}, {"bool", 1}
    };
    
    string code = "int main(){int n = 0, p = 0; int m = n + 3*p;return 0;} ";
 
    parse(code);
    return 0;
}
