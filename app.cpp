// File: main.cpp
#include "includes/home.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("com.example.telegram");

  auto css_provider = Gtk::CssProvider::create();
  css_provider->load_from_path(
      "/home/injustice/Documents/projects/splitgram/assets/styles/style.css");

  Gtk::StyleContext::add_provider_for_display(
      Gdk::Display::get_default(), css_provider,
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

  auto home_window =
      std::make_shared<Home>(); // Create a shared pointer for the window

  return app->make_window_and_run<Home>(argc, argv); // Updated for GTK 4
}
