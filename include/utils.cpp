#ifndef _UTILS_H_
#define _UTILS_H_

#include"utils.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
int* add_ (int x, int y)
{
    int *res = new int(x+y);
    return res;
}

int minus_(int x, int y){
    return x - y;
}

int* operation_ptr(int x, int y, int* (*func)(int, int)) {
    return (*func)(x, y);
}

int operation(int x, int y, int (*func)(int, int)) {
    return (*func)(x, y);
}

void test1()
{
    int x = 3;
    int y = 5;
    int* (*op1)(int, int) = add_;
    int (*op2)(int, int) = minus_;
    int *res1 = 0, res2 = 0;
    res1 = operation_ptr(x, y, op1);
    res2 = operation(x, y, op2);
    printf("%d %d.\n", *res1, res2);
    delete(res1);
}

void test2()
{
    vector<int> S;
    int max_size = 1000;
    for (int i = 0; i < max_size; i++) {
        S.push_back(i);
    }
    srand((uint32_t)time(NULL));
    int target = rand() % max_size;
    int idx = binary_search(S, target);
    printf("searched list is from 0 to %d.\n", max_size);
    // print_vector(S);
    cout << "target is " << target << endl;
    cout << "find at pos " << idx << endl;
}

void (*test_func)();
typedef void (*TEST_FUNC)();
int main()
{
    test_func = test2;
    test_func();
    return 0;
}
#endif