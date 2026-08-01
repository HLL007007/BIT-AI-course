#include <stdio.h>

void printBracket(int index, char* result, int left, int right);

int main()
{	int n;
	char result[100];
	scanf("%d", &n);
	printBracket(0, result, n, n);
	return 0;
}

void printBracket(int index, char* result, int left, int right){
	if (left == 0 && right == 0){
		result[index] = '\0';
		printf("%s\n",result);
		return ;
	}
	if (left > 0){
		result[index] = '{';
		printBracket(index + 1, result, left - 1, right);
	}
	if (right > left){
		result[index] = '}';
		printBracket(index + 1, result, left, right - 1);
	}
}
