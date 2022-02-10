#include "unity.h"
#include <functions.h>

#define PROJECT_NAME "hospital"





void setUp(){}

void tearDown(){}

void test_exitt(void){
  TEST_ASSERT_EQUAL_STRING("EXITING THE PROGRAM",exitt());
    
}
int main()
{

  UNITY_BEGIN();


  RUN_TEST(test_exitt);
  return UNITY_END();
}