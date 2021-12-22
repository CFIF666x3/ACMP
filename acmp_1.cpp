using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#pragma warning(disable : 4996)

class Point
{
private:
	double x, y;
public:
	Point()
	{}
	Point(int n, int m)
	{
		x = n; y = m;
	}
	Point Maxx(Point p)
	{
		if (x >= p.x) return *this;
		else return p;
	}
	Point Miny(Point p)
	{
		if (y >= p.y) return *this;
		else return p;
	}
	double angleX(Point p)
	{
		return atan((p.y - y) / (p.x - x));
	}
	Point rotate(double a)
	{
		Point p;
		p.x = x * cos(a) + y * sin(a);
		p.y = -x * sin(a) + y * cos(a);
		return p;
	}
	int isinrect(Point A, Point B, Point C, Point D)
	{
		if (A.x == B.x or A.y == B.y)
		{
			int Max_x = max(max(A.x, B.x), C.x), Max_y = max(max(A.y, B.y), C.y), Min_x = min(min(A.x, B.x), C.x), Min_y = min(min(A.y, B.y), C.y);
			if (x >= Min_x and x <= Max_x and y >= Min_y and y <= Max_y) return 1;
			else return 0;
		}
		else
		{
			double alpha = (A.Maxx(B)).Maxx(C.Maxx(D)).angleX((A.Miny(B)).Miny(C.Miny(D)));
			Point An = A.rotate(alpha), Bn = B.rotate(alpha), Cn = C.rotate(alpha), Dn = D.rotate(alpha), P = this->rotate(alpha);
			int Max_x = max(max(An.x, Bn.x), Cn.x), Max_y = max(max(An.y, Bn.y), Cn.y), Min_x = min(min(An.x, Bn.x), Cn.x), Min_y = min(min(An.y, Bn.y), Cn.y);
			P.print(); An.print(); Bn.print(); Cn.print(); Dn.print();
			if (P.x >= Min_x and P.x <= Max_x and P.y >= Min_y and P.y <= Max_y) return 1;
			else return 0;
		}
	}
	void print()
	{
		cout << x << ' ' << y << ' ';
	}
};
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	/*int n, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{*/
		int x, y, x1, x2, x3, x4, y1, y2, y3, y4;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		Point A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4), P(x, y);
		cout << P.isinrect(A, B, C, D);
		/*k += P.isinrect(A, B, C, D);
	}
	cout << k;*/
}