#include "buttons.h"
#include "gtk/gtk.h"
#include "gtkmm/object.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm/box.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/styleprovider.h>
#include <iostream>

Buttons::Buttons() {

  set_title("Styled Buttonss");
  set_size_request(400, 400);

  // create an image and label
  auto pmap = Gtk::make_managed<Gtk::Image>("Info.xpm ");
  auto label = Gtk::make_managed<Gtk::Label>("Cool Button");
  label->set_expand(true);

  // put them in a box
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);

  m_button.set_label("Styled Button");
  set_title("pix buttons");

  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &Buttons::on_button_clicked));

  m_button.set_size_request(100, 100);
  m_button.set_margin(100);

  // load css
  auto css_provider = Gtk::CssProvider::create();
  try {
    css_provider->load_from_path(
        "/home/injustice/Documents/projects/splitgram/style/button.css");

  } catch (const Glib::Error &ex) {
    std::cerr << "Css load error" << std::endl;
  }

  // apply css to button
  auto style_context = m_button.get_style_context();
  style_context->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

  // put the box in button
  m_button.set_child(*hbox);

  set_child(m_button);
}

Buttons::~Buttons() { std::cout << "Destrotying the button!!!"; }

void Buttons::on_button_clicked() {
  std::cout << "button clicked" << std::endl;
};
