// unittest_NameScoreSorter.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"


#include "NameScoreSorter.h"


TEST(testNameScoreSorter, simpleTest)
{
	NameScoreSorter sorter;

	sorter.pushline("SMITH, ALLAN, 70");
	sorter.pushline("KING, MADISON, 88");
	sorter.pushline("SMITH, FRANCIS, 85");
	sorter.pushline("BUNDY, TERESSA, 88");

	// count should be 4
	EXPECT_EQ(4, sorter.count());

	
	// before sorting
	std::string s0(sorter.getnthline(0));
	std::string s1(sorter.getnthline(1));
	std::string s2(sorter.getnthline(2));
	std::string s3(sorter.getnthline(3));

	EXPECT_STREQ("SMITH, ALLAN, 70", s0.c_str());
	EXPECT_STREQ("KING, MADISON, 88", s1.c_str());
	EXPECT_STREQ("SMITH, FRANCIS, 85", s2.c_str());
	EXPECT_STREQ("BUNDY, TERESSA, 88", s3.c_str());

	
	// sort by score and last name in descending order
	sorter.sortDescOrderByScoreAndLastName();


	// after sorting
	s0 = sorter.getnthline(0);
	s1 = sorter.getnthline(1);
	s2 = sorter.getnthline(2);
	s3 = sorter.getnthline(3);

	EXPECT_STREQ("BUNDY, TERESSA, 88", s0.c_str());
	EXPECT_STREQ("KING, MADISON, 88", s1.c_str());
	EXPECT_STREQ("SMITH, FRANCIS, 85", s2.c_str());
	EXPECT_STREQ("SMITH, ALLAN, 70", s3.c_str());
}

TEST(testNameScoreSorter, allSameScoreTest)
{
	NameScoreSorter sorter;

	sorter.pushline("SMITH, ALLAN, 88");
	sorter.pushline("KING, MADISON, 88");
	sorter.pushline("SMITH, FRANCIS, 88");
	sorter.pushline("BUNDY, TERESSA, 88");

	// before sorting
	std::string s0(sorter.getnthline(0));
	std::string s1(sorter.getnthline(1));
	std::string s2(sorter.getnthline(2));
	std::string s3(sorter.getnthline(3));

	EXPECT_STREQ("SMITH, ALLAN, 88", s0.c_str());
	EXPECT_STREQ("KING, MADISON, 88", s1.c_str());
	EXPECT_STREQ("SMITH, FRANCIS, 88", s2.c_str());
	EXPECT_STREQ("BUNDY, TERESSA, 88", s3.c_str());


	// sort by score and last name in descending order
	sorter.sortDescOrderByScoreAndLastName();


	// after sorting
	s0 = sorter.getnthline(0);
	s1 = sorter.getnthline(1);
	s2 = sorter.getnthline(2);
	s3 = sorter.getnthline(3);

	EXPECT_STREQ("BUNDY, TERESSA, 88", s0.c_str());
	EXPECT_STREQ("KING, MADISON, 88", s1.c_str());
	EXPECT_STREQ("SMITH, FRANCIS, 88", s2.c_str());
	EXPECT_STREQ("SMITH, ALLAN, 88", s3.c_str());
}

TEST(testNameScoreSorter, allSameScoreSameLastNameTest)
{
	NameScoreSorter sorter;

	sorter.pushline("SMITH, TERESSA, 88");
	sorter.pushline("KING, TERESSA, 88");
	sorter.pushline("JAMES, TERESSA, 88");
	sorter.pushline("BUNDY, TERESSA, 88");

	// before sorting
	std::string s0(sorter.getnthline(0));
	std::string s1(sorter.getnthline(1));
	std::string s2(sorter.getnthline(2));
	std::string s3(sorter.getnthline(3));

	EXPECT_STREQ("SMITH, TERESSA, 88", s0.c_str());
	EXPECT_STREQ("KING, TERESSA, 88", s1.c_str());
	EXPECT_STREQ("JAMES, TERESSA, 88", s2.c_str());
	EXPECT_STREQ("BUNDY, TERESSA, 88", s3.c_str());


	//// sort by score and last name in descending order
	sorter.sortDescOrderByScoreAndLastName();


	//// after sorting
	s0 = sorter.getnthline(0);
	s1 = sorter.getnthline(1);
	s2 = sorter.getnthline(2);
	s3 = sorter.getnthline(3);

	EXPECT_STREQ("SMITH, TERESSA, 88", s0.c_str());
	EXPECT_STREQ("KING, TERESSA, 88", s1.c_str());
	EXPECT_STREQ("JAMES, TERESSA, 88", s2.c_str());
	EXPECT_STREQ("BUNDY, TERESSA, 88", s3.c_str());
}


	
	
