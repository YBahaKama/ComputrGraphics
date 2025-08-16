#include "cg/vec3.hpp"
#include <cmath>

namespace cg {

	Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

	Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	float Vec3::length() const {
		return std::sqrt((x * x) + (y * y) + (z * z));
	}

	Vec3 Vec3::operator+(const Vec3& other) const {
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

}