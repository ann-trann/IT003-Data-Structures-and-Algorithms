#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max_le = -1000;
    int min_chan = 1000;
    int k = 0, h = 0;

    for (int i = 0; i < n; i++){
        if (i % 2 == 1) {
            if (max_le < a[i]){
                max_le = a[i];
                k = i;
            }
        }
        if (i % 2 == 0) {
            if (min_chan > a[i]){
                min_chan = a[i];
                h = i;
            }
        }
    }
    if (max_le > min_chan){
        swap(a[k], a[h]);
    }


    int sum = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 1){
            sum -= a[i];
        }
        else {
            sum += a[i];
        }
    }
    cout << sum;

    return 0;
}
