#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int t = k % n;

    int b[n];

    for (int i = 0; i < n; i++){
        b[(i + t) % n] = a[i];
    }

    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }

    return 0;
}
