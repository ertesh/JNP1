#include <iostream>
#include <cmath>

#include "quatseq.h"

using namespace std;

Quaternion::Quaternion(double a_, double b_, double c_, double d_)
: a(a_), b(b_), c(c_), d(d_)
{
}

Quaternion::Quaternion(const Quaternion& q)
: a(q.r()), b(q.i()), c(q.j()), d(q.k())
{
}

Quaternion& Quaternion::operator= (const Quaternion& q) {
    a = q.r();
    b = q.i();
    c = q.j();
    d = q.k();
    return *this;
}

Quaternion& Quaternion::operator- () {
    a = -a;
    b = -b;
    c = -c;
    d = -d;
    return *this;
}

Quaternion& Quaternion::operator+= (const Quaternion& q) {
    
}

inline double Quaternion::r() const {
    return a;
} 

inline double Quaternion::i() const {
    return b;
}

inline double Quaternion::j() const {
    return c;
}

inline double Quaternion::k() const {
    return d;
}


inline Quaternion re(const Quaternion& q) {
    return Quaternion(q.r(), 0, 0, 0);
}

inline Quaternion im(const Quaternion& q) {
    return Quaternion(0, q.i(), q.j(), q.k());
}

inline Quaternion conj(const Quaternion& q) {
    return Quaternion(q.r(), -q.i(), -q.j(), -q.k());
}

inline static double sqr(double d) {
    return d*d;
}

inline double norm(const Quaternion& q) {
    return sqrt(sqr(q.r()) + sqr(q.i()) + sqr(q.j()) + sqr(q.k()));
}

