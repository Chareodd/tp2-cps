CC = gcc
CFLAGS = -Wall -g

all : test_read test_write bitabit generate_sequence

test_read : test_read.o bfile.o
	$(CC) -o $@ $^

test_write : test_write.o bfile.o
	$(CC) -o $@ $^

bitabit : bitabit.o bit_operations.o
	$(CC) -o $@ $^

generate_sequence : generate_sequence.o
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f bitabit test_read test_write generate_sequence sequence coded_sequence decoded_sequence *.o