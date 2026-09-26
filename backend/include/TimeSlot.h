#ifndef TIMESLOT_H
#define TIMESLOT_H

struct TimeSlot
{
    char day[10];
    int period;
    char start[10];
    char end[10];
};

void InputTimeSlots(TimeSlot slots[], int &n);
void OutputTimeSlots(TimeSlot slots[], int n);

#endif