#include <stdio.h>

/*
    
*/

void inp(int rows, int cols, int arr[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Enter value at row %d and coloumn %d\n", i, j);
            int t;
            scanf("%d", &t);
            arr[i][j] = t;
        }
    }
    printf("\n");
}

void disp(int rows, int cols, int arr[rows][cols]){ //display matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void compact(int rows, int cols, int arr[rows][cols], int cp[rows][3]){
    cp[0][0] = rows;
    cp[0][1] = cols;
    int k = 1;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] != 0){
                cp[k][0] = i;
                cp[k][1] = j;
                cp[k][2] = arr[i][j];
                k++;
            }
        }
    }

    cp[0][2] = k - 1;
}

void transpose(int rows, int cp[rows][3], int s[rows][3]){
    int m = cp[0][0];
    int n = cp[0][1];
    int t = cp[0][2];

    if(t <= 0){
        return;
    }
    
    for(int col = 0; col < n; col++){

    }

}

int main(){
    printf("Hello World\n"); //Test start of program

    printf("Enter numbers of rows\n");
    int rows;
    scanf("%d", &rows);

    printf("Enter numbers of coloumns\n");
    int cols;
    scanf("%d", &cols);

    int a[rows][cols];
    inp(rows, cols, a);
    disp(rows, cols, a);

    int cp[rows][3];
    compact(rows, cols, a, cp);
    disp(cp[0][2] + 1, 3, cp);

    int t[cp[0][2] + 1][3];
    transpose(cp[0][2] + 1, cp, t);

    disp(t[0][2] + 1, 3, t);

    return(0);
}
