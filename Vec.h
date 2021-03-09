#ifndef Vec_h
#define Vec_h

#include <ostream>
#include <math.h>
template<typename T>
class _vec3{
public:
    _vec3<T>(): d{0,0,0} {} //!< null constructor
    _vec3<T>(T a, T b, T c) : d{a,b,c} {} //!< overloaded constructor
    //! Implement vector notation brackets
    T& operator[] (int i) {return d[i];}
    T operator[] (int i) const {return d[i];}
    //! Implement addition of two vectors
    /**
     *@param a first vector
     *@param b second vector
     *@return Vector \f$\vec{a} + \vec{b}\f$
     */
    friend _vec3<T> operator+(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0]+b[0],a[1]+b[1],a[2]+b[2]);
    }
    //! Implement subtraction of two vectors
    /**
     *@param a first vector
     *@param b second vector
     *@return Vector \f$\vec{a} - \vec{b}\f$
     */
    friend _vec3<T> operator-(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
    }
    //! Returns dot product of two vectors
    /**
     *@param a first vector
     *@param b second vector
     *@return dot product \f$\vec{a}\cdot\vec{b}=a_0b_0+a_1b_1+a_2b_2\f$
    */
    friend T dot(const _vec3<T>&a, const _vec3<T>&b) {
        return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    }
    //! Returns vector magnitude
    /**
     *@return Vector magnitude \f$\left|\vec{a}\right| = \sqrt{\vec{a}\cdot\vec{a}}\f$
     */
    friend double mag(const _vec3<T>&a) {return sqrt(dot(a,a));}
    //! Outputs vector to console
    //! @param a vector to be printed
    friend std::ostream& operator<<(std::ostream &out, const _vec3<T>&a) {
        out<<a[0]<<" "<<a[1]<<" "<<a[2]; return out;
    }
protected:
    T d[3];
};
using double3 = _vec3<double>; // assign a nickname

#endif /* Vec_h */
