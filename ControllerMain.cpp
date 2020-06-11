#include "Display.h"
#include <gtkmm.h>

int main(int argc, char **argv)
{
	auto app = Gtk::Application::create(argc, argv);

	Display Window; 

	return app->run(Window);
}	
