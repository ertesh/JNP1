#include <iostream>
#include <cmath>

#include "quatseq.h"

using namespace std;

#ifdef DEBUG_LEVEL
    static const int debuglevel = DEBUG_LEVEL;
#else
    static const int debuglevel = 0;
#endif

class Debug {
    public:
    int verbose_debuglevel;

    template <class T>
    Debug& operator<< (const T& message) {
       if (debuglevel >= verbose_debuglevel)
            cerr << message;
        return *this;
    }

    Debug& operator<< (ostream& (*fun)(ostream&)) {
        if (debuglevel >= verbose_debuglevel)
            cerr << fun;
        return *this;
    }
};

static Debug& debug(int dbglevel) {
    static Debug db;
    db.verbose_debuglevel = dbglevel;
    if (debuglevel >= dbglevel)
        cerr << "quatseq: ";
    return db;
}

// Quaternion

Quaternion::Quaternion(double a_, double b_, double c_, double d_)
: a(a_), b(b_), c(c_), d(d_)
{
    debug(2) << "Constructor" << endl;
}

Quaternion::Quaternion(Quaternion const& q)
: a(q.r()), b(q.i()), c(q.j()), d(q.k())
{
    debug(2) << "Copy constructor" << endl;
}

double const Quaternion::r() const {
    return a;
}

double const Quaternion::i() const {
    return b;
}

double const Quaternion::j() const {
    return c;
}

double const Quaternion::k() const {
    return d;
}

Quaternion const& Quaternion::operator= (Quaternion const& q) {
    debug(2) << "Operator=" << endl;
    if (this != &q) {
	    a = q.r();
	    b = q.i();
        c = q.j();
        d = q.k();
    }
    return *this;
}

Quaternion const& Quaternion::operator+= (Quaternion const& q) {
    debug(2) << "Operator+=" << endl;
    a += q.r();
    b += q.i();
    c += q.j();
    d += q.k();
    return *this;
}

Quaternion const& Quaternion::operator-= (Quaternion const& q) {
    debug(2) << "Operator-=" << endl;
    a -= q.r();
    b -= q.i();
    c -= q.j();
    d -= q.k();
    return *this;
}

Quaternion const& Quaternion::operator*= (Quaternion const& q) {
    debug(2) << "Operator*=" << endl;
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

Quaternion const operator+ (Quaternion const& p, Quaternion const& q) {
    debug(2) << "Operator+" << endl;
    Quaternion r(p);
    return r += q;
}

Quaternion const operator- (Quaternion const& p, Quaternion const& q) {
    debug(2) << "Operator- (binary)" << endl;
    Quaternion r(p);
    return r -= q;
}

Quaternion const operator* (Quaternion const& p, Quaternion const& q) {
    debug(2) << "Operator*" << endl;
    Quaternion r(p);
    return r *= q;
}

Quaternion const operator- (Quaternion const& p) {
    debug(2) << "Operator- (unary)" << endl;
    Quaternion r(0);
    return r -= p;
}

bool operator== (Quaternion const& p, Quaternion const& q) {
    debug(2) << "Operator==" << endl;
    return (p.r() == q.r() && p.i() == q.i()
        && p.j() == q.j() && p.k() == q.k());
}

bool operator!= (Quaternion const& p, Quaternion const& q) {
    debug(2) << "Operator!=" << endl;
    return !(p == q);
}

ostream& operator<< (ostream& out, Quaternion const& q) {
    out << "(" << q.r() << "," << q.i() << "," << q.j()
        << "," << q.k() << ")";
    return out;
}

Quaternion const re(Quaternion const& q) {
    return Quaternion(q.r(), 0, 0, 0);
}

Quaternion const im(Quaternion const& q) {
    return Quaternion(0, q.i(), q.j(), q.k());
}

Quaternion const conj(Quaternion const& q) {
    return Quaternion(q.r(), -q.i(), -q.j(), -q.k());
}

static double sqr(double d) {
    return d*d;
}

double norm(Quaternion const& q) {
    return sqrt(sqr(q.r()) + sqr(q.i()) + sqr(q.j()) + sqr(q.k()));
}

Quaternion const Zero() {
    static Quaternion ret(0, 0, 0, 0);
    return ret;
}

Quaternion const I() {
    static Quaternion ret(0, 1, 0, 0);
    return ret;
}

Quaternion const J() {
    static Quaternion ret(0, 0, 1, 0);
    return ret;
}

Quaternion const K() {
    static Quaternion ret(0, 0, 0, 1);
    return ret;
}

// QuaternionSequence

QuaternionSequence::QuaternionSequence()
: data()
{
}

QuaternionSequence::QuaternionSequence(map_type const& m)
: data(m)
{
    removeNullQuaternions();
}

QuaternionSequence::QuaternionSequence(std::vector<Quaternion> const& v)
{
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] != Quaternion(0))
            data[i] = v[i];
    }
}

