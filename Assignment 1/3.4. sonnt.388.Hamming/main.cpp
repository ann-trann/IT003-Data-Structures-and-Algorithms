#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    if (a.length() != b.length())
        cout << b.length();
    else {
        int flag = 1;
        for (int i = 0; i < a.length(); i++){
            if (a[i] != b[i]) {
                cout << a.length() - i;
                flag = 0; break;
            }
        }
        if (flag) cout << 0;
    }
    return 0;
}
