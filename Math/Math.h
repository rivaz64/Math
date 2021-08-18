#pragma once
#ifdef MATH_EXPORTS
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
class MATH_API Vector2
{
public:
	float x=0, y=0;
	Vector2() {}
	Vector2(int X, int Y) :x(X), y(Y) {}
	float dot(Vector2 v);
	float len();
	Vector2 normalize();
	Vector2 operator-(Vector2 v);
	bool operator==(Vector2 v);
};
class MATH_API Angle
{
public:
	float num = 0;
	Angle();
	Angle(float n);
	Angle(Vector2 v);
	Vector2 get();
	void set(Vector2 v);
	void inRange();
	Angle operator+(float a);
	bool operator==(Angle a);
};
class MATH_API Line {
public:
	float a, b, c;
	Vector2 begin, finish;
	Line(Vector2 start, Vector2 end);
	bool isinline(Vector2 v);
	inline float len();
	inline Angle Orientation();
	Vector2 normal();

};
