/**
 * @author Matthew Palmer <matt@matthewpalmer.net>
 * @version 0.0.1
 * @since 2015-01-28
 */

/**
 * bitqueue ADT
 *
 * A bitqueue abstracts the bitwise operations necessary to shift bits along,
 * append bits, and so on.
 * A bitqueue is FIFO.
 * Bits move from right to left, for example
 *   1 0 1 1 0 1 0 0
 * the 1 at the left end was added earliest (longest time ago), and the 0
 * at the right end was added soonest (shortest time ago).
 *
 * Also, the queue is always full, so enqueuing a bit dequeues
 * the bit on the other end.
 */
typedef struct bitqueueRep *bitqueue;

/**
 * Create a new bitqueue
 *
 * This creates a new queue of bits to be used.
 * 
 * @param  length        The maximum number of bits in the bitqueue at 
 *                       any time.
 *                       Bits 'to the left' of the maximum length 'drop off'
 *                       the queue. That is, they cannot be accessed any
 *                       more, and no guarantees are made about their
 *                       accuracy or validity.
 *                       
 * @param  initial_value The initial value to store in the bitqueue.
 *                       Often, this will be 0.
 * @return               Returns a new bitqueue.
 */
bitqueue new_bitqueue(int length, int initial_value);

/**
 * Gets the *leftmost* bit from the queue.
 * This is the oldest bit in the queue.
 * @param  b The bitqueue to get the head of.
 * @return   1 | 0
 */
int head_bitqueue(bitqueue b);

/**
 * Gets the length of the bitqueue, i.e. the maximum number of
 * bits that can be in the queue.
 * @param  b The bitqueue to get the length of.
 * @return   Returns the length of the bitqueue.
 */
int length_bitqueue(bitqueue b);

/**
 * Gets the current value of the bitqueue, as an integer
 * @param  b The queue to get the current value of.
 * @return   Returns the value of the queue.
 */
int current_value_bitqueue(bitqueue b);

/**
 * Appends a bit to the bitqueue on the right-hand end.
 * Note that this function also dequeus the leftmost bit,
 * since a bitqueue must always be full.
 * @param b   The queue to enqueue the bit on.
 * @param bit 1 | 0
 */
int enqueue_bitqueue(bitqueue b, int bit);

/**
 * Prints the bitqueue.
 * Note that this doesn't limit the number of leading zeroes
 * that are printed. It is left to the user to determine where
 * the appropriate starting bit is in the queue they are viewing.
 * @param b The bitqueue to display.
 */
void show_bitqueue(bitqueue b);

/**
 * Sets the current value of the bitqueue
 * @param b     The bitqueue to set the current value of
 * @param value The value to set the queue to
 */
void set_current_value_bitqueue(bitqueue b, int value)