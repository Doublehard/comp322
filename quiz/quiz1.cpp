//
// Created by Wendy Wu on 2022-02-26.
//
#include <iostream>
using namespace std;

// iteration
int fibonacci(int n){
    int s1 = 1;
    int s2 = 1;
    if(n>=1){
        cout << s1 << ", " << s2 << ", ";
    }
    int s3 = s1+s2;
    while(s3<=n){
        cout << s3 << ", ";
        int temp = s3;
        s3 = s2+s3;
        s2 = temp;
    }
    return 0;
}

// recursion
int fibonacci_2(int n){
    // exit:
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    // recurs
    return fibonacci_2(n-1) + fibonacci_2(n-2);
}

int getLength(char* myString){
    int length = 0;
    char* ptr = myString;
    while(*ptr != '\0'){
        length++;
        ptr++;
    }
    return length;
}

void transpose_Matrix(int matrix[5][5]){
    int prefix = 1;
    for(int row=0;row<5;row++){
        for(int col=prefix;col<5;col++){
            int temp =  matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
            prefix++;
        }
    }
}

void print_Matrix(int matrix[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//int main(){
//    cout << "Please input a number: ";
//    int n;
//    cin >> n;
//    fibonacci(n);
//    cout << endl;
//    for(int i=1;fibonacci_2(i)<=n;i++){
//        cout << fibonacci_2(i) << ", ";
//    }
//    cout << endl;
//    // Q9
//    char* my_array = "hello world\0 wendyy";
//    cout << my_array << " has length = " << getLength(my_array) << endl;
//    // Q10
//    int matrix[5][5] = {{7,6,5,10,9},{-1,13,6,-1,4},{9,4,4,-4,17},{2,7,7,5,7},{6,0,0,3,10}};
//    transpose_Matrix(matrix);
//    print_Matrix(matrix);
//    return 0;
//}
