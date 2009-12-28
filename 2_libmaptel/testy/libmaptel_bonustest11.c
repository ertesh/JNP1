#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "1234a6789";

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "is_cyclic niepoprawny numer,"
                  " powinno zadzialac assert()\n");
  maptel_is_cyclic(id, t1);

  return 0;
}
