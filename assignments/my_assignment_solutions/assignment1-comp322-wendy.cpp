//
// Created by Wendy Wu on 2022-02-13.
//
#include <iostream>
#include <set>
#include <map>
#include <cstdlib>
#include <random>

using namespace std;
const set<int> numbers = {'0','1','2','3','4','5','6','7','8',9};
const set<char> specials = {'*','#','$'};

bool checkPassword(string temp_password){
//    check if at least 8 character
    if (temp_password.length() < 8){
        cout << "Password is less then 8 characters. Try Again." << endl;
        return false;
    }

    bool ifOneNumber = false;
    bool ifSpecial = false;
    set<char> temp_password_set(begin(temp_password), end(temp_password));
    for (auto c:temp_password){
        if(numbers.count(c)!=0){
            ifOneNumber = true;
        }
        if (specials.count(c)!=0){
            ifSpecial = true;
        }
        //    if each character does not occur more than 2 times
        if (std::count(temp_password.begin(), temp_password.end(), c)>2){
            cout << "Each character should not occur more than 2 times. Try Again." << endl;
            return false;
        }
    }
    //    check if contains at least one number,
    //    and contain one of the special chars "*,#,$"
    if (!ifSpecial){
        cout << "Password should contains at least one of the following special characters *,#,$. Try Again." << endl;
        return false;
    }
    if (!ifOneNumber){
        cout << "Password should contains at least one number. Try Again." << endl;
        return false;
    }
    return true;
}

void checkPassword(){
    string temp_password;
    while(!(checkPassword(temp_password))) {
        cout << "Input a password. (Should be at least 8 characters)" << endl;
        cin >> temp_password;
    }
}

void convertPhonetic(){
    map<char,string> my_dict = {
            {'a', "Alfa"},
            {'b', "Bravo"},
            {'c', "Charlie"},
            {'d', "Delta"},
            {'e', "Echo"},
            {'f', "Foxtrot"},
            {'g', "Golf"},
            {'h', "Hotel"},
            {'i', "India"},
            {'j', "Juliett"},
            {'k', "Kilo"},
            {'l', "Lima"},
            {'m', "Mike"},
            {'n', "November"},
            {'o', "Oscar"},
            {'p', "Papa"},
            {'q', "Quebec"},
            {'r', "Romeo"},
            {'s', "Sierra"},
            {'t', "Tango"},
            {'u', "Uniform"},
            {'v', "Victor"},
            {'w', "Whiskey"},
            {'x', "X-ray"},
            {'y', "Yankee"},
            {'z', "Zulu"}
    };
    cout << "Please enter a word: ";
    string temp_word;
    cin >> temp_word;
    for (auto c:temp_word){
        try{
            const string x = my_dict.at(tolower(c));
            cout << x << "\t";
        } catch (const out_of_range){
            cout << "Find unexpected character. Program terminates." << endl;
            return;
        }
    }
    cout << endl;
}

const int rows = 5;
const int cols = 5;

void fillMatrix(int matrix[rows][cols]){
    uniform_int_distribution<int> dist{0,25};
    random_device seed;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(seed());
    for (int row = 0; row < rows; row++){
        for (int col = 0; col<cols; col++){
            matrix[row][col] = dist(gen);
        }
    }
}

void printMatrix(int matrix[rows][cols]){
    for (int row = 0; row < rows; row++){
        for (int col = 0; col<cols; col++){
            cout << matrix[row][col] << " | ";
        }
        cout << endl << "--------------------------" << endl;
    }
}

//should be recursive
void multiplyMatrices(int matrix_left[rows][cols], int matrix_right[rows][cols], int matrix_result[rows][cols]){
    static int i=0,j=0,k=0;

    if (i>=rows){
        return;
    }
    if (j<cols){
        if(k<cols){
            matrix_result[i][j] += matrix_left[i][k]*matrix_right[k][j];
            k++;
            multiplyMatrices(matrix_left,matrix_right,matrix_result);
        }
        k = 0;
        j++;
        multiplyMatrices(matrix_left,matrix_right,matrix_result);
    }
    j = 0;
    i++;
    multiplyMatrices(matrix_left,matrix_right,matrix_result);
}

//int main(){
//    checkPassword();
//    convertPhonetic();
//    int matrix[rows][cols];
//    int matrix2[rows][cols];
//    int matrix_result[rows][cols] = {0};
//    fillMatrix(matrix);
//    fillMatrix(matrix2);
//    cout << "Matrix 1" << endl;
//    printMatrix(matrix);
//    cout << "Matrix 2" << endl;
//    printMatrix(matrix2);
//    multiplyMatrices(matrix, matrix2, matrix_result);
//    cout << "Matrix result" << endl;
//    printMatrix(matrix_result);
//    return 0;
//}
