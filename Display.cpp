#include "Display.h"

Display::Display(int xSize, int ySize):
mHeader(),
startButton("start"),
stopButton("stop"),
mBox(Gtk::ORIENTATION_VERTICAL, 5),
cells(),
gridRows(30),
gridColumns(30),
BoardGrid(gridRows, gridColumns)
{
	//set window properties
	set_title("Conway's Game of Life");
	set_size_request(xSize, ySize);
	set_border_width(5);
	mHeader.set_size_request(-1, 20);
	BoardGrid.set_size_request(600, 600);
	
	//add to header bar
	mHeader.pack_start(startButton);
	mHeader.pack_start(stopButton);

	//add header to window
	mBox.pack_start(mHeader, 0, 0);
	mBox.pack_start(BoardGrid);
	add(mBox);

	//make everything visible
	show_all();


}

Display::Display():
Display(600, 600)
{}

Display::~Display() {}

//add cell to list of black cells
void Display::addCell(int row, int column)
{
	std::vector<int> cell(2);
	cell.push_back(row);
	cell.push_back(column);
	cells.push_back(cell);
	BoardGrid.cells = cells;
}

void Display::removeCell(int row, int column)
{
	for(auto it = cells.begin(); it != cells.end(); it++)
	{
		if(row == it->at(0) && column == it->at(1)) cells.erase(it--);
	}
	BoardGrid.cells = cells;
}

//drawing area 
MyGrid::MyGrid(const int rows, const int columns):
gridRows(rows),
gridColumns(columns),
cells()
{}

MyGrid::~MyGrid(){}

bool MyGrid::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	int lineSize = 2;
	double x = 0;
	double y = 0;

	//get coords
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width() - lineSize;
	const int height = allocation.get_height() - lineSize;

	//fill board white
	cr->set_source_rgb(1, 1, 1);
	cr->rectangle(0, 0, width, height);
	cr->fill();

	//set up brush
	cr->set_line_width(lineSize);
	cr->set_source_rgb(0, 0, 0);

	//draw grid
	for(int n = 0; n <= gridRows; n++)
	{
		cr->move_to(0, n*height/gridRows+lineSize/2.0);
		cr->line_to(width, n*height/gridRows+lineSize/2.0);
	}

	for(int n = 0; n <= gridColumns; n++)
	{
		cr->move_to(n*width/gridColumns+lineSize/2.0, 0);
		cr->line_to(n*width/gridColumns+lineSize/2.0, height);
	}

	//draw black cells
	for(auto it = cells.begin(); it != cells.end(); it++)
	{
		x = ((double)(it->at(1))-0.5)*(width/gridColumns);
		y = ((double)(it->at(0))-0.5)*(height/gridRows);
		cr->rectangle(x, y, width/gridColumns, height/gridRows);
		cr->fill();
	}

	//draw
	cr->stroke();
}





