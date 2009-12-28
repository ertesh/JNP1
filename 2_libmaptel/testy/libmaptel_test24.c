#include <assert.h>
#include <stdio.h>
#include "maptel.h"

int main() {
  unsigned long id;
  char t9[22];

  id = maptel_create();
  fprintf(stderr, "transform pusty numer,"
                  " powinno zadzialac assert()\n");
  maptel_transform(id, "", t9, 22);

  return 0;
}
