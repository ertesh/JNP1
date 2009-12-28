#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";

int main() {
  char t9[22];

  fprintf(stderr, "transform nieistniejacy slownik,"
                  " powinno zadzialac assert()\n");
  maptel_transform(7, t1, t9, 22);

  return 0;
}
