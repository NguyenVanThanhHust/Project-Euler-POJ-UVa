#include <iostream>
#include <cmath>
# define M_PI           3.14159265358979323846
# define eps 1e-5
using namespace std;

struct point
{
    float x, y;
};

class line
{
public:
	float a, b, c;

public:
	line(float m_a, float m_b, float m_c);
	line(point p1, point p2);
	~line();

private:

};

line::line(float m_a, float m_b, float m_c)
{
	a = m_a;
	b = m_b;
	c = m_c;
}

line::~line()
{
}

line::line(point p1, point p2)
{
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = (p2.x*p1.y - p1.x*p2.y);
}


struct circle
{
    point center;
    float radius;
};

float distance_point_to_point(point &p1, point &p2);
float distance_point_to_line(point &p, line &l);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}

float distance_point_to_point(point &p1, point &p2)
{
    float d_x = (p1.x - p2.x) * (p1.x - p2.x);
    float d_y = (p1.y - p2.y) * (p1.y - p2.y);
    float res = sqrt(d_x + d_y);
    return res;
}

float distance_point_to_line(point &p, line &l)
{
    float mau = sqrt(l.a * l.a + l.b * l.b);
    float tu = abs(l.a * p.x + l.b * p.y + l.c);
    float res = tu / mau;
    return res;
}