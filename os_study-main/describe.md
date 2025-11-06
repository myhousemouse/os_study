- 2강
    - Operating System 운영체제
        - 하드웨어를 관리하는 소프트웨어
    - 컴퓨터 시스템의 4가지 구성요소
        - 하드웨어
        - 운영체제
        - 응용프로그램
        - 사용자
    - 운영체제의 핵심 - kernel
    - 현대의 컴퓨터 시스템
        - CPU - disk Controller - … bus로 통한다
    - bootstrap 프로그램
        - 부팅용 프로그램
        - 파워온 되자마자 바로 실행하는 프로그램
            - 특히 커널을 로딩하는 역할(메모리에 로딩하는)
    - Interrupts
        - CPU ↔ I/O device 통신하는 방법 중 하나
        - 하드웨어의 트리거 → 시스템 버스로 전송
    - 폰노이만 아키텍처 (1강에 있음)
        - fetch - execute - IR - ALU
    - storage 는 계층적 구조
        - 레지스터 →캐시 →메인 메모리 → SSD→ HDD→ 옵티컬 디스크 →마그네틱 테이프
    - I/O structure
        - 인풋 아웃풋을 처리하기 위해서
    - 컴퓨터 시스템 구성요소
        - CPU
        - Processor
        - Core
        - Multicore
            - cpu를 많이 다는건 비싸니까, core를 여러개
            - 듀얼코어, 쿼드코어…
        - Multiprocessor
            - 멀티코어가 여러개 붙은 것
        - SMP(semetric multi processing)
        - Multiprogramming
            - 메모리에 여러개의 프로그램을 동시에 올리기
            - CPU사용 효율 올리기
            - = 멀티태스킹
            - 하나의 CPU로 word, ppt 동시에 사용
            - cpu가 놀고 있을때 → 남은 자리를 cpu 스케줄링이 자리 잡아줌
    - 운영체제의 2가지 분리
        - 유저모드
        - 커널모드
            - 직접적인 하드웨어 제어
    - Virtualization
        - VMM (VMware, Xen …)
        - 여러개의 OS를 돌릴 수 있음
    - 컴퓨팅 환경의 다양성
        - 모바일 컴퓨팅
        - 클라이언트-서버 컴퓨팅
        - P2P 컴퓨팅
        - 클라우드 컴퓨팅
        - 리얼타임 임베디드 시스템 (RTOS)
    - OS 인터페이스
        - CLI (shell:bash,csh,zsh etc)
        - GUI(window, mac etc)
        - 터치 스크린(android , iphone etc)
    - OS ↔ 응용 프로그램
        - System Calls
            - = API (OS의 API가 시스템 콜)
    - 
- 3강: 프로세스가 무엇인지
    - 프로세스 : 실행중인 프로그램
        - 프로세스가 실행중인 프로그램의 단위
        - CPU - memory 에서 하나씩 해체해서 패치하는 것 = CPU를 점령해야 excute됨
            - text section
                - 명령어들이 있는 코드
            - data section
                - 전역변수 저장
            - heap section
                - 메모리 할당
            - stack section
                - 함수 호출
                - 리턴주소, 지역변수
        - 프로세스를 실행에 따른 상태 변화
            - new
                - created된 상태
            - running
                - cpu 점유하고 있는 상태
            - waiting
                - cpu 대기상태(일 안끝났음)
            - ready
                - 레디큐에서 점유 준비 (준비대기상태)
                - cpu 스케줄러가 레디→러닝으로 갈때를 **디스패치**라고 함
            - terminated
                - 다 끝난상태
            
        - 프로세스를 어떻게 관리하는가?
            - PCB(Process Control Block) or TCB(Task Control Block)
                - 이 구조체에 필요한 프로세스 정보 다 넣는다
                - 프로세스 상태(위 5가지)
                - 프로그램 카운터
                    - (프로그램 카운터 레지스터에 있는)메모리에 있는 명령어 패치 해야함
                - CPU 레지스터 (=문맥 컨텍스트)
                - CPU 스케줄링 정보
                - 메모리 관리 정보
                - 계정 정보
                - I/O 상태
        - 싱글 스레드
            - 요즘엔 다 멀티 스레드
    - 프로세스 스케줄링
        - 멀티프로그래밍의 목적
            - CPU 사용성 최대화
        - 타임 쉐어링의 목적
            - CPU core switch 상호작용
        - 스케줄링 큐 (큐: PIPO)
            - CPU를 스케줄링
        - 문맥 교환
            - 문맥:프로세스 입장에서 프로세스가 사용되고 있는 상황 → PCB에 저장중 == 즉, 운영체제 입장에서 PCB 정보가 문맥이다
    - OS 메커니즘 제공
        - 프로세스 생성
        - 프로세스의 트리구조
            - fork() 시스템 코어 사용
    
