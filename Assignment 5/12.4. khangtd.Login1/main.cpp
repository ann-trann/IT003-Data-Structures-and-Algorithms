#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    map<string, string> mp;
    string acc, pass;

    for (int i = 0; i < n; i++){
        cin >> acc >> pass;
        mp[acc] = pass;
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

}

/*
5 2
ATTN 2020
CTDL L21
Code 123
UIT HCM
NTS TDK
abc
ATTN
*/
