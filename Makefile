CC=gcc
CFLAGS=-Wall -Werror -g

bin/test_bitqueue : bitqueue_tests.o bitqueue.o bitutils.o
	$(CC) $(CFLAGS) -o $@ $^

bin/bitqueue : bitqueue.o bitutils.o
	$(CC) $(CFLAGS) -o $@ $^

bitqueue_tests.o : src/bitqueue_tests.c
	$(CC) $(CFLAGS) -c $^

bitqueue.o : src/bitqueue.c
	$(CC) $(CFLAGS) -c $^

bitutils.o : src/bitutils.c
	$(CC) $(CFLAGS) -c $^
	
clean : 
	rm *.o