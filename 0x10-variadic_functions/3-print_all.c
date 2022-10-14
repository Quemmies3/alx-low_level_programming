#include "variadic_functions.h"

void print_char(va_list valist);
void print_int(va_list valist);
void print_float(va_list valist);
void print_string(va_list valist);
void print_all(const char * const format, ...);

/**
 * print_char - Prints a char.
 * @valist: A list of arguments pointing to
 *       the character to be printed.
 */

void print_char(va_list valist)
{
	char letter;

	letter = va_arg(valist, int);
	printf("%c", letter);
}

/**
 * print_int - Prints an int.
 * @valist: A list of arguments pointing to
 *       the integer to be printed.
 */

void print_int(va_list valist)
{
	int num;

	num = va_arg(valist, int);
	printf("%d", num);
}

/**
 * print_float - Prints a float.
 * @valist: A list of arguments pointing to
 *       the float to be printed.
 */

void print_float(va_list valist)
{
	float num;

	num = va_arg(valist, double);
	printf("%f", num);
}

/**
 * print_string - Prints a string.
 * @valist: A list of arguments pointing to
 *       the string to be printed.
 */

void print_string(va_list valist)
{
	char *str;

	str = va_arg(valist, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", str);
}

/**
 * print_all - prints anything.
 * @format: a list of types of arguments passed to the function.
 *
 * Return: no return.
 */

void print_all(const char * const format, ...)
{
	va_list valist;

	unsigned int i = 0, j, c = 0;

	char *str;

	const char t_arg[] = "cifs";

	va_start(valist, format);
	while (format && format[i])
	{
		j = 0;
		while (t_arg[j])
		{
			if (format[i] == t_arg[j] && c)
			{
				printf(", ");
				break;
			} j++;
		}
		switch (format[i])
		{
		case 'c':
			printf("%c", va_arg(valist, int)), c = 1;
			break;
		case 'i':
			printf("%d", va_arg(valist, int)), c = 1;
			break;
		case 'f':
			printf("%f", va_arg(valist, double)), c = 1;
			break;
		case 's':
			str = va_arg(valist, char *), c = 1;
			if (!str)
			{
				printf("(nil)");
				break;
			}
			printf("%s", str);
			break;
		} i++;
	}
	printf("\n");
	va_end(valist);
}
