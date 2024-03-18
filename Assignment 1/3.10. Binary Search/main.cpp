#include <bits/stdc++.h>
using namespace std;

bool Binary_Search(int a[], int n, int x){
    int l = 0, r = n - 1;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        else if (a[m] < x){
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return false;
}

bool cmp(int a, int b){
    return a <= b;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
// create vector array
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        vec.push_back(x);
    }
//sort vector array
    sort(vec.begin(), vec.end(), cmp);

// assign vector array to a[] array
    for (int i = 0; i < n; i++){

        a[i] = vec[i];
    }
// create b[] array get value 1 if k in array a[], 0 if k not in array a
    int b[q];
    for (int i = 0; i < q; i++){
        int k; cin >> k;
        if (Binary_Search(a, n, k)){
            b[i] = 1;
        }
        else {
            b[i] = 0;
        }
    }

// if b[i] == 1 output 'yes', b[i] == 0 output 'no'
    for (int i = 0; i < q; i++){
        if (b[i] == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
