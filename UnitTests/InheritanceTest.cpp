#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


class A
{
public:
	virtual ~A() {}

	virtual int getA() = 0;
};

class B : public A
{
public:
	~B() {}

	int getA() { return 5; }
	int getB() { return 10; }
};

class Master
{
public:
	virtual ~Master() {}

	virtual A* getOverridenClass() = 0;
	virtual void doSomething(A* anA) = 0;
};

class Slave : public Master
{
public:
	~Slave() {}

	B* getOverridenClass() override
	{
		return new B();
	}

	void doSomething(A* aB) override
	{

	}
};

namespace UnitTests
{
	TEST_CLASS(TestInheritance)
	{
	public:

		TEST_METHOD(TestCallingMethod)
		{
		}
	};
}