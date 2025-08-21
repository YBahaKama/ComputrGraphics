/* 
 * <test/source/vec2_test.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */


#include <cg/vec2.hpp>
#include <gtest/gtest.h>

TEST(Vec2Test, DefaultConstructor) {
	cg::Vec2 v;
	EXPECT_FLOAT_EQ(v.x, 0.0f);
	EXPECT_FLOAT_EQ(v.y, 0.0f);
}

TEST(Vec2Test, ParameterizedConstructor) {
	cg::Vec2 v(1.0f, 2.0f);
	EXPECT_FLOAT_EQ(v.x, 1.0f);
	EXPECT_FLOAT_EQ(v.y, 2.0f);
}