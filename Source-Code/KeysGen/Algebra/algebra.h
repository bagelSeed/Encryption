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

// Finds another non-negative number coprime to a number num.
long long findCoPrime(const long long num);

// Finds the multiplicative inverse of a number num modulo m.
long long findMultInverse(const long long num, const long long m);

#endif
