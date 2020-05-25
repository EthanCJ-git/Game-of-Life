#include "modelGame.h"

//constructor with dimensions specified
ModelGame::ModelGame(const int width, const int height):
width(width),
height(height),
{
	Board = new vector<vector<bool>>(height);
	for(int i = 0; i < height; i++)
	{
		vector<bool> temp = new vector<bool>(width);
		temp.fill(fill.begin(), fill.end(), 0);
		Board[i] = temp;
	}//populate the Board vector
}//end constructor

//constructor with default dimensions
ModelGame::ModelGame():
width(400),
height(400),
{
	Board = new vector<vector<bool>>(height);
	for(int i = 0; i < height; i++)
	{
		vector<bool> temp = new vector<bool>(width);
		temp.fill(fill.begin(), fill.end(), 0);
		Board[i] = temp;
	}//populate the Board vector
}//end constructor

//check individual cell (private)
//output 1 if cell must change, 0 if not
//x is row and y is column (matrix convention, not cartesian)
ModelGame::check(int x, int y)
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
}//end check

//loop through all cells check them and update board
ModelGame::update()
{
	//list of all cells that must be changed
	vector<vector<int>> change = new vector<vector<int>>();
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			if(check(Board[r][c]))
			{	
				index[0] = r;
				index[1] = c;
				change.push_back(index);
			}//end if(cell update needed) 
		}//for c
	}//for r

	//iterate through vector and change listed cells
	for(vector<vector<int>>::iterator it = change.begin(); it != change.end; ++it)
	{
		Board[*it[0]][*it[1]] = Board[*it[0]][*it[1]] ^ 1;
	}

}//end update

//return vector of black cells
ModelGame::blackCells()
{
	vector<vector<int>> black = new vector<vector<int>>();
	vector<int> index = new vector<int>();
	for(r = 0; r < height; r++)
	{
		for(c = 0; c < width; c++)
		{
			if(Board[r][c]) 
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



