/*
 * UVA 1637������+DP��
 */
#include<bits/stdc++.h>
using namespace std;

string a[9][4];
map<vector<int>,double> res;

bool read(){

    for(int i=0;i<9;i++)
        for(int j=0;j<4;j++)
            if(!(cin>>a[i][j])) return false;
    return true;
}
double dp(vector<int> &ct,int x){

    if(!x) return 1;                    //ȫ��ȡ��
    if(res.count(ct)) return res[ct];   //���仯����
    int tot=0;
    double sum=0;
    for(int i=0;i<8;i++) if(ct[i])      //ij����������ͬʱȡ��
        for(int j=i+1;j<9;j++) if(ct[j]&&a[i][ct[i]-1][0]==a[j][ct[j]-1][0]){
                tot++;
                ct[i]--;ct[j]--;
                sum+=dp(ct,x-2);
                ct[i]++;ct[j]++;
        }
    if(!tot) return res[ct]=0;          //һ�ζ�ȡ������ʧ��
    return res[ct]=sum/tot;             //ȫ����
}
void solve(){

    res.clear();
    vector<int> ct(9,4);    //��ʼ��Ϊ4����¼ʣ���Ƶĸ���
    printf("%.6lf\n",dp(ct,36));
}
int main(){

    while(read()) solve();
//    system("pause");

    return 0;
}
/*
AS 9S 6C KS
JC QH AC KH
7S QD JD KD
QS TS JS 9H
6D TD AD 8S
QC TH KC 8D
8C 9D TC 7C
9C 7H JH 7D
8H 6S AH 6H
 */
