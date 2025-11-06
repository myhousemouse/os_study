# include <stdio.h>
# include <omp.h>

int main(int argc, char *argv[])
{
    omp_set_num_threads(4); //4개의 쓰레드 사용
    #pragma omp parallel //블록 지정
    {
        printf("i am a parallel region from thread %d\n", omp_get_thread_num()); //4개의 쓰레드가
        //parallel 하게 돌려주세요
    }
    return 0;
}