#pragma once

#include <Engine/Math/Math.h>

namespace math
{
	//! Converts degrees to radians.
	float toRadians(float deg);

	//! Converts radians to degrees
	float toDegrees(float rad);

	//! Clamps a value to provided range
	float clamp(const float fVal, const float fMin, const float fMax);

	//! Assumes unit quaternion and calculate w component.
	float calcQuatWComponent(const glm::quat &q);

	//! Multiply q1 with q2.
	glm::quat multiplyQuat(const glm::quat &q1, const glm::quat &q2);

	//! Calculates spherical linear interpolation between quaternions q1 and q2.
	glm::quat slerp(const glm::quat &q1, const glm::quat &q2, float u);
}
