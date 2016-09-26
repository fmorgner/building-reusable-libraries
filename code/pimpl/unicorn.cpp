#include "unicorn.hpp"

struct unicorn_impl {
  unicorn_impl(std::string name, std::string color) :
    m_name{name}, m_color{color} {}

  void glitter(std::ostream & out) const {
    out << m_name << " glitters beautifully\n";
  }

  void fly(std::ostream & out) const {
    out << m_name << " flies at " << altitude() << "m\n";
  }

  private:
    std::size_t altitude() const { return 14 * m_color.size(); }
    std::string const m_name;
    std::string const m_color;
};

// MUST define dtor after unicorn_impl is known
unicorn::~unicorn() = default;

unicorn::unicorn(std::string name, std::string color) :
  m_impl{std::make_unique<unicorn_impl>(name, color)} { }

void unicorn::glitter(std::ostream & out) const {
  m_impl->glitter(out);
}

void unicorn::fly(std::ostream & out) const {
  m_impl->fly(out);
}
