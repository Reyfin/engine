#include "vector3d.h"


Physix::Vector3D Physix::Vector3D::operator*(double scalar) const
{
	return Vector3D(scalar * this->__x, scalar * this->__y, scalar * this->__z);
}

Physix::Vector3D&Physix::Vector3D::operator+=(const Physix::Vector3D& right)
{
	this->__x += right.__x;
	this->__y += right.__y;
	this->__z += right.__z;

	return *this;
}
