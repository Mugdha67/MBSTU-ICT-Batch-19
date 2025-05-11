#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define debug(x) cout << #x << " " << x << endl
#define sze(a) (int)(a.size())
#define srt(v) sort((v).begin(), (v).end())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
}
void solve()
{
    int n; cin >> n;
    vector<vector<int>>v(2*n-1,vector<int>(2*n-1,0));
    int pi = 0, pj = (2*n-1)/2,cnt=0;
    int ci = pi,cj = pj;
    for (int i = 1; i <= n*n; i++) {
        v[pj][pi] = i;
        ++pi;
        --pj;
        cnt++;
        if(cnt == n){
            pi = ++ci;
            pj = ++cj;
            cnt = 0;
        }
    }
    
    int pos = n/2;
    for(int i = 0; i < 2*n-1; i++){
        for(int j = 0; j < 2*n-1; j++){
            if(i>=pos && i < pos + n && j >= pos && j < pos + n) continue;
            if(i < pos && v[i+n][j] == 0){
                v[i+n][j] = v[i][j];
            }
            else if(j < pos && v[i][j+n] == 0){
                v[i][j+n] = v[i][j];
            }
            else if(j >= pos + n && v[i][j-n] == 0){
                v[i][j-n] = v[i][j];
            }
            else if(i >= pos + n && v[i-n][j] == 0){
                v[i-n][j] = v[i][j];
            }
        }
    }
    for(int i = n/2; i < n/2+n; i++){
        for(int j = n/2; j < n/2+n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

solve();
}