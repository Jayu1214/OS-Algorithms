
#include <stdio.h>

void fwt(int n, int at[], int bt[], int wt[]) {
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0; // waiting time for first process is 0

    // calculating waiting time
    for (int i = 1; i < n; i++) {
        // Add burst time of previous processes
        service_time[i] = service_time[i-1] + bt[i-1];

        // Find waiting time for current process
        wt[i] = service_time[i] - at[i];

        // If waiting time for a process is in negative
        // that means it is already in the ready queue before CPU becomes idle
        // so its waiting time is 0
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void ftat(int n, int bt[], int wt[], int tat[]) {
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void fat(int n, int at[], int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    fwt(n, at, bt, wt);

    // Function to find turn around time for all processes
    ftat(n, bt, wt, tat);

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average burst time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], arrival_time[n], burst_time[n];

    for(int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Assigning process ID
    }

    fat(n, arrival_time, burst_time);
    return 0;
}
