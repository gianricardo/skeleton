#include <gmock/gmock.h>

#include <device/timer.h>

using namespace ::testing;

namespace
{

TEST(A_timer, is_not_expired_after_initialisation)
{
  Timer testee;

  Timer_init(&testee);

  ASSERT_FALSE(Timer_expired(&testee));
}

TEST(A_timer, with_a_value_of_zero_expires_immediately)
{
  Timer testee;

  Timer_init(&testee);

  Timer_start(&testee, 0);

  ASSERT_TRUE(Timer_expired(&testee));
}

TEST(A_timer, is_not_expired_after_starting_when_the_set_time_has_not_yet_passed)
{
  Timer testee;

  Timer_init(&testee);

  Timer_start(&testee, 3);
  Timer_update(&testee);

  ASSERT_FALSE(Timer_expired(&testee));
}

TEST(A_timer, expires_after_the_given_number_of_milliseconds)
{
  Timer testee;

  Timer_init(&testee);

  Timer_start(&testee, 3);
  Timer_update(&testee);
  Timer_update(&testee);
  Timer_update(&testee);

  ASSERT_TRUE(Timer_expired(&testee));
}

TEST(A_timer, is_not_expired_if_it_was_stopped)
{
  Timer testee;

  Timer_init(&testee);

  Timer_start(&testee, 3);
  Timer_update(&testee);

  Timer_stop(&testee);
  ASSERT_FALSE(Timer_expired(&testee));
}

TEST(A_timer, is_not_expired_even_when_the_time_passed_after_stopping)
{
  Timer testee;

  Timer_init(&testee);

  Timer_start(&testee, 2);
  Timer_update(&testee);

  Timer_stop(&testee);
  Timer_update(&testee);

  ASSERT_FALSE(Timer_expired(&testee));
}

TEST(A_timer, DISABLED_is_not_expired_anymore_if_it_is_stopped_after_expiration)
{
  FAIL();
}


} // namespace