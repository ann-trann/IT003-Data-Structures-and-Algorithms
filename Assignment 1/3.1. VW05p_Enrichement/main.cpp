#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector < vector < int > > vec;

    for (int i = 0; i < n; i++){
        vector<int> v1;
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            v1.push_back(x);
        }
        vec.push_back(v1);
    }
    int min = 1e6;
    for (int i = 0; i < n - 2; i++){
        for (int j = 0; j < m - 2; j++){
            int sum = vec[i][j] + vec[i+1][j] + vec[i+2][j] + vec[i][j+1] + vec[i+1][j+1] + vec[i+2][j+1] + vec[i][j+2] + vec[i+1][j+2] + vec[i+2][j+2];
            if (sum < min){
                min = sum;
            }
        }
    }
    cout << min;

    return 0;
}
