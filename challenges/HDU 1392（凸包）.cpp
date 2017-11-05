/*
 *
 * @ģ����
 * HDU 1392��͹����
 * ��Ŀ���⣺����n�������꣬���͹�����ܳ���
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
const double eps=1e-8;

class point{
public:
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    point operator-(point t){   //��������
        return point(x-t.x,y-t.y);
    }
    double operator*(point t){  //�������
        return x*t.y-y*t.x;
    }
    bool operator<(const point t)const{
        if(fabs(x-t.x)<eps) return y<t.y;
        return x<t.x;
    }
    double len(){   //������ģ
        return sqrt(x*x+y*y);
    }
}a[maxn],s[maxn];//aΪ��ʼ����,sΪջ

double cb(point a,point b,point o){ //����oa,ob���

    return (a-o)*(b-o);
}
void Graham(int &n){

    int top=1,tt;
    s[0]=a[0];
    s[1]=a[1];
    for(int i=2;i<n;i++){   //��ǰ����ɨ
        while(top>0&&cb(a[i],s[top],s[top-1])>=0) top--;
        s[++top]=a[i];
    }
    tt=top;
    s[++top]=a[n-2];
    for(int i=n-3;i>=0;i--){    //�Ӻ���ǰɨ
        while(top>tt&&cb(a[i],s[top],s[top-1])>=0) top--;
        s[++top]=a[i];
    }
    n=top;
}

int main(){

    int n;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a,a+n);

        int ct=0;
        for(int i=1;i<n;i++)    //ȥ���ظ��ĵ�
            if(fabs(a[i].x-a[ct].x)>eps||fabs(a[i].y-a[ct].y>eps)) a[++ct]=a[i];
        ct++;

        if(ct==1){
            puts("0.00");
            continue;
        }
        if(ct==2){
            printf("%.2lf\n",(a[0]-a[1]).len());
            continue;
        }

        Graham(ct);
        double res=(s[0]-s[ct-1]).len();
        for(int i=1;i<ct;i++) res+=(s[i]-s[i-1]).len();
        printf("%.2lf\n",res);
    }

    return 0;
}