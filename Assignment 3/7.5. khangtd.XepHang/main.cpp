#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }

    vector<int> flags(n + 1);
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    for (int i = m - 1; i >= 0; i--){
        if (flags[b[i]] == 0){
            cout << b[i] << " ";
            flags[b[i]]++;
        }
    }

    for (int i = 0; i < n; i++){
        if (flags[a[i]] == 0){
            cout << a[i] << " ";
        }
    }

    return 0;
}
