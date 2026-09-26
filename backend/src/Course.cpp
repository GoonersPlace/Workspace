#include "Course.h"
#include <stdio.h>

void InputCourses(const char *filePath, Course courses[], int &n)
{
    FILE *file = fopen(filePath, "r");

    if (file == NULL)
    {
        n = 0;
        return;
    }

    n = 0;

    while (n < MAX_COURSE &&
           fscanf(file, "%49[^,],%d\n", courses[n].name, &courses[n].periods) == 2)
    {
        n++;
    }

    fclose(file);
}
