#include <bits/stdc++.h>
using namespace std;

struct Hang{
    string s;
    int cnt;
};

void quickSort(string a[], int l, int r){
    int i = l, j = r;
    string p = a[(l + r) / 2];
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

int SoSanh(Hang a, Hang b){
    if (a.cnt == b.cnt){
        if (a.s.size() == b.s.size()){
            return a.s < b.s;
        }
        return a.s.size() < b.s.size();
    }
    return a.cnt > b.cnt;
}

void merge(Hang a[], int l, int m, int r){
     vector<Hang> x(a + l, a + m + 1);
     vector<Hang> y(a + m + 1, a + r + 1);
     int i = 0, j = 0;
     while (i < x.size() && j < y.size()){
        if (SoSanh(x[i], y[j])){
            a[l] = x[i]; ++l; ++i;
        }
        else {
            a[l] = y[j]; ++l; ++j;
        }
     }
     while (i < x.size()){
        a[l] = x[i]; ++l; ++i;
     }
     while (j < y.size()){
        a[l] = y[j]; ++l; ++j;
     }
}
void mergeSort(Hang a[], int l, int r){
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main()
{
    int n; cin >> n;
    string a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);

    Hang b[n];

    b[0].s = a[0];
    b[0].cnt = 1;
    int j = 0;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1]){
            b[j].cnt++;
        }
        else {
            j++;
            b[j].cnt = 1;
            b[j].s = a[i];
        }
    }

    mergeSort(b, 0, j);

    for (int i = 0; i <= j; i++){
        cout << b[i].s << " " << b[i].cnt << "\n";
    }


    return 0;
}
