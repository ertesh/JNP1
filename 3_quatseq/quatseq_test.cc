#include "quatseq.h"

#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>


#if TEST_NUM == 129 || TEST_NUM == 130 || TEST_NUM == 137
void test_fun_1(Quaternion q)
{
    q+q;
}

void test_fun_2(Quaternion const q)
{
    q+q;
}

void test_fun_3(Quaternion const & q)
{
    q+q;
}
#endif


#if TEST_NUM == 402
void test_fun_1(void * ptr)
{
}
#endif


int main()
{
#if TEST_NUM == 0
    {
        ::std::clog << "Test." << ::std::endl;
    }
#endif
#if TEST_NUM == 101
    {
        ::std::clog << "Quaternion - konstruktor domyslny i destruktor." << ::std::endl;
        Quaternion q;
    }
#endif
#if TEST_NUM == 102
    {
        ::std::clog << "Quaternion - odczyt skladowych." << ::std::endl;
        Quaternion q;
        q.r();
        q.i();
        q.j();
        q.k();
    }
#endif
#if TEST_NUM == 103
    {
        ::std::clog << "Quaternion - skladowe obiektu domyslnego rowne zero." << ::std::endl;
        Quaternion q;
        assert(q.r() == 0.0);
        assert(q.i() == 0.0);
        assert(q.j() == 0.0);
        assert(q.k() == 0.0);
    }
#endif
#if TEST_NUM == 104
    {
        ::std::clog << "Quaternion - konstruktor jednoargumentowy." << ::std::endl;
        Quaternion q(1.0);
        assert(q.r() == 1.0);
        assert(q.i() == 0.0);
        assert(q.j() == 0.0);
        assert(q.k() == 0.0);
    }
#endif
#if TEST_NUM == 105
    {
        ::std::clog << "Quaternion - konstruktor dwuargumentowy." << ::std::endl;
        Quaternion q(1.0, 2.0);
        assert(q.r() == 1.0);
        assert(q.i() == 2.0);
        assert(q.j() == 0.0);
        assert(q.k() == 0.0);
    }
#endif
#if TEST_NUM == 106
    {
        ::std::clog << "Quaternion - konstruktor czteroargumentowy." << ::std::endl;
        Quaternion q(1.0, 2.0, 3.0, 4.0);
        assert(q.r() == 1.0);
        assert(q.i() == 2.0);
        assert(q.j() == 3.0);
        assert(q.k() == 4.0);
    }
#endif
#if TEST_NUM == 107
    {
        ::std::clog << "Quaternion - konstruktor kopiujacy." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(q1);
        assert(q2.r() == 1.0);
        assert(q2.i() == 2.0);
        assert(q2.j() == 3.0);
        assert(q2.k() == 4.0);
    }
#endif
#if TEST_NUM == 108
    {
        ::std::clog << "Quaternion - operator przypisania." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2;
        assert(q2.r() == 0.0);
        assert(q2.i() == 0.0);
        assert(q2.j() == 0.0);
        assert(q2.k() == 0.0);
        q2 = q1;
        assert(q2.r() == 1.0);
        assert(q2.i() == 2.0);
        assert(q2.j() == 3.0);
        assert(q2.k() == 4.0);
    }
#endif
#if TEST_NUM == 109
    {
        ::std::clog << "Quaternion - operator += ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(5.0, 6.0, 7.0, 8.0);
        q2 += q1;
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 6.0);
        assert(q2.i() == 8.0);
        assert(q2.j() == 10.0);
        assert(q2.k() == 12.0);
    }
#endif
#if TEST_NUM == 110
    {
        ::std::clog << "Quaternion - operator -= ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(8.0, 7.0, 6.0, 5.0);
        q2 -= q1;
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 7.0);
        assert(q2.i() == 5.0);
        assert(q2.j() == 3.0);
        assert(q2.k() == 1.0);
    }
#endif
#if TEST_NUM == 111
    {
        ::std::clog << "Quaternion - operator *= ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(8.0, 7.0, 6.0, 5.0);
        q2 *= q1;
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == -44.0);
        assert(q2.i() == 32.0);
        assert(q2.j() == 12.0);
        assert(q2.k() == 46.0);
    }
#endif
#if TEST_NUM == 112
    {
        ::std::clog << "Quaternion - operator - (element przeciwny)." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(-q1);
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == -1.0);
        assert(q2.i() == -2.0);
        assert(q2.j() == -3.0);
        assert(q2.k() == -4.0);
    }
