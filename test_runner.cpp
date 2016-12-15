#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Foo
{
public:
	virtual void bar(int a , int b) = 0;
};

class MockFoo : public Foo
{
public:
	MOCK_METHOD2(bar, void(int a, int b));
};

TEST(DummyCase, MockingTest)
{
	using ::testing::AtLeast;
	using ::testing::_;
	MockFoo foo;
	EXPECT_CALL(foo, bar(_, _)).Times(AtLeast(1));
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
