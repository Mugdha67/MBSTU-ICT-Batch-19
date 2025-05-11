#include<bits/stdc++.h> 
using namespace std;
 void generate(int n)
 {
if(!n&1)
    {
        cout<<"Not applicable . \n"; return;
    }
    int l=2*n-1;
    vector<vector<int>>v(l,vector<int>(l,0));
        int x=l/2,y=0;
        int rx=x,rc=y;
        int cnt=0;
        for(int i=1;i<=n*n;i++)
        {
            v[rx][rc]=i;
            rx--; rc++;
            cnt++;
            if(cnt==n)
            {
                cnt=0;
                rx=++x; rc=++y;
            }
        }

        for(int i=n/2;i<l-(n/2);i++)
        {
            for(int j=n/2;j<l-(n/2);j++)
            {
               if(v[i][j]==0)
               {
                   if(i+n<l&&v[i+n][j]!=0)
                   {
                      v[i][j]=v[i+n][j];
                   }
                   else  if(j+n<l&&v[i][j+n]!=0)
                   {
                      v[i][j]=v[i][j+n];
                   }
                   else if(i-n>=0&&v[i-n][j]!=0)
                   {
                      v[i][j]=v[i-n][j];
                   }
                   else if(j-n>=0&&v[i][j-n]!=0)
                   {
                      v[i][j]=v[i][j-n];
                   }
               }
            }
        }
 for(int i=n/2;i<l-(n/2);i++)
        {
            for(int j=n/2;j<l-(n/2);j++)
            {
             cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
 }
void solve()
{
    int n; cin>>n; 
    generate(n);
    
}
int32_t main()
{
   ios_base::sync_with_stdio (0);
   cin.tie (0);
   cout.tie (0);
   //int t; cin>>t; while(t--)
   solve();
}