#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e6+7;
ll vec[N],t[4*N],lazy[4*N];//原数组,线段树,延迟处理.

void pd(int i,int l,int r)
{
    if (lazy[i])
    {
        int m=(l+r)/2;
        //传递标记到左子节点
		t[i*2]+=lazy[i]*(m-l+1);
		lazy[i*2]+=lazy[i];//之前可能存过标记,so +=,not =
		//右
		t[i*2+1]+=lazy[i]*(r-m);
		lazy[i*2+1]+=lazy[i];
		lazy[i]=0;
    }
    
}

void init(int i,int l,int r)
{
    if (l==r) t[i]=vec[l];
    int m=(l+r)/2;
    init(i*2,l,m); init(i*2+1,m+1,r);
    t[i]=t[i*2]+t[i*2+1];
}

ll sum(int i,int l,int r,int gl,int gr)
{
    if(l>gr||r<gl) return 0;
    if (l>=gl&&r<=gr) return t[i];

    pd(i,l,r);
    int m=(l+r)/2;
    return sum(i*2,l,m,gl,gr)+sum(i*2+1,m+1,r,gl,gr);
}

void update(int i,int l,int r,int gl,int gr,int add)
{
    if (l>gr||r<gl) return;
    if(l>=gl&&r<gr)
    {
        t[i]+=add*(r-l+1);
        lazy[i]+=add;
        return;
    }
    pd(i,l,r);
    int m=(l+r)/2;
    update(i*2,l,m,gl,gr,add);update(i*2+1,m+1,r,gl,gr,add);
    t[i]=t[i*2]+t[i*2+1];
}
