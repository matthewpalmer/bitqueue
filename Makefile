CC=gcc
CFLAGS=-Wall -Werror -g

test_biqueue : bitqueue_tests.o bitqueue.o bitutils.o
	$(CC) $(CFLAGS) -o $@ $^

bitqueue : bitqueue.o bitutils.o
	$(CC) $(CFLAGS) -o $@ $^

bitqueue_tests.o : bitqueue_tests.c
	$(CC) $(CFLAGS) -c $^

bitqueue.o : bitqueue.c
	$(CC) $(CFLAGS) -c $^

bitutils.o : bitutils.c
	$(CC) $(CFLAGS) -c $^
	
