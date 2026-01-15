#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define REP(i,s,e) for(ll i=s;i<=e;++i)
const int P=1e9+7;
const int N=1e7+7;

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
    
}