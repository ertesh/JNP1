#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";

int main() {
  fprintf(stderr, "erase nieistniejacy slownik,"
                  " powinno zadzialac assert()\n");
  maptel_erase(7, t1);

  return 0;
}
