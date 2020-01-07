CC = gcc
CFLAGS = -Wall -g
BINS = libmiscc-test libmiscc.so libmiscc.o

all: $(BINS)

libmiscc.o: ../src/data/*.c ../src/data/*.h
	$(CC) $(CFLAGS) -c ../src/data/*.c

libmiscc.so: ../src/data/*.c ../src/data/*.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ ../src/data/*.c -lc

libmiscc-test: ../src/test.c libmiscc.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm *.o $(BINS)
