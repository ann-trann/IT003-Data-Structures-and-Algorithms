#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> flags(n+1, 0); // mảng đánh dấu
    for (int i = 0; i < n; i++) {
        if (arr[i] <= n) {
            flags[arr[i]] = 1; // đánh dấu phần tử a[i]
        }
    }

    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (flags[i] == 0) {
            mex = i;
            break;
        }
    }

    cout << mex << endl;
    return 0;
}
