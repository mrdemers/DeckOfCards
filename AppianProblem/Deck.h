#pragma once

#include "Card.h"

namespace appian
{
	class Deck
	{
	public:
		virtual void shuffle() = 0;
		virtual Card* dealOneCard() = 0;

		virtual int getNumCardsRemaining() = 0;
	};
}