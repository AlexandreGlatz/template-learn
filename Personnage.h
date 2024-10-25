#pragma once
class Personnage
{
public:
	Personnage( int life , int attack , int defence ) : m_attack( attack ) , m_defence( defence ), m_life(life) {}
	~Personnage();

private:
	int m_life;
	float m_attack;
	float m_defence;

};

