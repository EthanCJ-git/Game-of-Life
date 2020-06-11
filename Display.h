#include <gtkmm/window.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/menubar.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/drawingarea.h>
#include <vector>

//class for game grid
class MyGrid : public Gtk::DrawingArea
{
public:
	MyGrid(const int rows, const int columns);
	virtual ~MyGrid();
	const int gridRows;
	const int gridColumns;
	std::vector<std::vector<int>> cells;
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
	void addCell(int row, int column);
	void removeCell(int row, int column);
	const int gridRows;
	const int gridColumns;

private:
	//child widgets
	Gtk::Box mBox;
	Gtk::HeaderBar mHeader;
	Gtk::Button startButton;
	Gtk::Button stopButton;
	MyGrid BoardGrid;

	//list of black cells
	std::vector<std::vector<int>> cells;

};


