#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Course.h"
#include "TimeSlot.h"
#include "Graph.h"

#define MAX_COURSE 100
#define MAX_TIMESLOT 100

struct Schedule
{
    int courseIndex;
    int timeSlotIndex;
};

void ColoringGraph(Graph graph, int color[]);

void CreateSchedule(
    Course courses[],
    int nCourse,
    TimeSlot slots[],
    int nSlot,
    int color[],
    Schedule schedule[]
);

void OutputSchedule(
    Schedule schedule[],
    int nCourse,
    Course courses[],
    TimeSlot slots[]
);

#endif  