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

vector <pair<string,string> > g;
map <string , int> m;
//map <int , string> m1;
set<string> s;
vector <int> v[20005];
//vector <pair<string,string> > g;
ll low[20005];
ll num[20005];
vector <ll> pila;
ll cont=1,sol=0;
ll vis[20005];
ll comp[20005];

void tarjan(ll ini){
    vis[ini]=1;
    low[ini]=num[ini]= cont++;
    pila.pb(ini);
    for(int i=0;i<v[ini].size();i++){
        ll vecino=v[ini][i];
        if(num[vecino]==-1) tarjan(vecino);
        if(vis[vecino]){
            low[ini]=min(low[ini],low[vecino]);
        }
    }
    if(low[ini]==num[ini]){
        while(1){
            ll aux=pila.back();
            pila.pop_back();
            vis[aux]=0;
            comp[aux]=sol;
            if(ini==aux) break;
        }
        sol++;
    }
}  

int main(){
    fastio;
    int casos;
    cin>>casos;
    //defines el vector y si la posicion i tiene num[i]==-1 aplicas tarjan
}