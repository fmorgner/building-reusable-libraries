#ifndef BOX
#define BOX

#ifndef EXPORTED
#define EXPORTED __attribute__((visibility("default")))
#endif

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct box * box_t;

  EXPORTED
  box_t box_create(size_t size, int * err);

  EXPORTED
  void box_destroy(box_t ins);

  EXPORTED
  int box_pop(box_t ins, int * err);

  EXPORTED
  void box_push(box_t ins, int elem, int * err);

#ifdef __cplusplus
}
#endif

#endif
