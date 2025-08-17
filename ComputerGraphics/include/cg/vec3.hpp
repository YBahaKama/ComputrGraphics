#pragma once
#include "Export.h"


namespace cg {
	class Vec3 {
    public:
        float x, y, z;

        Vec3();
        Vec3(float x, float y, float z);

        float length() const;

        Vec3 operator+(const Vec3& other) const;

        float Vec3::dot(const Vec3& other) const;

        float Vec3::cross(const Vec3& other) const;

	};
}