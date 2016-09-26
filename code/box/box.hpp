#ifndef BOXPP
#define BOXPP

#include "box.h"
#include <cstdint>
#include <stdexcept>

namespace cppug {
  struct box {

  box(std::size_t size) : m_impl{box_create(size, nullptr)} {
    if(!m_impl) {
      throw std::runtime_error{"Failed to alloc box"};
    }
  }

  ~box() {
    box_destroy(m_impl);
  }

  void push(int elem) {
    int error{};
    box_push(m_impl, elem, &error);
    if(error) {
      throw std::overflow_error{"Box is full"};
    }
  }

  int pop() {
    int error{};
    int val = box_pop(m_impl, &error);
    if(error) {
      throw std::overflow_error{"Box is full"};
    }

    return val;
  }

  private:
    box_t m_impl{};
  };
}

#endif