#endif
#if TEST_NUM == 113
    {
        ::std::clog << "Quaternion - operator + ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(5.0, 6.0, 7.0, 8.0);
        Quaternion q3(q2 + q1);
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 5.0);
        assert(q2.i() == 6.0);
        assert(q2.j() == 7.0);
        assert(q2.k() == 8.0);
        assert(q3.r() == 6.0);
        assert(q3.i() == 8.0);
        assert(q3.j() == 10.0);
        assert(q3.k() == 12.0);
    }
#endif
#if TEST_NUM == 114
    {
        ::std::clog << "Quaternion - operator - ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(8.0, 7.0, 6.0, 5.0);
        Quaternion q3(q2 - q1);
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 8.0);
        assert(q2.i() == 7.0);
        assert(q2.j() == 6.0);
        assert(q2.k() == 5.0);
        assert(q3.r() == 7.0);
        assert(q3.i() == 5.0);
        assert(q3.j() == 3.0);
        assert(q3.k() == 1.0);
    }
#endif
#if TEST_NUM == 115
    {
        ::std::clog << "Quaternion - operator * ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(8.0, 7.0, 6.0, 5.0);
        Quaternion q3(q2 * q1);
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 8.0);
        assert(q2.i() == 7.0);
        assert(q2.j() == 6.0);
        assert(q2.k() == 5.0);
        assert(q3.r() == -44.0);
        assert(q3.i() == 32.0);
        assert(q3.j() == 12.0);
        assert(q3.k() == 46.0);
    }
#endif
#if TEST_NUM == 116
    {
        ::std::clog << "Quaternion - operator == ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2;
        q2 = Quaternion(1.0, 2.0, 3.0, 4.0);
        assert(q1 == q2);
        q2 = Quaternion(999.0, 2.0, 3.0, 4.0);
        assert(!(q1 == q2));
        q2 = Quaternion(1.0, 999.0, 3.0, 4.0);
        assert(!(q1 == q2));
        q2 = Quaternion(1.0, 2.0, 999.0, 4.0);
        assert(!(q1 == q2));
        q2 = Quaternion(1.0, 2.0, 3.0, 999.0);
        assert(!(q1 == q2));
    }
#endif
#if TEST_NUM == 117
    {
        ::std::clog << "Quaternion - operator != ." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2;
        q2 = Quaternion(1.0, 2.0, 3.0, 4.0);
        assert(!(q1 != q2));
        q2 = Quaternion(999.0, 2.0, 3.0, 4.0);
        assert(q1 != q2);
        q2 = Quaternion(1.0, 999.0, 3.0, 4.0);
        assert(q1 != q2);
        q2 = Quaternion(1.0, 2.0, 999.0, 4.0);
        assert(q1 != q2);
        q2 = Quaternion(1.0, 2.0, 3.0, 999.0);
        assert(q1 != q2);
    }
#endif
#if TEST_NUM == 118
    {
        ::std::clog << "Quaternion - operator << ." << ::std::endl;
        ::std::ostringstream oss;
        Quaternion q(1.0, 2.0, 3.0, 4.0);
        oss << q;
        ::std::string const & s = oss.str();
        assert(s.find('1') != ::std::string::npos);
        assert(s.find('2') != ::std::string::npos);
        assert(s.find('3') != ::std::string::npos);
        assert(s.find('4') != ::std::string::npos);
    }
#endif
#if TEST_NUM == 119
    {
        ::std::clog << "Quaternion - funkcja re." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(re(q1));
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 1.0);
        assert(q2.i() == 0.0);
        assert(q2.j() == 0.0);
        assert(q2.k() == 0.0);
    }
#endif
#if TEST_NUM == 120
    {
        ::std::clog << "Quaternion - funkcja im." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(im(q1));
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 0.0);
        assert(q2.i() == 2.0);
        assert(q2.j() == 3.0);
        assert(q2.k() == 4.0);
    }
#endif
#if TEST_NUM == 121
    {
        ::std::clog << "Quaternion - funkcja conj." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(conj(q1));
        assert(q1.r() == 1.0);
        assert(q1.i() == 2.0);
        assert(q1.j() == 3.0);
        assert(q1.k() == 4.0);
        assert(q2.r() == 1.0);
        assert(q2.i() == -2.0);
        assert(q2.j() == -3.0);
        assert(q2.k() == -4.0);
    }
