#pragma once

#include "Deck.h"
#include "StandardPlayingCard.h"

#include <vector>
#include <functional>
#include <memory>

namespace appian
{
	class StandardDeck : public Deck
	{
	public:
		StandardDeck();

		void shuffle() override;

		//This function releases managment of the pointer and must be freed by the caller
		StandardPlayingCard* dealOneCard() override;

		int getNumCardsRemaining() override;

		void setShuffleAlgorithm(std::function<void(std::vector<std::unique_ptr<StandardPlayingCard>>::iterator, std::vector<std::unique_ptr<StandardPlayingCard>>::iterator)> newAlgorithm);

	private:
		std::vector<std::unique_ptr<StandardPlayingCard>> cards;
		std::function<void(std::vector<std::unique_ptr<StandardPlayingCard>>::iterator, std::vector<std::unique_ptr<StandardPlayingCard>>::iterator)> shuffleFunction;
	};
}