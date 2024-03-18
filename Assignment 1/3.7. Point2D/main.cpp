#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

bool cmp(Point a, Point b){
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        return (a.y > b.y);
    }
    return false;
}

int main()
{
    int n; cin >> n;
    vector<Point> a;
    for (int i = 0; i < n; i++){
        Point p;
        cin >> p.x >> p.y;
        a.push_back(p);
    }

    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; i++){
        cout << a[i].x << " " << a[i].y << '\n';
    }

    return 0;
}
