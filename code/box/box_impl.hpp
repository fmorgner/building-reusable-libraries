#ifndef BOX_IMPL
#define BOX_IMPL

#include <memory>

namespace impl {

  struct box {
    box(std::size_t const size);

    void push(int const element);

    int pop();

    private:
      std::unique_ptr<int[]> m_data{};
      std::size_t const m_capacity{};
      std::size_t m_size{};
  };

}

#endif
