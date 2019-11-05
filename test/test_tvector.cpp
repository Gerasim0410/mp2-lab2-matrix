#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(2);
	v[0] = 1;
	v[1] = 2;
	TVector<int> m(v);
	EXPECT_EQ(m, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(3);
	v[0] = 1;
	TVector<int> m(v);
	m[0] = 2;
	EXPECT_NE(m[0], v[0]);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);
	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);
	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;
	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE+1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> m(5), v(m);
	m = m;
	EXPECT_EQ(m, v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> m(5), v(5);
	m = v;
	EXPECT_EQ(m, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> m(5), v(7);
	m = v;
	EXPECT_EQ(m.GetSize(), 7);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> m(5), v(7);
	m = v;
	EXPECT_EQ(m, v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> m(3);
	m[0] = 1;
	m[1] = 2;
	m[2] = 3;
	TVector<int>  v(m);
	EXPECT_EQ(m, v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> m(3);
	EXPECT_EQ(m, m);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> m(3), v(10);
	EXPECT_NE(m, v);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> m(4), v(4);
	for (int i = 0; i < 4; i++)	{
		m[i] = 1;
		v[i] = 2;
	}
	m = m + 1;
	EXPECT_EQ(m, v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> m(4), v(4);
	for (int i = 0; i < 4; i++){
		m[i] = 3;
		v[i] = 2;
	}
	m = m - 1;
	EXPECT_EQ(m, v);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> m(4), v(4);
	for (int i = 0; i < 4; i++){
		m[i] = 1;
		v[i] = 5;
	}
	m = m * 5;
	EXPECT_EQ(m, v);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> m(4), v(4), res(4);
	for (int i = 0; i < 4; i++){
		m[i] = i;
		v[i] = 5*i+2;
		res[i] = 5*i+2+i;
	}
	EXPECT_EQ(m + v, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> m(4), v(6);
	ASSERT_ANY_THROW(m + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> m(4), v(4), res(4);
	for (int i = 0; i < 4; i++){
		m[i] = 5;
		v[i] = i;
		res[i] = 5 - i;
	}
	EXPECT_EQ(m - v, res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> m(4), v(6);
	ASSERT_ANY_THROW(m - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> m(4), v(4);
	int res = 0;
	for (int i = 0; i < 4; i++){
		m[i] = 5;
		v[i] = i;
		res = res + 5 * i;
	}
	EXPECT_EQ(m * v, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> m(4), v(6);
	ASSERT_ANY_THROW(m * v);
}
