#include "Scheduler.h"

void ColoringGraph(Graph graph, int color[])
{
    for (int i = 0; i < graph.n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < graph.n; i++)
    {
        bool used[MAX_COURSE] = {false};

        for (int j = 0; j < graph.n; j++)
        {
            if (graph.A[i][j] == 1 && color[j] != -1)
            {
                used[color[j]] = true;
            }
        }

        int c = 0;

        while (used[c])
        {
            c++;
        }

        color[i] = c;
    }
}
void CreateSchedule(
    int nCourse,
    int nSlot,
    int color[],
    Schedule schedule[])
{
    for (int i = 0; i < nCourse; i++)
    {
        schedule[i].courseIndex = i;

        if (color[i] < nSlot)
        {
            schedule[i].timeSlotIndex = color[i];
        }
        else
        {
            schedule[i].timeSlotIndex = -1;
        }
    }
}
