
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

int main() {
	/*	Standard replacements	*/
	TITLE("Main Functions");

	TEST_NAME("Standard string");
	ft_printf("FT: test");
	printf("\nLC: test\n\n");

	TEST_NAME("Char insert");
	ft_printf("FT: %c", 'c');
	printf("\nLC: %c\n\n", 'c');

	TEST_NAME("String insert");
	ft_printf("FT: %s", "test");
	printf("\nLC: %s\n\n", "test");

	TEST_NAME("Pointer address");
	ft_printf("FT: %p", NULL);
	printf("\nLC: %p\n\n", NULL);

	TEST_NAME("Signed decimal int");
	ft_printf("FT: %d", -666);
	printf("\nLC: %d\n\n", -666);

	TEST_NAME("%sSigned decimal int");
	ft_printf("FT: %i", 69420);
	printf("\nLC: %i\n\n", 69420);

	TEST_NAME("Unsigned decimal int");
	ft_printf("FT: %u", 220000000);
	printf("\nLC: %u\n\n", 220000000);

	TEST_NAME("Unsigned hex (lowercase)");
	ft_printf("FT: %x", 0xFEFAB1);
	printf("\nLC: %x\n\n", 0xFEFAB1);

	TEST_NAME("Unsigned hex (uppercase)");
	ft_printf("FT: %X\n", 0xFEFAB1);
	printf("\nLC: %X\n\n", 0xFEFAB1);

	/*	Bonus section	*/
	TITLE("Bonus Functions");

	TEST_NAME("Left justify");
	ft_printf("FT: %-.10i", 123);
	printf("\nLC: %-.10i\n\n", 123);

	TEST_NAME("Dot precision");
	ft_printf("FT: %0.10i", 123);
	printf("\nLC: %0.10i\n\n", 123);

	TEST_NAME("Hex prefix");
	ft_printf("FT: %#X", 0xFEFAB1);
	printf("\nLC: %#X\n\n", 0xFEFAB1);

	TEST_NAME("Blank sign");
	ft_printf("FT: % i", 100);
	printf("\nLC: % i\n\n", 100);

	TEST_NAME("Forced sign");
	ft_printf("FT: %+i", 100);
	printf("\nLC: %+i\n\n", 100);

	printf("%sYou are a failure!\n%s", red, default);

	return 0;
}