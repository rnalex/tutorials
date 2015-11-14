#include <iostream>
#include <gtest/gtest.h>
#include "try.hpp"
#include "tree.hpp"
#include "xsection.hpp"

using namespace std;

TEST(SimpleTestCase,SimpleComparatorTest) {
	int expected = 5, actual=4;
	int val1 = 1 , val2=4;
	ASSERT_TRUE(true);
	ASSERT_FALSE(false);
	ASSERT_EQ(expected, expected);
	EXPECT_EQ(expected, expected);
	ASSERT_NE(val1, val2);	
	EXPECT_NE(val1, val2);
	ASSERT_LT(val1, val2);	
	EXPECT_LT(val1, val2);
	ASSERT_LE(val1, val2);	
	EXPECT_LE(val1, val2);	
	ASSERT_GT(val2, val1);	
	EXPECT_GT(val2, val1);	
	ASSERT_GE(val2, val1);
	EXPECT_GE(val2, val1);
}


TEST(SimpleTestCase,SimpleStringTest) {
	char *str1, *str2;
	char str1val[]="Test"; 
	char str2val[]="Test"; 
	str1 = str1val;
	str2 = str2val;

	ASSERT_STREQ(str1, str2); EXPECT_STREQ(str1, str2);	//the two C strings have the same content
	str2val[0]='E';
	ASSERT_STRNE(str1, str2); EXPECT_STRNE(str1, str2);	//the two C strings have different content
	str2val[0]='t';
	ASSERT_STRCASEEQ(str1, str2);	EXPECT_STRCASEEQ(str1, str2);//the two C strings have the same content, ignoring case
	str2val[0]='E';
	ASSERT_STRCASENE(str1, str2);	EXPECT_STRCASENE(str1, str2);	//the two C strings have different content, ignoring case
}

class SimpleTestFixtureCase : public ::testing::Test {
	public:
		virtual void SetUp()
		{
		}

		virtual void TearDown()
		{
		}
};

TEST_F(SimpleTestFixtureCase,SimpleTestFixtureTest)
{

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
		if (sv != nullptr) return false;
	}

	return true;
}
TEST_F(CacheStoreTestCase, cache_it_and_find_it) {
 ASSERT_TRUE(cache_it_and_find_it());
}

TEST_F(CacheStoreTestCase, find_uncached) {
 ASSERT_TRUE(find_uncached());
}


class TreeTestCase : public ::testing::Test {
	public:
		virtual void SetUp()
		{
		}

		virtual void TearDown()
		{
		}
};


TEST_F(TreeTestCase,find_common_elements)
{

	test_combo<int,vector>();
	test_combo<float,vector>();
	test_combo<float,deque>();
	test_combo<char,deque>();
	test_combo<long long,deque>();
}

TEST_F(TreeTestCase,find_ancestor_in_tree_after_inserting)
{
	Tree<int> t;
	int six=6;
	int four=4;
	int two=2;
	int five=5;
	int nine=9;
	int ancestor=0;

	t.Insert(four);
	t.Insert(six);
	t.Insert(two);
	t.Insert(five);

	ASSERT_TRUE(t.FindCommonAncestor(ancestor,two,five));
	ASSERT_EQ(ancestor,four);

	ASSERT_FALSE(t.FindCommonAncestor(ancestor,two,nine));
}
