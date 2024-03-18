#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if ((s[i] == '}' || s[i] == ')' || s[i] == ']') && st.empty()){
            return false;
        }
        if (s[i] == '{') st.push('{');
        if (s[i] == '(') st.push('(');
        if (s[i] == '[') st.push('[');

        if (s[i] == '}'){
            if (st.top() == '(' || st.top() == '[')
                return false;
            else if (st.top() == '{')
                st.pop();
        }
        if (s[i] == ')'){
            if (st.top() == '{' || st.top() == '[')
                return false;
            else if (st.top() == '(')
                st.pop();
        }
        if (s[i] == ']'){
            if (st.top() == '(' || st.top() == '{')
                return false;
            else if (st.top() == '[')
                st.pop();
        }

    }
    if (!st.empty()){
        return false;
    }
    return true;
}

int main()
{
    string s; cin >> s;
    if (check(s)) cout << 1;
    else cout << 0;

    return 0;
}
