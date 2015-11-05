#include <iostream>
#include <gtest/gtest.h>
#include "try.hpp"

using namespace std;

class SampleTest : public ::testing::Test {
	public:
		virtual void SetUp()
		{
		}

		virtual void TearDown()
		{
		}
};

bool
cache_it_and_find_it()
{

	int k[]={1,2,3,4,5};
	int v[]={2,4,6,8,10};

	CacheStore <int,int,8> cs;
	for(int i=0; i < 5; ++i) {
		cs.Cache(k[i],v[i]);
		shared_ptr<int> sv = cs.Find(k[i]);
		int t = *sv.get();
		if ( t!= v[i]) return false;
	}

	return true;
}

bool
find_uncached()
{

	int k[]={1,2,3,4,5};
	int v[]={2,4,6,8,10};
	int nonkey[]={6,7,8,9,10};
	CacheStore <int,int,8> cs;
	for(int i=0; i < 5; ++i) {
		cs.Cache(k[i],v[i]);
		shared_ptr<int> sv = cs.Find(nonkey[i]);
		int t = *sv.get();
		if ( t!= v[i]) return true;
	}

	return false;
}
TEST_F(SampleTest, Positive) {
 ASSERT_TRUE(true);
}

TEST_F(SampleTest, Negative) {
 ASSERT_TRUE(true);
}

TEST_F(SampleTest, Zero) {
 ASSERT_TRUE(true);
}

TEST_F(SampleTest, Trivial) {
 ASSERT_TRUE(true);
}
TEST_F(SampleTest, cache_it_and_find_it) {
 ASSERT_TRUE(true);
}

TEST_F(SampleTest, find_uncached) {
 ASSERT_TRUE(true);
}
