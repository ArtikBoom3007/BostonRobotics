#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <Eigen/Dense>

class Kinematics
{
public:
	static Kinematics& instance() {
		static Kinematics c;
		return c;
	};
	Eigen::Vector3d forwardTransform();
	
private:
	Kinematics() {};
	~Kinematics() {};
	Kinematics(const Kinematics&) = delete;
	Kinematics& operator= (const Kinematics&) = delete;
	Eigen::Matrix4d T_matrix(double theta, double a, double d, double alpha);
};

#endif // KINEMATICS_H
