/* 
 * <include/cg/vec3.hpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */



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

        float dot(const Vec3& other) const;

        float cross(const Vec3& other) const;

	};
}