#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    vector<int> vec;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end(), cmp);

    int h_index = n - 1;

    while(h_index + 1 > vec[h_index]){
        h_index--;
    }

    cout << h_index + 1;


    return 0;
}
