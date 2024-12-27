#include "button.h"
#include "gtkmm/box.h"
#include "home.h"
#include <gtkmm/window.h>

Button::Button() {
  // Add CSS class to the button
  add_css_class("round-button");

  // Create box to hold the lines
  auto box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);

  // Create 3 lines as individual widgets
  for (int i = 0; i < 3; ++i) {
    auto line = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL);
    line->set_size_request(30, 3); // Width 30px, Height 3px
    line->set_hexpand(false);      // Do not expand horizontally
    line->set_halign(Gtk::Align::CENTER);
    line->add_css_class("line");
    box->append(*line);
  }
  Home(box);
  // Add the box to the button (with the lines)
}

Button::~Button() {}
