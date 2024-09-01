#include "kinematics.h"

Eigen::Vector3d Kinematics::forwardTransform(param::Robot &rb)
{
	Eigen::Matrix4d T = Eigen::Matrix4d::Identity();

	for (int i = 0; i < 6; ++i) {
		T = T * T_matrix(rb.theta[i] * M_PI / 180.0, rb.a[i], rb.d[i], rb.alpha[i]);
	}

	Eigen::Vector3d position = T.block<3, 1>(0, 3);
	return position;
}

Eigen::Matrix4d Kinematics::T_matrix(double theta, double a, double d, double alpha) {
	Eigen::Matrix4d A;
	
	A << cos(theta), -sin(theta) * cos(alpha), sin(theta) * sin(alpha), a * cos(theta),
		sin(theta), cos(theta) * cos(alpha), -cos(theta) * sin(alpha), a * sin(theta),
		0, sin(alpha), cos(alpha), d,
		0, 0, 0, 1;
	
	return A;
}
