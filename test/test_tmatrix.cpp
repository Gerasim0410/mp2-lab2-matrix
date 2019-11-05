#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE+ 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5), v(m);
	EXPECT_EQ(m, v);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	m[1][1] = 1;
	TMatrix<int> v(m);
	v[1][1] = 2;
	EXPECT_NE(v, m);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][1] = 1;
	EXPECT_EQ(m[1][1], 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE+1][2]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;
	TMatrix<int> v(m);
	m = m;
	EXPECT_EQ(m, v);
}

TEST(TMatrix, can_assign_matrixes_of_equal_size)
{
	TMatrix<int> m(5), v(5);
	m = v;
	EXPECT_EQ(m, v);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(3), v(6);
	m = v;
	EXPECT_EQ(m.GetSize(), 6);
}

TEST(TMatrix, can_assign_matrixes_of_different_size)
{
	TMatrix<int> m(5), v(8);
	m = v;
	EXPECT_EQ(m, v);
}

TEST(TMatrix, compare_equal_matrixes_return_true)
{
	int n = 3;
	TMatrix<int> m(n), v(n);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			m[i][j] = i + j;
			v[i][j] = i + j;
		}
	EXPECT_EQ(m, v);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(3);
	EXPECT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(3), v(5);
	EXPECT_NE(m, v);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int n= 5;
	TMatrix<int> m(n), v(n), result(n);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			m[i][j] = i + j;
			v[i][j] = -j;
			result[i][j] = i;
		}
	EXPECT_EQ(m + v, result);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), v(6);
	ASSERT_ANY_THROW(m + v);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int n= 5;
	TMatrix<int> m(n), v(n), result(n);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			m[i][j] = i + j;
			v[i][j] = -j;
			result[i][j] = i + 2 * j;
		}
	EXPECT_EQ(m - v, result);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(6), v(7);
	ASSERT_ANY_THROW(m - v);
}
