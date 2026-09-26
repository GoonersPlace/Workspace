#include "TimeSlot.h"
#include <stdio.h>

void InputTimeSlots(const char *filePath, TimeSlot slots[], int &n)
{
    FILE *file = fopen(filePath, "r");

    if (file == NULL)
    {
        n = 0;
        return;
    }

    n = 0;

    char slotCountLine[32];
    if (fgets(slotCountLine, sizeof(slotCountLine), file) == nullptr)
    {
        fclose(file);
        return;
    }

    while (n < MAX_TIMESLOT &&
           fscanf(file,
                  "%9[^,],%d,%9[^,],%9[^\n]\n",
                  slots[n].day,
                  &slots[n].period,
                  slots[n].start,
                  slots[n].end) == 4)
    {
        n++;
    }

    fclose(file);
}
