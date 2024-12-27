#include "home.h"
#include "button.h"
#include "gtk/gtk.h"
#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include <gtkmm/button.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/stylecontext.h>
#include <iostream>

Home::Home() {

  set_title("Splitgram");
  set_size_request(500, 500);

  // Create main horizontal box
  auto Hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL);

  // Add CSS classes
  add_css_class("Hwindow");
  Hbox->add_css_class("Hbox");

  // Apply CSS to the window and the boxes
  auto cssprovider = Gtk::CssProvider::create();
  try {
    cssprovider->load_from_path(
        "/home/injustice/Documents/projects/splitgram/style/style.css");
  } catch (const Glib::Error &ex) {
    std::cerr << "CSS Load Error: " << ex.what() << std::endl;
    return;
  }

  // Apply CSS context
  auto SHcontext = get_style_context();
  auto SBcontext = Hbox->get_style_context();
  SHcontext->add_provider(cssprovider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  SBcontext->add_provider(cssprovider, GTK_STYLE_PROVIDER_PRIORITY_USER);

  // Set the boxes to expand to take equal space in the main window
  Hbox->set_homogeneous(true); // Distribute space evenly between child boxes

  // Add buttons for testing the box's layout
  auto button1 = Gtk::make_managed<Gtk::Button>("Button 1");
  auto button2 = Gtk::make_managed<Gtk::Button>("Button 2");

  // Add the main box to the window
  set_child(*Hbox);
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
  Hbox->append(*box);
  Hbox->show();
}

Home::~Home() {}

