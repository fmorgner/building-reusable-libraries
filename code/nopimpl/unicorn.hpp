#ifndef UNICORN
#define UNICORN

#include <iostream>
#include <string>

struct unicorn {
  unicorn(std::string name, std::string color);

  void glitter(std::ostream & out = std::cout) const;

  void fly(std::ostream & out = std::cout) const;

  private:
    std::size_t calculate_altitude() const;

    std::string const m_name{};
    std::string const m_color{};
};

#endif
