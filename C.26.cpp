#include <stdio.h>
#include <stdbool.h>
#define max 100

typedef struct{
    int row;
    int col;
    int value;
} Element;

typedef struct{
    int row;
    int col;
    int nonZero;
    Element data[max];
} SparseMatrix;

// 初始化稀疏矩阵
void init(SparseMatrix *matrix, int row, int col){
    matrix->row = row;
    matrix->col = col;
    matrix->nonZero = 0;
}

// 向稀疏矩阵中插入非零元素
void insert(SparseMatrix *matrix, int row, int col, int value){
    if (row < 0 || row >= matrix->row || col < 0 || col >= matrix->col){
        printf("Invalid position\n");
        return;
    }
    
    if (value != 0){
        matrix->data[matrix->nonZero].row = row;
        matrix->data[matrix->nonZero].col = col;
        matrix->data[matrix->nonZero].value = value;
        matrix->nonZero++;
    }
}

// 稀疏矩阵的相加运算
SparseMatrix add(SparseMatrix A, SparseMatrix B){
    if (A.row != B.row ||A.col != B.col){
        printf("Matrix size does not match\n");
        SparseMatrix empty;
        init(&empty, 0, 0);
        return empty;
    }

    SparseMatrix result;
    init(&result,A.row,A.col);

    int indexA = 0;
    int indexB = 0;

    while (indexA < A.nonZero && indexB < B.nonZero){
        if (A.data[indexA].row == B.data[indexB].row &&A.data[indexA].col == B.data[indexB].col){
            insert(&result, A.data[indexA].row,A.data[indexA].col, A.data[indexA].value + B.data[indexB].value);
            indexA++;
            indexB++;
        }
        else if (A.data[indexA].row < B.data[indexB].row || (A.data[indexA].row == B.data[indexB].row && A.data[indexA].col < B.data[indexB].col)){
            insert(&result, A.data[indexA].row, A.data[indexA].col, A.data[indexA].value);
            indexA++;
        }
        else{
            insert(&result, B.data[indexB].row, B.data[indexB].col, B.data[indexB].value);
            indexB++;
        }
    }
    
    while (indexA < A.nonZero){
        insert(&result, A.data[indexA].row, A.data[indexA].col, A.data[indexA].value);
        indexA++;
    }

    while (indexB < B.nonZero){
        insert(&result, B.data[indexB].row, B.data[indexB].col, B.data[indexB].value);
        indexB++;
    }
    return result;
}

// 稀疏矩阵的相乘运算
SparseMatrix multiply(SparseMatrix A, SparseMatrix B)
{
    if (A.col != B.row){
        printf("Matrix size does not match\n");
        SparseMatrix emptyMatrix;
        init(&emptyMatrix, 0, 0);
        return emptyMatrix;
    }

    SparseMatrix result;
    init(&result, A.row, B.col);

    int sum = 0;

    for (int i = 0; i < A.row; i++)
    {
        for (int j = 0; j < B.col; j++)
        {
            sum = 0;
            for (int k = 0; k < A.col; k++){
                int indexA = 0;
                int indexB = 0;
                while (indexA < A.nonZero && indexB < B.nonZero){
                    if (A.data[indexA].row == i && A.data[indexA].col == k && B.data[indexB].row == k && B.data[indexB].col == j){
                        sum += A.data[indexA].value * B.data[indexB].value;
                        indexA++;
                        indexB++;
                    }else if (A.data[indexA].row < i || (A.data[indexA].row == i && A.data[indexA].col < k)){
                        indexA++;
                    }else{
                        indexB++;
                    }
                }
            }

            insert(&result, i, j, sum);
        }
    }

    return result;
}

// 打印稀疏矩阵
void print(SparseMatrix matrix)
{
    for (int i = 0; i < matrix.row; i++){
        for (int j = 0; j < matrix.col; j++){
            int value = 0;
            for (int k = 0; k < matrix.nonZero; k++){
                if (matrix.data[k].row == i && matrix.data[k].col == j){
                    value = matrix.data[k].value;
                    break;
                }
            }
            printf("%d\t", value);
        }
        printf("\n");
    }
}

int main()
{
    SparseMatrix A;
    init(&A, 4, 4);

    insert(&A, 0, 0, 1);
    insert(&A, 0, 1, 7);
    insert(&A, 0, 2, 4);
    insert(&A, 1, 0, 9);
    insert(&A, 1, 1, 2);
    insert(&A, 1, 2, 5);
    insert(&A, 2, 2, 3);
    insert(&A, 3, 3, 2);

    SparseMatrix B;
    init(&B, 4, 4);

    insert(&B, 0, 0, 2);
    insert(&B, 0, 1, 3);
    insert(&B, 0, 2, 1);
    insert(&B, 1, 0, 6);
    insert(&B, 1, 1, 8);
    insert(&B, 1, 2, 1);
    insert(&B, 2, 3, 4);
    insert(&B, 3, 3, 5);
    
	printf("矩阵A：\n");
	print(A);
	printf("矩阵B：\n");
	print(B);
    SparseMatrix addResult = add(A, B);
    printf("相加结果:\n");
    print(addResult);
    printf("\n");

    SparseMatrix multiplyResult = multiply(A, B);
    printf("相乘结果:\n");
    print(multiplyResult);
    printf("\n");

    return 0;
}
