
const int N=1e5+7;
struct E
{
    int x;int y;
    bool operator<(const E &a)const
    {
        return y>a.y;
    }
};
int n,m,ans,d[N];
vector<E> g[N];bitset<N>vis;
void solve()
{
    //init
    cin>>n>>m;
    memset(d,0x3f,sizeof(d));
    
    for (int i=1;i<=m;++i)
    {
        int u,v,w;cin>>u>>v>>w;
        if (u!=v){g[u].push_back({v,w});g[v].push_back({u,w});}
    }
    priority_queue <E> pq;
    pq.push({1,0});

    //op
    while(pq.size())
    {
        auto [x,y]=pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x]=1;
        ans+=y; d[x]=0;
        for (auto& [v,w]:g[x])//相邻且不在树中
        {
            if (!vis[v]&&w<d[v]) {d[v]=w;pq.push({v,d[v]});}//cout<<"ins "<<v<<' ';
        }
    }
    for (int i=1;i<=n;++i) if (!vis[i]) ans=-1;

}

