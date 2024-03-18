#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x; cin >> x;
    int flag = 1;
    for (int i = 0; i < n; i++){
        if (a[i] == x) {
            flag = 0;
            cout << i + 1 << " ";
        }
    }
    if (flag){
        cout << "NO";
    }

    return 0;
}
