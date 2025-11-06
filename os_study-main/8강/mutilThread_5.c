# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>       // 추가: fork()
# include <sys/types.h>    // 추가: pid_t
# include <sys/wait.h> 
# include <pthread.h>

int value;
void *runner(void *param);

int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid; // thread id

    printf("A: %d\n", getpid());
    pid = fork();
    if (pid > 0) {
        wait(NULL);
        printf("B: %d\n", pid);
    }

    if (pid == 0) { // Child process
        pid = fork();
        if (pid > 0) {
            wait(NULL);
            if (pid > 0)
                printf("C: %d\n", pid);
        }
        pthread_create(&tid, NULL, runner, argv[1]);
        //create 하는 순간 runner 실행됨
    }   
    pid = fork();
    if (pid > 0) {
        wait(NULL); // wait for child process to finish
        if (pid > 0)
            printf("D: %d\n", pid);
    }
    return 0;
}
void *runner(void *param) //argv[1] 인가로 넘어옴
{
    value = 5;
    pthread_exit(0);
}