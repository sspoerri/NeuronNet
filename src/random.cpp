#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
{
	if( s > 0 )
		rng = std::mt19937(s);
	else {
		std::random_device rd;
		rng = std::mt19937(rd());
	}
}

void RandomNumbers::uniform_double(std::vector<double>& v, double lower, double upper)
{
	for(auto& a : v)
		a = uniform_double(lower, upper);
}

double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> u(lower,upper);
	return u(rng);
}

void RandomNumbers::normal(std::vector<double>& v, double mean, double sd)
{
	for(auto& a : v)
		a = normal(mean, sd);
}

double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<double> n(mean,sd);
	return n(rng);
}

void RandomNumbers::poisson(std::vector<int>& v, double mean)
{
	for(auto& a : v)
		a = poisson(mean);
}

int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<> p (mean);
	return p(rng);
}