QuaternionSequence::QuaternionSequence(QuaternionSequence const& q)
: data(q.data)
{
    removeNullQuaternions();
}

QuaternionSequence const& QuaternionSequence::operator= (
        QuaternionSequence const& q)
{
    data = q.data; // czy mapa sama robi sprzątanie?
    removeNullQuaternions();
    return *this;
}

QuaternionSequence const& QuaternionSequence::operator-= (
        QuaternionSequence const& q)
{
    for (map_type::const_iterator ii = q.data.begin(); ii != q.data.end(); ii++)
    {
        Quaternion val = (*this)[ii->first] - ii->second;
        this->data[ii->first] = val;
    }
    removeNullQuaternions();
    return *this;
}
QuaternionSequence const& QuaternionSequence::operator+= (
        QuaternionSequence const& q)
{
    for (map_type::const_iterator ii = q.data.begin(); ii != q.data.end(); ii++)
    {
        Quaternion val = (*this)[ii->first] + ii->second;
        this->data[ii->first] = val;
    }
    removeNullQuaternions();
    return *this;
}
QuaternionSequence const& QuaternionSequence::operator*= (
        QuaternionSequence const& q)
{
    for (map_type::const_iterator ii = q.data.begin(); ii != q.data.end(); ii++)
    {
        Quaternion val = (*this)[ii->first] * ii->second;
        this->data[ii->first] = val;
    }
    removeNullQuaternions();
    return *this;
}

Quaternion const QuaternionSequence::operator[] (int k) const
{
    map_type::const_iterator ii = data.find(k);
    if (ii == data.end())
        return Quaternion(0);
    return ii->second;
}

Quaternion& QuaternionSequence::operator[] (int k)
{
    map_type::iterator ii = data.find(k);
    if (ii == data.end()) {
        data[k] = Zero();
        return data[k];
        // The condition 'non-zero elements' is not kept
    }
    return ii->second;
}

QuaternionSequence const operator- (QuaternionSequence const& p,
        QuaternionSequence const& q)
{
    QuaternionSequence r(p);
    return r -= q;
}

QuaternionSequence const operator+ (QuaternionSequence const& p,
        QuaternionSequence const& q)
{
    QuaternionSequence r(p);
    return r += q;
}

QuaternionSequence const operator* (QuaternionSequence const& p,
        QuaternionSequence const& q)
{
    QuaternionSequence r(p);
    return r *= q;
}

void QuaternionSequence::removeNullQuaternions()
{
    Quaternion emp(0);
    for (QuaternionSequence::map_type::iterator ii = data.begin();
            ii != data.end(); ii++) {
        if (ii->second == emp)
            data.erase(ii); // ii is still OK?
    }
}

bool operator== (QuaternionSequence const& p,
        QuaternionSequence const& q)
{
    debug(1) << "Operator ==" << endl << p << q;
    return p.data == q.data;
}

bool operator!= (QuaternionSequence const& p,
        QuaternionSequence const& q)
{
    debug(1) << "Operator !=" << endl << p << q;
    return !(p == q);
}

std::ostream& operator<< (std::ostream& out, QuaternionSequence const& q)
{
    out << "QuaternionSequence: " << endl;
    for (QuaternionSequence::map_type::const_iterator ii = q.data.begin();
            ii != q.data.end(); ii++) {
        out << ii->first << ": " << ii->second << endl;
    }
    return out;
}

