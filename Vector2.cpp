#include "Vector2.h"
#include <math.h>
Vec2::Vec2( float x , float y ) :
	m_x( 0 ) ,
	m_y( 0 )
{
	m_x = x;
	m_y = y;
}

Vec2::~Vec2()
{}

void Vec2::SetVector( float& x , float& y )
{
	m_x = x;
	m_y = y;
}

void Vec2::Normalize()
{
	float invNorm = 1 / GetNorm();
	m_x *= invNorm;
	m_y *= invNorm;
}

float Vec2::GetNormSquared() const { return m_x * m_x + m_y * m_y; }

float Vec2::GetNorm() const { return sqrtf( GetNormSquared() ); }

float Vec2::GetDistanceFrom( const Vec2* other )
{
	return sqrtf( ( other->m_x - m_x ) * ( other->m_x - m_x ) + ( other->m_y - m_y ) * ( other->m_y - m_y ) );
}

Vec2& Vec2::operator*=( const float& other )
{
	m_x *= other;
	m_y *= other;
	return *this;
}

Vec2 operator*( Vec2 left , const float& right )
{
	left *= right;
	return left;
}

Vec2& Vec2::operator+=( const Vec2& other )
{
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

Vec2 operator+( Vec2 left , const Vec2& right )
{
	left += right;
	return left;
}

Vec2& Vec2::operator-=( const Vec2& other )
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	return *this;
}

Vec2 operator-( Vec2 left , const Vec2& right )
{
	left -= right;
	return left;
}