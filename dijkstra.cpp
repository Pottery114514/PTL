//单源带权最短路径,原理是贪心+dp,拓展后的点的距离即是最短路

/*
示例数据
5 9
1 2 4 1 3 2 2 3 3 3 2 1 2 4 2 2 5 3 3 4 4 3 5 5 5 4 1
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e5+5,inf=1e9+7;
int n,m,st=1;
struct E
{
    int x;int y;
    bool operator < (const &E a) const{return y>a.y;}
};//{后节点,权}
vector<E> g[N];
int dist[N];
bitset<N> vis; 

void dijkstra1()
{
    //外循环确保所有点都拓展过,内循环找到距离当前出点最近的点.
    for (int i=1;i<=n;++i)
    {
        int u=1;
        for (int j=1;j<=n;++j)
            //找到一个没拓展过的中的最小的,注意对初始u是否访问过的判断!!
            if ((!vis[j]&&dist[j]<dist[u])||vis[u]) u=j;//
        vis[u]=1;
        for (auto &[v,w]:g[u])if(!vis[v]&&dist[v]>dist[u]+w) dist[v]=dist[u]+w;
    }
}
void dijkstra2()
{
    priority_queue<E> pq; pq.push({st,dist[st]});
    while(pq.size())
    {
        int x=pq.top().x; pq.pop();
        //重边,也就是说pq中可能会出现多个出点相同的边.延迟修改vis故需判断.
        if (vis[x])continue;
        vis[x]=1;
        for (auto &[y,w]:g[x])
        {
            if (!vis[y]&&dist[y]>dist[x]+w){dist[y]=dist[x]+w;pq.push({y,dist[y]});}
        }
    }
}
void init()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        int u,v,w;cin>>u>>v>>w;
        if (u!=v)g[u].push_back({v,w});
    }
    memset(dist,0x3f,sizeof(dist));dist[st]=0;
}
int main()
{
    init();
    dijkstra();
    for (int i=1;i<=n;++i) cout<<dist[i]<<' ';
    return 0;
}
