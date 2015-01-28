# bitqueue
A bitqueue abstracts the bitwise operations necessary to shift bits along, append bits, and so on.

A bitqueue is a FIFO queue of bits. In `1 0 1 1 0 1 0 0`, the 1 at the left end was added earliest (longest time ago), and the 0 at the right end was added soonest (shortest time ago).

Also, a bitqueue is always full, so enqueuing a bit dequeues
the bit on the other end.

## Usage
Create a new bitqueue

```c
int length = 4;
int initial_value = 5;  // 0101
bitqueue b = new_bitqueue(length, initial_value);  // => 0101
```

Add an item to the bitqueue

```c
enqueue_bitqueue(b, 1);  // => 1011
```

Note that a bitqueue must always be full, so enqueuing an item also dequeues the head of the bitqueue

```c    
int head = head_bitqueue(b); // Gets the head, doesn't remove anything.
int old_head = enqueue_bitqueue(b, 1); // => 0111
// Note: head == old_head.
```

There are also a few other useful functions

```c    
int length_bitqueue(bitqueue b);
int current_value_bitqueue(bitqueue b);
void show_bitqueue(bitqueue b);
```

Refer to [src/bitqueue.h][bq] for further documentation.

[bq]: src/bitqueue.h

## bitutils
Also of interest in the [src][sr] directory is a collection of utility functions for manipulating bits. Documentation for these can be found in [src/bitutils.h][bu].

[sr]: src/
[bu]: src/bitutils.h