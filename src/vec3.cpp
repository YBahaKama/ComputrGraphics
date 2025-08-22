/*
 * <src/vec3.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */


#include "cg/vec3.hpp"
#include <cmath>

namespace cg {

Vec3::Vec3 () : x (0.0f), y (0.0f), z (0.0f) {
}

Vec3::Vec3 (float x, float y, float z) : x (x), y (y), z (z) {
}

float Vec3::length () const {
    return std::sqrt ((x * x) + (y * y) + (z * z));
}

Vec3 Vec3::operator+ (const Vec3& other) const {
    return Vec3 (x + other.x, y + other.y, z + other.z);
}

float Vec3::dot (const Vec3& other) const {
    return (x * other.x) + (y * other.y) + (z * other.z);
}

float Vec3::cross (const Vec3& other) const {
    return (y * other.z - z * other.y) + (z * other.x - x * other.z) +
    (x * other.y - y * other.x);
}
} // namespace cg
