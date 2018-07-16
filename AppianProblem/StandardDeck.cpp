#include "StandardDeck.h"

#include <exception>
#include "RandomArrayShuffler.h"

namespace appian
{

StandardDeck::StandardDeck()
{
	auto insertSuit = [this](StandardPlayingCard::Suit suit) {
		using SPC = StandardPlayingCard;
		addCard(SPC(suit, SPC::Face::Ace));
		addCard(SPC(suit, SPC::Face::Two));
		addCard(SPC(suit, SPC::Face::Three));
		addCard(SPC(suit, SPC::Face::Four));
		addCard(SPC(suit, SPC::Face::Five));
		addCard(SPC(suit, SPC::Face::Six));
		addCard(SPC(suit, SPC::Face::Seven));
		addCard(SPC(suit, SPC::Face::Eight));
		addCard(SPC(suit, SPC::Face::Nine));
		addCard(SPC(suit, SPC::Face::Ten));
		addCard(SPC(suit, SPC::Face::Jack));
		addCard(SPC(suit, SPC::Face::Queen));
		addCard(SPC(suit, SPC::Face::King));
	};

	insertSuit(StandardPlayingCard::Suit::Clubs);
	insertSuit(StandardPlayingCard::Suit::Hearts);
	insertSuit(StandardPlayingCard::Suit::Spades);
	insertSuit(StandardPlayingCard::Suit::Diamonds);
}

}