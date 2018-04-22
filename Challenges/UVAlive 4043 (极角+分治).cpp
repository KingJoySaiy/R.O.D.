/*
 * UVAlive 4043 (����+����)
 * ��Ŀ���⣺����n���׵��n���ڵ�����꣬���ÿ���׵��Ӧ�ڵ�ı�ţ�ʹ������Եĺڰ׵㹹�ɵ��߶β��ཻ��
 */
#include<bits/stdc++.h>
#define ang(a,b) atan2(a.y-b.y,a.x-b.x) //��λ��
#define x first
#define y second
using namespace std;
typedef pair<int,int> point;

const int maxn=105;
int res[maxn<<1],n;
struct node{
    point po;
    double ang;
    int id;
    bool operator<(const node &t){
        return ang<t.ang;
    }
    int check(){
        return id<n?1:-1;   //����Ȩֵ�����ڰ׸������ʱ��Ȩֵ��Ϊ0
    }
}a[maxn<<1];

bool cmp(node a,node b){

    return a.po.y<b.po.y||a.po.y==b.po.y&&a.po.x<b.po.x;
}
void work(int l,int r){

    if(l+1>r) return;
    swap(a[l],a[min_element(a+l,a+r,cmp)-a]);   //�ҳ����㣬��l����
    for(int i=l+1;i<r;i++)
        a[i].ang=ang(a[i].po,a[l].po);
    sort(a+l+1,a+r);    //��������������

    for(int i=l+1,ct=a[l].check();i<r;i++){
        ct+=a[i].check();
        if(!ct){
            res[a[l].id]=a[i].id;   //˫����id����Ϊ��֪���ĸ��ǰ׵�
            res[a[i].id]=a[l].id;
            work(l+1,i);    //����
            work(i+1,r);
            return;
        }
    }
}
int main(){

    while(cin>>n){
        for(int i=0;i<2*n;i++){ //0~n-1�׵㣬n~2n-1�ڵ�
            scanf("%d%d",&a[i].po.x,&a[i].po.y);
            a[i].id=i;
        }
        work(0,n<<1);
        for(int i=0;i<n;i++) cout<<res[i]-n+1<<endl;
    }

//    system("pause");
    return 0;
}
/*
5
-42  58
44  86
7  28
99  34
-13  -59
-47  -44
86  74
68  -75
-68  60
99  -60
 */
