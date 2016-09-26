#include "box_impl.hpp"

#include <stdexcept>

namespace impl {

  box::box(std::size_t size) :
    m_data{std::make_unique<int[]>(size)},
    m_capacity{size} { }

  void box::push(int const element) {
    if(m_size == m_capacity) {
      throw std::overflow_error{"Box is full"};
    }

    m_data[m_size++] = element;
  }

  int box::pop() {
    if(!m_size) {
      throw std::underflow_error{"Box is empty"};
    }

    return m_data[--m_size];
  }

}
