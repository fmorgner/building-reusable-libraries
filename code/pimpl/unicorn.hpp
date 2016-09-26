#ifndef UNICORN
#define UNICORN

#include <iostream>
#include <string>
#include <memory>

struct unicorn {
  unicorn(std::string name, std::string color);

  // MUST declare dtor!
  ~unicorn();

  void glitter(std::ostream & out = std::cout) const;

  void fly(std::ostream & out = std::cout) const;

  private:
    std::unique_ptr<struct unicorn_impl> m_impl;
};

#endif