#endif
#if TEST_NUM == 122
    {
        ::std::clog << "Quaternion - funkcja norm." << ::std::endl;
        Quaternion q(3.0, 4.0, 12.0, 84.0);
        double n(norm(q));
        assert(n == 85.0);
    }
#endif
#if TEST_NUM == 123
    {
        ::std::clog << "Quaternion - funkcja I." << ::std::endl;
        assert(I().r() == 0.0);
        assert(I().i() == 1.0);
        assert(I().j() == 0.0);
        assert(I().k() == 0.0);
    }
#endif
#if TEST_NUM == 124
    {
        ::std::clog << "Quaternion - funkcja J." << ::std::endl;
        assert(J().r() == 0.0);
        assert(J().i() == 0.0);
        assert(J().j() == 1.0);
        assert(J().k() == 0.0);
    }
#endif
#if TEST_NUM == 125
    {
        ::std::clog << "Quaternion - funkcja K." << ::std::endl;
        assert(K().r() == 0.0);
        assert(K().i() == 0.0);
        assert(K().j() == 0.0);
        assert(K().k() == 1.0);
    }
#endif
#if TEST_NUM == 126
    {
        ::std::clog << "Quaternion - aksjomaty addytywne." << ::std::endl;
        Quaternion zero;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(5.0, 6.0, 7.0, 8.0);
        Quaternion q3(9.0, 10.0, 11.0, 12.0);
        assert(q1 + q2 == q2 + q1);
        assert(q2 + q3 == q3 + q2);
        assert(q3 + q1 == q1 + q3);
        assert((q1 + (q2 + q3)) == ((q1 + q2) + q3));
        assert(q1 + (-q1) == zero);
        assert(q2 + (-q2) == zero);
        assert(q3 + (-q3) == zero);
        assert(q1 - q1 == zero);
        assert(q2 - q2 == zero);
        assert(q3 - q3 == zero);
        assert(q1 + zero == q1);
        assert(zero + q1 == q1);
        assert(q2 + zero == q2);
        assert(zero + q2 == q2);
        assert(q3 + zero == q3);
        assert(zero + q3 == q3);
        assert(q1 - zero == q1);
        assert(zero - q1 == -q1);
        assert(q2 - zero == q2);
        assert(zero - q2 == -q2);
        assert(q3 - zero == q3);
        assert(zero - q3 == -q3);
        assert(q1 + (-q2) == q1 - q2);
        assert(q2 + (-q3) == q2 - q3);
        assert(q3 + (-q1) == q3 - q1);
        assert(q1 - q2 == -(q2 - q1));
        assert(q2 - q3 == -(q3 - q2));
        assert(q3 - q1 == -(q1 - q3));
    }
#endif
#if TEST_NUM == 127
    {
        ::std::clog << "Quaternion - aksjomaty multiplikatywne." << ::std::endl;
        Quaternion zero;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(5.0, 6.0, 7.0, 8.0);
        Quaternion q3(9.0, 10.0, 11.0, 12.0);
        assert(I() * J() == K());
        assert(J() * K() == I());
        assert(K() * I() == J());
        assert(J() * I() == -K());
        assert(K() * J() == -I());
        assert(I() * K() == -J());
        assert((q1 * (q2 * q3)) == ((q1 * q2) * q3));
        assert(q1 * q2 != q2 * q1);
        assert(q2 * q3 != q3 * q2);
        assert(q3 * q1 != q1 * q3);
        assert(q1 * zero == zero);
        assert(zero * q1 == zero);
        assert(q2 * zero == zero);
        assert(zero * q2 == zero);
        assert(q3 * zero == zero);
        assert(zero * q3 == zero);
    }
#endif
#if TEST_NUM == 128
    {
        ::std::clog << "Quaternion - aksjomaty re, im, conj, norm." << ::std::endl;
        Quaternion zero;
        Quaternion q1(3.0, 4.0, 12.0, 84.0);
        Quaternion q2(0.0, 5.0, 12.0, 84.0);
        Quaternion q3(0.0, 0.0, 13.0, 84.0);
        assert(q1 == re(q1) + im(q1));
        assert(q2 == re(q2) + im(q2));
        assert(q3 == re(q3) + im(q3));
        assert(conj(conj(q1)) == q1);
        assert(conj(conj(q2)) == q2);
        assert(conj(conj(q3)) == q3);
        assert(im(q1*conj(q1)) == zero);
        assert(im(q2*conj(q2)) == zero);
        assert(im(q3*conj(q3)) == zero);
        assert(im(q1+conj(q1)) == zero);
        assert(im(q2+conj(q2)) == zero);
        assert(im(q3+conj(q3)) == zero);
        assert(q1 * conj(q1) == Quaternion(norm(q1)*norm(q1)));
        assert(q2 * conj(q2) == Quaternion(norm(q2)*norm(q2)));
        assert(q3 * conj(q3) == Quaternion(norm(q3)*norm(q3)));
        assert(norm(q1 * q2) == norm(q1) * norm(q2));
        assert(norm(q2 * q3) == norm(q2) * norm(q3));
        assert(norm(q3 * q1) == norm(q3) * norm(q1));
        assert(norm(zero) == 0.);
    }
