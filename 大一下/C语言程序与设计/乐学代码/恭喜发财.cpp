# include <stdio.h>
# include <string.h>
typedef struct{
    char name[20];
    int money;
}Person;

int find_index(Person people[], int n, char target_name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(people[i].name, target_name) == 0) {
            return i;
        }
    }
    return -1; 
}

int main(){
    int n;
    scanf("%d",&n);
    Person people[n]; 
    for (int i = 0; i < n; i++){
        scanf("%s",people[i].name);
        people[i].money = 0;
    }
    for (int i = 0; i < n; i++){
        char str1[20];
        scanf("%s",str1);
        int idx1 = find_index(people,n,str1);
        int cnt;
        int money;
        scanf("%d %d",&money,&cnt);
        if (cnt > 0){
            int each_give = money / cnt;
            people[idx1].money -= cnt * each_give;
            for (int j = 0; j < cnt; j++){
                char str2[20];
                scanf("%s",str2);
                int idx2 = find_index(people,n,str2);
                people[idx2].money += each_give;
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%s %d\n",people[i].name,people[i].money);
    }
    return 0;
}