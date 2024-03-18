#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    map<string, string> mp;

    string acc, pass;
    for (int i = 0; i < n; i++){
        cin >> acc >> pass;
        if (mp.count(acc) == 0){
            mp[acc] = pass;
        }
        else {
            mp[acc] = mp[acc] + " " + pass;
        }
    }

    vector<string> vt;
    for (int i = 0; i < q; i++){
        cin >> acc;
        if (mp.count(acc) == 0){
            vt.push_back("Chua Dang Ky!");
        }
        else {
            vt.push_back(mp[acc]);
        }
    }

    for (auto it : vt)
        cout << it << "\n";

    return 0;
}
