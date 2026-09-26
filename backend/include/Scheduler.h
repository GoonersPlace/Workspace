#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Course.h"
#include "TimeSlot.h"
#include "Graph.h"

struct Schedule
{
    int courseIndex;
    int timeSlotIndex;
};

void ColoringGraph(Graph graph, int color[]);

void CreateSchedule(
    int nCourse,
    int nSlot,
    int color[],
    Schedule schedule[]
);

#endif
