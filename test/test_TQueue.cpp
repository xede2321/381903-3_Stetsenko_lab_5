#include "Queue.h"
#include "Queue.cpp"
#include "../gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> qe(3));
}

TEST(TQueue, cant_create_queue_with_null)
{
  ASSERT_ANY_THROW(TQueue<int> qe(0));
}


TEST(TQueue, create_empty_queue)
{
  TQueue<int> qe(3);

  EXPECT_EQ(true, qe.IsEmpty());
}

TEST(TQueue, can_push_if_ok)
{
  TQueue<int> qe(3);

  ASSERT_NO_THROW(qe.Push(3));
}

TEST(TQueue, can_get_elem)
{
  TQueue<int> qe(2);
  qe.Push(4);

  EXPECT_EQ(4, qe.Get());
}

TEST(TQueue, cant_get_if_empty)
{
  TQueue<int> qe(1);

  ASSERT_ANY_THROW(qe.Get());
}

TEST(TQueue, can_copy_queue)
{
  TQueue<int> qe1(2);
  qe1.Push(1);

  ASSERT_NO_THROW(TQueue<int> qe2(qe1));
}

TEST(TQueue, can_assing_queue)
{
  TQueue<int> qe1(2);
  qe1.Push(1);
  TQueue<int> qe2(2);
  qe2 = qe1;

  EXPECT_EQ(1, qe2.Get());
}

TEST(TQueue, test_ring_queue)
{
  TQueue<int> qe(2);
  qe.Push(1);
  qe.Push(2);
  qe.Push(3);
  EXPECT_EQ(2, qe.Get());
}

TEST(TQueue, can_get_Lenght)
{
  TQueue<int> qe(2);

  EXPECT_EQ(2, qe.Length());
}

TEST(TQueue, can_get_MIN_elem)
{
  TQueue<int> qe(3);
  qe.Push(1);
  qe.Push(14);
  qe.Push(7);

  EXPECT_EQ(1, qe.min_elem());
}

TEST(TQueue, can_get_MAX_elem)
{
  TQueue<int> qe(3);
  qe.Push(1);
  qe.Push(14);
  qe.Push(7);

  EXPECT_EQ(14, qe.max_elem());
}