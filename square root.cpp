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
const ll mod=998244353;

ll tree[200005];
ll a[200005];
ll block[200005];
ll b[200005];
ll sz;//tamaño de los bloques

void update(ll indice,ll val){
    ll p=indice/sz;
    block[p] += val - b[indice]; 
    b[indice]= val;
}
ll query(ll l,ll r){
    ll ans=inf;
    while(l<r && l%sz!=0 ){
        //sum+= b[l];
        ans=min(ans,b[l]);
        l++;
    }
    while(l+sz <=r){
        //sum+= block[l/sz];
        ans= min(ans,block[l/sz]);
        l +=sz ;
    }
    while(l<=r){
        //sum+= b[l];
        ans= min(ans,b[l]);
        l++;
    }
    return ans;
}

void build(ll a[],ll n){
    ll index=-1;
    sz=sqrt(n);
    for(int i=0;i<sz+10;i++){
        block[i]=inf;
    }
    for(int i=0;i<n;i++){
        //guardamos para futuros cambios updates
        b[i]= a[i];
        if(i % sz == 0 ){
            index++;
        }
        //operacion
        block[index] = min(block[index],a[i]);
    }
}
int main(){
    fastio;
    ll casos;
    cin>>casos;
    ll cont=1;
    while(casos--){
        ll n,m;
        cout<<"Scenario #"<<cont<<":"<<endl;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>tree[i];
        }
        build(tree,n);
        while(m--){
            ll a,b;
            cin>>a>>b;
            //cout<<a<<" "<<b<<endl;
            cout<<query(a-1,b-1)<<endl;
        }
        cont++;
    
    }



}
