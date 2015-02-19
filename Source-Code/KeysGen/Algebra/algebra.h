//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to perform algebraic
// calculations
// @version: 1.8 13/02/2015
//====================================================================

// Algebra module (algebra.h)

#ifndef __ALGEBRA_H__
#define __ALGEBRA_H__

// Finds another non-negative number coprime to num.
long long coprime(const long long num);

// Calculates multiplicative inverse of num modulo modulus.
long long multInverse(const long long num, const long long modulus);

// Calculates base raised to the exponent modulo modulus.
long long modularPow(long long base, long long exponent, const long long modulus);

#endif
