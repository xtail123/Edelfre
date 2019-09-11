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


int main(){
    fastio;
    ll casos;
    cin>>casos;
    while(casos--){
        ll a;
        cin>>a;
        if(a==1) cout<<0<<endl;
        else if(a==2 || a==3) cout<<1<<endl;
        else if(a>=4 && a<= 7) cout<<2<<endl;
        else cout<<3<<endl;
    }

}