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
 
ll dp[1005][1005];
ll p[1005];
ll c[1005];
ll maxi(ll a, ll b){
    if(a>b) return a;
    else return b;
 
}
 
int main(){
    ll casos;
    ll num,n;
    cin>>casos;
    while(casos--){
        cin>>num;
        vector <ll> v;
        ll aux=num;
        ll ans=0;
        ll cont=1;
        while(aux--){
            ll a,b;
            cin>>a>>b;
            p[cont]=b;
            c[cont]=a;
            cont++;
        }
        cin>>n;
        while(n--){
            ll a;
            cin>>a;
            v.pb(a);
        }
        //inicio de mochila
        for(int k=0;k<v.size();k++){
            for(int i=0;i<=num;i++){
                dp[i][0]=0;
            }
            for(int i=0;i<=v[k];i++){
                dp[0][i]=0;
            }
            for(int i=1;i<=num;i++){
                for(int j=0;j<=v[k];j++){
                 if(p[i]>j){
                    dp[i][j]=dp[i-1][j];
                 }
                 else{
                    dp[i][j]=maxi(dp[i-1][j],dp[i-1][j-p[i]]+c[i]);
                 }
                }
            }
            //normalmete es dp[num][peso];
            ans+=dp[num][v[k]];
        }
        cout<<ans<<endl;

    }
    
 
}