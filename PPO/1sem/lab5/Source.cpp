#include <iostream>
#include <cmath>

using namespace std;

class Apex
{
public:
    double x, y;
    Apex()
    {
        x = 0;
        y = 0;
    }
    virtual double area(void) = 0;
    virtual double perimeter(void) = 0;
};

class Convex_Quadrangle : public Apex
{
public:
    double a[2], b[2], c[2], d[2];

    Convex_Quadrangle() {};

    Convex_Quadrangle(double ca[2], double cb[2], double cc[2], double cd[2])
    {
        a[0] = ca[0];
        a[1] = ca[1];
        b[0] = cb[0];
        b[1] = cb[1];
        c[0] = cc[0];
        c[1] = cc[1];
        d[0] = cd[0];
        d[1] = cd[1];
    }

    double area(void)
    {
        double S;
        S = 0.5 * abs((a[0] - b[0]) * (a[1] + b[1]) + (b[0] - c[0]) * (b[1] + b[1]) + (c[0] - d[0]) * (c[1] + d[1]) + (d[0] - a[0]) * (d[1] + a[1]));
        return S;
    }
    double perimeter(void)
    {
        double ab, bc, cd, ad, P;
        ab = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
        bc = sqrt(pow(b[0] - c[0], 2) + pow(b[1] - c[1], 2));
        cd = sqrt(pow(c[0] - d[0], 2) + pow(c[1] - d[1], 2));
        ad = sqrt(pow(a[0] - d[0], 2) + pow(a[1] - d[1], 2));
        P = ab + bc + cd + ad;
        return P;
    }
    bool intersect()
    {
        double dir1[2] = { c[0] - a[0], c[1] - a[1] };
        double dir2[2] = { d[0] - b[0], d[1] - b[1] };
        //������� ��������� ������ ���������� ����� �������
        double a1 = -dir1[1];
        double b1 = +dir1[0];
        double d1 = -(a1 * a[0] + b1 * a[1]);
        double a2 = -dir2[1];
        double b2 = +dir2[0];
        float d2 = -(a2 * b[0] + b2 * b[1]);
        //����������� ����� ��������, ��� ��������� � ����� ������������� ���
        double seg1_line2_start = a2 * a[0] + b2 * a[1] + d2;
        double seg1_line2_end = a2 * c[0] + b2 * c[1] + d2;
        double seg2_line1_start = a1 * b[0] + b1 * b[1] + d1;
        double seg2_line1_end = a1 * d[0] + b1 * d[1] + d1;
        //���� ����� ������ ������� ����� ���� ����, ������ �� � ����� ������������� � ����������� ���.
        if (seg1_line2_start * seg1_line2_end >= 0 || seg2_line1_start * seg2_line1_end >= 0)
            return false;
        return true;
    }
};

class Trapezoid : private Convex_Quadrangle
{
public:
    double A, B, C, D; //a � b - ���������, � � d - ������� �������

    Trapezoid(double cA, double cB, double cC, double cD)
    {
        A = cA;
        B = cB;
        C = cC;
        D = cD;
    }

    double area(void)
    {
        double S, k;
        k = (pow(B - A, 2) + pow(C, 2) - pow(D, 2)) / (2 * (B - A));
        S = (A + B) * sqrt(pow(C, 2) - pow(k, 2)) / 2;
        return S;
    }
    double perimeter(void)
    {
        return A + B + C + D;
    }
};

class Parallelogram : private Convex_Quadrangle
{
public:
    double a, b, h;
    Parallelogram(double ca, double cb, double ch)
    {
        a = ca;
        b = cb;
        h = ch;
    }

    double area(void)
    {
        return a * h;
    }
    double perimeter(void)
    {
        return (a + b) * 2;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y, S, P, a[2], b[2], c[2], d[2], A, B, C, D, h;
    cout << "����� ������ ���������� � ������� ������, ����� ���������� ����� �������!!!" << endl;
    cout << "������� ���������� ��������� ���������������:" << endl;
    cout << "������� ���������� ������ ����� �����: ";
    cin >> x >> y;
    a[0] = x;
    a[1] = y;

    cout << "������� ���������� ������� ����� �����: ";
    cin >> x >> y;
    b[0] = x;
    b[1] = y;

    cout << "������� ���������� ������� ������ �����: ";
    cin >> x >> y;
    c[0] = x;
    c[1] = y;

    cout << "������� ���������� ������ ������ �����: ";
    cin >> x >> y;
    d[0] = x;
    d[1] = y;

    Convex_Quadrangle q(a, b, c, d);

    if (q.intersect())
        cout << "�������� ��������������!!" << endl;
    else
        cout << "��� �� �������� ��������������!!!" << endl;

    S = q.area();
    cout << "�������: " << S << endl;

    P = q.perimeter();
    cout << "��������: " << P << endl;

    Trapezoid t(4, 2, 3, 3);

    S = t.area();
    cout << "������� ��������: " << S << endl;

    P = t.perimeter();
    cout << "�������� ��������: " << P << endl;

    Parallelogram p(2, sqrt(2), 1);

    S = p.area();
    cout << "������� ���������������: " << S << endl;

    P = p.perimeter();
    cout << "�������� ���������������: " << P << endl;

    return 0;
}