#endif
#if TEST_NUM == 129
    {
        ::std::clog << "Quaternion - implicit konwersje." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(q1 + 3.0);
        Quaternion q3(q2 - 4);
        Quaternion q4(q3 * 'a');
        Quaternion q5 = 3.0;
        Quaternion q6 = 4;
        Quaternion q7 = 'b';
        Quaternion q8 = 1. + 2.*I() + 3.*J() + 4.*K();
        Quaternion q9 = 4 + 3*I() + 2*J() + K();
        test_fun_1(3.0);
        test_fun_2(3.0);
        test_fun_3(3.0);
        test_fun_1(4);
        test_fun_2(4);
        test_fun_3(4);
        test_fun_1('a');
        test_fun_2('a');
        test_fun_3('a');
    }
#endif
#if TEST_NUM == 130
    {
        ::std::clog << "Quaternion - const correctness." << ::std::endl;
        Quaternion const q1(1.0, 2.0, 3.0, 4.0);
        Quaternion const q2(1.0, 2.0, 3.0, 4.0);
        q1.r();
        q1.i();
        q1.j();
        q1.k();
        -q1;
        q1 + q2;
        q1 - q2;
        q1 * q2;
        q1 + q2;
        (q1 + q2).r();
        (q1 - q2).i();
        (q1 * q2).j();
        (-q1).k();
        Quaternion const & q3 = q1 + q2;
        test_fun_1(q1 + q2 * q3);
        test_fun_2(q1 + q2 + q3);
        test_fun_3(q1 + q2 - q3);
        test_fun_3(re(q1));
        test_fun_3(im(q1));
        test_fun_3(conj(q1));
        ::std::ostringstream oss;
        oss << q3;
        oss << q1 + q2;
    }
#endif
#if TEST_NUM == 131
    {
        ::std::clog << "Quaternion - laczenie operatorow." << ::std::endl;
        Quaternion q1(1.0, 2.0, 3.0, 4.0);
        Quaternion q2(1.0, 2.0, 3.0, 4.0);
        Quaternion q3 = q1 * q2;
        q1 += q2 += q3;
        q1 -= q2 -= q3;
        q1 *= q2 *= q3;
        ::std::ostringstream oss;
        oss << q1 << q2 << (q1 + q2) << q3;
        q1 = q2 = q3;
        q1 += q2 -= q3 *= q1;
        q1 + q2 + q3;
    }
#endif
#if TEST_NUM == 132
    {
        ::std::clog << "Quaternion - konstrukcja z typow calkowitoliczbowych." << ::std::endl;
        Quaternion q1(1, 2, 3, 4);
        Quaternion q2('a', 'b', 'c', 'd');
        Quaternion q3(true, false, true, false);
    }
#endif
#if TEST_NUM == 133
    {
        ::std::clog << "QuaternionSequence - konstruktor domyslny i destruktor." << ::std::endl;
        QuaternionSequence qs;
    }
#endif
#if TEST_NUM == 134
    {
        ::std::clog << "QuaternionSequence - konstrukcja z wektora" << ::std::endl;
        ::std::vector<Quaternion> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        QuaternionSequence qs(v);
    }
#endif
#if TEST_NUM == 135
    {
        ::std::clog << "QuaternionSequence - konstrukcja z mapy" << ::std::endl;
        ::std::map<QuaternionSequence::size_type, Quaternion> m;
        m[2] = 3;
        m[5] = 4;;
        m[9] = 7;
        m[11] = 13;
        QuaternionSequence qs(m);
    }
#endif
#if TEST_NUM == 136
    {
        ::std::clog << "QuaternionSequence - konstrukor kopiujacy." << ::std::endl;
        QuaternionSequence qs1;
        QuaternionSequence qs2(qs1);
    }
