#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "bitqueue.h"
#include "bitutils.h"

#define BITS_IN_BYTE 8

typedef struct bitqueueRep {
    int length;
    int current_value;
} bitqueueRep;

static int head_index(bitqueue b);
static int max_value(bitqueue b);
static int dequeue_bitqueue(bitqueue b);

bitqueue new_bitqueue(int length, int initial_value) {
    bitqueue b = malloc(sizeof(bitqueue));
    assert(b != NULL);
    b->length = length;
    b->current_value = initial_value;
    return b; 
}

int enqueue_bitqueue(bitqueue b, int bit) {
    assert(bit == 1 || bit == 0);
    // Dequeueing from the bitqueue has the convenient effect
    // of leaving the rightmost bit a 0, so we can safely OR
    // the incoming bit onto the queue.
    int leftmost = dequeue_bitqueue(b);
    b->current_value = b->current_value | bit;
    return leftmost;
}

int head_bitqueue(bitqueue b) {
    int current = current_value_bitqueue(b);
    return kth_bit_from_right(current, head_index(b));
}

int length_bitqueue(bitqueue b) {
    return b->length;
}

int current_value_bitqueue(bitqueue b) {
    return b->current_value;
}

void set_current_value_bitqueue(bitqueue b, int value) {
    b->current_value = value;
}

void show_bitqueue(bitqueue b) {
    int current = current_value_bitqueue(b);
    print_bits(sizeof(current), &current);
}

/**
 * Private functions
 */
static int head_index(bitqueue b) {
    return length_bitqueue(b) - 1;
}

static int max_value(bitqueue b) {
    return pow(2, length_bitqueue(b) - 1);
}

static int dequeue_bitqueue(bitqueue b) {
    // Get the current head.
    // Shift the value left (i.e. off the queue).
    int value = head_bitqueue(b);
    b->current_value = current_value_bitqueue(b) << 1;

    // If the current value has exceeded its max, then we need to remove
    // the shifted head. e.g. if we have 100000 (32) and dequeue the head,
    // then it would become 1000000 (64) if we didn't 
    // remove the shifted head.
    int i;
    int new;
    if (current_value_bitqueue(b) > max_value(b)) {
        i = head_index(b) + 1;
        new = unset_kth_bit_from_right(current_value_bitqueue(b), i);
        b->current_value = new;
    }

    return value;
}
