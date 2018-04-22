/*
 * UVA 10479 (����+DFS)
 * ��Ŀ���⣺����һ�����У������¹��򣺵�һ������0��ÿ�ζ���ǰһ���Ƴ�����ÿ������x�������x��0��
 * �����x+1��0 -> 1 -> 02 -> 1003 -> 02110004...���̶�����Ϊ:0102100302110004...��
 * ��������е�n����Ϊ���٣�0<n<2^63��
 */
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

ULL a[64];

int dfs(ULL n,int p){//��p�ѵ�n����

    int ct=1;      //��i����ct����ct=1,2,3...p-1
    ULL len;       //��i�ѵĳ���
    for(int i=p-2;i>=0;i--){
        len=i?a[i-1]:1;     //ע���0�ѳ���Ϊ1
        for(int j=0;j<ct;j++){
            if(n>len) n-=len;
            else return dfs(n,i);
        }
        ct++;
    }
    return p;   //��p�����λ��Ϊp
}
int main(){

    ULL n;
    for(int i=0;i<64;i++) a[i]=1ull<<i;
    while(cin>>n,n){
        size_t t=lower_bound(a,a+64,n)-a;
        cout<<dfs(n-a[t-1],t)<<endl;    //�ҵ�n�ڵ�t�ѵ�n-a[t]��
    }

//    system("pause");
    return 0;
}
/*
4
7
44
806856837013209088
0
 */