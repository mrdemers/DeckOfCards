#pragma once

#include "StandardPlayingCard.h"

#include <vector>
#include <functional>

namespace appian
{
	class Deck
	{
	using Itr = std::vector<StandardPlayingCard>::iterator;
	public:
		virtual ~Deck() {}
		Deck(const Deck& other) = default;
		Deck(Deck&& other) = default;
		Deck& operator=(const Deck& other) = default;
		Deck& operator=(Deck&& other) = default;

		void shuffle();
		StandardPlayingCard dealOneCard();
		int getNumCardsRemaining();

		void setShuffleAlgorithm(std::function<void(Itr, Itr)> newAlgorithm);

	protected:
		Deck();
		void addCard(const StandardPlayingCard& card);

	private:
		std::vector<StandardPlayingCard> cards;
		std::function<void(Itr, Itr)> shuffleFunction;
	};
}