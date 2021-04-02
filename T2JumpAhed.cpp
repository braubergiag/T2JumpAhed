
#include <iostream>
#include <cmath>
#include "../LCG.h"
#include <Eigen/Dense>
#include <iomanip>
using namespace Eigen;




uint_fast64_t jump_ahead(Matrix < uint_fast64_t, 2, 2> mat, uint_fast64_t n, uint_fast64_t seed, uint_fast64_t modulus);
int main()
{



  // LCG Test
	std::cout << "Test(LCG): " << std::endl;
	uint_fast64_t  modulus = pow(2, 63), a = 123,seed = 2, c = 15,l = 10e8;
	Matrix < uint_fast64_t, 2, 2 > mat;
	int width = 25;
	mat << a, c,
		0, 1;
	LCG g2(a,c, seed, modulus);
	std::cout << "Params :" << "A : " << a << ", C : " << c << ", X_0 :" << seed << std::endl;
	std::cout << "Jump ahead for " << std::setw(width) << " l = " << l << " " << std::setw(width) << jump_ahead(mat, l, seed, modulus) << std::endl;;
	for (int i = 0; i < 100; ++i) {
		std::cout << i << " LCG value: " << std::setw(width) <<  *(g2) << " Jump Ahead value: " << std::setw(width) <<  jump_ahead(mat, i, seed, modulus) << std::endl;
		g2++;
	}
	// RANDU TEST 
	std::cout << '\n';
	std::cout << "Test(Multiplicative) RANDU: " << std::endl;
	uint_fast64_t  modulus_r = pow(2, 31), a_r = 65539, seed_r = 1, c_r = 0;
	Matrix < uint_fast64_t, 2, 2 > mat_r;
	mat_r << a_r, c_r,
		0, 1;
	LCG g1(a_r,c_r, seed_r, modulus_r);
	std::cout << "Jump ahead for " << std::setw(width) << " l = " << l << " " << std::setw(width) << jump_ahead(mat_r, l, seed_r, modulus_r) << std::endl;;
	
	for (int i = 0; i < 100; ++i) {
		
		std::cout <<     i  << " LCG value: " << std::setw(width)  << *(g1) << " Jump Ahead value: " << std::setw(width) << jump_ahead(mat_r, i, seed_r, modulus_r) << std::endl;
		g1++;
	}


}
uint_fast64_t jump_ahead(Matrix < uint_fast64_t, 2, 2> mat, uint_fast64_t n, uint_fast64_t seed, uint_fast64_t modulus) {
	Matrix < uint_fast64_t, 2, 2 > result;
	result = result.Identity(2, 2);
	Matrix <uint_fast64_t, 2, 1> vec;
	vec << seed, 1;

	while (n > 0) {
		if (n % 2 == 1) result *= mat;
		mat *= mat;
		n /= 2;
	}

	return (result * vec)(0, 0) % modulus;
}

