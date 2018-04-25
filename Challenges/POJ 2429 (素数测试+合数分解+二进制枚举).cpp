/*
 * POJ 2429 (��������+�����ֽ�+������ö��)
 * ��Ŀ���⣺������������gcd��lcm��������֮����С����������������
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long LL;

const int S = 8;
vector<LL> fact;    //��¼����
map<LL,int> a;      //��¼ÿ�����ӵĸ���
LL x,y;

LL mod_mult(LL x,LL y,const LL &mod){  //return x*y%mod

    LL res = 0;
    while(y){
        if(y & 1) res = (res + x) % mod;
        x = (x << 1) % mod;
        y >>= 1;
    }
    return res;
}
LL mod_pow(LL x,LL n,const LL &mod){   //return x^n%mod

    LL res = 1;
    while(n){
        if(n & 1) res = mod_mult(res,x,mod);
        x = mod_mult(x,x,mod);
        n >>= 1;
    }
    return res;
}
LL poww(LL x,LL n){

    LL res = 1;
    while(n){
        if(n & 1) res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}
bool check(LL a,LL n,LL x,LL t){    //���ʲ���n�Ƿ�Ϊ����

    LL now = mod_pow(a,x,n), pre = now;
    for(int i = 0; i < t; i++){
        now = mod_mult(now,now,n);
        if(now == 1 and pre != 1 and pre != n-1) return true;   //����̽��
        pre=now;
    }
    return now != 1;
}
bool Miller_Rabin(LL n){    //�ж�n�Ƿ�Ϊ����

    if(n == 2) return true;
    if(n < 2 || (n & 1) == 0) return false;
    LL x = n-1, t = 0;   //n-1 = x*2^t
    while((x & 1) == 0){
        x >>= 1;
        t ++;
    }
    for(int i = 0;i < S; i++){
        LL a = rand() % (n - 1) + 1;
        if(check(a,n,x,t)) return false;
    }
    return true;
}
LL gcd(LL a,LL b){  //����С������

    LL res = b ? gcd(b,a % b) : a;
    return res < 0 ? -res : res;  //ע�⴦�������
}
LL pollard_rho(LL x,LL c){  //���x��һ������

    LL i = 1, k = 2;
    LL x1 = rand() % (x-1) + 1, x2 = x1;
    while(1){
        i ++;
        x2=(mod_mult(x2,x2,x) + c) % x;
        LL d = gcd(x1-x2,x);
        if(d != 1 and d != x) return d;    //��gcd��Ϊ1�򷵻�����
        if(x1 == x2) return x;
        if(i == k){
            x1 = x2;
            k += k;
        }
    }
}
void find_fac(LL n,int k){    //�ҳ�����¼����

    if(n == 1) return;
    if(Miller_Rabin(n)){
        fact.push_back(n);
        a[n]++;
        return;
    }
    LL p = n;
    while(p >= n) p = pollard_rho(p,k--);
    find_fac(p,k);   //����Ѱ������
    find_fac(n / p, k);
}
void solve(){

    if(x == y){
        cout<<x<<' '<<y<<endl;
        return;
    }
    fact.clear();
    a.clear();
    LL z = y/x, base = x;   //�����������������base�ı������ֽ�lcm/gcd����
    find_fac(z,107);        //cһ����Ϊ107�μ���
    pair<LL,LL> res = make_pair(LL(2.3e18),LL(2.3e18)); //��ȡ�����󣬵�����֮�Ͳ��ܱ�LL
    sort(fact.begin(),fact.end());
    int ct = unique(fact.begin(),fact.end()) - fact.begin();    //�����ӽ���ȥ��
    for(int i = 0; i < (1 << ct); i++){     //�����Ʊ���ö���������
        x = 1;
        for(int j = 0; j < ct; j++)
            if(i & (1<<j)) x *= poww(fact[j],a[fact[j]]);   //ÿ�ν���ͬ���������Ӷ�������
        if(x + z/x < res.first + res.second) res = make_pair(x,z/x);
    }
    if(res.first > res.second) swap(res.first,res.second);
    printf("%lld %lld\n",res.first * base, res.second * base);
}
int main(){

    while(scanf("%lld%lld",&x,&y) != -1) solve();

//    system("pause");
    return 0;
}