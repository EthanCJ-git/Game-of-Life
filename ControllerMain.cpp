#include "Display.h"
#include <gtkmm.h>

//wrapper for member function to pass to g_timout_add
extern "C" gboolean wrap(gpointer data)
{
	static_cast<Display*>(data)->runGame();
}


int main(int argc, char **argv)
{
	auto app = Gtk::Application::create(argc, argv);

	Display Window; 

	g_timeout_add(1000, wrap, &Window);
	return app->run(Window);
}	
