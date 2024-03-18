#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

bool cmp(Point a, Point b){
    if (a.x != b.x){
        return a.x < b.x;
    }
    else if (a.y != b.y){
        return a.y > b.y;
    }
}

void merge(Point a[], int l, int m, int r){
     vector<Point> x(a + l, a + m + 1);
     vector<Point> y(a + m + 1, a + r + 1);
     int i = 0, j = 0;
     while (i < x.size() && j < y.size()){
        if (cmp(x[i], y[j]) == true){
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
void mergeSort(Point a[], int l, int r){
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}



int main()
{
    int n; cin >> n;
    Point a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }

    mergeSort(a, 0, n - 1);

    cout << endl;
    for (int i = 0; i < n; i++){
        cout << a[i].x << " " << a[i].y << "\n";
    }

    return 0;
}
