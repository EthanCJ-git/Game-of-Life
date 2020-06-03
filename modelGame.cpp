#include "modelGame.h"
#include <vector>
#include <iostream>

using std::vector;

//constructor with dimensions specified
ModelGame::ModelGame(const int w, const int h):
width(w),
height(h),
Board(height)
{
	//vector<vector<bool>> Board (height);
	

	for(int i = 0; i < height; i++)
	{
		vector<bool> temp (width);
		temp.assign(width, 0);
		Board.at(i) = temp;
		
	}//populate the Board vector
	std::cout << Board.size();
}//end constructor

//constructor with default dimensions
ModelGame::ModelGame():
width(400),
height(400)
{
	vector<vector<bool>> Board (height);

	for(int i = 0; i < height; i++)
	{
		vector<bool> temp (width);
		temp.assign(width, 0);
		Board.at(i) = temp;
	
	}//populate the Board vector
}//end constructor

//check individual cell (private)
//output 1 if cell must change, 0 if not
//x is row and y is column (matrix convention, not cartesian)
bool ModelGame::check(int x, int y)
{
	bool output = 0;
	int sum = 0;
	sum += Board[(x-1)%height][(y-1)%width];
	sum += Board[(x-1)%height][(y)%width];
	sum += Board[(x-1)%height][(y+1)%width];
	sum += Board[(x)%height][(y-1)%width];
	sum += Board[(x)%height][(y+1)%width];
	sum += Board[(x+1)%height][(y-1)%width];
	sum += Board[(x+1)%height][(y)%width];
	sum += Board[(x+1)%height][(y+1)%width];

	if(sum < 2) output = Board[x][y];
	if(sum == 2) output = 0;
	if(sum > 2) output = !Board[x][y];

	return output;
}//end check

//loop through all cells check them and update board
void ModelGame::update()
{
	//list of all cells that must be changed
	vector<vector<int>> change;
	vector<int> index (2);

	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			if(check(r, c))
			{	
				index[0] = r;
				index[1] = c;
				change.push_back(index);
			}//end if(cell update needed) 
		}//for c
	}//for r

	//iterate through vector and change listed cells
	for(vector<vector<int>>::iterator it = change.begin(); it != change.end(); ++it)
	{
		Board[(*it).at(0)][(*it).at(1)].flip();
	}

}//end update

//return vector of black cells
vector<vector<int>> ModelGame::blackCells()
{
	vector<vector<int>> black;
	vector<int> index (2);
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			if((bool)Board.at(r).at(c)) 
			{
				index[0] = r;
				index[1] = c;
				black.push_back(index);
			}//end if(black)
		}//end for columns
	}//end for rows
	
	//return vector
	return black;
}

void ModelGame::setBlack(int row, int column)
{
	
	if(row < height && column < width) Board[row][column] = true;
}



