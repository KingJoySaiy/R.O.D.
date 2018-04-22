/*
 * UVA 1635�������ѧ��
 * ��Ŀ���⣺��
 */
#include<bits/stdc++.h>
using namespace std;

const int maxn=int(1e5+5);
bool bad[maxn];

void fact(int m,vector<int> &primes){  //m�ֽ�����

    int x=int(sqrt(m)+0.5);
    for(int i=2;i<=x;i++){
        if(m%i==0){
            primes.push_back(i);
            while(m%i==0) m/=i;
        }
    }
    if(m>1) primes.push_back(m);
}
int main(){

    int n,m;
    while(cin>>n>>m){

        memset(bad,false,sizeof(bad));
        vector<int> primes;
        fact(m, primes);
        n--;

        // ��c(n,0)~c(n,n)����Щ����m�ı���
        for(int i=0;i<primes.size();i++){
            int p=primes[i],e=0;    //C(n,0)=p^e
            int min_e=0,x=m;
            while(x%p==0){
                x/=p;
                min_e++;
            }
            // c(n,k)=c(n,k-1)*(n-k+1)/k
            // ��k�������prime[i]��ϵ��������min_e���ܱ�����
            for(int k=1;k<n;k++){
                x=n-k+1;
                while(x%p==0){
                    x/=p;
                    e++;
                }
                x=k;
                while(x%p==0){
                    x/=p;
                    e--;
                }
                if(e<min_e) bad[k]=true;    //��k��ܱ�����
            }
        }
        vector<int> res;
        for(int k=1;k<n;k++) if(!bad[k]) res.push_back(k+1);
        cout<<res.size()<<endl;
        if(!res.empty()){
            cout<<res[0];
            for(int i=1;i<res.size();i++) cout<<' '<<res[i];
        }
        puts("");
    }
    return 0;
}

