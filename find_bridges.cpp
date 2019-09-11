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
//algoritmo para hallar puentes
vector <ll> v[100005];
vector <pair <ll,ll> > ans;
ll vis[1000005]={};
ll dis[1000005];
ll low[1000005];
ll tim;
void dfs(ll ini,ll p=-1){
	vis[ini]=1;
	low[ini]=dis[ini]=tim++;
	for(int i=0;i<v[ini].size();i++){
		ll vecino=v[ini][i];
		if(vecino==p) continue;
		if(vis[vecino]){
			low[ini]=min(low[ini],dis[vecino]);
		}
		else{
			dfs(vecino,ini);
			low[ini]=min(low[ini],low[vecino]);
			if(low[vecino]>dis[ini]){ans.pb(mp(ini,vecino));} 
		} 
	}
}
void find_bridge(ll n){
	tim=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
}

int main(){
    fastio;
   	ll cont=0;
   	ll n,m;
   	cin>>n>>m;
   	ll aux=m;
   	while(aux--){
   		ll a,b;
   		cin>>a>>b;
   		v[a].pb(b);
   		v[b].pb(a);
   	}
   	find_bridge(n);
   	for(int i=0;i<ans.size();i++){
   		cout<<ans[i].fs<<" "<<ans[i].sc<<endl; 
   	}
}