#endif
#if TEST_NUM == 137
    {
        ::std::clog << "QuaternionSequence - operator []" << ::std::endl;
        ::std::vector<Quaternion> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        QuaternionSequence const qs1(v);
        assert(qs1[0] == 1);
        assert(qs1[1] == 2);
        assert(qs1[2] == 3);
        assert(qs1[3] == 4);
        assert(qs1[4] == 0.);
        assert(qs1[5] == 0.);
        assert(qs1[6] == 0.);
        assert(qs1[7] == 0.);
        assert(qs1[8] == 0.);
        qs1[3].r();
        re(qs1[3]);
        qs1[10000].i();
        im(qs1[10000]);
        test_fun_1(qs1[3]);
        test_fun_2(qs1[3]);
        test_fun_3(qs1[3]);
        test_fun_1(qs1[10000]);
        test_fun_2(qs1[10000]);
        test_fun_3(qs1[10000]);
        qs1[0] + qs1[1] - qs1[2] * qs1[3];
        QuaternionSequence qs2;
        for(int i = 0; i < 1000; ++i)
            assert(qs2[i] == 0.0);
    }
#endif
#if TEST_NUM == 138
    {
        ::std::clog << "QuaternionSequence - operatory == i != ." << ::std::endl;
        ::std::vector<Quaternion> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(0);
        v1.push_back(4);
        QuaternionSequence const qs1(v1);
        ::std::map<QuaternionSequence::size_type, Quaternion> m2;
        m2[2] = 3;
        m2[5] = 4;;
        m2[9] = 7;
        m2[11] = 13;
        QuaternionSequence qs2(m2);
        ::std::map<QuaternionSequence::size_type, Quaternion> m3;
        m3[0] = 1;
        m3[1] = 2;;
        m3[3] = 4;
        QuaternionSequence qs3(m3);
        assert(!(qs1 == qs2));
        assert(qs1 != qs2);
        assert(qs1 == qs3);
        assert(!(qs1 != qs3));
    }
#endif
#if TEST_NUM == 139
    {
        ::std::clog << "QuaternionSequence - dodawanie i odejmowanie." << ::std::endl;
        ::std::vector<Quaternion> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        QuaternionSequence qs1(v);
        ::std::map<QuaternionSequence::size_type, Quaternion> m;
        m[2] = 3;
        m[3] = 4;;
        m[5] = 7;
        m[7] = 13;
        QuaternionSequence qs2(m);
        assert((qs1 + qs2)[0] == 1.);
        assert((qs1 + qs2)[1] == 2.);
        assert((qs1 + qs2)[2] == 6.);
        assert((qs1 + qs2)[3] == 8.);
        assert((qs1 + qs2)[4] == 0.);
        assert((qs1 + qs2)[5] == 7.);
        assert((qs1 + qs2)[6] == 0.);
        assert((qs1 + qs2)[7] == 13.);
        assert((qs1 + qs2)[8] == 0.);
        assert((qs1 + qs2)[9] == 0.);
        qs1 + qs2 + qs1 + qs2;
        qs1 += (qs2 + qs1);
        qs1 += qs2 += qs1;
        assert(qs1 + qs2 == qs2 + qs1);
        QuaternionSequence zero;
        assert(qs1 - qs1 == zero);
        assert(qs1 + zero == qs1);
        assert(qs2 - zero == qs2);
    }
#endif
#if TEST_NUM == 140
    {
        ::std::clog << "QuaternionSequence - mnozenie." << ::std::endl;
        ::std::vector<Quaternion> v;
        v.push_back(1 + I());
        v.push_back(2 + J());
        v.push_back(3 + K());
        v.push_back(4);
        QuaternionSequence qs1(v);
        ::std::map<QuaternionSequence::size_type, Quaternion> m;
        m[2] = 3 + I();
        m[3] = 4 + J();
        m[5] = 7;
        m[7] = 13;
        QuaternionSequence qs2(m);
        assert((qs1 * qs2)[0] == 0.);
        assert((qs1 * qs2)[1] == 0.);
        assert((qs1 * qs2)[2] != 0.);
        assert((qs1 * qs2)[3] != 0.);
        assert((qs1 * qs2)[4] == 0.);
        assert((qs1 * qs2)[5] == 0.);
        assert((qs1 * qs2)[6] == 0.);
        assert((qs1 * qs2)[7] == 0.);
        assert((qs1 * qs2)[8] == 0.);
        assert((qs1 * qs2)[9] == 0.);
        qs1 * qs2 * qs1 * qs2;
        qs1 * Quaternion(1, 2, 3, 4);
        qs1 *= (qs2 + qs1);
        qs1 *= qs2 *= qs1;
        qs1 *= Quaternion(1, 2, 3, 4);
        assert(qs1 * qs2 != qs2 * qs1);
        QuaternionSequence zero;
        assert(qs1 * zero == zero);
        assert(qs1 * Quaternion() == zero);
    }
