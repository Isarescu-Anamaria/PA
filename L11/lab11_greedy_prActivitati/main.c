/*#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int t_start;
    int t_final;
    char nume[30];
}Date_intrare;

int main()
{
    FILE* f = fopen("in.txt","r");
    if(f == NULL)
    {
        printf("Nu exista date in fisier");
        return -1;
    }
    Date_intrare v[100];
    int i = 0;
    while(fscanf(f,"%d %d %s",v[i].t_start,v[i].t_final,v[i].nume) == 3)
    {
        printf("Activitatea %s incepe la &d si se termina la %d:\n",v[i].nume,v[i].t_start,v[i].t_final);
        i++;
    }
    return 0;
}
*/
#include <stdio.h>

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int s[], int f[], char nume[6][20], int n)
{
    int i, j;

    printf("Following activities are selected\n");

    // The first activity always gets selected
    i = 0;
    printf("%s ", nume[i]);

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (s[j] >= f[i]) {
            printf("%s ", nume[j]);
            i = j;
        }
    }
}

// Driver code
int main()
{
    int s[] = { 1, 3, 0, 5, 8, 5 };
    int f[] = { 2, 4, 6, 7, 9, 9 };
    char nume[6][20] = {"balet", "pictat", "cantat", "scris", "citit","alergat"};
    int n = sizeof(s) / sizeof(s[0]);

    // Function call
    printMaxActivities(s, f, nume, n);
    return 0;
}
