#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "transform zerowy wskaznik,"
                  " powinno zadzialac assert()\n");
  maptel_transform(id, t1, 0, 22);

  return 0;
}
