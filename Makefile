CC = gcc
CFLAGS = -g --std=gnu99 -Wall
src = $(wildcard *.c)
obj = $(src:.c=.o)


movies_by_year: $(obj)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
		rm -f $(obj) movies
