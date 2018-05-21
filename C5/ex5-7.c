#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /*max number of lines to be sorted*/
#define MAXSPACE 10000
#define MAXLEN 1000         /* max length of any input line */

char *lineptr[MAXLINES];    /* lineptr is an array of MAXLINE number of elements, all of which are char pointers*/
                            /* lineptr[i] is char pointer, and *lineptr[i] is the char it points to */
int readlines(char *lineptr[], int nlines);
int readlines2(char *lineptr[], int maxlines, char *ls);
void writelines(char *lineptr[], int nlines);
int my_getline(char *, int);
char *alloc(int);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;             /* number of input lines */
    char linestore[MAXSPACE];

    if ((nlines = readlines2(lineptr, MAXLINES, linestore)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return -1;
    }
}

/* a readline routine that store lines in an array rather than calling alloc */
int readlines2(char *lineptr[], int maxlines, char *ls)
{
    int len, nlines;
    char *pt, line[MAXLEN];

    nlines = 0;
    pt = ls + strlen(ls);
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (strlen(ls) + len) > MAXSPACE)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(pt, line);
            lineptr[nlines++] = pt;
            pt += len;
        }
    return nlines;
}


/* readlines: read  input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines (rewritten) */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)      /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* krgetline get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000     /* size of available space */

static char allocbuf[ALLOCSIZE];        /* storage for alloc */
static char *allocp = allocbuf;         /* next free position */

char *alloc(int n)         /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;       /* old */
    } else                      /* not enough room */
        return 0;
}