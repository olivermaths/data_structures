CFLAGS = -O2

Stack: source/stack/stack.c
	gcc $(CFLAGS) source/stack/stack.c source/test_stack.c -o stacktest

run: Stack
	./stacktest