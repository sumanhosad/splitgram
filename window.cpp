#include "gtkmm/window.h"
#include "gtkmm/application.h"

// create a class that inherits from GTk::Window
class MyWindow : public Gtk::Window {
public:
  MyWindow();
};

MyWindow::MyWindow() {
  set_title("A window");
  set_default_size(500, 500);
}

int main(int argc, char *argv[]) {
  // Initialize the Gtkmm application
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  // Run the application
  return app->make_window_and_run<MyWindow>(argc, argv);
}
