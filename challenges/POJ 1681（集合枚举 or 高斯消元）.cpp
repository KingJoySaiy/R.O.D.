/*
 * @ģ����
 * POJ 1681������ö�� or ��˹��Ԫ��
 * ��Ŀ���⣺��������,��ʹ������ɫ��Ϊ��ɫ������С������
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;
const int maxn=20;
const int dx[]={0,-1,0,0,1};
const int dy[]={-1,0,0,1,0};
int n,ct;
char a[maxn][maxn];
bool b[maxn][maxn];     //b�����ɫ

bool check(int x,int y){  //�ж�(x,y)�Ƿ���Ҫ��ת

    int c=a[x][y];
    for(int i=0;i<5;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(tx>=0&&ty>=0&&tx<n&&ty<n) c+=b[tx][ty];
    }
    return c&1;
}
int calc(){             //��֪��1�У�����С������

    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            if(check(i-1,j)) b[i][j]=true;

    for(int j=0;j<n;j++)    //������һ�в�ȫΪ�ף����޽�
        if(check(n-1,j)) return -1;

    int ct=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ct+=b[i][j];

    return ct;
}
int main() {

    scanf("%d",&ct);
    while(ct--) {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'y') a[i][j] = 0;    //��ɫ���Ϊ0������Ϊ1
                else a[i][j] = 1;
            }

        int res = INT_MAX;
        for (int i = 0; i < (1 << n); i++) {
            memset(b, 0, sizeof(b));
            for (int j = 0; j < n; j++)
                b[0][j] = (i >> j) & 1;

            int t = calc();
            if (t != -1 && res > t) {
                res = t;
            }
        }

        if (res == INT_MAX) puts("inf");
        else cout << res << endl;
    }
    return 0;
}