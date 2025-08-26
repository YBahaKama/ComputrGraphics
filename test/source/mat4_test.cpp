/*
 * <test/source/mat4_test.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <cg/mat4.hpp>
#include <gtest/gtest.h>

TEST(Mat4Test, DefaultConstructor)
{
    cg::Mat4 m;
    EXPECT_FLOAT_EQ(m.m[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m.m[0][1], 0.0f);
    EXPECT_FLOAT_EQ(m.m[0][2], 0.0f);
    EXPECT_FLOAT_EQ(m.m[0][3], 0.0f);
    EXPECT_FLOAT_EQ(m.m[1][0], 0.0f);
    EXPECT_FLOAT_EQ(m.m[1][1], 1.0f);
    EXPECT_FLOAT_EQ(m.m[1][2], 0.0f);
    EXPECT_FLOAT_EQ(m.m[1][3], 0.0f);
    EXPECT_FLOAT_EQ(m.m[2][0], 0.0f);
    EXPECT_FLOAT_EQ(m.m[2][1], 0.0f);
    EXPECT_FLOAT_EQ(m.m[2][2], 1.0f);
    EXPECT_FLOAT_EQ(m.m[2][3], 0.0f);
    EXPECT_FLOAT_EQ(m.m[3][0], 0.0f);
    EXPECT_FLOAT_EQ(m.m[3][1], 0.0f);
    EXPECT_FLOAT_EQ(m.m[3][2], 0.0f);
    EXPECT_FLOAT_EQ(m.m[3][3], 1.0f);
}

TEST(Mat4Test, ParameterizedConstructor)
{
    cg::Mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    EXPECT_FLOAT_EQ(m.m[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m.m[0][1], 2.0f);
    EXPECT_FLOAT_EQ(m.m[0][2], 3.0f);
    EXPECT_FLOAT_EQ(m.m[0][3], 4.0f);
    EXPECT_FLOAT_EQ(m.m[1][0], 5.0f);
    EXPECT_FLOAT_EQ(m.m[1][1], 6.0f);
    EXPECT_FLOAT_EQ(m.m[1][2], 7.0f);
    EXPECT_FLOAT_EQ(m.m[1][3], 8.0f);
    EXPECT_FLOAT_EQ(m.m[2][0], 9.0f);
    EXPECT_FLOAT_EQ(m.m[2][1], 10.0f);
    EXPECT_FLOAT_EQ(m.m[2][2], 11.0f);
    EXPECT_FLOAT_EQ(m.m[2][3], 12.0f);
    EXPECT_FLOAT_EQ(m.m[3][0], 13.0f);
    EXPECT_FLOAT_EQ(m.m[3][1], 14.0f);
    EXPECT_FLOAT_EQ(m.m[3][2], 15.0f);
    EXPECT_FLOAT_EQ(m.m[3][3], 16.0f);
}

TEST(Mat4Test, MultiplicationOperator)
{
    cg::Mat4 m1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    cg::Mat4 m2(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
    cg::Mat4 result = m1 * m2;
    EXPECT_FLOAT_EQ(result.m[0][0], 80.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], 70.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], 60.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], 50.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], 240.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], 214.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], 188.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], 162.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], 400.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], 358.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], 316.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], 274.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], 560.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], 502.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], 444.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], 386.0f);
}

TEST(Mat4Test, AdditionOperator)
{
    cg::Mat4 m1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    cg::Mat4 m2(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
    cg::Mat4 result = m1 + m2;
    EXPECT_FLOAT_EQ(result.m[0][0], 17.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], 17.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], 17.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], 17.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], 17.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], 17.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], 17.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], 17.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], 17.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], 17.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], 17.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], 17.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], 17.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], 17.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], 17.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], 17.0f);
}

TEST(Mat4Test, SubtractionOperator)
{
    cg::Mat4 m1(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
    cg::Mat4 m2(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    cg::Mat4 result = m1 - m2;
    EXPECT_FLOAT_EQ(result.m[0][0], 15.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], 13.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], 11.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], 9.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], 7.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], 5.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], 3.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], 1.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], -1.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], -3.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], -5.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], -7.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], -9.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], -11.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], -13.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], -15.0f);
}

TEST(Mat4Test, Determinant)
{
    cg::Mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    float det = m.Determinant();
    EXPECT_FLOAT_EQ(det, 0.0f);
}

TEST(Mat4Test, Transpose)
{
    cg::Mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    cg::Mat4 result = m.Transpose();
    EXPECT_FLOAT_EQ(result.m[0][0], 1.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], 5.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], 9.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], 13.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], 2.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], 6.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], 10.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], 14.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], 3.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], 7.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], 11.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], 15.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], 4.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], 8.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], 12.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], 16.0f);
}

TEST(Mat4Test, Minor)
{
    cg::Mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    cg::Mat4 result = m.Minor();
    EXPECT_FLOAT_EQ(result.m[0][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], 0.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], 0.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], 0.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], 0.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], 0.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], 0.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], 0.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], 0.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], 0.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], 0.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], 0.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], 0.0f);
}

TEST(Mat4Test, Cofactor)
{
    cg::Mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    cg::Mat4 result = m.Cofactor();
    EXPECT_FLOAT_EQ(result.m[0][0], -24.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], -20.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], -16.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], -12.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], -18.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], -16.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], -14.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], -12.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], -12.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], -12.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], -12.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], -12.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], -8.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], -8.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], -8.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], -8.0f);
}

TEST(Mat4Test, InverseOfSingular)
{
    cg::Mat4 m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
    try
    {
        cg::Mat4 result;
        result = result.Inverse();
        FAIL() << "Expected 'Matrix is singular and cannot be inverted.'";
    }
    catch (const std::runtime_error &err)
    {
        EXPECT_EQ(err.what(), std::string("Matrix is singular and cannot be inverted."));
    }
}

TEST(Mat4Test, Inverse)
{
    cg::Mat4 m(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
    cg::Mat4 result = m.Inverse();
    EXPECT_FLOAT_EQ(result.m[0][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[0][1], 0.0f);
    EXPECT_FLOAT_EQ(result.m[0][2], 0.0f);
    EXPECT_FLOAT_EQ(result.m[0][3], 1.0f);
    EXPECT_FLOAT_EQ(result.m[1][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[1][1], 0.0f);
    EXPECT_FLOAT_EQ(result.m[1][2], 1.0f);
    EXPECT_FLOAT_EQ(result.m[1][3], -1.0f);
    EXPECT_FLOAT_EQ(result.m[2][0], 0.0f);
    EXPECT_FLOAT_EQ(result.m[2][1], 1.0f);
    EXPECT_FLOAT_EQ(result.m[2][2], 1.0f);
    EXPECT_FLOAT_EQ(result.m[2][3], -2.0f);
    EXPECT_FLOAT_EQ(result.m[3][0], 1.0f);
    EXPECT_FLOAT_EQ(result.m[3][1], -1.0f);
    EXPECT_FLOAT_EQ(result.m[3][2], -2.0f);
    EXPECT_FLOAT_EQ(result.m[3][3], 2.0f);
}
