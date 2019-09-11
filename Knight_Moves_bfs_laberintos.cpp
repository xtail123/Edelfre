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
//movimientos que se dispone
int dx[8]={1,-1,1,-1,2,-2,2,-2};
int dy[8]={2,2,-2,-2,1,1,-1,-1};

string s1,s2;
//se define de esta manera cuando se trata de tableros
ll vis[20][20];
ll tablero[20][20];
ll costo[20][20];
//ll linea=0;
//vector <ll> order;
//punto inicial y punto al que se quiere llegar
void bfs(ll x,ll y,ll a,ll b){  
    queue <pair <ll,ll> > q;
    //defines visitado como 0
    memset(vis,0,sizeof vis);
    q.push(mp(x,y));
    vis[x][y]=1;
    costo[x][y]=0;
    while(!q.empty()){
        pair<ll,ll> actual;
        actual=q.front();
        q.pop();
        //si llegaste al final
        if(actual.fs==a && actual.sc==b){
            //aqui se manda la respuesta;
            cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<costo[a][b]<<" knight moves."<<endl;
            break;
        } 
        //tamaño del los movimientos posibles dx y dy
        for(int i=0;i<8;i++){
            ll n=actual.fs+dx[i];
            ll m=actual.sc+dy[i];
            //pruebas si encaja y si no pasate por ahi antes
            if(n>0 && n<=8 && m>0 && m<=8 && !vis[n][m]){
                q.push(mp(n,m));
                vis[n][m];
                costo[n][m]=costo[actual.fs][actual.sc]+1;
            }

        }

    }



}

int main(){
    fastio;
    while(cin>>s1>>s2){
        ll a1=s1[0]-96;
        ll b1=s1[1]-'0';
        ll a2=s2[0]-96;
        ll b2=s2[1]-'0';
        //cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        bfs(a1,b1,a2,b2);
    }
    return 0;
}