#endif
#if TEST_NUM == 141
    {
        ::std::clog << "QuaternionSequence - wypisywanie." << ::std::endl;
        ::std::map<QuaternionSequence::size_type, Quaternion> m;
        m[200] = 3 + I();
        m[300] = 4 + J();
        m[500] = 7;
        m[700] = 13;
        QuaternionSequence qs(m);
        ::std::ostringstream oss;
        oss << qs;
    }
#endif
#if TEST_NUM == 142
    {
        ::std::clog << "QuaternionSequence - usuwanie zer." << ::std::endl;
        ::std::vector<Quaternion> v;
        for(int i = 0; i < 1000000; ++i)
            v.push_back(1);
        QuaternionSequence qs1(v);
        QuaternionSequence qs2(v);
        QuaternionSequence qs3(qs1 - qs2);
        QuaternionSequence const & qs4 = qs1 - qs2;
        QuaternionSequence zero;
        for(int i = 0; i < 1000000; ++i)
            assert(qs3 == zero);
        for(int i = 0; i < 1000000; ++i)
            assert(qs4 == zero);
    }
#endif
#if TEST_NUM == 201
    {
        ::std::clog << "Quaternion - przypisanie na stala." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        q1 = q2;
    }
#endif
#if TEST_NUM == 202
    {
        ::std::clog << "Quaternion - przypisanie na wynik dodawania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 + q2) = q3;
    }
#endif
#if TEST_NUM == 203
    {
        ::std::clog << "Quaternion - przypisanie na wynik odejmowania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 - q2) = q3;
    }
#endif
#if TEST_NUM == 204
    {
        ::std::clog << "Quaternion - przypisanie na wynik mnozenia." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 * q2) = q3;
    }
#endif
#if TEST_NUM == 205
    {
        ::std::clog << "Quaternion - += na wynik dodawania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 + q2) += q3;
    }
#endif
#if TEST_NUM == 206
    {
        ::std::clog << "Quaternion - += na wynik odejmowania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 - q2) += q3;
    }
#endif
#if TEST_NUM == 207
    {
        ::std::clog << "Quaternion - += na wynik mnozenia." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 * q2) += q3;
    }
#endif
#if TEST_NUM == 208
    {
        ::std::clog << "Quaternion - -= na wynik dodawania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 + q2) -= q3;
    }
#endif
#if TEST_NUM == 209
    {
        ::std::clog << "Quaternion - -= na wynik odejmowania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 - q2) -= q3;
    }
#endif
#if TEST_NUM == 210
    {
        ::std::clog << "Quaternion - -= na wynik mnozenia." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 * q2) -= q3;
    }
#endif
#if TEST_NUM == 211
    {
        ::std::clog << "Quaternion - *= na wynik dodawania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 + q2) *= q3;
    }
#endif
#if TEST_NUM == 212
    {
        ::std::clog << "Quaternion - *= na wynik odejmowania." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 - q2) *= q3;
    }
#endif
#if TEST_NUM == 213
    {
        ::std::clog << "Quaternion - *= na wynik mnozenia." << ::std::endl;
        Quaternion const q1;
        Quaternion const q2;
        Quaternion const q3;
        (q1 * q2) *= q3;
    }
#endif
#if TEST_NUM == 214
    {
        ::std::clog << "Quaternion - przypisanie na I." << ::std::endl;
        I() = Quaternion();
        I() += Quaternion();
        I() -= Quaternion();
        I() *= Quaternion();
    }
#endif
#if TEST_NUM == 215
    {
        ::std::clog << "Quaternion - przypisanie na J." << ::std::endl;
        J() = Quaternion();
        J() += Quaternion();
        J() -= Quaternion();
        J() *= Quaternion();
    }
