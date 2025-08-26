/*
 * <test/source/mat4_test.cpp>
 * Copyright (c) 2025 YusufBaha
 * Dedicated to the public domain under CC0 1.0 Universal.
 * SPDX-License-Identifier: CC0-1.0
 */
#include <array>
#include <cg/mat4.hpp>
#include <cmath>
#include <gtest/gtest.h>
#include <stdexcept>

using cg::Mat4;

namespace
{

constexpr float kEps = 1e-5f;

bool MatAlmostEqual(const Mat4 &a, const Mat4 &b, float eps = kEps)
{
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            if (std::fabs(a.m[r][c] - b.m[r][c]) > eps)
            {
                return false;
            }
        }
    }
    return true;
}

void ExpectMatAlmostEqual(const Mat4 &a, const Mat4 &b, float eps = kEps)
{
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            EXPECT_NEAR(a.m[r][c], b.m[r][c], eps) << "Mismatch at (" << r << "," << c << ")";
        }
    }
}

Mat4 MakeSequential()
{
    return Mat4(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
}

Mat4 MakeReverseSequential()
{
    return Mat4(16.f, 15.f, 14.f, 13.f, 12.f, 11.f, 10.f, 9.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f, 2.f, 1.f);
}

Mat4 Identity()
{
    return Mat4(); // Assuming default is identity
}

} // namespace

class Mat4TestFixture : public ::testing::Test
{
  protected:
    Mat4 A = MakeSequential();
    Mat4 B = MakeReverseSequential();
    Mat4 I = Identity();
};

TEST_F(Mat4TestFixture, DefaultIsIdentity)
{
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            EXPECT_FLOAT_EQ(I.m[r][c], r == c ? 1.f : 0.f);
        }
    }
}

TEST_F(Mat4TestFixture, ParameterizedConstructorStoresValues)
{
    Mat4 m = A;
    EXPECT_FLOAT_EQ(m.m[0][0], 1.f);
    EXPECT_FLOAT_EQ(m.m[3][3], 16.f);
}

TEST_F(Mat4TestFixture, Addition)
{
    Mat4 C = A + B;
    for (int r = 0; r < 4; ++r)
        for (int c = 0; c < 4; ++c)
            EXPECT_FLOAT_EQ(C.m[r][c], 17.f);
}

TEST_F(Mat4TestFixture, Subtraction)
{
    Mat4 C = A - B;
    // Spot check a few entries
    EXPECT_FLOAT_EQ(C.m[0][0], 1.f - 16.f);
    EXPECT_FLOAT_EQ(C.m[0][1], 2.f - 15.f);
    EXPECT_FLOAT_EQ(C.m[3][3], 16.f - 1.f);
}

TEST_F(Mat4TestFixture, Multiplication)
{
    Mat4 C = A * B;
    // These expected values from your original test:
    EXPECT_FLOAT_EQ(C.m[0][0], 80.f);
    EXPECT_FLOAT_EQ(C.m[0][1], 70.f);
    EXPECT_FLOAT_EQ(C.m[3][3], 386.f);
}

TEST_F(Mat4TestFixture, MultiplicationAssociativity)
{
    Mat4 C = A * (B * I);
    Mat4 D = (A * B) * I;
    ExpectMatAlmostEqual(C, D);
}

TEST_F(Mat4TestFixture, IdentityNeutralElement)
{
    ExpectMatAlmostEqual(A * I, A);
    ExpectMatAlmostEqual(I * A, A);
}

TEST_F(Mat4TestFixture, TransposeInvolution)
{
    Mat4 T = A.Transpose();
    Mat4 TT = T.Transpose();
    ExpectMatAlmostEqual(TT, A);
}

TEST_F(Mat4TestFixture, DeterminantOfSequentialIsZero)
{
    EXPECT_FLOAT_EQ(A.Determinant(), 0.f);
}

TEST_F(Mat4TestFixture, MinorMatrix)
{
    Mat4 M = I.Minor();
    // Sample a few values from your previous expectations:

    EXPECT_FLOAT_EQ(M.m[0][0], 1.f);
    EXPECT_FLOAT_EQ(M.m[1][1], 1.f);
    EXPECT_FLOAT_EQ(M.m[2][2], 1.f);
    EXPECT_FLOAT_EQ(M.m[3][3], 1.f);

    EXPECT_FLOAT_EQ(M.m[0][2], 0.f);
    EXPECT_FLOAT_EQ(M.m[0][4], 0.f);
    EXPECT_FLOAT_EQ(M.m[2][3], 0.f);
    EXPECT_FLOAT_EQ(M.m[1][2], 0.f);
}

TEST_F(Mat4TestFixture, CofactorMatrixHasSignPattern)
{
    Mat4 M = A.Minor();
    Mat4 C = A.Cofactor();
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            float expected = ((r + c) % 2 == 0 ? 1.f : -1.f) * M.m[r][c];
            EXPECT_FLOAT_EQ(C.m[r][c], expected);
        }
    }
}

TEST_F(Mat4TestFixture, InverseThrowsOnSingular)
{
    EXPECT_THROW(A.Inverse(), std::runtime_error);
    try
    {
        A.Inverse();
    }
    catch (const std::runtime_error &e)
    {
        EXPECT_STREQ(e.what(), "Matrix is singular and cannot be inverted.");
    }
}

TEST(Mat4Standalone, InverseOfNonSingular)
{
    Mat4 m(1.f, 1.f, 1.f, 1.f, 1.f, -1.f, 1.f, 0.f, 1.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f);
    Mat4 inv = m.Inverse();

    // Hard-coded expected (from your original test)
    Mat4 expected(0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, -1.f, 0.f, 1.f, 1.f, -2.f, 1.f, -1.f, -2.f, 2.f);
    ExpectMatAlmostEqual(inv, expected);

    // Validate m * inv = I and inv * m = I
    Mat4 prod1 = m * inv;
    Mat4 prod2 = inv * m;
    ExpectMatAlmostEqual(prod1, Identity());
    ExpectMatAlmostEqual(prod2, Identity());
}
