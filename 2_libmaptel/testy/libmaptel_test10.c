#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";
static const char t2[] = "234567890";

int main() {
  fprintf(stderr, "insert nieistniejacy slownik,"
                  " powinno zadzialac assert()\n");
  maptel_insert(7, t1, t2);

  return 0;
}
