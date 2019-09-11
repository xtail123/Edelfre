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
//uva 315 AC ;v
//algoritmo para hallar puntos de articulacion
vector <ll> v[10005];
ll vis[10005]={};
ll dis[10005];
ll low[10005];
ll tim;
vector <pair <ll,ll> > g;
//set <ll> g;
ll b[10005];
void dfs(ll ini,ll p=-1){
	vis[ini]=1;
	low[ini]=dis[ini]=tim++;
	ll children=0;
	for(int i=0;i<v[ini].size();i++){
		ll vecino=v[ini][i];
		if(vecino==p) continue;
		if(vis[vecino]){
			low[ini]=min(low[ini],dis[vecino]);
		}
		else{
			dfs(vecino,ini );
			low[ini]=min(low[ini],low[vecino]);
			if(low[vecino]>=dis[ini] && p!=-1) {b[ini]++;}
			children++;
		}
	}
	if(p==-1 && children>1) b[ini]++;
}
void find_bridge(ll n){
	tim=0;
	for(int i=0;i<100005;i++){
		vis[i]=0;dis[i]=-1;low[i]=-1;b[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) {dfs(i);}
	}
}

int main(){
    fastio;
    ll n,m;
    while (cin>>n>>m) {
    	if (n == 0 && m== 0) break;
    	ll a,b;
    	cin>>a>>b;
    	if(a==-1 && b==-1 ){
    		find_bridge(n);
    		for(int i=0;i<n;i++){
    			g.pb(mp(b[i],i));
    		}
    		sor(g);
    		for(int i=0;i<m;i++){
    			cout<<g[i].sc<<" "<<g[i].fs<<endl;
    		}
    		for(int i=0;i<=n;i++){
	    	    v[i].clear();
	    	}

    	}
    	v[a].pb(b);
    	v[b].pb(a);
    }
   	

}