#endif
#if TEST_NUM == 216
    {
        ::std::clog << "Quaternion - przypisanie na K." << ::std::endl;
        K() = Quaternion();
        K() += Quaternion();
        K() -= Quaternion();
        K() *= Quaternion();
    }
#endif
#if TEST_NUM == 217
    {
        ::std::clog << "Quaternion - przypisanie na re." << ::std::endl;
        re(Quaternion()) = Quaternion();
        re(Quaternion()) += Quaternion();
        re(Quaternion()) -= Quaternion();
        re(Quaternion()) *= Quaternion();
    }
#endif
#if TEST_NUM == 218
    {
        ::std::clog << "Quaternion - przypisanie na im." << ::std::endl;
        im(Quaternion()) = Quaternion();
        im(Quaternion()) += Quaternion();
        im(Quaternion()) -= Quaternion();
        im(Quaternion()) *= Quaternion();
    }
#endif
#if TEST_NUM == 219
    {
        ::std::clog << "Quaternion - przypisanie na conj." << ::std::endl;
        conj(Quaternion()) = Quaternion();
        conj(Quaternion()) += Quaternion();
        conj(Quaternion()) -= Quaternion();
        conj(Quaternion()) *= Quaternion();
    }
#endif
#if TEST_NUM == 220
    {
        ::std::clog << "QuaternionSequence - przypisanie na stala." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        qs1 = qs2;
    }
#endif
#if TEST_NUM == 221
    {
        ::std::clog << "QuaternionSequence - przypisanie na wynik dodawania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 + qs2) = qs3;
    }
#endif
#if TEST_NUM == 222
    {
        ::std::clog << "QuaternionSequence - przypisanie na wynik odejmowania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 - qs2) = qs3;
    }
#endif
#if TEST_NUM == 223
    {
        ::std::clog << "QuaternionSequence - przypisanie na wynik mnozenia." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 * qs2) = qs3;
    }
#endif
#if TEST_NUM == 224
    {
        ::std::clog << "QuaternionSequence - += na wynik dodawania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 + qs2) += qs3;
    }
#endif
#if TEST_NUM == 225
    {
        ::std::clog << "QuaternionSequence - += na wynik odejmowania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 - qs2) += qs3;
    }
#endif
#if TEST_NUM == 226
    {
        ::std::clog << "QuaternionSequence - += na wynik mnozenia." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 * qs2) += qs3;
    }
#endif
#if TEST_NUM == 227
    {
        ::std::clog << "QuaternionSequence - -= na wynik dodawania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 + qs2) -= qs3;
    }
#endif
#if TEST_NUM == 228
    {
        ::std::clog << "QuaternionSequence - -= na wynik odejmowania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 - qs2) -= qs3;
    }
#endif
#if TEST_NUM == 229
    {
        ::std::clog << "QuaternionSequence - -= na wynik mnozenia." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 * qs2) -= qs3;
    }
#endif
#if TEST_NUM == 230
    {
        ::std::clog << "QuaternionSequence - *= na wynik dodawania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 + qs2) *= qs3;
    }
#endif
#if TEST_NUM == 231
    {
        ::std::clog << "QuaternionSequence - *= na wynik odejmowania." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 - qs2) *= qs3;
    }
#endif
#if TEST_NUM == 232
    {
        ::std::clog << "QuaternionSequence - *= na wynik mnozenia." << ::std::endl;
        QuaternionSequence const qs1;
        QuaternionSequence const qs2;
        QuaternionSequence const qs3;
        (qs1 * qs2) *= qs3;
    }
#endif
#if TEST_NUM == 233
    {
        ::std::clog << "QuaternionSequence - konstruktory z wektora i mapy explicit" << ::std::endl;
        QuaternionSequence qs;
        ::std::vector<Quaternion> v;
        ::std::map<QuaternionSequence::size_type, Quaternion> m;
        qs + m;
        qs + v;
    }
#endif
#if TEST_NUM == 301
    {
        ::std::clog << "Bonus - dzielenie kwaternionow." << ::std::endl;
        assert(K() / J() == I());
        assert(I() / K() == J());
        assert(J() / I() == K());
        Quaternion q1(3, 4, 12, 84);
        Quaternion q2(1, 2, 4, 8);
        Quaternion q3(q1 * q2);
        assert(q1 / q1 == 1);
        assert(q3 / q2 == q3 * (1/q2));
        q3 /= q2;
        QuaternionSequence qs;
        qs / q2;
        qs /= q2;
    }
