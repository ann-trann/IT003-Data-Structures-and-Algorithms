#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <string> vt;
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (find(vt.begin(), vt.end(), s) == vt.end()){
            vt.push_back(s);
        }
    }

    cout << vt.size();
    return 0;
}
