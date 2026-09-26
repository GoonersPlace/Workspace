#include "TimeSlot.h"
#include <stdio.h>

void InputTimeSlots(const char *filePath, TimeSlot slots[], int &n)
{
    FILE *file = nullptr;
    if (fopen_s(&file, filePath, "r") != 0)
    {
        file = nullptr;
    }

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
           fscanf_s(file,
                    "%9[^,],%d,%9[^,],%9[^\n]\n",
                    slots[n].day,
                    static_cast<unsigned>(sizeof(slots[n].day)),
                    &slots[n].period,
                    slots[n].start,
                    static_cast<unsigned>(sizeof(slots[n].start)),
                    slots[n].end,
                    static_cast<unsigned>(sizeof(slots[n].end))) == 4)
    {
        n++;
    }

    fclose(file);
}
