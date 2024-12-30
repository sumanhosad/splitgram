#include "../includes/home.h"
#include "gtkmm/enums.h"

Home::Home() {
  // Set up main container
  set_title("Splitgram");
  set_default_size(800, 600);
  add_css_class("home");

  // adding css labels

  // Main box
  mBox.set_orientation(Gtk::Orientation::VERTICAL);
  mBox.set_vexpand(true); // Allow mBox to expand vertically
  mBox.set_hexpand(true); // Allow mBox to expand horizontally

  // Set up the grid
  mGrid.set_row_homogeneous(true);
  mGrid.set_column_homogeneous(false); // Allow different column widths
  mGrid.add_css_class("mBox");

  // Configure topBarBox
  topBarBox.set_spacing(10);    // Add space between the buttons
  topBarBox.set_vexpand(false); // Fixed height for the top bar
  topBarBox.set_hexpand(true);  // Allow horizontal expansion

  // Configure children sizes
  profileButton.set_size_request(75, 0);
  searchButton.set_size_request(75, 0);
  topLabel.set_expand(true);       // Allow the label to take up remaining space
  profileButton.set_expand(false); // Fixed size for the button
  searchButton.set_expand(false);  // Fixed size for the button

  // Add children to the grid
  mGrid.attach(profileButton, 0, 0, 1, 1); // Attach at (0, 0), span 1 column
  mGrid.attach(topLabel, 1, 0, 1, 1);      // Attach at (1, 0), span 1 column
  mGrid.attach(searchButton, 2, 0, 1, 1);  // Attach at (2, 0), span 1 column

  // Add the grid to the topBarBox
  topBarBox.append(mGrid);

  // Add the topBarBox to the main container
  mBox.append(topBarBox);

  // Configure chatList
  chatList.add_css_class("chatList");
  chatList.set_vexpand(
      true); // Allow chatList to take up remaining vertical space
  chatList.set_hexpand(true); // Allow chatList to expand horizontally

  // Add chatList to the main container
  mBox.append(chatList);

  // Set the main container (mBox) as the window's child
  set_child(mBox);
}

Home::~Home() {}
