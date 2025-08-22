/*
 * <include/cg/vec2.hpp>
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

class CG_API Vec2 {
    public:
    float x, y;

    Vec2 ();
    Vec2 (float x, float y);

    float length () const;

    Vec2 operator+ (const Vec2& other) const;

    float dot (const Vec2& other) const;

    float cross (const Vec2& other) const;
};
} // namespace cg
