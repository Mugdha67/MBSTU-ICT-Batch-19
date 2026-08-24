#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b) / gcd(a,b)
#define ll long long int
#define ld long double
#define pb push_back
#define endl "\n"
#define pi acos(-1)
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define no  cout<<"no\n"
#define NO  cout<<"NO\n"
#define No  cout<<"No\n"
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fin(a) for (auto &x : a) cin>>x
#define fout(a) for (auto &x : a) cout<<x<<" "; cout<<endl;
//const int MAX = 10005;
//vector<int> adj[MAX];
//bool visited[MAX];
//void dfs(int u) {
//visited[u] = true;
//for (int v : adj[u]) {
//if (!visited[v]) {
//dfs(v);
//}
//}
//}
bool composite(int n)
{
if(n<4) return false;
for(int i=2;i*i<=n;i++)
{
if(n%i==0) return true;
}
return false;
}
void Kuldip_Saha_Mugdha()
{
     string ip;
     cin>>ip;
        int n=ip.size();
        int a = (ip[0]-'0')*100 + (ip[1]-'0')*10 + (ip[2]-'0');
        if(a>=0 && a<=127)
        cout<<"Class A"<<endl;
        else if(a>=128 && a<=191)
        cout<<"Class B"<<endl;
        else if(a>=192 && a<=223)
        cout<<"Class C"<<endl;
        else if(a>=224 && a<=239)
        cout<<"Class D"<<endl;
        else
        cout<<"Class E"<<endl;
}
//int32_t main()
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int t; cin>>t; while(t--)
    Kuldip_Saha_Mugdha();
}