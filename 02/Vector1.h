#pragma once

class Vector1
{
// 접근제어(access modifier) 키워드가 없으면 기본은 private
public:
	Vector1();
	Vector1(int x, int y);

// 클래스 단위 접근제어자 (개체가 아님)
private:
	int mX;
	int mY;
};