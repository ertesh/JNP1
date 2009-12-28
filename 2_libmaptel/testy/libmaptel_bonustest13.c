#include <assert.h>
#include <stdio.h>
#include "maptel.h"

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "is_cyclic pusty numer,"
                  " powinno zadzialac assert()\n");
  maptel_is_cyclic(id, "");

  return 0;
}
