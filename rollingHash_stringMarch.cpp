/*
rolling hash is a hash function that efficiently computes the hash value 
for a sliding window of data. 
It is particularly useful in applications like approximate string matching,
repeated substring detection, and data deduplication. 
The key advantage of a rolling hash is that it allows the hash value 
to be updated incrementally as the window moves, 
avoiding the need to recompute the hash from scratch for each new position.
总之,滚动哈希为容器中每个元素分配伪随机数作为唯一识别码
*/
//应用案例:字符串检索
/**
不同于直接标号,注意如何保证相同串一定使用相同哈希值的
*/
#include<bits/stdc++.h>
using namespace std;
using ull= unsigned long long;
#define REP(i,s,e) for(int i=s;i<=e;++i)
const ull base=131;

int n,m;
vector<string> vec;
unordered_set<ull> H;

ull toH(const string& s){
    ull h=0;
    for(auto c:s)h=h*base+c;//key
    return h;
}

void march(){
    cin>>n>>m;
    vec.resize(n);H.clear();
    REP(i,0,n-1){
        cin>>vec[i];H.insert(toH(vec[i]));
    }
    REP(i,1,m){
        string qs;cin>>qs;
        //使用toH()同一套规则
        auto cur=toH(qs);
        if(H.count(cur))cout<<1;
        else cout<<0;
    }

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    march();
    return 0;
}