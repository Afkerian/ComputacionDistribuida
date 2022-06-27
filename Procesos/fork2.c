#include<stdio.h>
#include<unistd.h>

int main(){

    printf("Ejercicio 2 FORKs\n");
    int c = 0;

    pid_t pid;
    pid = fork();
    int i = 0;
    while (i<=10)
    {
        /* code */

        if(pid == 0){
            printf("HIJO PID %d con PADRE PID %d\n",getpid(),getppid());
            c--;
            printf("El valor de C = %d \n",c);
        }
        else{
            printf("El valor de C = %d y PPID %d y PID %d\n",c,getpid(),pid);
            c++;
        }
        i++;
    }
    
    return 0;
}