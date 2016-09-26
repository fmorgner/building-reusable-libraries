#ifndef FANCYPP
#define FANCYPP

#include "fancy.h"
#include <string>

namespace cppug {

  void be_fancy(std::string entity) {
    cppug_be_fancy_on_stdout(entity.c_str());
  }

}

#endif
