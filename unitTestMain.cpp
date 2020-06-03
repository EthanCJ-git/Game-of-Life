#include <gtest/gtest.h>
#include "modelGame.h"


TEST(SetAndTrackCells, OneBlackCell)
{
	ModelGame model = ModelGame(10, 10);
	model.setBlack(9, 9);
	vector<vector<int>> black = model.blackCells();
	EXPECT_EQ(black.at(0).at(0), (int)9);
	EXPECT_EQ(black.at(0).at(1), (int)9);
	EXPECT_EQ(black.size(), (int)1);
}

TEST(SetAndTrackCells, ThreeBlackCells)
{
	ModelGame model = ModelGame(10, 10);
	model.setBlack(9, 9);
	model.setBlack(1, 1);
	model.setBlack(2, 3);
	vector<vector<int>> black = model.blackCells();
	EXPECT_EQ(black.at(2).at(0), (int)9);
	EXPECT_EQ(black.at(2).at(1), (int)9);
	EXPECT_EQ(black.at(0).at(0), (int)1);
	EXPECT_EQ(black.at(0).at(1), (int)1);
	EXPECT_EQ(black.at(1).at(0), (int)2);
	EXPECT_EQ(black.at(1).at(1), (int)3);
	EXPECT_EQ(black.size(), (int)3);
}

TEST(TestAutomata, CheckCheck)
{
	ModelGame model = ModelGame(10, 10);
	model.setBlack(5, 5);
	EXPECT_EQ(model.check(5, 5), true);
	EXPECT_EQ(model.check(4, 5), false);
}

int main(int argc, char **argv)
{
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
