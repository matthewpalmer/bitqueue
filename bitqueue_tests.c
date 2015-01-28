#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitqueue.h"

int main(int argc, char const *argv[])
{
    // Test bitqueue
    bitqueue b = new_bitqueue(10, 0);
    assert(length_bitqueue(b) == 10);
    assert(current_value_bitqueue(b) == 0);
    assert(head_bitqueue(b) == 0);

    bitqueue c = new_bitqueue(2, 2);
    assert(head_bitqueue(c) == 1);

    bitqueue d = new_bitqueue(2, 3);
    assert(length_bitqueue(d) == 2);
    assert(current_value_bitqueue(d) == 3);
    assert(head_bitqueue(d) == 1);

    bitqueue e = new_bitqueue(6, 32);
    assert(length_bitqueue(e) == 6);
    assert(current_value_bitqueue(e) == 32);
    assert(head_bitqueue(e) == 1);

    bitqueue f = new_bitqueue(4, 0);
    int num1 = enqueue_bitqueue(f, 1);
    assert(num1 == 0);
    assert(current_value_bitqueue(f) == 1);
    assert(head_bitqueue(f) == 0);

    int num2 = enqueue_bitqueue(f, 1);
    assert(num2 == 0);
    assert(current_value_bitqueue(f) == 3);
    assert(head_bitqueue(f) == 0);

    int num3 = enqueue_bitqueue(f, 0);
    assert(num3 == 0);
    assert(current_value_bitqueue(f) == 6);
    assert(head_bitqueue(f) == 0);

    int num4 = enqueue_bitqueue(f, 1);
    assert(num4 == 0);
    assert(current_value_bitqueue(f) == 13);
    assert(head_bitqueue(f) == 1);

    int num5 = enqueue_bitqueue(f, 1);
    assert(num5 == 1);
    assert(current_value_bitqueue(f) == 11);
    assert(head_bitqueue(f) == 1);

    printf("All tests passed.\n");

    return EXIT_SUCCESS;
}