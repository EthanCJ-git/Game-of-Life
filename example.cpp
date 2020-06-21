#include <gtkmm/window.h>


class Display: public Gtk::Window
{
	public:
	Display() {}
	virtual ~Display() {}
	
};

int main(int argc, char **argv)
{
	auto app = Gtk::Application::create(argc, argv);

	Display Window;

	return app->run(Window);
}
