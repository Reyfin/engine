#include "Vector4D.h"
#include <stdexcept>
#include <iostream>

namespace Math
{

	Vector4D& Vector4D::add(const Vector4D& v)
	{
		data[0] += v.data[0];
		data[1] += v.data[1];
		data[2] += v.data[2];
		data[3] += v.data[3];

		return *this;
	}

	Vector4D& Vector4D::subtract(const Vector4D& v)
	{
		data[0] -= v.data[0];
		data[1] -= v.data[1];
		data[2] -= v.data[2];
		data[3] -= v.data[3];

		return *this;
	}

	float Vector4D::scalarProduct(const Vector4D& v)
	{
		return data[0] * v.x() + data[1] * v.y() + data[2] * v.z() + data[3] * v.w();
	}

	void Vector4D::print() const
	{
		std::cout << "[";

		for(auto i = 0; i < 4; i++)
			std::cout << data[i] << ";";
		std::cout << "]" << std::endl;
	}

	float Vector4D::operator[](int index) const
	{
		if(index < 0 || index >= 4)
			throw std::out_of_range("0 <= x <= 3 is the range of vector4d");

		return data[index];
	}

	float& Vector4D::operator[](int index)
	{
		if(index < 0 || index >= 4)
			throw std::out_of_range("0 <= x <= 3 is the range of vector4d");

		return data[index];
	}



	Vector4D operator+(const Vector4D& v, const Vector4D& w)
	{
		Vector4D res(v);

		return res.add(w);
	}

	Vector4D operator-(const Vector4D& v, const Vector4D& w)
	{
		Vector4D res(v);

		return res.subtract(w);
	}


}
