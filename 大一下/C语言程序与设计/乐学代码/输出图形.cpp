# include <stdio.h>

char next_char(char ch){
    return (ch - 'A' + 1) % 26 + 'A';
}
int main(){
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    if (ch < 'A' || ch > 'Z') return 0;
    int cols = 4 * n - 3;
    char grid[n][cols + 1];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < cols; j++){
            grid[i][j] = ' ';
        }
        grid[i][cols] = '\0';
    }
    char current = ch;
    grid[0][0] = current;
    grid[0][cols - 1] = current;
    current = next_char(current);
    for (int i = 1; i < n - 1; i++){
        grid[i][2 * i] = current;
        grid[i][cols - 1 - 2 * i] = current;
        current = next_char(current);
    }
    if (n > 1){
        grid[n - 1][2 * (n - 1)] = current;
        current = next_char(current);
    }
    for (int k = 1; k < n; k++){
        grid[n - 1][2 * (n - 1) + 2 * k] = current;
        grid[n - 1][2 * (n - 1) - 2 * k] = current;
        current = next_char(current);
    }
    for (int r = n - 2; r >= 1; r--) {
            grid[r][0] = current;
            grid[r][cols - 1] = current;
            current = next_char(current);
    }
    for (int i = 0; i < n; i++){
        printf("%s\n",grid[i]);
    }
    return 0;

}