#include "c_shell.h"

/**
 * _strlen - strlen funct
 * @s: str
 * @max: max length
 * Return: length
 */
size_t _strlen(const char *s, size_t max)
{
	const char *p = s;
	size_t length = 0;

	while (length < max && *p != '\0')
	{
		p++;
		length++;
	}
	return (length);
}

/**
 * _memcpy - memcpy func
 * @dest: str
 * @src: str
 * @n: num
 * Return: void
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}

/**
 * _strdup - strdup func
 * @s: str
 * Return: str
 */
char *_strdup(const char *s)
{
	size_t len = _strlen(s, SIZE_MAX) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		_memcpy(dup, s, len);
	}
	return (dup);
}

/**
 * _memset - memset func
 * @ptr: pointer
 * @v: value
 * @num: num
 * Return: void
 */
void *_memset(void *ptr, int v, size_t num)
{
	unsigned char *p = ptr;

	while (num-- > 0)
	{
		*p++ = (unsigned char)v;
	}
	return (ptr);
}

/**
 * _strncpy - strncpy func
 * @dest: str
 * @src: str
 * @n: num
 * Return: str
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *r = dest;

	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}
	if (n > 0)
	{
		*dest = '\0';
	}
	return (r);
}
