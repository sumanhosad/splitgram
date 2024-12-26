#include "helloworld.h"
#include "sigc++/functors/mem_fun.h"
#include <iostream>
#include <ostream>

HelloWorld::HelloWorld()
    : m_button(
          "HelLo_World!!!") // creates a new button with the name hello world
{
  // set the margin
  m_button.set_margin(10);

  // When the button is clicked it will call the on_button_clicked function we
  // defined below
  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloWorld::on_button_clicked));

  // this packs the button into a window
  // simply means adds the button to window
  set_child(m_button);
}

HelloWorld::~HelloWorld() { std::cout << "Destroying!!!"; }

void HelloWorld::on_button_clicked() {
  std::cout << "Hello World!!!" << std::endl;
}
