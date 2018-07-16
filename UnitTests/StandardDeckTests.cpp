#include "stdafx.h"
#include "CppUnitTest.h"

#include "StandardDeck.h"
#include "RandomArrayShuffler.h"

#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace appian;
using namespace std::placeholders;

namespace UnitTests
{
	TEST_CLASS(TestStandardDeck)
	{
	public:
		static const int NUM_CARDS_IN_DECK = 52;

		TEST_METHOD(TestCreateDeck)
		{
			StandardDeck deck;

			Assert::AreEqual(NUM_CARDS_IN_DECK, deck.getNumCardsRemaining());
		}

		TEST_METHOD(TestDealCard)
		{
			StandardDeck deck;

			StandardPlayingCard card1 = deck.dealOneCard();
			StandardPlayingCard card2 = deck.dealOneCard();

			Assert::IsTrue(card1 != card2);
			Assert::AreEqual(NUM_CARDS_IN_DECK - 2, deck.getNumCardsRemaining());
		}

		TEST_METHOD(TestDealTooManyCardsThrowsError)
		{
			StandardDeck deck;

			discardNCards(deck, NUM_CARDS_IN_DECK);

			try {
				deck.dealOneCard();
				Assert::Fail();
			}
			catch (std::out_of_range& exception) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestShuffleDeckDeterministically)
		{
			StandardDeck deck;
			StandardPlayingCard normalFirstCard = deck.dealOneCard();
			StandardPlayingCard normalLastCard = getNthCard(deck, NUM_CARDS_IN_DECK - 1);

			StandardDeck newDeck;
			newDeck.setShuffleAlgorithm(std::reverse<std::vector<StandardPlayingCard>::iterator>);
			newDeck.shuffle();

			StandardPlayingCard newFirstCard = newDeck.dealOneCard();
			StandardPlayingCard newLastCard = getNthCard(newDeck, NUM_CARDS_IN_DECK - 1);

			Assert::IsTrue(newFirstCard == normalLastCard);
			Assert::IsTrue(newLastCard == normalFirstCard);
		}

		TEST_METHOD(TestShuffleRandomlyCompletesSuccessfully)
		{
			StandardDeck deck;

			deck.shuffle();

			Assert::AreEqual(NUM_CARDS_IN_DECK, deck.getNumCardsRemaining());
		}

		TEST_METHOD(TestRandomShuffle)
		{
			StandardDeck deck;

			//Creates a shuffle function with a fixed random seed
			auto shuffleFunction = std::bind(RandomArrayShuffler::shuffleSeeded<std::vector<StandardPlayingCard>::iterator>, _1, _2, 100);
			deck.setShuffleAlgorithm(shuffleFunction);
			deck.shuffle();
			StandardPlayingCard lastCard = getNthCard(deck, NUM_CARDS_IN_DECK);

			StandardDeck referenceDeck;
			srand(100);
			int posOfBottomCard = NUM_CARDS_IN_DECK - rand() % NUM_CARDS_IN_DECK;
			StandardPlayingCard expectedLastCard = getNthCard(referenceDeck, posOfBottomCard);

			Assert::IsTrue(lastCard == expectedLastCard);
		}

		void discardNCards(StandardDeck& deck, int numToDeal) {
			for (int i = 0; i < numToDeal; i++) {
				deck.dealOneCard();
			}
		}

		StandardPlayingCard getNthCard(StandardDeck& deck, int n) {
			discardNCards(deck, n - 1);
			return deck.dealOneCard();
		}
	};
}