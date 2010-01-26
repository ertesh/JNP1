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
        
        Quaternion& operator= (const Quaternion&);
        Quaternion& operator- ();
        Quaternion& operator+= (const Quaternion&);
    //    Quaternion& 
};

// Returns quaternion equal to real part of given quaternion
Quaternion re(const Quaternion&);

// Returns quaternion equal to imaginary part of given quaternion
Quaternion im(const Quaternion&);

// Returns conjugation of given quaternion
Quaternion conj(const Quaternion&);

// Returns norm of iven quaternion
double norm(const Quaternion&);


#endif
//       q2 = q1; - przypisuje kwaternion q1 na zmienną q2;
//      -q; - zwraca kwaternion przeciwny do kwaternionu q;
//     q1 + q2; - zwraca kwaternion będący sumą kwaternionów q1 i q2;
//    q1 += q2; - dodaje do kwaternionu q1 kwaternion q2;
//   q1 - q2; - zwraca kwaternion będący różnicą kwaternionów q1 i q2;
//  q1 -= q2; - odejmuje od kwaternionu q1 kwaternion q2;
// q1 * q2; - zwraca kwaternion będący iloczynem kwaternionów q1 i q2;
//q1 *= q2; - mnoży kwaternion q1 przez kwaternion q2;
//q1 == q2; - zwraca true wtw. gdy kwaterniony q1 i q2 są równe;
//q1 != q2; - zwraca true wtw. gdy kwaterniony q1 i q2 są różne;

