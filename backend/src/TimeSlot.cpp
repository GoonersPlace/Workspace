#include "TimeSlot.h"
#include <stdio.h>

#define TIMESLOT_FILE "backend/data/timeslot.txt"

void InputTimeSlots(TimeSlot slots[], int &n)
{
    FILE *file = fopen(TIMESLOT_FILE, "r");

    if (file == NULL)
    {
        printf("Khong mo duoc file timeslot.txt!\n");
        n = 0;
        return;
    }

    n = 0;

    while (fscanf(file, "%9[^,],%d,%9[^,],%9[^\n]\n",
                  slots[n].day,
                  &slots[n].period,
                  slots[n].start,
                  slots[n].end) == 4)
    {
        n++;
    }

    fclose(file);
}

void OutputTimeSlots(TimeSlot slots[], int n)
{
    printf("\n===== DANH SACH KHUNG GIO =====\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - tiet %d - %s -> %s\n",
               i + 1,
               slots[i].day,
               slots[i].period,
               slots[i].start,
               slots[i].end);
    }
}