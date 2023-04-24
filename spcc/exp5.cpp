#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string getstr(int i){string res = "t"; res+= to_string(i); return res;}
string getstr(string op1, string op2, char opr){
    string res = op1; res+=opr; res+=op2; return res;
}
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
int32_t main() {
    cout << "Enter the expression to generate TAC code \n";
    string expr; cin >> expr; 
    cout<< infixToPostfix(expr) <<"\n";
    string postfix = infixToPostfix(expr);
    int cnt = 1; 
    map<string,string> mp;
    stack<string> st;
    cout << "TAC(Three address code generation is) - \n";
    for(auto it: postfix){
        if(isalnum(it)){
            if(mp.find(string(1,it)) != mp.end());
            else {
                string res = getstr(cnt++);
                cout << res << "="<<it<<"\n";
                mp[string(1,it)] = res;
            }
            st.push(mp[string(1,it)]);
        }
        else{
            string op1 = st.top(); st.pop(); 
            string op2 = st.top(); st.pop(); 
            string res = getstr(op1,op2,it), ans = getstr(cnt++);
            cout<<ans<<"="<<res<<"\n";
            st.push(ans);
            mp[op1+it+op2] = ans;
        }
    }
    
}
