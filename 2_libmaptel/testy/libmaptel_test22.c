#include <assert.h>
#include <stdio.h>
#include "maptel.h"

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "erase zerowy wskaznik,"
                  " powinno zadzialac assert()\n");
  maptel_erase(id, 0);

  return 0;
}
