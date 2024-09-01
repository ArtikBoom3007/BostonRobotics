#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <Eigen/Dense>
#include "parameters.h"

// Kinematics is singleton class because physics engine is the object
// which should process different objects same way.
class Kinematics
{
public:
	static Kinematics& instance() {
		static Kinematics c;
		return c;
	};
	Eigen::Vector3d forwardTransform(param::Robot &rb);
	
private:
	Kinematics() = default;
	~Kinematics() = default;
	Kinematics(const Kinematics&) = delete;
	Kinematics& operator= (const Kinematics&) = delete;
	Eigen::Matrix4d T_matrix(double theta, double a, double d, double alpha);
};

#endif // KINEMATICS_H
