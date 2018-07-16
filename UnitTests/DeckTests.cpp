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
	TEST_CLASS(TestDeck)
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
				Assert::IsTrue(false);
			}
			catch (std::out_of_range& exception) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestShuffleDeck)
		{
			StandardDeck deck;
			StandardPlayingCard normalFirstCard = deck.dealOneCard();
			discardNCards(deck, NUM_CARDS_IN_DECK - 2);
			StandardPlayingCard normalLastCard = deck.dealOneCard();

			auto reverseCards = [](std::vector<StandardPlayingCard>::iterator start, std::vector<StandardPlayingCard>::iterator end) {
				std::reverse(start, end);
			};

			StandardDeck newDeck;
			newDeck.setShuffleAlgorithm(reverseCards);
			newDeck.shuffle();

			StandardPlayingCard newFirstCard = newDeck.dealOneCard();
			discardNCards(newDeck, NUM_CARDS_IN_DECK - 2);
			StandardPlayingCard newLastCard = newDeck.dealOneCard();

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

			auto shuffleFunction = std::bind(RandomArrayShuffler::shuffleSeeded<std::vector<StandardPlayingCard>::iterator>, _1, _2, 100);
			deck.setShuffleAlgorithm(shuffleFunction);
			deck.shuffle();

			StandardDeck referenceDeck;
			srand(100);
			auto posOfBottomCard = rand() % NUM_CARDS_IN_DECK;
			discardNCards(referenceDeck, NUM_CARDS_IN_DECK - posOfBottomCard - 1);
			StandardPlayingCard expectedLastCard = referenceDeck.dealOneCard();

			discardNCards(deck, NUM_CARDS_IN_DECK - 1);
			StandardPlayingCard lastCard = deck.dealOneCard();

			Assert::IsTrue(lastCard == expectedLastCard);
		}

		void discardNCards(StandardDeck& deck, int numToDeal) {
			for (int i = 0; i < numToDeal; i++) {
				deck.dealOneCard();
			}
		}
	};
}