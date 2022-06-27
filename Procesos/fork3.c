#include<stdio.h>
#include<unistd.h>

int main(){
    
    printf("Ejercicio 3 FORKs\n");
    pid_t pid;
    int procesos = 0;
    for(int i = 0; i<3;i++){
        pid = fork();
        procesos ++;
        if(pid != 0){
            printf("Se esta ejecutando el padre\n");
            printf("PID %d y mi HIJO: %d\n", getpid(),pid);
        }else{
            printf("Se esta ejecutando el hijo\n");
            printf("PPID %d y PID %d \n",getppid(),getpid());
        }

    }

    return 0;
}