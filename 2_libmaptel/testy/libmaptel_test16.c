#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "1234a6789";

int main() {
  unsigned long id;
  char t9[22];

  id = maptel_create();
  fprintf(stderr, "transform niepoprawny numer,"
                  " powinno zadzialac assert()\n");
  maptel_transform(id, t1, t9, 22);

  return 0;
}
