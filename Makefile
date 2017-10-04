CC=gcc
CFLAGS=-I. -g
DEPS = conn.h ssl_conn.h
OBJ = main.o conn.o ssl_conn.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
