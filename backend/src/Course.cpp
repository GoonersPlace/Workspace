#include "Course.h"
#include <stdio.h>

#define COURSE_FILE "backend/data/course.txt"

void InputCourses(Course courses[], int &n)
{
    FILE *file = fopen(COURSE_FILE, "r");

    if (file == NULL)
    {
        printf("Khong mo duoc file course.txt!\n");
        n = 0;
        return;
    }

    n = 0;

    while (fscanf(file, "%49[^,],%d\n",
                  courses[n].name,
                  &courses[n].periods) == 2)
    {
        n++;
    }

    fclose(file);
}

void OutputCourses(Course courses[], int n)
{
    printf("Danh sach mon hoc:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - %d tiet/tuan\n",
               i + 1,
               courses[i].name,
               courses[i].periods);
    }
}