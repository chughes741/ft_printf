
/*
	Test program for ft_printf, compares to printf
*/

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define default "\033[0m"
#define black "\033[1;30m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define yellow "\033[1;33m"
#define blue "\033[1;34m"
#define purple "\033[1;35m"
#define cyan "\033[1;36m"
#define white "\033[1;37m"

#define TITLE(title) print_title(title)
#define TEST_NAME(test_name) print_test(test_name)

void print_title(char* title) {
	printf("%s\n", cyan);
	printf("\t-*-*- %s -*-*-", title);
	printf("%s\n\n", default);
}

void print_test(char* test_name) {
	printf("%s", blue);
	printf("%s", test_name);
	printf("%s\n", default);
}

void count_test(int x, int y) {
	x == (y - 2) ? printf("%sCount matches%s\n\n", green, default) : \
			 printf("%sLC: %i\tFT: %i %s\n\n", red, (y - 6), (x - 4), default); 
}

int main() {
	int x = 0;
	int y = 0;
	
	/*	Standard replacements	*/
	TITLE("Main Functions");

	TEST_NAME("Standard string");
	x = ft_printf("FT: test");
	y = printf("\nLC: test\n");
	count_test(x, y);

	TEST_NAME("Char insert");
	x = ft_printf("FT: %c", 'z');
	y = printf("\nLC: %c\n", 'z');
	count_test(x, y);

	TEST_NAME("String insert");
	x = ft_printf("FT: %s", "test");
	y = printf("\nLC: %s\n", "test");
	count_test(x, y);

	TEST_NAME("Pointer address");
	x = ft_printf("FT: %p", &y);
	y = printf("\nLC: %p\n", &y);
	count_test(x, y);

	TEST_NAME("Signed decimal int");
	x = ft_printf("FT: %d", -666);
	y = printf("\nLC: %d\n", -666);
	count_test(x, y);

	TEST_NAME("Signed decimal int");
	x = ft_printf("FT: %i", 69420);
	y = printf("\nLC: %i\n", 69420);
	count_test(x, y);

	TEST_NAME("Unsigned decimal int");
	x = ft_printf("FT: %u", 220000000);
	y = printf("\nLC: %u\n", 220000000);
	count_test(x, y);

	TEST_NAME("Unsigned hex (lowercase)");
	x = ft_printf("FT: %x", 0xFEFAB1);
	y = printf("\nLC: %x\n", 0xFEFAB1);
	count_test(x, y);

	TEST_NAME("Unsigned hex (uppercase)");
	x = ft_printf("FT: %X", 0xFEFAB1);
	y = printf("\nLC: %X\n", 0xFEFAB1);
	count_test(x, y);

	TEST_NAME("Print %%");
	x = ft_printf("FT: %%");
	y = printf("\nLC: %%\n");
	count_test(x, y);

	/*	Bonus section	*/
	TITLE("Bonus Functions");

	TEST_NAME("Left justify");
	x = ft_printf("FT: %-10itest", 123);
	y = printf("\nLC: %-10itest\n", 123);
	count_test(x, y);

	TEST_NAME("Int zero padding");
	x = ft_printf("FT: %10i", 12345);
	y = printf("\nLC: %010i\n", 12345);
	count_test(x, y);

	TEST_NAME("Str width padding");
	x = ft_printf("FT: %10s", "Hello");
	y = printf("\nLC: %10s\n", "Hello");
	count_test(x, y);

	TEST_NAME("Dot precision");
	x = ft_printf("FT: %0.10i", 123);
	y = printf("\nLC: %0.10i\n", 123);
	count_test(x, y);

	TEST_NAME("Hex prefix");
	x = ft_printf("FT: %#X", 0xFEFAB1);
	y = printf("\nLC: %#X\n", 0xFEFAB1);
	count_test(x, y);

	TEST_NAME("Blank sign");
	x = ft_printf("FT: % i", 100);
	y = printf("\nLC: % i\n", 100);
	count_test(x, y);

	TEST_NAME("Forced sign");
	x = ft_printf("FT: %+i", 100);
	y = printf("\nLC: %+i\n", 100);
	count_test(x, y);

	return 0;
}