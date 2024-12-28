// File: include/home.h
#ifndef HOME_H
#define HOME_H

#include "gtkmm/button.h"
#include "gtkmm/entry.h"
#include <gtkmm/box.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/listbox.h>
#include <gtkmm/window.h>

class Home : public Gtk::Window {
public:
  Home();
  virtual ~Home();

private:
  // Main containers
  Gtk::Box mBox;
  Gtk::Grid mGrid;
  // topBarBox elements
  Gtk::Box topBarBox{Gtk::Orientation::HORIZONTAL};
  Gtk::Entry searchBox;
  Gtk::Button searchButton{"$"};
  Gtk::Button profileButton{"="};

  Gtk::Button nChatButton{"+"};
  Gtk::ListBox chatList{};
  Gtk::Box bottomBox{Gtk::Orientation::HORIZONTAL};

  ;
  // Chat area elements
  Gtk::Box chatAreaBox{Gtk::Orientation::VERTICAL};
  Gtk::Label chatAreaLabel{"Welcome to the chat area!"};

protected:
  void onSearch(char *search);
  void onProfile();
  void onNewChatB();
};

#endif // HOME_H
