#ifndef VECTOR2D_H
#define VECTOR2D_H


#include "Math/Vector3D.h"

namespace Math
{
	class Vector2D : public Vector3D
	{
	public:
		Vector2D() : Vector3D(0, 0, 0) {}
		Vector2D(float x, float y) : Vector3D(x, y, 0) {}

		void z(float z) = delete;
		float z() const = delete;
	};
}

#endif // VECTOR2D_H
