#include "pch.h"
#include "CppUnitTest.h"
#include"../Math/Math.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathTest
{
	TEST_CLASS(MathTest)
	{
	public:
		Vector2 v = Vector2(3, 4);
		Vector2 v1 = Vector2(1, 2);
		Vector2 v2 = v.normalize();
		Vector2 v3 = Vector2(1, 1);
		Angle an= Angle(v);
		Angle an1 = Angle(v3);
		Line linea = Line(v1, v);
		Vector2 v4 = linea.normal();
		Angle an2 = Angle(v4);
		Angle an3 = linea.Orientation() ;
		TEST_METHOD(TestDot)
		{
			Assert::AreEqual(11.f, v.dot(v1));
		}
		TEST_METHOD(TestLen)
		{
			Assert::AreEqual(5.f, v.len());
		}
		TEST_METHOD(TestNormalize)
		{
			Assert::AreEqual(1.f, v2.len());
		}
		TEST_METHOD(TestAngleFromVector)
		{
			Assert::AreEqual(0.927295218001f, Angle(v).num);
		}
		TEST_METHOD(TestAngleNotInRange)
		{
			Assert::AreEqual(-2.2831853071795862f, Angle(4.f).num);
		}
		TEST_METHOD(TestLineA)
		{
			Assert::AreEqual(-2.f, linea.a);
		}
		TEST_METHOD(TestLineB)
		{
			Assert::AreEqual(2.f, linea.b);
		}
		TEST_METHOD(TestLineC)
		{
			Assert::AreEqual(2.f, linea.c);
		}
		TEST_METHOD(TestRestaVec)
		{
			Assert::IsTrue(Vector2(2,2)== v-v1);
		}
		TEST_METHOD(TestInLine)
		{
			Assert::IsTrue(linea.isinline(Vector2(2, 3)));
		}
		TEST_METHOD(TestInFrontOfLine)
		{
			Assert::IsFalse(linea.isinline(Vector2(4, 5)));
		}
		TEST_METHOD(TestInBackOfLine)
		{
			Assert::IsFalse(linea.isinline(Vector2(0, 1)));
		}
		TEST_METHOD(TestNotAligned)
		{
			Assert::IsFalse(linea.isinline(Vector2(1.5, 3.5)));
		}
		TEST_METHOD(TestAngle)
		{
			Assert::AreEqual(float(PI/4.f), an3.num);
		}
		TEST_METHOD(TestNormalOfALine)
		{
			Assert::AreEqual(an3.num+float(PI/2), an2.num);
		}
	};
}
