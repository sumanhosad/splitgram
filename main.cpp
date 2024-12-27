#include "includes/home.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("hello");

  return app->make_window_and_run<Home>(argc, argv);
}
