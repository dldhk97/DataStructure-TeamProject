# DataStructure-TeamProject

## Purpose
* **자료구조 조별과제**를 위한 레포지토리입니다.
* **정렬 알고리즘**을 구현하여 각 특징에 대하여 알아보기 위함입니다.

## Goal
* 동일한 조건에서 각 알고리즘들의 시간복잡도 등의 차이를 비교하고 **성능 검증**을 합니다.
* 직접 만든 알고리즘의 성능이 이론상의 성능에 가깝게 하는 것이 목표입니다.

------------------------------

## Project Original Text

### 정렬 과제 - 제출방식
#### 4명까지 한 팀을 이루어 과제 수행
* 분반간 팀 구성 가능, 재수강생은 재수강생끼리 팀구성, 1~3인팀 허용
  * 예외적인 경우 허용할 수 있으니 교수에게 문의할 것
* .hwp 파일(1개)와 폴더 2개 압축하여 제출
  * .hwp 파일에는 문제풀이와 (정렬 프로그램) 결과 분석을 포함
  * 폴더에는 정렬 프로그램 code를 포함
    * 1번과 2번 문제별로 폴더 구성하면 됨
    * source code만 포함할 것 (.cpp .h, .java. 필요하다면 README.txt )
   
#### 제출 방법
* 팀 구성 내역은 팀장이 elearning의 “정렬과제. 팀등록게시판”에 남길 것
  * 1인 팀도 반드시 남길 것
* 과제 결과물은 강의지원시스템에 6/2(일) 23:00까지 upload
  * 팀 대표자 1인만 upload하면 됨
 * 첫 페이지에 과제에 충분히 참가한 팀원 이름만 작성할 것
 
### 정렬 과제 – 문제풀이

* **stable sort란 동일한 값이 정렬 대상 배열에 들어가 있을 때, 정렬이 종료 되었을 때, 원 배열의 순서대로 정렬 결과에 값들이 저장되는 정렬 방식**
  * insertion, merge, radix sort는 stable함.
  * selection, shell, quick, heap sort는 non-stable함.
* **stable한 sort는 어떻게 stable한 결과를 보일 수 있는지 알고리즘을 기반으로 대략적으로 설명하시오.**
* **non-stable한 sort는 stable하지 않은 예제를 보여 stable 하지 않음을 보이시오.**

### 정렬 과제 – 프로그래밍(1)
* **아래 각 정렬 방식에 대해서**
  * 삽입정렬, 이원삽입정렬, 연결삽입정렬, 쉘정렬(shell size는 각팀에서 결정)
  * 첫번째 값을 pivot으로 삼는 recursive quick sort
  median of three를 pivot으로 삼는 recursive quick sort,
  median of three를 pivot으로 삼는 non-recursive quick sort(직접 stack을 구현하여 sort)
  * recursive merge sort, non-recursive merge sort, natural merge sort
  * heap sort, bubble sort, selection sort
  * Java나 C++에서 제공하는 std::sort나 Arrays.sort, Collections.sort
* **아래 자료형을 가지는**
  * int, double, string, class Rectangle
    * Rectangle은 너비/높이를 data로 가지며 면적을 기준으로 정렬. 면적을 미리 저장하지 말고,
    정렬시 매번 계산하도록 할 것(C++에서는 < 또는 <= 에 대한 operator overloading을 구현,
    Java에서는 CompareTo를 구현하고, 각 함수 안에서 면적 구하는 함수를 호출하게 구현할 것)
* **아래 각 배열에 대해서**
  * random value / increase order value / decrease order value
* **충분히 큰 n의 5개 이상의 값에 대해서**
* **수행 시간의 성능을 비교하시오.**
  * 한 알고리즘에서 각 자료형과 random/increasing/decreasing 에 대해서, n에 대해서 비교
  * 각기 다른 알고리즘 간에 대해서도 비교
  * 속도 측정의 기준에 대해서 μ-sec로 할지 clock rate로 할지는 각 팀에서 알아서 결정
  
### 정렬 과제 – 프로그래밍(2)
* **comparison based v.s. non-comparison based & arithmetic operation v.s. logical operation**
  * 0~216-1 범위의 충분히 큰 random unsigned int 배열을 생성하고
  * 아래 각 방식에 의한 정렬의 속도를 비교할 것
    * 1) modular 연산(%) 으로 16진수 LSB 값을 얻어 정렬하는 radix sort
    * 2) masking(&)과 shift 연산(>>)연산으로 16진수 LSB값을 얻어 정렬하는 radix sort
    * 3) modular 연산(%) 으로 10진수 LSB 값을 얻어 정렬하는 radix sort
    * 4) 팀에서 만든 sort 중 random int에 대해서 제일 좋은 효율을 낸 것
  * 위 문제는 다양한 n에 대해서는 시행하지 않아도 됨
* **유의점**
  * 각 code가 어느 정렬에 해당하는지 알아보기 쉽게 함수를 구성하고, naming을 하고, 적절하게 주석을 작성할 것
* 한 실행파일에서 각 입력 유형과 크기에 따라 각 정렬 방식을 구동하고 그 결과를 알아보기 쉽게 출력하도록 구성할 것
* 입력을 file으로 만들었으면 file도 같이 제출 할 것(file에서 입력 읽는 방식은 권장하지 않음)
