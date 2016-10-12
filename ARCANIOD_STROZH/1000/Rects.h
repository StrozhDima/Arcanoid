#pragma once
#include <SFML\Graphics.hpp>

class Rects
{
private:
	const int rectNum;
	sf::Vector2f position;

	sf::Color randomColor(); //����������� ������

public:
	std::vector<sf::RectangleShape> rects;

	Rects(void);
	~Rects(void);
	
	void initialize();//������������� �������
	void reset();//����� �������
	void draw(sf::RenderWindow &window); //��������� �������

	float x(int index)		{ return rects[index].getPosition().x; }
	float y(int index)		{ return rects[index].getPosition().y; }
	float left(int index)	{ return x(index) - rects[index].getSize().x / 2.f; }
	float right(int index)	{ return x(index) + rects[index].getSize().x / 2.f; }
	float top(int index)	{ return y(index) - rects[index].getSize().y / 2.f; }
	float bottom(int index) { return y(index) + rects[index].getSize().y / 2.f; }
	int getRectNum()		{ return rectNum; }
};

