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

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <iterator>
#include <string>

template <uint32_t DIM> class Iterator;
template <uint32_t DIM> class ConstIterator;

template <uint32_t DIM> class Vector {
public:
    /**
     * Initializes a Default Vector of zeroes.
     * This operation provides strong exception safety.
     */
    Vector() noexcept;

    /**
     * Initializes a Default Vector according to arr.
     * This operation provides strong exception safety.
     */
    explicit Vector(const double* arr) noexcept;

    /**
     * Initializes the Vector to be a copy of src.
     * This operation provides strong exception safety.
     * @param src Vector to copy passed by reference
     */
    Vector(const Vector<DIM>& src) noexcept = default;

    /**
     * Makes this Vector a copy of rhs using the same guidelines as the copy
     * constructor. Note that calling this method on yourself (l = l;) is
     * equivalent to a no-op.
     * This operation provides strong exception safety.
     * @param rhs Vector to copy
     * @return *this, used for chaining.
     */
    Vector<DIM>& operator=(const Vector<DIM>& rhs) = default;

    /**
     * Prints a string representation of the console.
     * @return string representation of the vector
     */
    std::string toString() const noexcept;

    /**
     * Calculates the dot product of a particular vector passed in as a param
     * @param src Vector object
     * @return double representing dot product of the vector
     */
    double dot(const Vector<DIM> src) const noexcept;

    /**
     * Calculates the cross product of a particular Vector passed in as a param.
     * This operation provides strong exception safety.
     * @param rhs Vector object
     * @return another vector of dimension DIM containing the cross product of this and src
     */
    Vector<DIM> cross(const Vector<DIM> rhs) const;

    /**
     * Calculates the norm, or magnitude of the lhs object
     * Calls normSq() to get the square then returns the root of this
     * This operation provides strong exception safety.
     * @param  none
     * @return double representing the magnitude of the vector
     */
    double norm() const noexcept;

    /**
     * Helps calculate the norm of a vector by calculating the squared magnitude
     * This operation provides strong exception safety.
     * @param  none
     * @return double representing the magnitude of the vector
     */
    double normSq() const noexcept;

    /**
     * Returns a normalized version of the Vector object
     * This operation provides strong exception safety.
     * @param  none
     * @return Vector object that is normalized
     */
    Vector<DIM> normalize() const;

    /**
     * Returns an iterator to the end of the arr.
     * This operation is a no-throw.
     * @param: none
     * @return iterator
     */
    double* end() noexcept;

    /**
     * Returns a const iterator to the end of the arr.
     * This operation is a no-throw.
     * @param: none
     * @return const double*
     */
    double* end() const noexcept;

    /**
     * Returns an iterator to the beginning of the Vector.
     * This operation is a no-throw.
     * @param: none
     * @return iterator to the beginning of the Vector
     */
    double* begin() noexcept;

    /**
     * Returns a const iterator to the beginning of the Vector.
     * This operation is a no-throw.
     * @param: none
     * @return const_iterator to beginning of the Vector
     */
    double* begin() const noexcept;

    /**
     * Adds two vector objects together mathematically and returns the resulting object
     * This operation provides strong exception safety.
     * @param  rhs Vector to be added
     * @return Vector obj representing sum of last two Vectors
     */
    Vector<DIM> add(const Vector<DIM> rhs) const noexcept;

    /**
     * Inverts elements in a Vector obj
     * This operation provides strong exception safety.
     * @param  none
     * @return Vector obj representing inversion of object called on
     */
    Vector<DIM> invert() const noexcept;

    /**
     * Scales elements on a particular vector by the param val
     * This operation provides strong exception safety.
     * @param  val
     * @return Vector obj representing scaling of Vector called on
     */
    Vector<DIM> scale(const double& val) const noexcept;

    /**
     * Returns the value at param index in the Vector
     * @param index
     * @return the value at index in the Vector
     */
    double& operator[](const uint32_t index);

    /**
     * Returns a const reference to the value at param index in the Vector
     * @param index
     * @return the value at index in the Vector
     */
    const double& operator[](const uint32_t index) const;

    /**
     * Returns true if and only if this Vector is logically equivalent to
     * rhs, i.e. the size and contents are equal.
     * This operation provides strong exception safety.
     * @param rhs the Vector being compared to
     * @return true iff logically equivalent
     */
    bool operator==(const Vector<DIM>& rhs) const noexcept;

    /**
     * Returns false if this Vector is equal to rhs and true otherwise.
     * This operation provides strong exception safety.
     * @param rhs the Vector being compared to
     * @return true iff not logically equivalent
     */
    bool operator!=(const Vector<DIM>& rhs) const noexcept;

    /**
     * Operator overloaded for scaling a Vector by another number (allows vec1 = vec1 * 2)
     * @param scale
     * @return scaled vector by factor of num
     */
    Vector<DIM> operator*(const double scale) noexcept;

    /**
     * Operator overloaded for scaling a Vector by another number (allows vec1 *= 2)
     * @param scale
     * @return scaled vector by factor of num
     */
    // Vector<DIM> operator*=(const double scale) noexcept;

    /**
     * Operator overloaded for multiplying a Vector object by another via dot product
     * @param rhs Vector obj
     * @return double representing the dot product
     */
    double operator*(const Vector<DIM>& rhs) noexcept;

    /**
     * Operator overloaded for subtracting two Vector objects and returning the resulting Vector
     * @param rhs Vector obj
     * @return Vector representing subtraction
     */
    Vector<DIM> operator-(const Vector<DIM>& rhs) const noexcept;

    /**
     * Returns a new vector representing this being inverted (multiplied by -1)
     * @param: none
     * @return new Vector that is inversion of last
     */
    Vector<DIM> operator-() const noexcept;

    /**
     * Returns a new vector in which param rhs is subtracted from itself
     * @param rhs Vector obj
     * @return subtracted Vector
     */
    Vector<DIM> operator-=(const Vector<DIM>& rhs) noexcept;

    /**
     * Adds two vector objects together mathematically and returns the resulting object
     * This operation provides strong exception safety.
     * @param  rhs Vector to be added
     * @return Vector obj representing sum of last two Vectors
     */
    Vector<DIM> operator+(const Vector<DIM>& rhs) const;

    /**
     * Adds two vector objects together mathematically and returns the resulting object
     * This operation provides strong exception safety.
     * @param  rhs Vector to be added
     * @return Vector obj representing sum of last two Vectors
     */
    Vector<DIM> operator+=(const Vector<DIM>& rhs) noexcept;

    /**
     * Returns a vector in which all elements are divided by param val
     * @param scale
     * @return Vector obj that has been scaled accordingly
     */
    Vector<DIM> operator/(const double scale) noexcept;

    /**
     * Returns a vector in which all elements are divided by param val
     * @param scale
     * @return Vector obj that has been scaled accordingly
     */
    Vector<DIM> operator/=(const double scale);

    /**
     * General cross product template function throws error for invalid argument
     * for non 3D vectors and uses a specializes function for 3D vectors to find
     * the proper cross product
     * @param rhs
     * @returns cross product for 3D vectors
     * @throws std::invalid argument for non 3D vectors
     */
    Vector<DIM> operator^(const Vector<DIM>& rhs) const;

private:
    double arr[DIM];
};

#include "../src/Vector.cpp"
#endif