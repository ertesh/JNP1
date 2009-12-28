#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t1[] = "123456789";
static const char t2[] = "23456+890";

int main() {
  unsigned long id;

  id = maptel_create();
  fprintf(stderr, "insert bledny numer,"
                  " powinno zadzialac assert()\n");
  maptel_insert(id, t1, t2);

  return 0;
}
