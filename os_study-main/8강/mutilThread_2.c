# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

int sum;                   
void *runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid; // thread id
    pthread_attr_t attr; // thread attribute

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    //자바에서는 new Thread().start() 와 동일
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
    //runner가 다 돌고나면 sum 출력
}
void *runner(void *param) //argv[1] 인가로 넘어옴
{
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++) //1부터 upper까지 더함
        sum += i;
    pthread_exit(0);
}