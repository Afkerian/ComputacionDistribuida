#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Ejercicio 1 FORKs\n");
    printf("Inicio del Programa %d \n", getpid());//Esto solo lo ejecuta el padre

    pid_t pid;

    pid = fork();//El hijo empieza su ejecucion desde este punto

    if(pid == 0){
        printf("Soy el HIJO con PID es %d y mi padre con PID %d \n",getpid(),getppid());
    }else{
        printf("Soy el PADRE con PID es %d y mi hijo tiene PID %d \n", getpid(),pid);
    }
    printf("Fin del programa \n\n");//Lo ejecuta tanto el padre como el hijo
    return 0;
}