- 4강. operations on processes
    - 유닉스
        - fork()  시스템 콜
        - child process : 부모 주소공간의 카피
            - fork() 리턴값 0 → 자식
            - fork() 리턴값 pid → 부모
        - fork() 시스템 콜 이후
            - 자식이 구동 중 → 부모는 시스템 콜에서 wait() 상태, 레디큐에서 웨이트 큐에서 interrupt걸길 기다리는 것
    - 프로세스라는 것은 a program in execution process
    os 스케줄러 즉, cpu 스케줄러가 프로세스들을 여러 멀티프로그램으로 same time 동시에 concurrent하게 실행시키기 위해서 → time sharing을 한다.
    - cpu는 이를 위해 컨텍스트 스위치를(프로그램 카운더나 인스트럭터 레지스터, 정보 저장 복원 등) 진행하는데, 이를 위해서는 동기화를 잘 진행해주어야 한다.
- 5강. 프로세스간 통신(IPC)
    - processes executing concurrently
        - 프로세스가 독립적
            - 프로세스 간 공유하는 데이터 없음
        - 프로세스 간 협력
            - 프로세스 간 어떻게 영향을 주고 받을지
            - 프로세스 간 공유하는 데이터
    - IPC(Inter-Process Communication)
        - 프로세스간 통신문제 발생 → 데이터를 서로 주고 받는것
        1. 공유 메모리 사용 방법 (공유 공간 사용)
            1. 생산자 소비자 문제
                1. 생산자:정보 생산, 소비자: 정보 소비
                2. 생산자 서버 ↔ 소비자 서버 (concurrently하게 돌아감)
                3. buffer - 생산자는 보내고싶은것을 버퍼에 채우고 소비자는 버퍼에 있는것을 소비함
                    1. buffer → 바운디드 버퍼(무한X)
                    2. 꽉차면 wait, 비어있어도 wait
                    3. ex) 컴파일러(생산)는 어셈블리어 제작, 어셈블리어(생산)는 loader 넘겨주고
                    4. ex) 웹서버(생산) → HTML제작, 브라우저(소비)는 HTML을소비
        2. 메시지 주고 받는 방법(message - passing)
            1. os가 코퍼레이팅 프로세스들(데이터 공유하는)에게 api제공
            2. 생산자 → 소비자 다이렉트로 메시지 보내겠다
                1. 보내고 받고 하는 시스템콜 두개만 있으면 된다
                
                1. direct / indirect 방법
                    - direct
                    1. send, receive 명시해야 함
                    2. 커뮤니케이션 링크는 자동적으로 생성(누가 누구한테 주는지 아니까) 
                    - indirect
                    1. mailbox / **ports** 통해 전송 및 수신이 가능
                    2. 메일박스(포트)를 사용해야 링크가 생성
                    3. 여러생성자, 여러소비자여도 문제가 없음
                    4. os는 메일박스(create,send,receive,delete)만 하면 됨
                    
                2. synchronous / asynchronus(아무때나)
                    - blocking / non-blocking
                        - synchronous(동기화)
                            1. if 소비자가 0원이면 지급, 0원 아니면 지급x
                            2. blocking : 메시지를 다 받을때까지 보내는사람 막기
                            3. blocking receive : 메시지 다 사용이 될때까지 받는사람 막기
                        - asynchronus
                            1. non-blocking : 메시지 연속해서 전달
                            2. non-blocking receive : 어떤 메시지를 받던 할일 계속 함
                3. automatic / explicit(명시적 지정) buffering
                
        
