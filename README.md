# bitqueue
A bitqueue abstracts the bitwise operations necessary to shift bits along, append bits, and so on.

## Usage
Create a new bitqueue

    int length = 4;
    int initial_value = 5;  // 0101
    bitqueue b = new_bitqueue(length, initial_value);  // => 0101


Add an item to the bitqueue

    enqueue_bitqueue(b, 1);  // => 1011

Note that a bitqueue must always be full, so enqueuing an item also dequeues the head of the bitqueue
    
    int head = head_bitqueue(b);
    int old_head = enqueue_bitqueue(b, 1); // => 0111
    // Note: head == old_head.

There are also a few useful functions
    
    int length_bitqueue(bitqueue b);
    int current_value_bitqueue(bitqueue b);
    void show_bitqueue(bitqueue b);

Refer to [src/bitqueue.h][bq] for further documentation.

[bq]: src/bitqueue.h

## bitutils
Also of interest in the [src][sr] directory is a collection of utility functions for manipulating bits. Documentation for these can be found in [src/bitutils.h][bu].

[sr]: src/
[bu]: src/bitutils.h