#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<vector<int>> vt(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x; cin >> x;
            if (x != 0){
                vt[i].push_back(j + 1);
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (!vt[i].empty()){
            cout << i + 1 << "->";
        }
        for (auto j : vt[i]){
            cout << j << " ";
        }
        if (!vt[i].empty()){
            cout << "\n";
        }
    }
}
