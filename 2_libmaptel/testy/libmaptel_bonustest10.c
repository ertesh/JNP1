#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";

int main() {
  fprintf(stderr, "is_cyclic nieistniejacy slownik,"
                  " powinno zadzialac assert()\n");
  maptel_is_cyclic(7, t1);

  return 0;
}
