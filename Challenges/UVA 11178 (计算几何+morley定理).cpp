/*
 * UVA 11178 (���㼸�� + morley����)
 * ��Ŀ���⣺�����������������㣬�ֱ��������ڽǵ������ߣ����Ӧ�������ߵ�������������
 */
#include <bits/stdc++.h>

using namespace std;

struct Point;
typedef Point Vector;

const double eps = 1e-10;

int dcmp(double x) {     //�ж�x�Ƿ�Ϊ0

    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
struct Point{

    double x, y;
    Point(double x = 0, double y = 0):x(x),y(y){}
    double len(){       //�����ĳ���
        return sqrt(x * x + y * y);
    }
    Vector operator +(const Vector &b) const {       //����+����
        return Vector(x + b.x, y + b.y);
    }
    Vector operator -(const Point &b) const {        //����-���� or ��-��
        return Vector(x - b.x, y - b.y);
    }
    double operator ^(const Vector &b) const {       //�����Ĳ��
        return x * b.y - y * b.x;
    }
    double operator *(const Vector &b) const {       //�����ĵ��
        return x * b.x + y * b.y;
    }
    double angle(Vector &b){           //�������ļн�
        return acos((*this * b) / len() / b.len());
    }
    void trans_XY(double B) {           //��ԭ������B�����ȣ�
        double tx = x, ty = y;
        x = tx * cos(B) - ty * sin(B);
        y = tx * sin(B) + ty * cos(B);
    }
};
struct Line{

    Point s, e;
    Line(){}
    Line(Point s, Point e):s(s),e(e){}
    pair<int, Point> operator &(const Line &b) const {   //��ֱ���ཻ�󽻵�

        //��һ��ֵΪ0��ʾֱ���غϣ�Ϊ0��ʾ�غϣ�Ϊ1��ʾƽ�У�Ϊ2���ཻ
        Point res = s;
        if (dcmp((s - e) ^ (b.s - b.e)) == 0){
            if (dcmp((s - b.e) ^ (b.s - b.e)) == 0) return make_pair(0, res);    //�غ�
            else return make_pair(1, res);              //ƽ��
        }
        double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e)); //�õ����ȷֵ�
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return make_pair(2, res);                        //ֻ�е�һ��ֵΪ2ʱ�������������
    }
};
Point a, b, c;
Point d, e, f;

Point work(Point A, Point B, Point C){

    Vector v1 = C - B, v2 = B - C;

    v1.trans_XY((A - B).angle(v1) / 3);     //v1��ʱ����ת
    v2.trans_XY(-(A - C).angle(v2) / 3);    //v2˳ʱ����ת
    Line l1(B, B + v1), l2(C, C + v2);

    return (l1 & l2).second;    //��������ֱ�߱�Ȼ�н��㣬�����ж�
}
int main(){

    int ct;
    cin>>ct;
    while(ct--){
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        d = work(a, b, c);
        e = work(b, c, a);
        f = work(c, a, b);
        printf("%.6f %.6f %.6f %.6f %.6f %.6f\n", d.x, d.y, e.x, e.y, f.x, f.y);
    }


//    system("pause");
    return 0;
}
/*
2
1 1 2 2 1 2
0 0 100 0 50 50
 */