#ifndef GTK_BUTTONS_H
#define GTK_BUTTONS_H

#include "gtkmm/button.h"
#include "gtkmm/window.h"

class Buttons : public Gtk::Window {

public:
  Buttons();
  ~Buttons();

protected:
  // signal handlers
  void on_button_clicked();

  // Child widgets
  Gtk::Button m_button;
};

#endif // !GTK_BUTTONS_H
