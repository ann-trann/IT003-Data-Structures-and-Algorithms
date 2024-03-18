#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        vec.push_back(k);
    }

    sort(vec.begin(), vec.end(), cmp);

    int sum = 0;
    int l = 0, r = n - 1;
    while (l < r){
        if (vec[l] + vec[r] <= x) {
            sum = max(sum, vec[l] + vec[r]);
            l++;
        }
        else {
            r--;
        }
    }
    cout << sum;

    return 0;
}

