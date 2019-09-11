#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
//primos
ll vis[105]={};
vector <ll > v[105];
vector <ll> topsor;
void dfs(ll ini){
   vis[ini]=1;
   for(int i=0;i<v[ini].size();i++){
      ll vecino=v[ini][i];
      if(!vis[vecino]){
         dfs(vecino);
      }
   }
   topsor.pb(ini);
}
void topological_sort(ll n) {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(topsor.begin(), topsor.end());
}

int main(){
    fastio;
      ll cont=0;
      ll n,m;
      while(cin>>n>>m){
         if(n==0 && m==0) break;
         while(m--){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
         }
         topological_sort(n);
         for(int i=0;i<topsor.size();i++){
            cout<<topsor[i]<<" ";
         }
         cout<<endl;
         for(int i=0;i<105;i++){
            vis[i]=0;
            v[i].clear();
         }
         topsor.clear();
      }

}