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

bool p[1000005];
void criba(){
    int n=1000005;
    p[0]=false;
    p[1]=false;
    for(int i=2;i<=n;i++){
        p[i]=true;
    }
    for(int i=2;i<=sqrt(n);i++){
        if (p[i]==true){
            for(int j=i*i;j<n;j=j+i){
                p[j]=false;
            }
        }
    }
}

int main(){
    criba();
}
