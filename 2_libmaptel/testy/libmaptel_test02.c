#include <assert.h>
#include <string.h>
#include "maptel.h"

static const char t0[] = "012345678";
static const char t1[] = "12345678";
static const char t2[] = "23456789";
static const char t9[] = "9";

static const char t123[] = "123";
static const char t234[] = "234";
static const char t345[] = "345";
static const char t645[] = "645";

static const int i_max = 10;
static const int t_max = 22;

int main() {
  unsigned long id[i_max];
  int i;
  char tel[t_max];

  for (i = 0; i < i_max; ++i) {
    id[i] = maptel_create();
  }

  for (i = 0; i < i_max; ++i) {
    maptel_insert(id[i], t0, t2);
    maptel_insert(id[i], t1, t2);
    maptel_transform(id[i], t0, tel, t_max);
    assert(strcmp(tel, t2) == 0);
    maptel_transform(id[i], t1, tel, t_max);
    assert(strcmp(tel, t2) == 0);
  }

  for (i = 0; i < i_max; ++i) {
    maptel_insert(id[i], t123, t234);
    maptel_transform(id[i], t123, tel, t_max);
    assert(strcmp(tel, t234) == 0);
    maptel_insert(id[i], t123, t345);
    maptel_transform(id[i], t123, tel, t_max);
    assert(strcmp(tel, t345) == 0);
  }

  for (i = 0; i < i_max; ++i) {
    maptel_insert(id[i], t123, t234);
    maptel_insert(id[i], t645, t234);
    maptel_transform(id[i], t123, tel, t_max);
    assert(strcmp(tel, t234) == 0);
    maptel_transform(id[i], t645, tel, t_max);
    assert(strcmp(tel, t234) == 0);
  }

  for (i = 0; i < i_max; ++i) {
    maptel_erase(id[i], t123);
    maptel_transform(id[i], t123, tel, t_max);
    assert(strcmp(tel, t123) == 0);
    maptel_transform(id[i], t645, tel, t_max);
    assert(strcmp(tel, t234) == 0);
  }

  for (i = 0; i < i_max; ++i) {
    maptel_erase(id[i], t645);
    maptel_transform(id[i], t645, tel, t_max);
    assert(strcmp(tel, t645) == 0);
    maptel_insert(id[i], t645, t9);
    maptel_transform(id[i], t9, tel, t_max);
    assert(strcmp(tel, t9) == 0);
  }

  for (i = 0; i < i_max; ++i) {
    maptel_delete(id[i]);
  }

  return 0;
}
