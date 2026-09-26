#ifndef TIMESLOT_H
#define TIMESLOT_H

#define MAX_TIMESLOT 100

struct TimeSlot
{
    char day[10];
    int period;
    char start[10];
    char end[10];
};

void InputTimeSlots(const char *filePath, TimeSlot slots[], int &n);

#endif
