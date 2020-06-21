#include <gtkmm/window.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/menubar.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/drawingarea.h>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <glib.h>
#include "modelGame.h"

//class for game grid
class MyGrid : public Gtk::DrawingArea
{
public:
	MyGrid(const int rows, const int columns, ModelGame *data);
	virtual ~MyGrid();
	const int gridRows;
	const int gridColumns;
	ModelGame *board;
protected:
	//override signal handler
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

//class for display window
class Display : public Gtk::Window
{
public:
	Display();
	Display(int xSize, int ySize);
	virtual ~Display();
	const int gridRows;
	const int gridColumns;
	bool runGame();

private:
	//child widgets
	Gtk::Box mBox;
	Gtk::HeaderBar mHeader;
	Gtk::Button startButton;
	Gtk::Button stopButton;
	MyGrid BoardGrid;
	ModelGame GameBoard;

	//button handlers
	void onstart();
	void onstop();
	bool running;
	bool onButtonPress(GdkEventButton* event);
};


