#include "MultiStack.h"
#include "MultiStack.cpp"
#include "../gtest/gtest.h"

TEST(TMultiStack, can_create_MultiStack_with_positive_length)
{
	ASSERT_NO_THROW(TMultiStack<int> mst(9, 3));
}

TEST(TMultiStack, cant_create_MultiStack_with_null)
{
	ASSERT_ANY_THROW(TMultiStack<int> mst(0));
}

TEST(TMultiStack, check_empty_MultiStack)
{
	TMultiStack<int> mst(9, 3);

	EXPECT_EQ(true, mst.IsEmpty(1));
}

TEST(TMultiStack, check_for_non_existent_empty_MultiStack)
{
	TMultiStack<int> mst(9, 3);

	ASSERT_ANY_THROW(mst.IsEmpty(4));
}

TEST(TMultiStack, check_negative_empty_MultiStack)
{
	TMultiStack<int> mst(9, 3);

	ASSERT_ANY_THROW(mst.IsEmpty(-5));
}

TEST(TMultiStack, check_IsFull_MultiStack)
{
	TMultiStack<int> mst(9, 3);

	EXPECT_EQ(false, mst.IsFull(1));
}

TEST(TMultiStack, check_for_non_existent_IsFull_MultiStack)
{
	TMultiStack<int> mst(9, 3);

	ASSERT_ANY_THROW(mst.IsFull(4));
}

TEST(TMultiStack, check_negative_IsFull_MultiStack)
{
	TMultiStack<int> mst(9, 3);

	ASSERT_ANY_THROW(mst.IsFull(-5));
}

TEST(TMultiStack, can_push_with_mem)
{
	TMultiStack<int> mst(9, 3);

	ASSERT_NO_THROW(mst.Push(10, 1));
}

TEST(TMultiStack, cant_push_with_no_mem)
{
	TMultiStack<int> mst(9, 3);

	ASSERT_ANY_THROW(mst.Push(10, 4));
}

TEST(TMultiStack, can_copy_stack)
{
	TMultiStack<int> mst1(9, 3);
	mst1.Push(10, 1);

	ASSERT_NO_THROW(TMultiStack<int> mst2(mst1));
}

TEST(TMultiStack, can_assing_stack)
{
	TMultiStack<int> mst1(9, 3);
	mst1.Push(10, 1);
	TMultiStack<int> mst2(9, 3);
	mst2 = mst1;

	EXPECT_EQ(10, mst2.Get(1));
}

TEST(TMultiStack, can_get)
{
	TMultiStack<int> mst(9, 3);
	mst.Push(10, 1);

	ASSERT_NO_THROW(mst.Get(1));
}

TEST(TMultiStack, cant_get_nonexistent)
{
	TMultiStack<int> mst(9, 3);
	mst.Push(10, 1);

	ASSERT_ANY_THROW(mst.Get(-4));
}

TEST(TMultiStack, cant_get_negative)
{
	TMultiStack<int> mst1(9, 3);
	mst1.Push(10, 1);

	ASSERT_ANY_THROW(mst1.Get(4));
}

TEST(TMultiStack, can_GetSize)
{
	TMultiStack<int> mst1(9, 3);

	ASSERT_NO_THROW(mst1.GetSize());
}

TEST(TMultiStack, can_Resize)
{
	TMultiStack<int> mst1(1, 1);
	mst1.Push(10, 0);

	ASSERT_NO_THROW(mst1.Resize(5, 0));
}

TEST(TMultiStack, cant_Resize_negative)
{
	TMultiStack<int> mst1(1, 1);
	mst1.Push(10, 0);

	ASSERT_ANY_THROW(mst1.Resize(-5, 0));
}

TEST(TMultiStack, can_StackRelocation)
{
	TMultiStack<int> mst(9, 3);
	mst.Push(11, 0);
	mst.Push(12, 1);
	mst.Push(12, 1);
	mst.Push(12, 1);

	ASSERT_NO_THROW(mst.Push(15, 1));
}