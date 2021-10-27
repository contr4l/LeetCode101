#ifndef _UTILS_H_
#define _UTILS_H_

#include"utils.h"
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

int main()
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
    return 0;
}
#endif