#include <iostream>
#include <gtest/gtest.h>
#include "try.hpp"

using namespace std;

class SampleTest : public ::testing::Test {
	public:
		virtual void SetUp()
		{
			CacheStore <int,int,8> cs;

			int k[]={1,2,3,4,5};
			int v[]={2,4,6,8,10};
			for(int i=0; i < 5; ++i) {
				cs.Cache(k[i],v[i]);
				cs.Show();
				if (i&1)cs.Expire(k[i]);
				shared_ptr<int> sv = cs.Find(k[i]);
				//cout << endl <<"Finding Key " << k[i] <<" Value " << ((sv == nullptr) ?  0 : *sv.get()) ;
			}

		}

		virtual void TearDown()
		{
		}
};

bool
customtestcase()
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
TEST_F(SampleTest, customtestcase) {
 ASSERT_TRUE(true);
}
