#pragma once

#include "StandardPlayingCard.h"

namespace appian
{
	class Deck
	{
	public:
		virtual void shuffle() = 0;
		virtual StandardPlayingCard dealOneCard() = 0;

		virtual int getNumCardsRemaining() = 0;
	};
}