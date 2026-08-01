# include<stdio.h>
typedef struct{
    float scores[4];
    float average;
} Student;
int main(){
    Student students[3];
    int i, j;
    for (i = 0; i < 3; i++){
        students[i].average = 0;
        for (j = 0; j < 4; j++){
            scanf("%f", &students[i].scores[j]);
            students[i].average += students[i].scores[j];
        }
        students[i].average /= 4;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2 - i; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%g", students[i].scores[j]);
            if (j < 3) {
                printf(",");
            }
        }
        printf("\n"); 
    }
}