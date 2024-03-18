#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
//-----------------------------------------------

    for (int i = 0; i < A.size(); i++){
        if (Hash.count(A[i]) == 0){
            Hash.insert({A[i], 1});
        }
        else {
            Hash[A[i]]++;
        }
    }

    int i = 0;
    vector<int> B(A.size());
    for (auto it : Hash){
        B[i] = it.first;
        Hash[B[i]]--;
        i++;
    }

    for (auto it : Hash){
        if (it.first != 0){
            while (it.second){
                B[i] = it.first;
                i++;
                it.second--;
            }
        }
    }

    B.resize(K);

    return B;



//-----------------------------------------------
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans = get_ans(a,k);

	for (const int& x: ans) cout << x << ' ';
	return 0;
}
