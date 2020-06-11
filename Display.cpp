#include "Display.h"

Display::Display(int xSize, int ySize):
startButton("start"),
stopButton("stop"),
mHeader(),
mBox(),
mGrid()
{
	//set window properties
	set_title("Conway's Game of Life");
	set_size_request(xSize, ySize);
	set_border_width(5);
	mHeader.set_title("Game of Life");

	//add to header bar
	mHeader.pack_start(startButton);
	mHeader.pack_start(stopButton);

	//add header to window
	mBox.pack_start(mHeader);
	mBox.pack_start(mGrid);
	add(mBox);

	//make everything visible
	show_all();


}

Display::Display():
Display(600, 600)
{}

Display::~Display() {}



