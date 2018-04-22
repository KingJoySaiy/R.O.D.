/*
 * UVA 12333 (쳲�����+�߾���+�ֵ���)
 * ��Ŀ���⣺��쳲��������в�ѯ���������Ȳ�����40��ǰ׺��
 * ��ǰ1e5��쳲��������������ǰ׺����С������ţ����ܲ����ڣ���
 */
#include<bits/stdc++.h>
using namespace std;

struct node{    //�ֵ���

    int id=-1;
    node *ne[10]={};
}*root=new node;
string a="0",b="1",sum,xx;

void insert(string t,int id){   //����������id

    node *tmp=root;
    for(int i=0,x;i<t.length();i++){
        x=t[i]-'0';
        if(tmp->ne[x]==NULL){
            tmp->ne[x]=new node;
            tmp->ne[x]->id=id;
        }
        tmp=tmp->ne[x];
    }
}
int query(string t){    //��ѯ������id�������ڷ���-1

    node *tmp=root;
    for(int i=0,x;i<t.length();i++){
        x=t[i]-'0';
        if(tmp->ne[x]==NULL) return -1;
        tmp=tmp->ne[x];
    }
    return tmp->id;
}
string add(const string &a,const string &b){    //�߾��ȼӷ�

    string res;
    int i=a.length()-1,j=b.length()-1,in=0,t;
    while(i>=0&&j>=0){
        t=a[i]-'0'+b[j]-'0'+in;
        res+=(t%10+'0');
        in=t/10;
        i--,j--;
    }
    while(i>=0){
        t=a[i]-'0'+in;
        res+=t%10+'0';
        in=t/10;
        i--;
    }
    while(j>=0){
        t=b[j]-'0'+in;
        res+=t%10+'0';
        in=t/10;
        j--;
    }
    if(in) res+=in+'0';
    reverse(res.begin(),res.end());
    return res;
}
int main(){

    insert("0",0);
    insert("1",1);
    for(int i=2;i<1e5;i++){
        sum=add(a,b);   //����쳲�������
        a=b;
        b=sum;
        if(sum.length()>40) sum=sum.substr(0,40);   //ֻ������40λ�ľ��ȼ���
        insert(sum,i);
    }
    int ct,kase=0,res;
    cin>>ct;
    while(ct--){
        cin>>xx;
        printf("Case #%d: ",++kase);
        if((res=query(xx))==-1) cout<<res<<endl;
        else cout<<res-1<<endl;     //������1�ǵ�0��쳲������������Լ�һ
    }

//    system("pause");
    return 0;
}
/*
15
1
12
123
1234
12345
9
98
987
9876
98765
89
32
51075176167176176176
347746739
5610
 */