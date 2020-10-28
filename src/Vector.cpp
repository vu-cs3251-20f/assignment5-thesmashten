// File name: Vector.h
// Author: Nishant Jain
// Userid: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 5
// Honor statement: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment
// Description: Vector Class Definition
// Last Changed: 10/26/20

#ifndef VECTOR_CPP
#define VECTOR_CPP
#include <cstddef>
#include <string>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
#include <array>
#include <iostream>
#include <cmath>
#include "../include/Vector.h"

/*
template<class InputIt1, class InputIt2, class T> class sum_product {
public:
    sum_product() : product(0) {}
    T& operator()(InputIt1 first1, InputIt1 last1,
                    InputIt2 first2, T init){
        {
            while (first1 != last1) {
                init *= (*first1 * *first2); // std::move since C++20
                ++first1;
                ++first2;
            }
            return init;
        }
    }

private:
    double product;
};
 */




template <uint32_t DIM>
Vector<DIM> :: Vector() noexcept : mSize(DIM){
    std::fill(begin(), end(), 0);
}

template <uint32_t DIM>
Vector<DIM> :: Vector(const Vector<DIM>& src) noexcept {
    mSize = src.mSize;
    std::copy(src.begin(), src.end(), arr);
}

template <uint32_t DIM>
Vector<DIM>& Vector<DIM> :: operator=(const Vector<DIM>& rhs) {
    mSize = rhs.mSize;
    std::copy(rhs.begin(), rhs.end(), arr);
    return *this;
}


template <uint32_t DIM>
std::string Vector<DIM> :: toString() const noexcept{
    std::string ret = "";
    if (mSize != 0) {
        ret += "[";
        std::ostringstream oss;
        std::copy(begin(), end() - 1, std::ostream_iterator<double>(oss, ","));
        oss << end(); //add last element separately to avoid trailing comma
        ret += oss.str();
        ret += "]";
    }
    return ret;
}

/**
 * Calculates the dot product of a particular vector passed in as a param
 * @param src Vector object
 * @return double representing dot product of the vector
 */
//FOR TRANSFORM:
//param1 = start, param2 = end, param3 = beginning of second to transform, param4 = destination range
//param5 = function call
template <uint32_t DIM>
double Vector<DIM> :: dot(const Vector<DIM> src) const noexcept{
    double ret = 0;
    Vector<DIM> products;
    std::transform(begin(), end(), src.begin(), products.begin(),
        [&ret](auto lhs, auto rhs) {
            double product = lhs * rhs;
            ret += product;
            return product;
    });
    return ret;
}

/**
 * Calculates the cross product of a particular Vector passed in as a param.
 * This operation provides strong exception safety.
 * @param rhs Vector object
 * @return another vector of dimension DIM containing the cross product of this and src
 */
template<> Vector<3> Vector<3> :: cross(const Vector<3> rhs) const{
    Vector<3> crossProd;
    crossProd[0] = (arr[1] * rhs[2]) - (arr[2] * rhs[1]);
    crossProd[1] = (arr[2] * rhs[0]) - (arr[0] * rhs[2]);
    crossProd[2] = (arr[0] * rhs[1]) - (arr[1] * rhs[0]);
    return crossProd;
}

template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: cross(const Vector<DIM>) const{
    throw std :: domain_error("Invalid dimensions for this vector.");
}


/**
 * Calculates the norm, or magnitude of the lhs object
 * Calls normSq() to get the square then returns the root of this
 * This operation provides strong exception safety.
 * @param  none
 * @return double representing the magnitude of the vector
 */
template <uint32_t DIM>
double Vector<DIM> :: norm() const noexcept{
    return sqrt(normSq());
}

/**
* Helps calculate the norm of a vector by calculating the squared magnitude
* This operation provides strong exception safety.
* @param  none
* @return double representing the magnitude of the vector
*/
template <uint32_t DIM>
double Vector<DIM> :: normSq() const noexcept{
    Vector<DIM> squared;
    double sqNum = 0;
    std::transform(begin(), end(), squared.begin(),
                   [&sqNum](double d) -> double { return sqNum *= d;});
    return squared[mSize - 1];
}

/**
* Returns a normalized version of the Vector object
* This operation provides strong exception safety.
* @param  none
* @return Vector object that is normalized
*/
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: normalize() const noexcept{
    return scale(1/norm());
}

/**
 * Returns an iterator to the end of the arr.
 * This operation is a no-throw.
 * @param: none
 * @return iterator
 */
template <uint32_t DIM>
double* Vector<DIM> :: end() noexcept{
    double* ptr = const_cast<double*>(arr + mSize);
    return ptr;
}

/**
 * Returns a const iterator to the end of the arr.
 * This operation is a no-throw.
 * @param: none
 * @return const double*
 */
template <uint32_t DIM>
double* Vector<DIM> :: end() const noexcept{
    double* ptr = const_cast<double*>(arr + mSize);
    return ptr;
}

/**
 * Returns an iterator to the beginning of the Vector.
 * This operation is a no-throw.
 * @param: none
 * @return iterator to the beginning of the Vector
 */
template <uint32_t DIM>
double* Vector<DIM> :: begin() noexcept{
    double* ptr = const_cast<double*>(arr);
    return ptr;
}

/**
 * Returns a const iterator to the beginning of the Vector.
 * This operation is a no-throw.
 * @param: none
 * @return const_iterator to beginning of the Vector
 */
template <uint32_t DIM>
double* Vector<DIM> :: begin() const noexcept{
    double* ptr = const_cast<double*>(arr);
    return ptr;
}

