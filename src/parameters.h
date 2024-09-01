#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <cmath>
#include <initializer_list>

namespace param {

// Made for extensibility. If you wanna add more robots, you can describe it's parameters here.
struct Robot
{
	Robot(std::initializer_list<double> a_list,
		std::initializer_list<double> d_list,
		std::initializer_list<double> alpha_list)
	{
		std::copy(a_list.begin(), a_list.end(), a);
		std::copy(d_list.begin(), d_list.end(), d);
		std::copy(alpha_list.begin(), alpha_list.end(), alpha);
	}
	
	double theta[6];
	double a[6];
	double d[6];
	double alpha[6];
};

static param::Robot rb1({0, -0.8, -0.59, 0, 0, 0},
						{0.213, 0.193, -0.16, 0.25, 0.28, 0.25},
						{M_PI/2, 0, 0, M_PI/2, -M_PI/2, 0}
						);

}
	
#endif
