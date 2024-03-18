#include <bits/stdc++.h>

using namespace std;

int main() {
    string txt, pat;
    cin >> txt >> pat;
    int n = txt.size(), m = pat.size();

    vector<int> pos;
    for (int i = 0; i < n - m + 1; i++) {
        if (txt[i] == pat[0]) {
            if (txt.substr(i, m) == pat) {
                pos.push_back(i+1);
            }
        }
    }

    if (pos.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < pos.size(); i++) {
            cout << pos[i] << " ";
        }
    }
    return 0;
}
