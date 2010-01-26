// Maciej Andrejczuk
// Task 2 - Libmaptel

#ifndef _MAPTEL_H_
#define _MAPTEL_H_

#ifdef __cplusplus
    #include <cstring>
    extern "C" {
#else
    #include <string.h>
#endif

// Creates a dictionary and returns its unique `id`.
unsigned long maptel_create();

// Removes a dictionary with given `id`.
void maptel_delete(unsigned long id);

// Inserts to the dictionary `id` an edge from `tel_src` to `tel_dst`.
// If any edge from `id` existed, it is erased.
void maptel_insert(unsigned long id, const char *tel_src, const char *tel_dst);

// Erases from the dictionary `id` information about an edge from `tel_src`.
// If no such edge exists, nothing happens
void maptel_erase(unsigned long id, const char *tel_src);

// If in the dictionary `id` an edge from `tel_src` exists,
// `tel_dst` becomes a destination of this edge,
// otherwise `tel_dst` becomes `tel_src`.
void maptel_transform(unsigned long id, const char *tel_src, char *tel_dst,
                      size_t len);

// Checks if in the dictionary `id` a cycle containing `tel_src` exists.
// If starting from `tel_src` we could get to `tel_src` again, returns 1,
// otherwise returns 0.
int maptel_is_cyclic(unsigned long id, const char *tel_src);

// Works the same as `maptel_transform`, but follows the path from `tel_src`
// as long as possible, not just one step.
void maptel_transform_ex(unsigned long id, const char *tel_src, char *tel_dst,
              size_t len);

#ifdef __cplusplus
}
#endif

#endif

