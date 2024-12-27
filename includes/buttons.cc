#include "buttons.h"
#include "gtkmm/object.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>

Buttons::Buttons() {
  // create an image and label
  auto pmap = Gtk::make_managed<Gtk::Image>("Info.xpm ");
  auto label = Gtk::make_managed<Gtk::Label>("Cool Button");
  label->set_expand(true);

  // put them in a box
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);

  // put the box in button
  m_button.set_child(*hbox);

  set_title("pix buttons");

  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &Buttons::on_button_clicked));

  m_button.set_margin(10);
  set_child(m_button);
}

Buttons::~Buttons() { std::cout << "Destrotying the button!!!"; }

void Buttons::on_button_clicked() {
  std::cout << "button clicked" << std::endl;
};
