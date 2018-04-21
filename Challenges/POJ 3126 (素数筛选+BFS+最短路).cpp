/*
 * POJ 3126 (����ɸѡ+BFS+���·)
 * ��Ŀ���⣺����������λ��������ÿ�θı�ĳһλ��Ϊ��һ������������С����������
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = int(1e4);
vector<int> prime;
int x, y, len;

struct node{        //s->��ǰ����, step->��������

    int s, step;
    node(int s,int step):s(s),step(step){}
    node(){}
    node operator = (const node &t){
        s = t.s;
        step = t.step;
        return *this;
    }
};

void ini(){     //����ɸ�������λ����������

    bool book[maxn] = {};
    for(int i = 2; i < maxn; i++){
        if(!book[i]){
            if(i > 999) prime.push_back(i);
            for(int j = i + i; j < maxn; j += i) book[j] = true;
        }
    }
    len = prime.size();
}
inline int f(const int &x, const int &i){      //����x��iλ����

    switch(i){
        case 0: return x / 1000;
        case 1: return (x/100) % 10;
        case 2: return (x/10) % 10;
        default : return x % 10;
    }
}
inline int work(const int &x, const int &i, const int &tt){ //�ı�x��iλ����Ϊtt

    switch(i){
        case 0: return x % 1000 + tt * 1000;
        case 1: return x / 1000 * 1000 + x % 100 + tt * 100;
        case 2: return x / 100 * 100 + x % 10 + tt * 10;
        default: return x / 10 * 10 + tt;
    }
}
void solve(){

    cin >> x >> y;
    map<int,bool> book;     //��������Ƿ��Ѿ����ֹ�
    int num[10], id, tt;
    queue<node> que;
    que.push(node(x, 0));

    node t;
    while(!que.empty()){     //BFS

        t = que.front(); que.pop();
        if(t.s == y){
            cout<<t.step<<endl;
            return ;
        }
        for(int i = 0; i < 4; i++){
            memset(num, 0, sizeof(num));    //���0 - 9����Щ���ֿ���
            if(!i) num[0] = 1;              //ע�ⲻ�ܳ���ǰ��0
            num[f(t.s,i)] = 1;
            for(int j = 0; j < 10; j++)
                if(!num[j]){
                    tt = work(t.s,i,j);
                    id = lower_bound(prime.begin(), prime.end(),tt) - prime.begin();
                    
                    //tt��������������δ��ǹ�
                    if(id == len or prime[id] != tt or book.count(tt)) continue;
                    que.push(node(tt,t.step+1));
                    book[tt] = true;
                }
        }
    }
}
int main(){

    ini();
    int ct;
    cin >> ct;
    while(ct--) solve();

//    system("pause");
    return 0;
}