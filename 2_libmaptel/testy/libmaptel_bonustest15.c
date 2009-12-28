#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";

int main() {
  unsigned long id;
  char t9[22];

  id = maptel_create();
  fprintf(stderr, "transform_ex nieistniejacy slownik,"
                  " powinno zadzialac assert()\n");
  maptel_transform_ex(7, t1, t9, 22);

  return 0;
}
