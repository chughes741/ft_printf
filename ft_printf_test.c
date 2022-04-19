
/*
	Test program for ft_printf, compares to printf
*/

#include "ft_printf.h"
#include <stdio.h>

#define default "\033[0m"
#define black "\033[1;30m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define yellow "\033[1;33m"
#define blue "\033[1;34m"
#define purple "\033[1;35m"
#define cyan "\033[1;36m"
#define white "\033[1;37m"

int main() {
	/*	Standard replacements	*/
	printf("%s\tMain Functions:\n%s", cyan, default);
	ft_printf("Standard string test - FT\n");
	printf("Standard string test - LC\n\n");

	ft_printf("Char insert test: %c - FT\n", 'c');
	printf("Char insert test: %c - LC\n\n", 'c');

	ft_printf("String insert test: %s - FT\n", "test");
	printf("String insert test: %s - LC\n\n", "test");

	ft_printf("Pointer address test: %p - FT\n", NULL);
	printf("Pointer addres test: %p - LC\n\n", NULL);

	ft_printf("Signed decimal int test: %d - FT\n", -666);
	printf("Signed decimal int test: %d - LC\n\n", -666);

	ft_printf("Signed decimal int test: %i - FT\n", 69420);
	printf("Signed decimal int test: %i - LC\n\n", 69420);

	ft_printf("Unsigned decimal int test: %u - FT\n", 220000000);
	printf("Unsigned decimal int test: %u - LC\n\n", 220000000);

	ft_printf("Unsigned hex int (lowercase) test: %x - FT\n", 0xFEFAB1);
	printf("Unsigned hex int (lowercase) test: %x - LC\n\n", 0xFEFAB1);

	ft_printf("Unsigned hex int (uppercase) test: %X - FT\n", 0xFEFAB1);
	printf("Unsigned hex int (uppercase) test: %X - LC\n\n", 0xFEFAB1);

	/*	Bonus section	*/
	printf("%s\n\tBonus Section:\n%s", cyan, default);
	ft_printf("Left justify test: %-.10i - FT\n", 123); // TODO write test
	printf("Left justify test: %-.10i - LC\n\n", 123);

	ft_printf("Dot precision test: %0.10i - FT\n", 123); // TODO write test
	printf("Dot precision test: %0.10i - LC\n\n", 123);

	ft_printf("Hex prefix test: %#X - FT\n", 0xFEFAB1); // TODO write test
	printf("Hex prefix test: %#X - LC\n\n", 0xFEFAB1);

	ft_printf("Blank sign test: % i - FT\n", 100); // TODO write test
	printf("Blank sign test: % i - LC\n\n", 100);

	ft_printf("Forced sign test: %+i - FT\n", 100); // TODO write test
	printf("Forced sign test: %+i - LC\n\n", 100);

	return 0;
}