/**
  * Adds two vector objects together mathematically and returns the resulting object
  * This operation provides strong exception safety.
  * @param  rhs Vector to be added
  * @return Vector obj representing sum of last two Vectors
  */
template <uint32_t DIM>
Vector<DIM> Vector<DIM>::add(const Vector<DIM> rhs) const noexcept{
    return rhs;
}

/**
  * Inverts elements in a Vector obj. Basically the same as scale() but for -1
  * This operation provides strong exception safety.
  * @param  none
  * @return Vector obj representing inversion of object called on
  */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: invert() const noexcept{
    return scale(-1);
}

/**
  * Scales elements on a particular vector by the param val
  * This operation provides strong exception safety.
  * @param  val
  * @return Vector obj representing scaling of Vector called on
  */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: scale(const double& val) const noexcept {
    Vector<DIM> result;
    std::transform(begin(), end(), result.begin(),
                   [&val](double d) -> double { return d * val;});
    return result;
}

/**
 * Returns the value at param index in the Vector
 * @param index
 * @return the value at index in the Vector
 */
template <uint32_t DIM>
double& Vector<DIM> :: operator[](const uint32_t index){
    return arr[index];
}

/**
 * Returns a const reference to the value at param index in the Vector
 * @param index
 * @return the value at index in the Vector
 */
template <uint32_t DIM>
const double& Vector<DIM> :: operator[](const uint32_t index) const{
    return arr[index];
}

/**
 * Returns true if and only if this Vector is logically equivalent to
 * rhs, i.e. the size and contents are equal.
 * This operation provides strong exception safety.
 * @param rhs the Vector being compared to
 * @return true iff logically equivalent
 */
template <uint32_t DIM>
bool Vector<DIM> :: operator==(const Vector<DIM>& rhs) const noexcept{
    return toString() == rhs.toString();
}

/**
 * Returns false if this Vector is equal to rhs and true otherwise.
 * This operation provides strong exception safety.
 * @param rhs the Vector being compared to
 * @return true iff not logically equivalent
 */
template <uint32_t DIM>
bool Vector<DIM> :: operator!=(const Vector<DIM>& rhs) const noexcept{
    return !(this->operator==(rhs));
}

/**
 * Operator overloaded for scaling a Vector by another number (allows vec1 = vec1 * 2)
 * @param scale
 * @return scaled vector by factor of num
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator*(const double factor) noexcept{
    Vector result = this->scale(factor);
    return result;
}

/**
 * Operator overloaded for scaling a Vector by another number (allows vec1 *= 2)
 * @param scale
 * @return scaled vector by factor of num
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator*=(const double factor) noexcept{
    Vector result = scale(factor);
    return result;
}

/**
 * Operator overloaded for multiplying a Vector object by another via dot product
 * @param rhs Vector obj
 * @return double representing the dot product
 */
template <uint32_t DIM>
double Vector<DIM> :: operator*(const Vector<DIM>& rhs) noexcept{
    return this->dot(rhs);
}

/**
 * Operator overloaded for subtracting two Vector objects and returning the resulting Vector
 * @param rhs Vector obj
 * @return Vector representing subtraction
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator-(const Vector<DIM>& rhs) const noexcept{
    Vector storage;
    std::transform(begin(), end(), rhs.begin(), storage.begin(), std::minus());
    return storage;
}

/**
 * Returns a new vector representing this being inverted (multiplied by -1)
 * @param: none
 * @return new Vector that is inversion of last
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator-() const noexcept{
    Vector<DIM> result = invert();
    return result;
}

/**
 * Returns a new vector in which param rhs is subtracted from itself
 * @param rhs Vector obj
 * @return subtracted Vector
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator-=(const Vector<DIM>& rhs) noexcept{
    rhs.invert();
    Vector result = add(rhs);
    return result;
}

/**
  * Adds two vector objects together mathematically and returns the resulting object
  * This operation provides strong exception safety.
  * @param  rhs Vector to be added
  * @return Vector obj representing sum of last two Vectors
  */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator+(const Vector<DIM>& rhs) const{
    Vector tmp(rhs);
    Vector tmp2(*this);
    Vector result = tmp2.add(tmp);
    return result;
}

/**
  * Adds two vector objects together mathematically and returns the resulting object
  * This operation provides strong exception safety.
  * @param  rhs Vector to be added
  * @return Vector obj representing sum of last two Vectors
  */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator+=(const Vector<DIM>& rhs) noexcept{
    return this->add(rhs);
}

/**
 * Returns a vector in which all elements are divided by param val
 * @param scale
 * @return Vector obj that has been scaled accordingly
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator/(const double factor) noexcept{
    Vector result = scale(factor);
    return result;
}

/**
 * Returns a vector in which all elements are divided by param val
 * @param scale
 * @return Vector obj that has been scaled accordingly
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator/= (const double factor){
    Vector result = scale(1/factor);
    return result;
}

/**
 * General cross product template function throws error for invalid argument
 * for non 3D vectors and uses a specializes function for 3D vectors to find
 * the proper cross product
 * @param rhs
 * @returns cross product for 3D vectors
 * @throws std::invalid argument for non 3D vectors
 */
template <uint32_t DIM>
Vector<DIM> Vector<DIM> :: operator^(const Vector<DIM>& rhs) const{
    if (DIM == 3 || DIM == 7){
        return cross(rhs);
    }
    else {
        throw std::invalid_argument("Invalid Argument.");
    }
}







#endif
