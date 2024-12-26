#include "gtkmm/application.h"
#include "includes/helloworld.h"

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtk.example");

  return app->make_window_and_run<HelloWorld>(argc, argv);
}
