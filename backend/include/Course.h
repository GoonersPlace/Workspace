#ifndef COURSE_H
#define COURSE_H

#define MAX_COURSE 100

struct Course
{
    char name[50];
    int periods;
};

void InputCourses(const char *filePath, Course courses[], int &n);

#endif
