#include <bits/stdc++.h>
using namespace std;

void Xuatvitri(int n){
    int p, q;
    if (n % 2 == 0){
        q = 2;
        p = n / 2;
    }
    else {
        q = 1;
        p = (n + 1) / 2;
    }
    cout << p << " " << q;
}

int main()
{
    int n, k, p, q; cin >> n >> k >> p >> q;
    int t = 1;

    int x = 2 *(p - 1) + q - 1;
    int ma = x % k + 1;


    int flag1 = 1;
    for (int i = x - k; i >= 0; i -= k){
        if (i % k + 1 == ma) {
            Xuatvitri(i + 1);
            flag1 = 0; break;
        }
    }

    if (flag1) {
        int flag2 = 1;
        for (int i = x + k; i < n; i += k){
            if (i % k + 1 == ma) {
                Xuatvitri(i + 1);
                flag2 = 0; break;
            }
        }
        if (flag2) cout << -1;
    }

    return 0;
}
