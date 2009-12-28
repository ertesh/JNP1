#include <assert.h>
#include <string.h>
#include "maptel.h"

static const char t123[] = "123";
static const char t234[] = "234";
static const char t345[] = "345";
static const char t456[] = "456";
static const char t567[] = "567";
static const char t789[] = "789";

int main() {
  unsigned long id;
  char tel[22];
  int res;

  id = maptel_create();
  maptel_insert(id, t123, t123);
  maptel_transform(id, t123, tel, 22);
  assert(strcmp(tel, t123) == 0);
  res = maptel_is_cyclic(id, t123);
  assert(res != 0);
  maptel_insert(id, t123, t234);
  maptel_insert(id, t234, t123);
  res = maptel_is_cyclic(id, t123);
  assert(res != 0);
  res = maptel_is_cyclic(id, t234);
  assert(res != 0);
  maptel_insert(id, t123, t234);
  maptel_insert(id, t234, t345);
  maptel_insert(id, t345, t123);
  maptel_insert(id, t456, t234);
  res = maptel_is_cyclic(id, t123);
  assert(res != 0);
  res = maptel_is_cyclic(id, t234);
  assert(res != 0);
  res = maptel_is_cyclic(id, t345);
  assert(res != 0);
  res = maptel_is_cyclic(id, t456);
  assert(res != 0);
  maptel_insert(id, t345, t789);
  res = maptel_is_cyclic(id, t123);
  assert(res == 0);
  res = maptel_is_cyclic(id, t234);
  assert(res == 0);
  res = maptel_is_cyclic(id, t345);
  assert(res == 0);
  res = maptel_is_cyclic(id, t789);
  assert(res == 0);
  res = maptel_is_cyclic(id, t567);
  assert(res == 0);
  res = maptel_is_cyclic(id, t789);
  assert(res == 0);
  maptel_transform_ex(id, t123, tel, 22);
  assert(strcmp(tel, t789) == 0);
  maptel_transform_ex(id, t234, tel, 22);
  assert(strcmp(tel, t789) == 0);
  maptel_transform_ex(id, t345, tel, 22);
  assert(strcmp(tel, t789) == 0);
  maptel_transform_ex(id, t789, tel, 22);
  assert(strcmp(tel, t789) == 0);

  return 0;
}
