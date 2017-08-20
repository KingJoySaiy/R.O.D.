/*
 * @ģ����
 * POJ 2689 ������ɸѡ��
 * ��Ŀ���⣺���������������������֮�����Сֵ�����ֵ��
 */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;

const int maxn=1e5+5;
int prime[maxn+1],len;  //��¼С����[1,1e5]������
bool nprime[10*maxn];   //�ж�����[l,r]�ڵ����Ƿ�Ϊ����
int a[10*maxn],n;       //����ɸѡ������[l,r]�е���������

void init(){    //����ɸ��ö������

    bool book[maxn+1]={};
    for(int i=2;i<=maxn;i++)
        if(!book[i]){
            prime[len++]=i;
            for(int j=i+i;j<=maxn;j++) book[i]=true;
        }
}
void work(int l,int r){ //����ɸѡ�����ڵ�����

    memset(nprime,0,sizeof(nprime));
    l=max(l,2);

    //��С���������ɸѡ���������ֹ��ը
    for(int i=0;i<len&&(LL)prime[i]*prime[i]<=r;i++){
        int t=l/prime[i]+!!(l%prime[i]);    //�ҳ�[l,r]����С��prime[i]����t
        if(t==1) t=2;
        for(int j=t;(LL)j*prime[i]<=r;j++)
            if((LL)j*prime[i]>=l) nprime[j*prime[i]-l]=true;
    }
    n=0;
    for(int i=0;i<=r-l;i++)
        if(!nprime[i]) a[n++]=i+l;
}
int main(){

    init();
    int l,r;
    while(cin>>l>>r){
        work(l,r);
        if(n<2) puts("There are no adjacent primes.");
        else{
            int x1=0,x2=1e8,y1=0,y2=0;
            for(int i=1;i<n;i++){   //����ö�ٸ������Ž�
                if(a[i]-a[i-1]<x2-x1){
                    x1=a[i-1];
                    x2=a[i];
                }
                if(a[i]-a[i-1]>y2-y1){
                    y1=a[i-1];
                    y2=a[i];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",x1,x2,y1,y2);
        }
    }
    return 0;
}
