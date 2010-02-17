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

const Quaternion& Quaternion::operator= (const Quaternion& q) {
    if (this != &q) {
	a = q.r();
	b = q.i();
        c = q.j();
        d = q.k();
    }
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
    a += q.r();
    b += q.i();
    c += q.j();
    d += q.k();
    return *this;
}

Quaternion& Quaternion::operator-= (const Quaternion& q) {
    a -= q.r();
    b -= q.i();
    c -= q.j();
    d -= q.k();
    return *this;
}

Quaternion& Quaternion::operator*= (const Quaternion& q) {
    double pa = a * q.r() - b * q.i() - c * q.j() - d * q.k();
    double pb = a * q.i() + b * q.r() + c * q.k() - d * q.j();
    double pc = a * q.j() - b * q.k() + c * q.r() + d * q.i();
    double pd = a * q.k() + b * q.j() - c * q.i() + d * q.r();
    a = pa;
    b = pb;
    c = pc;
    d = pd;
    return *this;
}

inline Quaternion operator+ (const Quaternion& p, const Quaternion& q) {
    Quaternion r(p);
    return r += q;
}

inline Quaternion operator- (const Quaternion& p, const Quaternion& q) {
    Quaternion r(p);
    return r -= q;
}

inline Quaternion operator* (const Quaternion& p, const Quaternion& q) {
    Quaternion r(p);
    return r *= q;
}

inline bool operator== (const Quaternion& p, const Quaternion& q) {
    if (p.r() != q.r()) return false;
    if (p.i() != q.i()) return false;
    if (p.j() != q.j()) return false;
    return (p.k() == q.k());
}

inline bool operator!= (const Quaternion& p, const Quaternion& q) {
    return !operator==(p, q);
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

