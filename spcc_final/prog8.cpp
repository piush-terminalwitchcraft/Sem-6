#include <bits/stdc++.h>
using namespace std;
int prec(char c){
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^');}
string infixToPostfix(string infix){
    int i, j, n, top; j=i=0; top = -1; n=infix.size();
    stack<char> st; string res = "";
    for(;i<n;i++){
        if(isalnum(infix[i])) res+=infix[i];
        else if(infix[i]=='(') st.push('(');
        else if(infix[i]==')'){
            while(st.top() != '('){
                res+=st.top();st.pop();
            } st.pop();
        } else {
            while(!st.empty() and prec(infix[i])<=prec(st.top())){
                res+=st.top();st.pop();
            } st.push(infix[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res; 
}
string get(char c){
    string ans = "";
    if(c>='1' and c<='9') ans+='t';
    ans+=c; return ans;
}
int32_t main(){
    string expr = "x=a+(b*c)*(d/e)";    
    string infixExpr = expr.substr(2);
    string postfixExpr = infixToPostfix(infixExpr);
    // cout << postfixExpr << "\n";
    cout << "Three address code is - \n";
    map<int,string> variables; int cnt = 1; 
    stack<char> st; 
    for(auto it: postfixExpr){
        if(isOperator(it)){
            char b = st.top(); st.pop();
            char a = st.top(); st.pop();
            cout << 't' << cnt << "=" << get(a) << it << get(b) << "\n";
            st.push(cnt+'0'); cnt++;
        } else st.push(it);
    }
    cout << expr[0] << "=" << get(st.top()) << "\n";
    return 0;
}
