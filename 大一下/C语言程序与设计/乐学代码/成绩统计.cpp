# include <stdio.h>

typedef struct {
    char name[20];
    int score[4];
} Student;

int main(){
    Student students[4] = {
        {"wanglei", {78, 90, 87, 92}},
        {"lihong", {88, 91, 89, 78}},
        {"zhangli", {84, 76, 83, 75}},
        {"liuming", {88, 90, 71, 83}}
    };
    for (int i = 0; i < 4; i++){
        printf("%s,", students[i].name);
        int sum = 0;
        for (int j = 0; j < 4; j++){
            sum += students[i].score[j];
        }
        if (sum % 4 == 0){
            printf("%d", sum / 4);
        }
        else {
            printf("%.2f", sum / 4.0);
        }
        printf("\n");
    }
    printf("AVERAGE:");
    for (int j = 0; j < 4; j++){
        int sum = 0;
        for (int i = 0; i < 4; i++){
            sum += students[i].score[j];
        }
        if (sum % 4 == 0){
            printf("%d", sum / 4);
        }
        else {
            printf("%.2f", sum / 4.0);
        }
        if (j < 3) {
            printf(",");
        }
    }
    printf("\n");
}