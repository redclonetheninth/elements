all: bitwise_1 bitwise_2

bitwise_1: bitwise_1.c
	clang -o $@ $^

bitwise_2: bitwise_2.c
	clang -o $@ $^

clean:
	rm bitwise_1
	rm bitwise_2

.PHONY: all clean
