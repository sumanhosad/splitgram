#include "gtkmm/application.h"
#include "includes/buttons.h"

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("yes");

  return app->make_window_and_run<Buttons>(argc, argv);
}
