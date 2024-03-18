#include <bits/stdc++.h>
using namespace std;

vector<int> st;
int X;

struct P{
    int idx;
    int  price;
};

bool cmp(P a, P b){
    return a.price < b.price;
}

void Insert(P a[], int n, int &sum){

	for (int i = 0; i < n - 1; i++){
        if (i > 0 && a[i].price == a[i - 1].price) continue;
		for (int j = i + 1; j < n; j++){
		    if (j > i + 1 && a[j].price == a[j - 1].price) continue;

			int l = j + 1;
			int r = n - 1;
			while (l < r){
                int ss = a[i].price + a[j].price + a[l].price + a[r].price;
                if (ss > X){
                    r--;
                }
                else {
                    if (ss > sum){
                        sum = ss;
                        st.clear();
                        st.push_back(a[i].idx);
                        st.push_back(a[j].idx);
                        st.push_back(a[l].idx);
                        st.push_back(a[r].idx);
                    }
                    l++;
                }
			}
		}
	}
}

int main(){
	int n, sum = 0;
	cin >> n >> X;
	P a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].price;
		a[i].idx = i + 1;
	}
	sort(a, a + n, cmp);

	Insert(a, n, sum);
    if (sum == 0) cout << "Impossible";
    else {
       // sort(st.begin(), st.end());
        cout<< sum << endl;
        for (auto i = st.rbegin(); i != st.rend(); i++){
            cout << *i << " ";
        }
    }

}
