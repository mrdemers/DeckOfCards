#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>
#include "RandomArrayShuffler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace appian;

namespace UnitTests
{
	TEST_CLASS(TestShuffler)
	{
	public:
		TEST_METHOD(TestIterators)
		{	
			std::vector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(4);

			auto first = v.begin();
			auto second = v.begin() + 1;

			std::iter_swap(first, second);

			auto start = v.begin();
			Assert::AreEqual(2, v[0]);
			start++;
			Assert::AreEqual(1, v[1]);
			start++;
			Assert::AreEqual(4, *start);
		}

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
	};
}