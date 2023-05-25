#include "c_shell.h"

/**

 */

size_t_strlen(const char *s, size_t maxlen) { 
    const char *p = s;
    size_t len = 0;
    while (len < maxlen && *p != '\0') {
        p++;
        len++;
    }
    return len;
}
void *_memcpy(void *dest, const void *src, size_t n) {
   char *d dest;
   const char *s = src;
   while (n-- > 0) {
      *d++ = *s++;
   }
   return dest;
}
char *_strdup (const char *str) {
    size_t len = _strlen(str, SIZE_MAX) + 1;
    char *dup = malloc(len);
    if (dup != NULL) {
        _memcpy (dup, str, len);
    }
    return dup;
}
void *_memset (void *ptr, int value, size_t num) {
    unsigned char *p = ptr;
    while (num-- > 0) {
        *p++ = (unsigned char) value;
    }    
    return ptr;

}
char *_strncpy (char *dest, const char *src, size_t n) { 
     char *orig = dest;
     while (n > 0 && *src != '\0') {
         *dest++= *src++;
         n--;
     }
     if (n > 0) {
         *dest = '\0';
     } 
     return orig;
}