- 6강. IPC의 실습
    - Shared Memory : POSIX(Potable Operation System Interface for uniX) Shared Memory
        - memory mapped file 이용 (메모리에서 파일을 사용) 이를 shared memory에 매핑시켜 사용
    - Message Passing : Pipes
        - 두개의 프로세스가 커뮤니케이션하는 방식처럼 구동
            - unidirectional → one way (한개)
            - 왔다 갔다 가능 → two way (두개)
        - ordinary : 생산자 → 쓰기 / 소비자 → 읽기
    - Sockets : 컴퓨터간 통신을 위해 각 컴퓨터의 identification 은 ip 주소다, 컴퓨터 간 연결된 파이프는 포트다. 이들을 ip주소와 포트를 묶은것이 소켓이다.
        - 자바로 구현 가능
            - 서버 소켓 (TCP) : 연결 지향
            - 데이터그램 소켓(UDP) : 연결 지양 → 방송, 브로드캐스팅
            - 멀티 캐스트 소켓: 특정 recipient에게만 방송
    - RPCs(Remote Procedures Calls) : 원격 호출을 추상화한다.
        - 자바 → RMI …
        - 고급 엔터프라이즈 환경에서 자주 씀, 현재 구현하기엔 너무 복잡한 내용
        - 클라이언트에게 stub 제공
- 7강. 쓰레드의 이해
    - 쓰레드
        - code하고 data영역을 공유
        - lightweight process
        - CPU 유틸의 기본 유닛
            - CPU를 점유하는 단위
            - PID 안 tid(thread ID)가 CPU를 점유하는 것
        - PC(프로그램 카운터), register set, stack도 tid에 따라 달라져야 함
    - 멀티쓰레딩
        - Responsiveness : non-blocking으로 계속 실행할수있음
        - Resource Sharing
        - 코드와 데이터 영역을 공유하기 때문에 shared memory처럼 사용가능 → 리소스 사용에 자유로움
        - Economy : PCB(컨텍스트 스위칭)보다 쉬움
        - Scalability: 멀티프로세서 아키텍처 병렬처리로 확장성 높음
    - 자바에서 쓰레드
        - JVM이 쓰레드 기반 모델
        - 쓰레드 생성과 관리가 쉽다
        - 사용방법
            - 쓰레드 클래스 상속받기
                - public void run() 오버라이드
            - Implementing
                - runnable 인터페이스를 implementgks 클래스를 오버라이딩
            - 익명쓰레드(Lambda express)
                - 새로운 클래스 정의하지말고 람다 익스프레션으로 사용
    - 멀티코어 프로그래밍
        - 싱글 스레드 → 인터리브(사이사이 끼워놓는다)
        - 멀티 스레드 → 병렬처리
        - 문제점
            - separate tasks를 확인할수있어야 함
            - 밸런스:동등하게 데이터 쪼개서 일시키기
            - 데이터 쪼개기
            - 데이터 의존성 고려 (task 동기화 등)
            - 테스트 및 디버깅
        - 암달의 법칙
            - CPU코어가 많으면 많을수록 좋은건 아니다!
    
- 8강.멀티쓰레딩
    
    종류
    
    - 유저 쓰레드 → 사용자 모드
        - 네이티브 쓰레드
        - 유저모드 위에서 쓰레드 사용
    - 커널 쓰레드
        - 직접 manage함
    - 유저쓰레드 ↔ 커널쓰레드
        - Many to One
        - One to One
        - Many to Many
    - 쓰레드 라이브러리
        - 쓰레드를 매니징하는(생성, 종료, 슬립 등)
        - POSIX 피스레드
        - 윈도우 쓰레드
        - 자바 쓰레드 → JVM이기에 운영체제에 종속적
    - Implicit 쓰레딩
        - 자바 pthread → excutor 프레임워크를 사용하는 것과 같음
        - 동시성과 페러럴한 디자인이다.
        - 쓰레드 풀
            - 여러개 쓰레드를 풀에 저장하고 필요하면 풀에서 꺼내다가 쓴다.
        - 포크 앤 조인 (=create 쓰레드)
        - OpenMP
            - c,c++에서 병렬처리를 할수있도록
            - 페러렐 리전만 지정 → 코드 블록이 패밀리처럼 알아서 실행되지않는가?
                - 컴파일러에게 지시함 → 해당 리전만 병렬로 쓰레드 만듬
                
                <img width="1592" height="580" alt="image" src="https://github.com/user-attachments/assets/c3d121e2-ded4-4227-b17f-7f3fecd1d2fc" />

                
        - GDC
            - mac os에서 사용
