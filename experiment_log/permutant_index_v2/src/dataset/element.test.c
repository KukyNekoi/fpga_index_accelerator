#include "../tests/Unity/src/unity.h"
#include "element.h"

void test_element_init(void){
    element_t test;
    element_init(&test, 20);
    TEST_ASSERT_EQUAL_INT(test.dim, 20);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_element_init);
    return UNITY_END();
}
