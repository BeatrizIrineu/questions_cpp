#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

void searching_tags(const vector<vector<int>>& matrix, int tag_size){
    
    int points = matrix.size()/tag_size; // 2
    int row = 0; 
    int column = 0; 

    for (int i = 0; i < points; i++){
        for (int j = 0; j < points; j++){
            row = ((i+1)*tag_size) -1 ;
            column = ((j+1)*tag_size) -1;
           
            if (matrix[row][column] == 1){
                while (column > 0 && matrix[row][column-1] != 0  )
                    column = column -1;
                while (row > 0 && matrix[row-1][column] != 0  )
                    row = row -1;
                
                cout << "Found row = " << row << " column = " << column << endl;
            }
        }
    }
}

int main() {
    srand(time(nullptr));  

    int n = 9;
   
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int tag_size = sqrt(n);

    int start_row = rand() % (n - tag_size + 1);
    int start_col = rand() % (n - tag_size + 1);

   for (int i = start_row; i < start_row + tag_size; ++i) {
        for (int j = start_col; j < start_col + tag_size; ++j) {
            matrix[i][j] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    searching_tags(matrix, tag_size);

    return 0;
}
