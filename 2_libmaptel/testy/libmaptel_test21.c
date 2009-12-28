#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "1234a6789";

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "erase niepoprawny numer,"
                  " powinno zadzialac assert()\n");
  maptel_erase(id, t1);

  return 0;
}
