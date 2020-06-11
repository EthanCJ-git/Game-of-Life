#include <gtkmm/window.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/drawingarea.h>

class Display : public Gtk::Window
{
public:
	Display();
	Display(int xSize, int ySize);
	virtual ~Display();

private:
	//child widgets
	Gtk::Box mBox;
	Gtk::HeaderBar mHeader;
	Gtk::Button startButton;
	Gtk::Button stopButton;
	Gtk::DrawingArea mGrid;

};
