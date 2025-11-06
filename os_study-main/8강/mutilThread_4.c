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
    pthread_attr_t attr; // thread attribute

    pid = fork();

    if (pid == 0) { // Child process
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, argv[1]);
        //create 하는 순간 runner 실행됨
        pthread_join(tid, NULL);
        printf("Child Process: value = %d\n", value);
        //runner가 다 돌고나면 value 5 출력
    }   
    else if (pid > 0) {
        wait(NULL); // wait for child process to finish
        printf("Parent Process: value = %d\n", value);
        // Child process가 바꾼 value 0 출력
    }
}
void *runner(void *param) //argv[1] 인가로 넘어옴
{
    value = 5;
    pthread_exit(0);
}