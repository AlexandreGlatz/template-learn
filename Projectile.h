#pragma once
#include "Vector2.h"
template<typename T>
class Projectile
{
public:
	Projectile(T damageType, float speed, Vec2* pPos, Vec2* pDir);
	~Projectile();

	void Move();
	void Attack();

private:
	float m_speed;
	T m_damageType;
	Vec2* m_pPosition;
	Vec2* m_pDirection;
};

template<typename T>
inline Projectile<T>::Projectile( T damageType , float speed , Vec2* pPos , Vec2* pDir ): m_speed(speed), m_damageType(damageType), m_pPosition(pPos), m_pDirection(pDir)
{

}

template<typename T>
inline void Projectile<T>::Move()
{
	*m_pPosition += *m_pDirection * m_speed
}

template <>
void Projectile<int>::Attack()
{
	std::cout << "Enemy Killed with Arrow, damage" <<m_damageType;
}

template <>
void Projectile<float>::Attack()
{
	float attackRadius = 3.5f;
	std::cout << "Bomb Explode, Radius : " << attackRadius << " damage : " << m_damageType;
}
