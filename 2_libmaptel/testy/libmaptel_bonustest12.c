#include <assert.h>
#include <stdio.h>
#include "maptel.h"

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "is_cyclic zerowy wskaznik,"
                  " powinno zadzialac assert()\n");
  maptel_is_cyclic(id, 0);

  return 0;
}
