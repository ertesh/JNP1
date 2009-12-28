#include <assert.h>
#include <stdio.h>
#include "maptel.h"

static const char t123[] = "123";
static const char t234[] = "234";
static const char t345[] = "345";

int main() {
  unsigned long id;
  char tel[22];

  id = maptel_create();
  maptel_insert(id, t123, t234);
  maptel_insert(id, t234, t345);
  maptel_insert(id, t345, t123);
  fprintf(stderr, "transform_ex cykl,"
                  " powinno zadzialac assert()\n");
  maptel_transform_ex(id, t234, tel, 22);

  return 0;
}
