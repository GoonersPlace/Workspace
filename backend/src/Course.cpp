#include "Course.h"
#include <stdio.h>

void InputCourses(const char *filePath, Course courses[], int &n)
{
    FILE *file = nullptr;
    if (fopen_s(&file, filePath, "r") != 0)
    {
        file = nullptr;
    }

    if (file == NULL)
    {
        n = 0;
        return;
    }

    n = 0;

    while (n < MAX_COURSE &&
           fscanf_s(file,
                    "%49[^,],%d\n",
                    courses[n].name,
                    static_cast<unsigned>(sizeof(courses[n].name)),
                    &courses[n].periods) == 2)
    {
        n++;
    }

    fclose(file);
}
