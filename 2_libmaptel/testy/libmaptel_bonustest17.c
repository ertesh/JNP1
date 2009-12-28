#include <assert.h>
#include <stdio.h>
#include "maptel.h"

int main() {
  unsigned long id;
  char t9[22];

  id = maptel_create();
  fprintf(stderr, "transform_ex zerowy wskaznik,"
                  " powinno zadzialac assert()\n");
  maptel_transform_ex(id, 0, t9, 22);

  return 0;
}
