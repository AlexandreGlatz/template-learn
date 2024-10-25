#pragma once
#include <iostream>
class Vec2 {
public:
	Vec2( float x , float y );
	~Vec2();

	void SetVector( float& x , float& y );
	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void Normalize();
	float GetNorm() const;
	float GetNormSquared() const;
	float GetDistanceFrom( const Vec2* other );
	Vec2& operator*=( const float& other );
	friend Vec2 operator*( Vec2 left , const float& right );

	Vec2& operator+=( const Vec2& other );
	friend Vec2 operator+( Vec2 left , const Vec2& right );

	Vec2& operator-=( const Vec2& other );
	friend Vec2 operator-( Vec2 left , const Vec2& right );
private:
	float m_x;
	float m_y;
};