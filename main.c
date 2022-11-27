#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void selection() {

    int array[25];
    srand((unsigned)time( NULL )); //초기화
    for (int i = 0; i < 25; i++) { // 25번 반복
        array[i] = rand() % 100; // 0부텨 100까지 중 난수 생성

    }
    printf("정렬하기전: ");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    {
        printf("%d ", array[i]);// 배열의 인덱스에 반복문의 변수 i를 지정
    }
    printf("\n");
    int temp = 0;


    //오름차순 (작은 수 -> 큰 수)
    int Min = 0;
    for (int i = 0; i < 25 ; i++)
    {

        Min = i;
        for (int j = i + 1; j < 25; j++)
        {
            if (array[j] < array[Min])
            {    //data[Min]을 기준으로 data[j]를 검사한다.
                //data[Min]의 값 보다 작은 값을 발견한다면 Min = j가 된다.
                Min = j;
            }
        }
        // for문을 반복, 가장 작은 값을 찾으면 순서를 바꾼다.
        temp= array[Min];
        array[Min]= array[i];
        array[i]= temp;
    }



    //오름차순으로 출력
    printf("정렬한 후: ");
    for (int i = 0; i < 25; i++)
    {
        printf("%d ", array[i]);
    }

}
void insertion() {

    int array[25];
    int temp;
    srand((unsigned)time( NULL )); //초기화
    for (int i = 0; i < 25; i++) { // 25번 반복
        array[i] = rand() % 100; // 0부텨 100까지 중 난수 생성

    }
    printf("정렬하기전: ");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    {
        printf("%d ", array[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
    }


    for(int k=0;k<25;k++){
        int j=k-1;
        while((array[j] > array[j+1])&&(j>=0)){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            j--;
        }
    }
    printf("\n정렬한후: ");
    for (int i = 0; i < 25; i++) {
        printf("%d ", array[i]);
    }
}
void bubble() {

    int array[25];
    srand((unsigned) time(NULL)); //초기화
    for (int i = 0; i < 25; i++) { // 25번 반복
        array[i] = rand() % 100; // 0부텨 100까지 중 난수 생성

    }
    printf("정렬하기전: ");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    {
        printf("%d ", array[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
    }

    // 1~20의 숫자를 랜덤하게 가지는 배열


    //temp 변수는 데이터를 교환할때 쓸 임시 변수이다.
    int temp = 0;



    //오름차순 정렬
    for (int k = 0; k < 25 - 1; k++) {
        for (int j = 0; j < 25 - 1 - k; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    //오름차순 정렬된 출력
    printf("\n정렬한후: ");
    for (int i = 0; i < 25; i++) {
        printf("%d ", array[i]);
    }
}
void merge(int a[], int low, int mid, int hight)    //분리된 배열 정렬 및 병합 함수
    {
        int b[25];
        int i = low;        //왼쪽 시작
        int j = mid + 1;    //오른쪽 시작
        int k = 0;          //배열 b의 인덱스 값

        while(i <= mid && j <= hight)
        {
            if(a[i] <= a[j])        //분리된 왼쪽 배열과 오른쪽 배열 비교
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i <= mid)             //비교하지 않은 왼쪽 배열이 있다면 배열 b에 전부 채우기
            b[k++] = a[i++];
        while(j <= hight)           //비교하지 않은 오른쪽 배열이 있다면 배열 b에 전부 채우기
            b[k++] = a[j++];
        k--;

        while(k >= 0)               //배열 b 내용을 배열 a 내용에 덮어쓰기
        {
            a[low + k] = b[k];
            k--;
        }
    }
    void mergeSort(int a[], int low, int hight)    //배열의 요소를 분할하는 함수
    {

        int mid;
        if(low < hight)
        {
            mid = (low + hight) / 2;
            mergeSort(a, low, mid);            //왼쪽 배열의 요소 분리
            mergeSort(a, mid + 1, hight);      //오른쪽 배열의 요소 분리
            merge(a, low, mid, hight);         //분리된 배열 정렬 및 병합 함수
        }
    }
    void heap() {
    int j;
    int array[25];
    srand((unsigned) time(NULL)); //초기화
    for (int i = 0; i < 25; i++) { // 25번 반복
        array[i] = rand() % 100; // 0부텨 100까지 중 난수 생성

    }
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    {
        printf("%d ", array[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
    }
    printf("\n");



    //전체 트리 구조를 최대 힙으로 구성
    for (j = 1; j < 25; j++) {
        int c = j;

        do {
            int root = (c - 1) / 2;
            if (array[root] < array[c]) {
                int tmp = array[root];
                array[root] = array[c];
                array[c] = tmp;
            }
            c = root;
        } while (c != 0);
    }

    //크기를 줄이면서 반복적으로 힙을 구성
    for (j = 25 - 1; j >= 0; j--) {
        //루트 노드와 트리의 마지막 노드를 교환한다.
        int tmp = array[0];
        array[0] = array[j];
        array[j] = tmp;

        //Heap 구조를 구성

        int root = 0;
        int c = 1;

        do {
            c = 2 * root + 1;

            //자식 노드 중에 더 큰 값을 찾기
            if (array[c] < array[c + 1] && c < j - 1) {
                c++;
            }
            //루트보다 자식 노드가 더 크다면 교환
            if (array[root] < array[c] && c < j) {
                int tmp = array[root];
                array[root] = array[c];
                array[c] = tmp;
            }
            root = c;
        } while (c < j);
    }

    for (j = 0; j < 25; j++) {
        printf("%d ", array[j]);
    }
}


void quick(int array[], int L, int R) {
    int left = L, right = R;
    int pivot = array[(L + R) / 2];    // pivot은 가운데 기준
    int temp;
    do
    {
        while (array[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지
            left++;
        while (array[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지
            right--;
        if (left<= right)    // left가 right보다 왼쪽에 있다면 교환
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            //left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동
            left++;
            right--;
        }
    } while (left<= right);    // left가 right 보다 오른쪽에 있을 때까지 반복

    /* recursion */
    if (L < right)
        quick(array, L, right);    // 왼쪽 배열 반복

    if (left < R)
        quick(array, left, R);    // 오른쪽 배열 반복
}



void first_screen() {
    printf("***************************\n");
    printf("**** 여러가지 정렬 프로그램! ****\n");
    printf("**** 1.선택 정렬         ****\n");
    printf("**** 2.삽입 정렬         ****\n");
    printf("**** 3.버블 정렬         ****\n");
    printf("**** 4.퀵 정렬          ****\n");
    printf("**** 5.합병 정렬         ****\n");
    printf("**** 6.힙 정렬          ****\n");
    printf("**** 7.종료             ****\n");

}

int main() {
    first_screen();
    for(;;){
        int select;
        back:
        scanf("%d",&select);
        switch (select) {
            case 1:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   선택정렬 선택       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(•◡•) /\n");
                printf("/      /\n");
                selection();
                printf("\n");
                break;
            case 2:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   삽입정렬 선택       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(^-^) /\n");
                printf("/      /\n");
                insertion();
                printf("\n");
                break;

            case 3:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   버블정렬 선택       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(^-^) /\n");
                printf("/      /\n");
                bubble();
                printf("\n");
                break;
            case 4:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   퀵정렬 선택!       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(^-^) /\n");
                printf("/      /\n");
                int array[25];
                srand((unsigned) time(NULL)); //초기화
                for (int i = 0; i < 25; i++) { // 25번 반복
                    array[i] = rand() % 100; // 0부텨 100까지 중 난수 생성

                }
                printf("정렬하기전: ");
                for (int i = 0; i < sizeof(array) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
                {
                    printf("%d ", array[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
                }
                printf("\n");

                quick(array, 0, 25-1);

                printf("정렬 후 : ");
                for(int i=0; i<25; i++){
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 5:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   합병정렬 선택       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(^-^) /\n");
                printf("/      /\n");
                int arr[25];
                srand((unsigned) time(NULL)); //초기화
                for (int i = 0; i < 25; i++) { // 25번 반복
                    arr[i] = rand() % 100; // 0부텨 100까지 중 난수 생성

                }
                printf("정렬하기전: ");
                for (int i = 0; i < sizeof(arr) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
                {
                    printf("%d ", arr[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
                }
                mergeSort(arr, 0, 25 -1);
                printf("\n");
                printf("정렬한 후: ");
                for(int i = 0; i < 25; i++)
                    printf("%d ", arr[i]);
                    printf("\n");
                    break;
            case 6:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   힙정렬 선택!       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(^-^) /\n");
                printf("/      /\n");
                heap();
                printf("\n");
                break;
            case 7:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   종료를 선택!       |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(ㅇ-ㅇ) /\n");
                printf("/      /\n");
                printf("잘가!");
                exit(1);
            default:
                printf("|￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
                printf("|   잘못된 숫자입력     |\n");
                printf("|＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
                printf(" /(ㅠ-ㅠ) /\n");
                printf("/      /\n");
                goto back;
        }

    }
}