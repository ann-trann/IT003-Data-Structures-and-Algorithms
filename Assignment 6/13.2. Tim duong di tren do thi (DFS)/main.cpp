#include <bits/stdc++.h>
using namespace std;

vector<char> ke[1005];
bool ok[1005];
char truoc[1005];
vector<string> vt;

void dfs(char u, char v)
{
    if (ok[v]) return ;
    ok[u] = true;
    for (int i = 0; i < ke[u].size(); i++)
        if (!ok[ke[u][i]])
        {
            truoc[ke[u][i]] = u;
            dfs(ke[u][i], v);
        }
}

void trace(char u, char v)
{
    string s;
    if (!ok[v])
    {
        s =  "no_path";
        vt.push_back(s);
        return ;
    }
    vector<char> a;
    while(u != v)
    {
        if (u == 0)
        {
            s =  "no_path";
            vt.push_back(s);
            return ;
        }
            a.push_back(u);
            u = truoc[u];
    }
    a.push_back(v);
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++){
        s = s + a[i] + " ";
    }
        vt.push_back(s);
}

int main(){
    memset(ok, false, sizeof(ok));
    memset(truoc, 0, sizeof(truoc));
    for (int i = 0; i < 1001; i++)
        ke[i].clear();
    int a, b;
    char nguon, dich;
    cin >> a >> b;

    for (int i = 0; i < a; i++){
        char x; cin >> x;
    }

    for (int i = 0; i < b; i++)
    {
        char u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        //ke[v].push_back(u);
    }

    int t; cin >> t;
    while (t--)
    {
        memset(ok, false, sizeof(ok));
        memset(truoc, 0, sizeof(truoc));
        cin >> nguon >> dich;
        dfs(nguon, dich);
        trace(dich, nguon);
    }

    for (string x : vt)
        cout << x << "\n";

    return 0;
}


/*

6 13
W K I U M Q
W M
W Q
I W
I K
I U
I M
U W
U K
U Q
M U
M Q
Q I
Q M
3
U I
W K
K M

*/












