#include "Conflict.h"
#include <stdio.h>
#include <string.h>

#define CONFLICT_FILE "backend/data/conflict.txt"

void InputConflicts(
    Graph &graph,
    Course courses[],
    int nCourse
)
{
    FILE *file = fopen(CONFLICT_FILE, "r");

    if (file == NULL)
    {
        printf("Khong mo duoc file conflict.txt!\n");
        return;
    }

    char course1[50];
    char course2[50];

    while (fscanf(file, "%49[^,],%49[^\n]\n",
                  course1,
                  course2) == 2)
    {
        int u = -1;
        int v = -1;

        // Tim vi tri cua mon thu nhat
        for (int i = 0; i < nCourse; i++)
        {
            if (strcmp(courses[i].name, course1) == 0)
            {
                u = i;
                break;
            }
        }

        // Tim vi tri cua mon thu hai
        for (int i = 0; i < nCourse; i++)
        {
            if (strcmp(courses[i].name, course2) == 0)
            {
                v = i;
                break;
            }
        }

        // Neu tim thay ca hai mon
        if (u != -1 && v != -1)
        {
            AddEdge(graph, u, v);
        }
    }

    fclose(file);
}