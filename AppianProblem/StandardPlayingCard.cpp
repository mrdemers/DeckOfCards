#include "StandardPlayingCard.h"

namespace appian
{


StandardPlayingCard::StandardPlayingCard(StandardPlayingCard::Suit s, StandardPlayingCard::Face f)
	: suit(s)
	, face(f)
{
}

StandardPlayingCard::Suit StandardPlayingCard::getSuit()
{
	return suit;
}

StandardPlayingCard::Face StandardPlayingCard::getFace()
{
	return face;
}

bool StandardPlayingCard::operator==(const StandardPlayingCard& rhs)
{
	return suit == rhs.suit && face == rhs.face;
}

bool StandardPlayingCard::operator!=(const StandardPlayingCard& rhs)
{
	return !(*this == rhs);
}


}