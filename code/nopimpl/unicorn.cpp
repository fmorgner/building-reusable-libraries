#include "unicorn.hpp"

unicorn::unicorn(std::string name, std::string color) :
  m_name{name}, m_color{color} {}

void unicorn::glitter(std::ostream & out) const {
  out << m_name << " glitters beautifully\n";
}

void unicorn::fly(std::ostream & out) const {
  out << m_name << " flies at " << calculate_altitude() << "m\n";
}

std::size_t unicorn::calculate_altitude() const {
  return 8 * m_color.size();
}
