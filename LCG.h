#pragma once
#include <cstdint>
class LCG
{
	uint_fast64_t m_a;
	uint_fast64_t  m_seed;
	uint_fast64_t m_modulus;
	uint_fast64_t m_c;
public:
	LCG(uint_fast64_t a, uint_fast64_t c, uint_fast64_t  seed, uint_fast64_t  modulus) : m_a(a), m_c(c), m_seed(seed), m_modulus(modulus) {};
	LCG& operator ++ (int);
	uint_fast64_t operator* () {  return m_seed; }


};

