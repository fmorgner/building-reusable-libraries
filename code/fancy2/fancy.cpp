#include "fancy.h"
#include "fancy_lib.hpp"

extern "C" {

  void cppug_be_fancy_on_stdout(char const * const entity) {
    cppug::be_fancy(entity);
  }

}
