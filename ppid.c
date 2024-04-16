#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
void main(void)
{
    pid_t my_pid;

    my_pid = getppid();
    printf("%u\n", my_pid);
}
