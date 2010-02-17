#ifndef _QUATSEQ_H_
#define _QUATSEQ_H_

class Quaternion
{
    private:
        double a, b, c, d;
    public:
        // Constructor. Creates quaternion (a, b, c, d)
        Quaternion(double a = 0, double b = 0, double c = 0, double d = 0);
        // Copy constructor
        Quaternion(const Quaternion&);
        // Returns first coordinate of quaternion
        double r() const;
        // Returns second coordinate of quaternion
        double i() const;
        // Returns third coordinate of quaternion
        double j() const;
        // Returns forth coordinate of quaternion
        double k() const;
        
        const Quaternion& operator= (const Quaternion&);
        Quaternion& operator- ();
        Quaternion& operator+= (const Quaternion&);
        Quaternion& operator-= (const Quaternion&);
        Quaternion& operator*= (const Quaternion&);
};

Quaternion operator+ (const Quaternion&, const Quaternion&);
Quaternion operator- (const Quaternion&, const Quaternion&);
Quaternion operator* (const Quaternion&, const Quaternion&);

bool operator== (const Quaternion&, const Quaternion&);
bool operator!= (const Quaternion&, const Quaternion&);

// Returns quaternion equal to real part of given quaternion
Quaternion re(const Quaternion&);

// Returns quaternion equal to imaginary part of given quaternion
Quaternion im(const Quaternion&);

// Returns conjugation of given quaternion
Quaternion conj(const Quaternion&);

// Returns norm of iven quaternion
double norm(const Quaternion&);


#endif

