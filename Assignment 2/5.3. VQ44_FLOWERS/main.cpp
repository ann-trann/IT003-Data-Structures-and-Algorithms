#include<bits/stdc++.h>
using namespace std;

void quickSort(int a[], int l, int r){
    int i = l, j = r;
    int p = a[(l + r) / 2];
    while (i < j){
        while (a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if (i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (j > l) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    int flag[n] = {0};
    cout << a[0] << " ";
    flag[0] = 1;
    k--;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cout << a[i] << " ";
            flag[i] = 1;
            k--;
            if (k == 0) return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (flag[i] == 0) {
            cout << a[i] << " ";
            k--;
            if (k == 0) return 0;
        }
    }
}
