/*
This program creates a given number of child processes and sets 
their burst times in increasing order so that the first created child process
is finished and exited first, then the second one created is exited next,
and so on.

Usage: foo n
where n = number of child processes to be forked
*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


// Add delay to consume CPU time
void CPU_delay(int count)
{
    int i;
    int j, k;
    int *data;

    data = (int *)malloc(sizeof(int) * 1024 * 10);
    if (data <= 0)
        printf(1, "Error on memory allocation \n");

    for (i = 0; i < count; i++)
    {
        for (k = 0; k < 5700; k++)
            for (j = 0; j < 1024 * 10; j++)
                data[j]++;
    }
}

// Using sleep to replicate I/O interrupt
void io_bound_delay(){
    for(int i=0;i<200;i++){
        printf(1,"I/O interrupt\n");
    }
    sleep(5);
}

int main(int argc, char *argv[])
{
    // Check if program is called correctly
    if (argc < 2)
    {
        printf(1, "test-case <number-of-children>\n");
        exit();
    }
    
    // Number of child processes to be made
    int N = atoi(argv[1]);

    int pids[N];
    int retorder[N];
    set_burst_time(2); //Set burst time of parent process = 2
    printf(1, "Burst time of parent process = %d\n", get_burst_time());

    for (int i = 0; i < N; i++)
    {
        // Change burst time for each child process
        int burst_time = 2*(i+2);

        int cpid = fork();
        
        // if cpid == 0 then control is with the child process
        if (cpid == 0)
        {
            set_burst_time(burst_time);
            printf(1, "Pid: %d    Burst_Time: %d\n", getpid(), get_burst_time());
            // Uncomment for CPU interrupt
            CPU_delay(20);
            // Uncomment for I/O interrupt
            // io_bound_delay();
            exit();
        }
        else if (cpid > 0)
        {
            pids[i] = cpid;
        }
        else
        {
            printf(1, "fork error \n");
            exit();
        }
    }

    // store order of processes as they exit
    for (int i = 0; i < N; i++)
    {
        retorder[i] = wait();
    }

    printf(1, "\nExecution of all children completed!\n");
    for (int i = 0; i < N; i++)
        printf(1, "Child No. %d.    Pid: %d\n", i, pids[i]);

    printf(1, "\nExit order of Processes:-\n");
    for (int i = 0; i < N; i++){
        printf(1, "Pid: %d\n", retorder[i]);   
    }

    exit();
}
