#include "stdafx.h"
#include "CppUnitTest.h"

#include "RandomArrayShuffler.h"

#include <vector>
#include <array>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace appian;

namespace UnitTests
{
	TEST_CLASS(TestShuffler)
	{
	public:
		TEST_METHOD(TestShuffle)
		{
			std::vector<int> v;
			v.push_back(1);
			v.push_back(4);
			v.push_back(10);

			RandomArrayShuffler::shuffleSeeded(v.begin(), v.end(), 100);

			std::vector<int> expected = { 10, 4, 1 };
			Assert::IsTrue(v == expected);
		}

		TEST_METHOD(TestLargeShuffle)
		{
			std::vector<int> v;
			for (int i = 0; i < 10; i++) {
				v.push_back(i);
			}

			RandomArrayShuffler::shuffleSeeded(v.begin(), v.end(), 1000);

			std::vector<int> expected = { 4, 5, 3, 6, 7, 0, 2, 9, 8, 1 };
			Assert::IsTrue(v == expected);
		}

		TEST_METHOD(TestShuffleNonVector)
		{
			std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			RandomArrayShuffler::shuffleSeeded(arr.begin(), arr.end(), 1000);
			std::array<int, 10> expected = { 4, 5, 3, 6, 7, 0, 2, 9, 8, 1 };

			Assert::IsTrue(arr == expected);
		}
	};
}