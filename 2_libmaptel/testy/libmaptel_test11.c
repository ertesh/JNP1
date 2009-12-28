#include <assert.h>
#include <stdio.h>
#include "maptel.h"

int main() {
  fprintf(stderr, "delete nieistniejacy slownik,"
                  " powinno zadzialac assert()\n");
  maptel_delete(7);

  return 0;
}
