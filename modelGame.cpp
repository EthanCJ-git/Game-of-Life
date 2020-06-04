#include "modelGame.h"
#include <vector>
#include <iostream>

using std::vector;

//I have to add this because c++'s mod operator doesn't handle negative numbers!
//Isn't that wonderful?
int ModelGame::modulus(int a, int b)
{
	while(a < 0) a += b;
	return a%b;
}

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
	sum += (bool)Board.at(modulus((x-1),height)).at(modulus((y-1),width));
	sum += (bool)Board.at(modulus((x-1),height)).at(modulus((y),width));
	sum += (bool)Board.at(modulus((x-1),height)).at(modulus((y+1),width));
	sum += (bool)Board.at(modulus((x),height)).at(modulus((y-1),width));
	sum += (bool)Board.at(modulus((x),height)).at(modulus((y+1),width));
	sum += (bool)Board.at(modulus((x+1),height)).at(modulus((y-1),width));
	sum += (bool)Board.at(modulus((x+1),height)).at(modulus((y),width));
	sum += (bool)Board.at(modulus((x+1),height)).at(modulus((y+1),width));

	if(sum < 2) output = Board[x][y];
	if(sum == 2) output = 0;
	if(sum > 2) output = !Board[x][y];

	return output;
}//end check

//loop through all cells check them and update board
void ModelGame::update()
{
	//list of all cells that must be changed
	vector<int> rowIndex;
	vector<int> colIndex;
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			if(ModelGame::check(r, c))
			{	
				rowIndex.push_back(r);
				colIndex.push_back(c);
			}//end if(cell update needed) 
		}//for c
	}//for r

	//iterate through vector and change listed cells
	//not using iterator bc I need to iterate through 2 vectors
	for(int i = 0; i < colIndex.size(); i++)
	{
		std::printf("%d\t%d\n", rowIndex[i], colIndex[i]);
		Board.at(rowIndex[i]).at(colIndex[i]).flip();
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



