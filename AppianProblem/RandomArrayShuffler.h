#pragma once

#include <time.h>

namespace appian
{
	class RandomArrayShuffler
	{
	public:
		template<class IteratorType>
		static void shuffle(IteratorType& start, IteratorType& end)
		{
			shuffleSeeded(start, end, time(NULL));
		}

		template<class IteratorType>
		static void shuffleSeeded(IteratorType& start, IteratorType& end, unsigned int seed)
		{
			srand(seed);
			int length = end - start;
			for (int i = 0; i < length; i++) {
				int remainingElements = length - i;
				int swapOffset = rand() % remainingElements;
				auto toSwap = start + i;
				std::iter_swap(toSwap, toSwap + swapOffset);
			}
		}
	};
}