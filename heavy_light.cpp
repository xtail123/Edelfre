#include<bits/stdc++.h>
#define pi acos(-1);
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define sor(a) sort( a.begin(), a.end() )
#define rsor(a) sort( a.rbegin(), a.rend() )
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define inf 1LL<<62
typedef long long ll;
using namespace std;

//ll dp[505][20005];
ll dp[1005][25][80]={inf};
ll p1[1005];
ll p2[1005];
ll val[1005];

int main(){
    fastio;
    ll casos;
    cin>>casos;
    while(casos--){
        ll o,n;
        cin>>o>>n;
        ll m;
        cin>>m;
        for(int i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            p1[i+1]=a;
            p2[i+1]=b;
            val[i+1]=c;
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<=o;j++){
                for(int w=0;w<=n;w++){
                    if(p1[i]>j && p2[i]>w){
                        dp[i][j][w]=dp[i-1][j][w];
                    }
                    if(j>=p1[i] && w>= p2[i]){
                        dp[i][j][w]=min(dp[i-1][j][w],dp[i-1][j-p1[i]][w-p2[i]]+val[i]);
                    }
                }
            }
        }
        cout<<dp[m][o][n]<<endl;
        
        
        
    }
    
    
    
    
    
    
    
}