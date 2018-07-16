#include "stdafx.h"
#include "CppUnitTest.h"

#include "StandardPlayingCard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace appian;


namespace UnitTests
{
	TEST_CLASS(TestCard)
	{
	public:

		using SPC = StandardPlayingCard;
		TEST_METHOD(TestCreateCard)
		{
			StandardPlayingCard card(SPC::Suit::Hearts, SPC::Face::Ace);
		}

		TEST_METHOD(TestCardSuitAndFace)
		{
			StandardPlayingCard card(SPC::Suit::Diamonds, SPC::Face::Jack);

			Assert::IsTrue(card.getFace() == SPC::Face::Jack);
			Assert::IsTrue(card.getSuit() == SPC::Suit::Diamonds);
		}

		TEST_METHOD(TestCardsEqual)
		{
			StandardPlayingCard card1(SPC::Suit::Clubs, SPC::Face::Ace);
			StandardPlayingCard card2(SPC::Suit::Clubs, SPC::Face::Ace);

			Assert::IsTrue(card1 == card2);
		}

		TEST_METHOD(TestCardsInequalWhenFaceInequal)
		{
			StandardPlayingCard card1(SPC::Suit::Hearts, SPC::Face::Ace);
			StandardPlayingCard card2(SPC::Suit::Hearts, SPC::Face::Queen);

			Assert::IsTrue(card1 != card2);
		}

		TEST_METHOD(TestCardsInequalWhenSuitInequal)
		{
			StandardPlayingCard card1(SPC::Suit::Hearts, SPC::Face::Three);
			StandardPlayingCard card2(SPC::Suit::Spades, SPC::Face::Three);

			Assert::IsTrue(card1 != card2);
		}

		TEST_METHOD(TestCardsInequalWhenSuitAndFaceInequal)
		{
			StandardPlayingCard card1(SPC::Suit::Diamonds, SPC::Face::Four);
			StandardPlayingCard card2(SPC::Suit::Clubs, SPC::Face::Eight);

			Assert::IsTrue(card1 != card2);
		}
	};
}