CFLAGS = -Wall -std=c11 -pedantic -O0
HW_1: HW_1.c
	gcc $(CFLAGS) -o HW_1 HW_1.c
clean:
	rm *.o HW_1