#endif
#if TEST_NUM == 302
    {
        ::std::clog << "Bonus - kwaterniony i ciagi kwaternionow w wyrazeniach logicznych." << ::std::endl;
        {
            Quaternion q1;
            if(q1)
                assert(false);
            Quaternion q2(1);
            if(q2)
                ;
            else
                assert(false);
            assert(!q1);
            assert(q2);
            assert(q1 || q2);
            assert(q2 && q2);
            bool b = q1;
            if(b);
        }
        {
            QuaternionSequence qs1;
            if(qs1)
                assert(false);
            ::std::vector<Quaternion> v(1, Quaternion(1));
            QuaternionSequence qs2(v);
            if(qs2)
                ;
            else
                assert(false);
            assert(!qs1);
            assert(qs2);
            assert(qs1 || qs2);
            assert(qs2 && qs2);
            bool b = qs1;
            if(b);
        }
    }
#endif
#if TEST_NUM == 303
    {
        ::std::clog << "Bonus - przypisanie na wyraz ciagu kwaternionow." << ::std::endl;
        QuaternionSequence qs;
        qs[0] = Quaternion(1);
        qs[1] += Quaternion(2);
        qs[2] -= Quaternion(3);
        qs[0] *= Quaternion(4);
        qs[0].r();
        re(qs[0]);
        qs[0] + Quaternion(1);
        qs[0] + 1;
        qs[0] - Quaternion(1);
        qs[0] - 1;
        qs[0] * Quaternion(1);
        qs[0] * 1;
        Quaternion(1) + qs[0];
        1 + qs[0];
        Quaternion(1) - qs[0];
        1 - qs[0];
        Quaternion(1) * qs[0];
        1 * qs[0];
        ::std::ostringstream oss;
        oss << qs[0];
        Quaternion q1 = qs[0];
        Quaternion const & q2 = qs[1];
        q1 += q2;
    }
#endif
#if TEST_NUM == 304
    {
        ::std::clog << "Bonus - obliczanie wartosci szeregu w punkcie." << ::std::endl;
        {
            ::std::map<QuaternionSequence::size_type, Quaternion> m;
            m[0] = 1;
            m[4] = 1;
            m[8] = 1;
            m[12] = 1;
            QuaternionSequence qs(m);
            assert(qs(I()) == 4);
            assert(qs(J()) == 4);
            assert(qs(K()) == 4);
        }
        {
            ::std::vector<Quaternion> v;
            v.push_back(1);
            v.push_back(0);
            v.push_back(0);
            v.push_back(1);
            QuaternionSequence qs(v);
            assert(qs(2) == 9);
        }
        {
            ::std::vector<Quaternion> v;
            v.push_back(1);
            v.push_back(1);
            v.push_back(1);
            v.push_back(1);
            QuaternionSequence qs(v);
            assert(qs(2) == 15);
        }
        {
            for(int i = 0; i <= 65536; ++i)
            {
                int j = i;
                ::std::vector<Quaternion> v;
                while(j)
                {
                    v.push_back(j % 2);
                    j /= 2;
                }
                QuaternionSequence qs(v);
                assert(qs(2) == i);
            }
        }
        {
            for(int i = 0; i <= 625*625; ++i)
            {
                int j = i;
                ::std::vector<Quaternion> v;
                while(j)
                {
                    v.push_back(j % 5);
                    j /= 5;
                }
                QuaternionSequence qs(v);
                assert(qs(5) == i);
            }
        }
        {
            ::std::vector<Quaternion> v;
            for(int i = 0; i < 1000000; ++i)
                v.push_back(0.0);
            QuaternionSequence qs(v);
            for(int i = 0; i < 1000000; ++i)
                assert(qs(i) == 0.);
        }
    }
#endif
#if TEST_NUM == 401
    {
        ::std::clog << "Bonus - safe bool czesc 1." << ::std::endl;
        Quaternion q1;
        Quaternion q2;
        bool b = q1 < q2;
        if(b);
    }
#endif
#if TEST_NUM == 402
    {
        ::std::clog << "Bonus - safe bool czesc 2." << ::std::endl;
        Quaternion q;
        test_fun_1(q);
    }
#endif
#if TEST_NUM == 403
    {
        ::std::clog << "Bonus - przypisanie." << ::std::endl;
        QuaternionSequence qs;
        Quaternion & q = qs[0];
        q+q;
    }
#endif
    ::std::clog << "OK." << ::std::endl;
    return 0;
}
