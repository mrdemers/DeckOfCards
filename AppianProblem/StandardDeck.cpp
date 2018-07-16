#include "StandardDeck.h"

#include <exception>
#include "RandomArrayShuffler.h"

namespace appian
{

StandardDeck::StandardDeck()
{
	auto insertSuit = [this](StandardPlayingCard::Suit suit) {
		using SPC = StandardPlayingCard;
		cards.push_back(SPC(suit, SPC::Face::Ace));
		cards.push_back(SPC(suit, SPC::Face::Two));
		cards.push_back(SPC(suit, SPC::Face::Three));
		cards.push_back(SPC(suit, SPC::Face::Four));
		cards.push_back(SPC(suit, SPC::Face::Five));
		cards.push_back(SPC(suit, SPC::Face::Six));
		cards.push_back(SPC(suit, SPC::Face::Seven));
		cards.push_back(SPC(suit, SPC::Face::Eight));
		cards.push_back(SPC(suit, SPC::Face::Nine));
		cards.push_back(SPC(suit, SPC::Face::Ten));
		cards.push_back(SPC(suit, SPC::Face::Jack));
		cards.push_back(SPC(suit, SPC::Face::Queen));
		cards.push_back(SPC(suit, SPC::Face::King));
	};

	insertSuit(StandardPlayingCard::Suit::Clubs);
	insertSuit(StandardPlayingCard::Suit::Hearts);
	insertSuit(StandardPlayingCard::Suit::Spades);
	insertSuit(StandardPlayingCard::Suit::Diamonds);

	shuffleFunction = RandomArrayShuffler::shuffle<std::vector<StandardPlayingCard>::iterator>;
}

void StandardDeck::shuffle()
{
	shuffleFunction(cards.begin(), cards.end());
}

StandardPlayingCard StandardDeck::dealOneCard()
{
	if (cards.size() == 0)
		throw std::out_of_range("No cards remaining");

	StandardPlayingCard card = cards.back();
	cards.pop_back();
	return card;
}

int StandardDeck::getNumCardsRemaining()
{
	return cards.size();
}

void StandardDeck::setShuffleAlgorithm(std::function<void(std::vector<StandardPlayingCard>::iterator, std::vector<StandardPlayingCard>::iterator)> newAlgorithm)
{
	shuffleFunction = newAlgorithm;
}


}