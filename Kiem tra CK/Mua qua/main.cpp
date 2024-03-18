#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    set<int> st;
    map<int, int> mp;
    vector<int> vt1(n);
    for (int i; i < n; i++){
        int k; cin >> k;
        st.insert(k);
        mp[k] = i;
        vt1[i] = k;
    }
    vector<int> vt2 (st.begin(), st.end());

    int s = 0;
    for (int i = 0; i < 4; i++)
        s += vt2[i];
    if (s > x){
        cout << "Impossible";
        return 0;
    }
    else if (n < 4)


    int flag = 0;
    s = vt2[0] + vt2[1] + vt2[2];
    int x1 = vt2[0], x2 = vt2[1], x3 = vt2[2], x4 = vt2[3];
    int i1 = 0, i2 = 1, i3 = 2, i4 = 3;

    for (int i = n - 1; n >= 0; i--){
        if (s + vt2[i] == x){
            x4 = vt2[i];
            break;
        }
        else if (s + vt2[i] < x){
            x4 = vt2[i];
            i4 = i;
            flag = 1;
            break;
        }
    }

    if (flag == 1){
        s = vt2[0] + vt2[1] + x4;
        for (int i = i4; n >= 0; i--){
            if (s + vt2[i] == x){
                x3 = vt2[i];
                break;
            }
            else if (s + vt2[i] < x){
                x3 = vt2[i];
                i3 = i;
                flag = 2;
                break;
            }
        }
    }

    if (flag == 2){
        s = vt2[0] + x3 + x4;
        for (int i = i3; n >= 0; i--){
            if (s + vt2[i] == x){
                x2 = vt2[i];
                break;
            }
            else if (s + vt2[i] < x){
                x2 = vt2[i];
                i2 = i;
                flag = 3;
                break;
            }
        }
    }
    if (flag == 3){
        s = x2 + x3 + x4;
        for (int i = i2; n >= 0; i--){
            if (s + vt2[i] == x){
                x1 = vt2[i];
                break;
            }
            else if (s + vt2[i] < x){
                x1 = vt2[i];
                i1 = i;
                break;
            }
        }
    }

    vector<int> res;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (vt1[i] == x1 || vt1[i] == x2 || vt1[i] == x3 || vt1[i] == x4){
            res.push_back(i + 1);
            count++;
        }
        if (count == 4) break;
    }

    cout << x1 + x2 + x3 + x4 << endl;
    for (int x : res) cout << x << " ";


    return 0;
}
