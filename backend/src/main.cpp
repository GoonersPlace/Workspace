#include <stdio.h>

#include "Course.h"
#include "TimeSlot.h"
#include "Graph.h"
#include "Scheduler.h"

#define MAX_COURSE 100
#define MAX_TIMESLOT 100

int main()
{
    Course courses[MAX_COURSE];
    TimeSlot slots[MAX_TIMESLOT];

    int nCourse = 0;
    int nSlot = 0;

    // =========================
    // 1. Doc du lieu mon hoc
    // =========================

    InputCourses(courses, nCourse);

    printf("So mon hoc: %d\n", nCourse);

    OutputCourses(courses, nCourse);


    // =========================
    // 2. Doc du lieu khung gio
    // =========================

    InputTimeSlots(slots, nSlot);

    printf("\nSo khung gio: %d\n", nSlot);

    // Tam thoi khong in 96 dong
    // OutputTimeSlots(slots, nSlot);


    // =========================
    // 3. Tao do thi
    // =========================

    Graph graph;

    InitGraph(graph, nCourse);


    // =========================
    // 4. Tao cac canh
    // =========================

    // Tam thoi chua them canh.
    // Phan nay se lam sau khi
    // xac dinh quy tac xung dot.


    // =========================
    // 5. To mau do thi
    // =========================

    int color[MAX_COURSE];

    ColoringGraph(graph, color);


    // =========================
    // 6. Tao lich
    // =========================

    Schedule schedule[MAX_COURSE];

    CreateSchedule(
        courses,
        nCourse,
        slots,
        nSlot,
        color,
        schedule
    );


    // =========================
    // 7. Xuat lich
    // =========================

    OutputSchedule(
        schedule,
        nCourse,
        courses,
        slots
    );


    return 0;
}