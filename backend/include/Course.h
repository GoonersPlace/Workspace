#ifndef COURSE_H
#define COURSE_H

struct Course
{
    char name[50];
    int periods;
};

void InputCourses(Course courses[], int &n);
void OutputCourses(Course courses[], int n);

#endif