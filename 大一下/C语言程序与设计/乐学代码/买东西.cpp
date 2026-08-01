#include <stdio.h>  
  
typedef struct buy  
{  char  gname;  
   int   sname;  
   int   gprice;  
} BUY;  
int main( )  
{  int i, j, n;  
   int min, price[10][3];  
   int findm( int n, int price[][3], BUY scheme[] );  
  
   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };  
  
   scanf( "%d", &n );  
   for( i = 0; i < n; i++ )  
    for( j = 0; j < 3; j++ )  
       scanf( "%d", &price[i][j] );  
  
   min = findm( n, price, scheme );  
  
   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );  
   for ( i=0; i < 3; i++ )  
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );  
   return 0;  
}  
int findm(int n, int price[][3], BUY scheme[]){
    int min = 0;
    int vis[n];
    for (int i = 0; i < n; i++){
        vis[i] = 0;
    }
    for (int j = 0; j < 3; j++){
        int min_val = 100000;
        int min_index = 0;
        for (int i = 0; i < n; i++){
            if (vis[i]) continue;
            if (price[i][j] < min_val){
                min_val = price[i][j];
                min_index = i;
            }
        }
        vis[min_index] = 1;
        scheme[j].sname = min_index + 1;
        scheme[j].gprice = min_val;
    }
    for (int j = 0; j < 3; j++){
        min += scheme[j].gprice;
    }
    return min;
}