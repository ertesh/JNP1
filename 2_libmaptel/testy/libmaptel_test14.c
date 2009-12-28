#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "insert zerowy wskaznik,"
                  " powinno zadzialac assert()\n");
  maptel_insert(id, 0, t1);

  return 0;
}
