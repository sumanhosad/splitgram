#include "../includes/home.h"
#include "gtkmm/enums.h"

Home::Home() {
  // Set up main container
  set_title("Splitgram");
  set_default_size(800, 600);

  mBox.set_size_request(800, 600);
  mBox.set_orientation(Gtk::Orientation::VERTICAL);
  // setting up the grid
  mGrid.set_row_homogeneous(true);
  mGrid.set_column_homogeneous(true);
  mGrid.add_css_class("mBox");

  // configure topBarBox
  topBarBox.set_spacing(10); // Add space between the buttons
  topBarBox.set_size_request(800, 100);
  mGrid.set_size_request(800, 100);
  // attaching the items
  mGrid.attach(searchButton, 1, 0);
  mGrid.attach(profileButton, 0, 0);

  // Add the grid (containing the buttons) to the topBarBox
  topBarBox.append(mGrid);

  // Add topBarBox to the main container (mBox)
  mBox.append(topBarBox);

  // Add chatList to the main container (mBox), it will appear below the top bar
  chatList.add_css_class("chatList");
  mBox.append(chatList);

  // Set the main container (mBox) as the window's child
  set_child(mBox);
}

Home::~Home() {}
