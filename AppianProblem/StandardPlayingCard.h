#pragma once

namespace appian
{
	class StandardPlayingCard
	{
	public:

		enum class Suit {
			Hearts,
			Spades,
			Clubs,
			Diamonds
		};

		enum class Face {
			Ace,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Nine,
			Ten,
			Jack,
			Queen,
			King,
		};

		StandardPlayingCard(Suit suit, Face face);

		Suit getSuit();
		Face getFace();

		bool operator==(const StandardPlayingCard& rhs);
		bool operator!=(const StandardPlayingCard& rhs);

	private:
		Suit suit;
		Face face;
	};
}