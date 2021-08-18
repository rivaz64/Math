#include "pch.h"
#include "Math.h"
#include <math.h>
float Vector2::dot(Vector2 v)
{
    return x*v.x+y*v.y;
}

float Vector2::len()
{
    return sqrt(dot(*this));
}

Vector2 Vector2::normalize()
{
	float l = len();
	Vector2 v=*this;
	if (l == 0)
		return { 0,0 };
	v.x /= l;
	v.y /= l;
	return v;
}
Vector2 Vector2::operator-(Vector2 v)
{
	return Vector2(x-v.x,y-v.y);
}
bool Vector2::operator==(Vector2 v)
{
	return x==v.x&&y==v.y;
}

Angle::Angle()
{
	num = 0;
}

Angle::Angle(float n)
{
	num = n;
	inRange();
}

Angle::Angle(Vector2 v)
{
	set(v);
}

Vector2 Angle::get()
{
	return Vector2(cos(num), sin(num));
}

void Angle::set(Vector2 v)
{
	if (v.len() == 0) {
		return;
	}
	num = atan(v.y / v.x);
	if (v.x < 0)
		num = PI + num;
}

void Angle::inRange()
{
	if (num > PI) {
		num = fmodf(num, PI * 2);
		if (num > PI) {
			num = -PI * 2 + num;
		}
	}
	if (num < -PI) {
		num = fmodf(num, PI * 2);
		if (num < -PI) {
			num = PI * 2 + num;
		}
	}
}

Angle Angle::operator+(float a)
{
	Angle ans(num + a);
	ans.inRange();
	return ans;
	
}

bool Angle::operator==(Angle a)
{
	return num == a.num;
}

Line::Line(Vector2 start, Vector2 end)
{
	begin = start;
	finish = end;
	a = -end.y + start.y;
	b = end.x - start.x;
	c = a * start.x + b * start.y;
}

bool Line::isinline(Vector2 v)
{

	float lenline = len();
	float disttocol = (v - begin).len();
	float otherdist = (finish - v).len();
	Vector2 orientation = v - begin;
	return disttocol < lenline&& otherdist < lenline&& orientation.normalize()==(finish-begin).normalize();
}

inline float Line::len()
{
	return (finish - begin).len();
}

inline Angle Line::Orientation()
{
	Angle ans = Angle(finish - begin);
	return ans;
}

Vector2 Line::normal()
{
	Vector2 n = (finish - begin).normalize();
	float temp = n.x;
	n.x = -n.y;
	n.y = temp;
	return n;
}
