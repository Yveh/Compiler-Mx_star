extern int scanf(const char *restrict, ...);
extern int sscanf(const char *restrict, const char *restrict, ...);
extern int printf(const char *restrict, ...);
extern int sprintf(char *, const char *, ...);
extern unsigned int strlen(const char *);
extern int strcmp(const char*, const char *);
extern char* strcat(char*, const char *);
extern void* memcpy(void*, const void*, unsigned int);
extern void* malloc(unsigned int);

void print(char* str) {
    printf("%s", str);
}

void printInt(int n) {
    printf("%d", n);
}

void printlnInt(int n) {
    printf("%d\n", n);
}

char* getString() {
    char *ret = (char*) malloc(128);
    scanf("%s", ret);
    return ret;
}

int getInt() {
    int d;
    scanf("%d", &d);
    return d;
}

char* toString(int i) {
    char *ret = (char*) malloc(12);
    sprintf(ret, "%d", i);
    return ret;
}

int string_ord(char *s, int i) {
    return *(s + i);
}

int array_size(int *i) {
    return *(i - 1);
}

char* string_substring(char *s, int l, int r) {
    char *ret = (char*) malloc(r - l + 1);
    memcpy(ret, s + l, r - l);
    return ret;
}
int string_parseInt(char *s) {
    int d;
    sscanf(s, "%d", &d);
    return d;
}
int string_length(char *s) {
    return strlen(s);
}
char* string_strcat(char *lhs, char *rhs) {
    int l = strlen(lhs), r = strlen(rhs);
    char *ret = (char*) malloc(l + r + 1);
    memcpy(ret, lhs, l);
    strcat(ret, rhs);
    return ret;
}
_Bool string_equal(char *lhs, char *rhs) {
    return strcmp(lhs, rhs) == 0;
}

_Bool string_less(char *lhs, char *rhs) {
    return strcmp(lhs, rhs) < 0;
}

_Bool string_greater(char *lhs, char *rhs) {
    return strcmp(lhs, rhs) > 0;
}
