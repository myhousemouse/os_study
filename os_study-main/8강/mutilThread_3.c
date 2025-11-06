pid_t pid;
pid = fork();
if (pid == 0) {
    fork();
    thread_create(&tid, NULL, runner, argv[1]);
}
fork();

// 유니크한 프로세스는 몇개 생성 -> 6개
// 유니크한 쓰레드는 몇개 생성 -> 2개 (8개 = 6+2, 프로세스도 쓰레드로 해석할수있음)
// 추후 문제 다시 풀어보기