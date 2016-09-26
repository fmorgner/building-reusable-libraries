#include "box.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  box_t box = box_create(3, NULL);
  if(!box) {
    printf("Failed to create box\n");
    box_destroy(box);
    return EXIT_FAILURE;
  }

  box_push(box, 42, NULL);

  int err = 0;
  int val = box_pop(box, &err);
  if(!err) {
    printf("Popped %d\n", val);
    box_destroy(box);
    return EXIT_SUCCESS;
  }

  box_destroy(box);
  return EXIT_FAILURE;
}
