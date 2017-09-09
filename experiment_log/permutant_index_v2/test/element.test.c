#include "../lib/Unity/src/unity.h"

#include "../include/element.h"

void test_element_init(void){
    element_t test;
    element_init(&test, 20);
    TEST_ASSERT_EQUAL_INT(test.dim, 20);
    element_free(&test);
}
void test_element_get(void){
    element_t test;
    element_init(&test, 4);
    test.data[0] = 1.1;
    test.data[1] = 1.2;
    test.data[2] = 1.3;
    test.data[3] = 1.4;
    TEST_ASSERT_EQUAL_FLOAT(element_get(&test, 0), 1.1);
    TEST_ASSERT_EQUAL_FLOAT(element_get(&test, 1), 1.2);
    TEST_ASSERT_EQUAL_FLOAT(element_get(&test, 2), 1.3);
    TEST_ASSERT_EQUAL_FLOAT(element_get(&test, 3), 1.4);
    element_free(&test);
}
void test_element_set(void){

    element_t test;
    element_init(&test, 4);
    element_set(&test, 0, 1.1);
    element_set(&test, 1, 1.2);
    element_set(&test, 2, 1.3);
    element_set(&test, 3, 1.4);
    TEST_ASSERT_EQUAL_FLOAT(test.data[0], 1.1);
    TEST_ASSERT_EQUAL_FLOAT(test.data[1], 1.2);
    TEST_ASSERT_EQUAL_FLOAT(test.data[2], 1.3);
    TEST_ASSERT_EQUAL_FLOAT(test.data[3], 1.4);
    element_free(&test);
}
void test_element_free(void){
    element_t test;
    element_init(&test, 4);
    test.data[0] = 1.1;
    test.data[1] = 1.2;
    test.data[2] = 1.3;
    test.data[3] = 1.4;
    element_free(&test);
    TEST_ASSERT_NULL(test.data);
    TEST_ASSERT_EQUAL_INT(test.dim, 0);
}
void test_element_distance(void){
    element_t test_1;
    element_init(&test_1, 4);
    test_1.data[0] = 1;
    test_1.data[1] = 1;
    test_1.data[2] = 1;
    test_1.data[3] = 1;

    element_t test_2;
    element_init(&test_2, 4);
    test_2.data[0] = 1;
    test_2.data[1] = 1;
    test_2.data[2] = 1;
    test_2.data[3] = 1;
    
    // Test zero distance
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(element_distance(&test_1, &test_2, manhattan_distance), 0.0, "Zero Manhattan distance");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(element_distance(&test_1, &test_2, euclidean_full_distance), 0.0, "Zero Euclidean full distance");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(element_distance(&test_1, &test_2, euclidean_simple_distance), 0.0, "Zero Euclidean simple distance");

    test_2.data[0] = -1;
    test_2.data[1] = -1;
    test_2.data[2] = -1;
    test_2.data[3] = -1;
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(element_distance(&test_1, &test_2, manhattan_distance), 8.0, "Non negative, non zero manhattan distance");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(element_distance(&test_1, &test_2, euclidean_full_distance), 4.0, "Non negative, non zero euclidean full distance");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(element_distance(&test_1, &test_2, euclidean_simple_distance), 16.0, "Non negative, non zero euclidean simple distance");

    element_free(&test_1);
    element_free(&test_2);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_element_init);
    RUN_TEST(test_element_get);
    RUN_TEST(test_element_set);
    RUN_TEST(test_element_distance);
    return UNITY_END();
}
