#ifndef _QUATSEQ_H_
#define _QUATSEQ_H_

#include <ostream>
#include <map>
#include <vector>

class Quaternion
{
    public:
        // Constructor. Creates quaternion (a, b, c, d)
        Quaternion(double a = 0, double b = 0, double c = 0, double d = 0);
        // Copy constructor
        Quaternion(Quaternion const&);
        // Returns first coordinate of quaternion
        double const r() const;
        // Returns second coordinate of quaternion
        double const i() const;
        // Returns third coordinate of quaternion
        double const j() const;
        // Returns forth coordinate of quaternion
        double const k() const;

        Quaternion const& operator= (Quaternion const&);
        Quaternion const& operator-= (Quaternion const&);
        Quaternion const& operator+= (Quaternion const&);
        Quaternion const& operator*= (Quaternion const&);
    private:
        double a, b, c, d;
};

Quaternion const operator- (Quaternion const&);
Quaternion const operator- (Quaternion const&, Quaternion const&);
Quaternion const operator+ (Quaternion const&, Quaternion const&);
Quaternion const operator* (Quaternion const&, Quaternion const&);
bool operator== (Quaternion const&, Quaternion const&);
bool operator!= (Quaternion const&, Quaternion const&);
std::ostream& operator<< (std::ostream&, Quaternion const&);

// Returns quaternion equal to real part of given quaternion
Quaternion const re(Quaternion const&);
// Returns quaternion equal to imaginary part of given quaternion
Quaternion const im(Quaternion const&);
// Returns conjugation of given quaternion
Quaternion const conj(Quaternion const&);
// Returns norm of given quaternion
double norm(Quaternion const&);
// Returns quaternion (0, 0, 0, 0)
Quaternion const Zero();
// Returns quaternion (0, 1, 0, 0)
Quaternion const I();
// Returns quaternion (0, 0, 1, 0)
Quaternion const J();
// Returns quaternion (0, 0, 0, 1)
Quaternion const K();


class QuaternionSequence
{
    public:
        typedef unsigned int size_type;
        typedef std::map<size_type, Quaternion> map_type;

        // Creates an empty sequence
        QuaternionSequence();
        // Creates a sequence from map
        QuaternionSequence(map_type const&);
        // Creates a sequence from vector
        QuaternionSequence(std::vector<Quaternion> const&);
        // Copy constructor
        QuaternionSequence(QuaternionSequence const&);

        QuaternionSequence const& operator= (QuaternionSequence const&);
        QuaternionSequence const& operator-= (QuaternionSequence const&);
        QuaternionSequence const& operator+= (QuaternionSequence const&);
        QuaternionSequence const& operator*= (QuaternionSequence const&);
        Quaternion const operator[] (int k) const;
        Quaternion& operator[] (int k);
        friend bool operator== (QuaternionSequence const&,
            QuaternionSequence const&);
        friend std::ostream& operator<< (std::ostream&,
            QuaternionSequence const&);
    private:
        map_type data;
        void removeNullQuaternions();
        // Safe bool
        typedef void (Quaternion::*bool_type)() const;
        void this_type_does_not_support_comparisons() const {}
};

QuaternionSequence const operator- (QuaternionSequence const&,
        QuaternionSequence const&);
QuaternionSequence const operator+ (QuaternionSequence const&,
        QuaternionSequence const&);
QuaternionSequence const operator* (QuaternionSequence const&,
        QuaternionSequence const&);
bool operator== (QuaternionSequence const&,
        QuaternionSequence const&);
bool operator!= (QuaternionSequence const&,
        QuaternionSequence const&);

#endif

