#include "Deck.h"

#include "RandomArrayShuffler.h"

namespace appian
{


Deck::Deck()
{
	shuffleFunction = RandomArrayShuffler::shuffle<Itr>;
}

void Deck::addCard(const StandardPlayingCard& card)
{
	cards.push_back(card);
}

void Deck::shuffle()
{
	shuffleFunction(cards.begin(), cards.end());
}

StandardPlayingCard Deck::dealOneCard()
{
	if (cards.size() == 0)
		throw std::out_of_range("No cards remaining");

	StandardPlayingCard card = cards.back();
	cards.pop_back();
	return card;
}

int Deck::getNumCardsRemaining()
{
	return cards.size();
}

void Deck::setShuffleAlgorithm(std::function<void(Itr, Itr)> newAlgorithm)
{
	shuffleFunction = newAlgorithm;
}


}