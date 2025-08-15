//记住所有的操作都在根即代表节点上
//注意没有进行根节点更新,最后还要遍历一次才能更新.
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int fa[N];

void init(int n) {for (int i=1;i<=n;++i) fa[i]=i;}

int root(int id)//路径压缩的原理是直接指向根而不是先导节点
{
   if(fa[id]==id) return fa[id];
   else return fa[id]=root(fa[id]);
   //return fa[id]=(fa[id]==id ? id : root(fa[id]));
}

void fix(int i,int j) {fa[root(i)]=root(j);}

bool isSame(int x,int y){return root(x)==root(y);}
