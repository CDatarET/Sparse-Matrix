#include <stdio.h>
#define max 100
/*
    Take in a Sparse Matrix as input and perform-
    Display
    Compact form
    Simple Transpose
    Fast Transpose
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

void sTranspose(int cp[][3], int t[][3]){
    int m = cp[0][0];
    int n = cp[0][1];
    int e = cp[0][2];

    t[0][0] = m;
    t[0][1] = n;
    t[0][2] = e;

    if(e <= 0){
        return;
    }

    int q = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= e; j++){
            if(cp[j][1] == i){
                t[q][0] = cp[j][1];
                t[q][1] = cp[j][0];
                t[q][2] = cp[j][2];
                q++;
            }
        }
    }
}

void fTranspose(int cp[][3], int t[][3]) {
    int m = cp[0][0];
    int n = cp[0][1];
    int e = cp[0][2];

    t[0][0] = n;
    t[0][1] = m;
    t[0][2] = e;

    if (e == 0)
        return;

    int count[max] = {0};
    int index[max] = {0};

    for (int i = 1; i <= e; i++) {
        count[cp[i][1]]++;
    }

    index[0] = 1;
    for (int i = 1; i < n; i++) {
        index[i] = index[i - 1] + count[i - 1];
    }

    for (int i = 1; i <= e; i++) {
        int col = cp[i][1];
        int pos = index[col];

        t[pos][0] = cp[i][1];
        t[pos][1] = cp[i][0];
        t[pos][2] = cp[i][2];

        index[col]++;
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
    printf("\nOriginal Matrix\n");
    disp(rows, cols, a);

    int cp[max][3];
    compact(rows, cols, a, cp);
    printf("\nCompact Matrix\n");
    disp(cp[0][2] + 1, 3, cp);

    int nz = cp[0][2];
    int sT[nz + 1][3];
    sTranspose(cp, sT);
    printf("\nSimple Transpose\n");
    disp(sT[0][2] + 1, 3, sT);
    
    int fT[nz + 1][3];
    fTranspose(cp, fT);
    printf("Fast Transpose:\n");
    disp(fT[0][2] + 1, 3, fT);

    return(0);
}
