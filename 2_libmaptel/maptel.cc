// Maciej Andrejczuk
// Task 2 - Libmaptel

#include <iostream>
#include <map>
#include <assert.h>
#include "maptel.h"

using namespace std;

#ifdef DEBUG_LEVEL
    static const int debuglevel = DEBUG_LEVEL;
#else
    static const int debuglevel = 0;
#endif

// Representation of a single dictionary
typedef map<string, string> Dict; 

// Representation of all dictionaries
typedef map<unsigned long, Dict> DictMap; 


class Debug 
{
    public:
    static const int VERBOSE_DEBUGLEVEL = 2;
    
    template <class T> 
    Debug& operator<< (const T& message) {
        if (debuglevel >= VERBOSE_DEBUGLEVEL) 
            cerr << message;
        return *this;
    }
    
    Debug& operator<< (ostream& (*fun)(ostream&)) {
        if (debuglevel >= VERBOSE_DEBUGLEVEL)
            cerr << fun;
        return *this;
    }
};

static Debug& debug() 
{
    static Debug db;
    if (debuglevel >= Debug::VERBOSE_DEBUGLEVEL)
        cerr << "libmaptel: ";
    return db;
}

// Accessor to all dictionaries
static DictMap& dmap() 
{
    static DictMap dict_map;
    return dict_map;
}

static inline bool valid_dict_id(unsigned long id) 
{
    return (dmap().find(id) != dmap().end());
}

static bool valid_number(const char *tel) 
{
    if (tel == NULL) return false;
    int n = strlen(tel);
    if (n == 0) return false;
    for (int i = 0; i < n; i++)
        if (!isdigit(tel[i])) return false;
    return true;
}

static inline bool move(Dict::iterator &it, Dict &dict) 
{
    assert(it != dict.end());
    it = dict.find(it->second);
    return (it != dict.end());
}

// Implementation of public functions

unsigned long maptel_create()
{
    debug() << "maptel_create()" << endl;
    static unsigned long map_counter = 0;
    assert(map_counter + 1 > 0);
    dmap()[map_counter] = Dict();
    debug() << "maptel_create: new map id = " << map_counter << endl;
    return map_counter++;
}

void maptel_delete(unsigned long id)
{
    debug() << "maptel_delete()" << endl;
    assert(valid_dict_id(id));
    dmap()[id].clear();
    dmap().erase(id);
    debug() << "maptel_delete: map " << id << " deleted." << endl;
}

void maptel_insert(unsigned long id, const char *tel_src, const char *tel_dst)
{
    debug() << "maptel_insert(" << id << ", " << tel_src << ", " << tel_dst 
            << ")" << endl;
    assert(valid_dict_id(id));
    assert(valid_number(tel_src));
    assert(valid_number(tel_dst));
    dmap()[id][string(tel_src)] = string(tel_dst);
    debug() << "maptel_insert: inserted" << endl;
}

void maptel_erase(unsigned long id, const char *tel_src)
{
    debug() << "maptel_erase(" << id << ", " << tel_src << ")" << endl;
    assert(valid_dict_id(id));
    assert(valid_number(tel_src));
    Dict::iterator it = dmap()[id].find(tel_src);
    if (it == dmap()[id].end()) {
        debug() << "maptel_erase: nothing to erase" <<endl;
    }
    else {
        dmap()[id].erase(it);
        debug() << "maptel_erase: erased" << endl;
    }
}

void maptel_transform(unsigned long id, const char *tel_src, char *tel_dst, 
                      size_t len)
{
    debug() << "maptel_transform(" << id << ", " << tel_src << ", " 
            << (void*) tel_dst << ", " << len << ")" << endl;
    assert(valid_dict_id(id));
    assert(valid_number(tel_src));
    assert(tel_dst != NULL);
    const char *ans = tel_src;
    if (dmap()[id].find(string(tel_src)) != dmap()[id].end()) 
        ans = dmap()[id][tel_src].c_str();
    assert(strlen(ans) < len);
    strcpy(tel_dst, ans);
    debug() << "maptel_transform: " << tel_src << " -> " << tel_dst << endl;
}

int maptel_is_cyclic(unsigned long id, const char *tel_src)
{
    debug() << "maptel_is_cyclic(" << id << ", " << tel_src << ")" << endl;
    assert(valid_dict_id(id));
    assert(valid_number(tel_src));
    Dict::iterator ii = dmap()[id].find(string(tel_src));
    Dict::iterator jj = ii;
    bool is_cycle = false;
    while (ii != dmap()[id].end()) {
        if (!move(ii, dmap()[id])) break;
        if (!move(ii, dmap()[id])) break;
        if (!move(jj, dmap()[id])) break;
        if (jj == ii) {
            is_cycle = true;
            break;
        }
    }
    debug() << "maptel_is_cyclic: " << is_cycle << endl;
    return is_cycle;
}

void maptel_transform_ex(unsigned long id, const char *tel_src, char *tel_dst,
                         size_t len)
{
    debug() << "maptel_transform_ex(" << id << ", " << tel_src << ", " 
            << (void*) tel_dst << ", " << len << ")" << endl;
    assert(valid_dict_id(id));
    assert(valid_number(tel_src));
    assert(tel_dst != NULL);
    assert(!maptel_is_cyclic(id, tel_src));
    const char* ans = tel_src;
    Dict::iterator it = dmap()[id].find(string(tel_src));
    while (it != dmap()[id].end()) {
        ans = it->second.c_str();
        if (!move(it, dmap()[id])) break;
    } 
    assert(strlen(ans) < len);
    strcpy(tel_dst, ans);
    debug() << "maptel_transform_ex: " << tel_src << " -> " << tel_dst << endl;
}

