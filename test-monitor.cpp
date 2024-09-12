#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_TRUE(areVitalsNormal(98, 80, 95));
  ASSERT_FALSE(areVitalsNormal(90, 80, 95));
  ASSERT_FALSE(areVitalsNormal(98, 50, 95));
  ASSERT_FALSE(areVitalsNormal(98, 80, 80));
  ASSERT_FALSE(areVitalsNormal(90, 50, 80));
  ASSERT_FALSE(areVitalsNormal(90, 70, 98));
  ASSERT_FALSE(areVitalsNormal(90, 50, 88));
  ASSERT_FALSE(areVitalsNormal(90, 70, 88));
}
