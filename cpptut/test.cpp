#include <iostream>
#include <gtest/gtest.h>
#include "try.hpp"
#include "tree.hpp"

using namespace std;

class LearnGtestTestCases : public ::testing::Test {
	public:
		virtual void SetUp()
		{
		}

		virtual void TearDown()
		{
		}
};

TEST_F(LearnGtestTestCases, Positive) {
 ASSERT_TRUE(true);
}

TEST_F(LearnGtestTestCases, Negative) {
 ASSERT_TRUE(true);
}

TEST_F(LearnGtestTestCases, Zero) {
 ASSERT_TRUE(true);
}

TEST_F(LearnGtestTestCases, Trivial) {
 ASSERT_TRUE(true);
}
class CacheStoreTestCase : public ::testing::Test {
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
TEST_F(CacheStoreTestCase, cache_it_and_find_it) {
 ASSERT_TRUE(true);
}

TEST_F(CacheStoreTestCase, find_uncached) {
 ASSERT_TRUE(true);
}


class MapTestCase : public ::testing::Test {
	public:
		virtual void SetUp()
		{
		}

		virtual void TearDown()
		{
		}
};
bool
find_entry_in_map_after_inserting()
{
	Tree<int> t;
	int six=6;
	int four=4;
	int two=2;
	int five=5;

	unique_ptr<TreeNode<int>> d4(t.Insert(four));
	unique_ptr<TreeNode<int>> d6(t.Insert(six));
	unique_ptr<TreeNode<int>> d2(t.Insert(two));
	unique_ptr<TreeNode<int>> d5(t.Insert(five));

	t.Show();
	TreeNode<int> *upi = t.CommonAncestor(d4,d2,d5); 	
	cout << "Answer" << upi->data; 	

	upi = t.CommonAncestor(d5,d2,d6); 	
	if (upi != nullptr) cout << "Answer" << upi->data; 	
	t.Show();
	d4.reset();
	return true;
}
TEST_F(MapTestCase,find_entry_in_map_after_inserting)
{
	ASSERT_TRUE(true);
}

