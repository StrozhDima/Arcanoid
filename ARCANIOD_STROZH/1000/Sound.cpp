#include "Sound.h"

Sound::Sound(sf::String F)
{
	musicFile = F;

	if(!music.openFromFile("sounds/" + musicFile))
		return;
}

Sound::~Sound(void)
{
}

void Sound::play()
{
	music.play();
}

void Sound::stop()
{
	music.stop();
}

void Sound::setLoop(bool onOff)
{
	music.setLoop(onOff);
}