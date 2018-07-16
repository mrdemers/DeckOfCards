#pragma once

#include "Deck.h"

#include <vector>
#include <functional>

namespace appian
{
	class StandardDeck : public Deck
	{
	public:
		StandardDeck();

		void shuffle() override;
		StandardPlayingCard dealOneCard() override;

		int getNumCardsRemaining() override;


		void setShuffleAlgorithm(std::function<void(std::vector<StandardPlayingCard>::iterator, std::vector<StandardPlayingCard>::iterator)> newAlgorithm);

	private:
		std::vector<StandardPlayingCard> cards;
		std::function<void(std::vector<StandardPlayingCard>::iterator, std::vector<StandardPlayingCard>::iterator)> shuffleFunction;
	};
}