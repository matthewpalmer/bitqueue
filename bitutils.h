/**
 * @author Matthew Palmer <matt@matthewpalmer.net>
 * @version 0.0.1
 * @since 2015-01-28
 */

/**
 * A collection of handy bit utility functions.
 * Often paired with bitqueue
 */

/**
 * Get the kth bit *from the right* of the integer n.
 * The rightmost bit is bit 0
 * 
 * @param  n The integer to get the kth bit of
 * @param  k The index of the bit to get
 * @return   1 | 0
 */
int kth_bit_from_right(int n, int k);

/**
 * Sets the kth bit *from the right* of the integer n to 1.
 * @param  n The integer whose bit we want to set
 * @param  k The index of the bit to set
 * @return   The new value, with the set bit.
 */
int set_kth_bit_from_right(int n, int k);

/**
 * Unsets the kth bit *from the right* of the integer n to 0.
 * @param  n The integer whose bit we want to unset
 * @param  k The index of the bit to unset
 * @return   The new value, with the unset bit.
 */
int unset_kth_bit_from_right(int n, int k);

/**
 * Prints the bits of an item
 * @param size The number of bytes an item takes up
 * @param ptr  A pointer to the item to be printed.
 */
void print_bits(size_t const size, void const * const ptr);
