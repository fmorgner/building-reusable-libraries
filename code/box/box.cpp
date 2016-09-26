#include "box.h"
#include "box_impl.hpp"

extern "C" {

  struct box {
    box(std::size_t size) : real{size} {}
    impl::box real;
  };

  box_t box_create(size_t size, int * err) {
    box_t ins = nullptr;

    try {
      ins = new box{size};
    } catch (...) {
      if(err) {
        *err = 1;
      }
    }

    return ins;
  }

  void box_destroy(box_t ins) {
    delete(ins);
  }

  void box_push(box_t ins, int elem, int * err) {
    if(ins) {
      try {
        ins->real.push(elem);
      } catch(...) {
        if(err) {
          *err = 1;
        }
      }
    } else if(err) {
      *err = 2;
    }
  }

  int box_pop(box_t ins, int * err) {
    if(ins) {
      try {
        return ins->real.pop();
      } catch(...) {
        if(err) {
          *err = 1;
        }
      }
    } else if(err) {
      *err = 2;
    }

    return {};
  }

}
