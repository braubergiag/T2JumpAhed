#include "LCG.h"

LCG& LCG::operator++(int)
{
	m_seed = (m_a * m_seed + m_c) % m_modulus;
	return *this;
}
