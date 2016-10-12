#ifndef _SCORE_H
#define _SCORE_H

struct Score 
{
	Score()
	{
		if (!(font.loadFromFile("font.ttf")))
			return;

		scoreText.setFont(font);
		scoreText.setColor(sf::Color(77, 227, 251, 255));
		scoreText.setPosition(25, 25);
		scoreText.setCharacterSize(20);
	}

	void update(Rects &rects) 
	{ 
		score = static_cast<int>(rects.getRectNum() - rects.rects.size()); 
		scoreText.setString("Score: " + std::to_string(score));
		scoreText.setOrigin(scoreText.getScale().x / 2, scoreText.getScale().y / 2);
	}

	void reset()
	{
		score = 0;
	}

	void draw(sf::RenderWindow& window) 
	{ 
		window.draw(scoreText); 
	}

	int getScore()
	{
		return score;
	}

private:
	int score;
	sf::Text scoreText;
	sf::Font font;
};

#endif