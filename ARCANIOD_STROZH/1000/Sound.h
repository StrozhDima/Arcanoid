#pragma once
#include <SFML\Audio.hpp>

class Sound
{
public:
	Sound(sf::String F);
	~Sound(void);
	void play();
	void stop();
	void setLoop(bool onOff);

private:
	sf::String musicFile;
	sf::Music music;
};

