/*
 * @ģ����
 * POJ 1127 �����㼸��+���鼯��
 * ��Ŀ���⣺���������߶ε����˵����꣬�ж����߶��Ƿ��ཻ�����ཻ��
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#define x first
#define y second
using namespace std;

const double eps=1e-10;
const int maxn=15;
int n,par[maxn],ran[maxn];//��¼���鼯�����Ⱥ����

struct line{

    pair<int,int> l;
    pair<int,int> r;

};
int find(int xx){//�ҳ�xx������

    return par[xx]==xx?xx:par[xx]=find(par[xx]);
}
void unite(int a,int b){//��a��b�߶���ͬ����b�ӵ�a��

    a=find(a);
    b=find(b);
    if(a==b) return;
    if(ran[a]<ran[b]) par[a]=b;
    else{
        par[b]=a;
        if(ran[a]==ran[b]) ran[a]++;
    }
}
bool check(line xx,line yy){    //�ж����߶��Ƿ��ཻ

    pair<int,int> a=xx.l,b=xx.r,c=yy.l,d=yy.r;
    int e,f,g,h;

    //�����ų�ʵ��
    if(min(a.x,b.x)>max(c.x,d.x)||min(a.y,b.y)>max(c.y,d.y)||
       min(c.x,d.x)>max(a.x,b.x)||min(c.y,d.y)>max(a.y,b.y)) return false;

    //����ʵ��
    e=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    f=(b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
    g=(d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x);
    h=(d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-c.x);
    return e*f<=eps&&g*h<=eps;
}
int main(){

    while(cin>>n,n){
        for(int i=1;i<=n;i++){  //��ʼ�����鼯
            par[i]=i;
            ran[i]=1;
        }
        line a[n+1];        //����ÿ���߶ε����˵�����
        for(int i=1;i<=n;i++)
            cin>>a[i].l.x>>a[i].l.y>>a[i].r.x>>a[i].r.y;

        for(int i=1;i<n;i++)//���ݹ�ϵ������
            for(int j=i+1;j<=n;j++)
                if(check(a[i],a[j])) unite(i,j);

        int p,q;    //��ѯ�߶μ�Ĺ�ϵ
        while(cin>>p>>q,p||q){
            puts((find(p)==find(q))?"CONNECTED":"NOT CONNECTED");
        }
    }
    return 0;
}

