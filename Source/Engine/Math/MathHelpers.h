#pragma once

#include <Engine/Math/Math.h>

namespace core
{
	//! Assumes unit quaternion and calculate w component.
	float calcQuatWComponent(const glm::quat &q);

	//! Multiply q1 with q2.
	glm::quat multiplyQuat(const glm::quat &q1, const glm::quat &q2);

	//! Calculates spherical linear interpolation between quaternions q1 and q2.
	glm::quat slerpQuat(const glm::quat &q1, const glm::quat &q2, float u);

	//! Converts degrees to radians.
	float toRadians(float deg);

	//! Converts radians to degrees
	float toDegrees(float rad);

	//! Smooths current value toward target value.
	template <class T>
	static T smoothTo(const T &current, const T& target, float speed)
	{
		if (glm::length(target - current) > 0.01f)
			return current + (target - current)*speed;
		else
			return target;
	}
}
