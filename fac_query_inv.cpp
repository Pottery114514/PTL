#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define REP(i,s,e) for(ll i=s;i<=e;++i)
const int P=1e9+7;
const int N=1e7+7;
ll fac[N];
void init(){
    fac[0]=1;//定义如此
    REP(i,1,N)fac[i]=fac[i-1]*i%P;
}
//求逆元
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%P;
        a=a*a%P;b>>=1;
    }
    return res;
}
ll inv(ll x){return qmi(x,P-2);}

ll C(ll n,ll m){
    if(n<0||m<0||n<m)return 0;
    return fac[n]*inv(fac[m])%P*inv(fac[n-m])%P;//一定要在每次乘法后立即取模
}

int main(){
    init();
    int n,m;cin>>n>>m;
    cout<<C(n,m)<<'\n';
    return 0;
}