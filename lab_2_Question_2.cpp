#include<iostream>
#include<vector>
using namespace std;

class Matrix {
    private:
        vector<vector<int>> mat; 
        int rows, cols;

    public:
       
        Matrix(vector<vector<int>> a): mat(a) {
            rows = mat.size();
            cols = mat[0].size();
        }
        Matrix operator+(const Matrix &other) {
            if (rows != other.rows || cols != other.cols) {
                throw invalid_argument("Matrices must have the same dimensions for addition.");
            }
            vector<vector<int>> result(rows, vector<int>(cols));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = mat[i][j] + other.mat[i][j];
                }
            }
            return Matrix(result);
        }

        Matrix operator-(const Matrix &other) {
            if (rows != other.rows || cols != other.cols) {
                throw invalid_argument("Matrices must have the same dimensions for subtraction.");
            }
            vector<vector<int>> result(rows, vector<int>(cols));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = mat[i][j] - other.mat[i][j];
                }
            }
            return Matrix(result);
        }

        Matrix operator*(const Matrix &other) {
            if (cols != other.rows) {
                throw invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.");
            }
            vector<vector<int>> result(rows, vector<int>(other.cols, 0));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    for (int k = 0; k < cols; k++) {
                        result[i][j] += mat[i][k] * other.mat[k][j];
                    }
                }
            }
            return Matrix(result);
        }

        Matrix operator*(int scalar) {
            vector<vector<int>> result(rows, vector<int>(cols));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = mat[i][j] * scalar;
                }
            }
            return Matrix(result);
        }

        void transpose() {
            vector<vector<int>> result(cols, vector<int>(rows));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[j][i] = mat[i][j];
                }
            }
            mat = result;
            swap(rows, cols);
        }

    
        void display() const {
            for (const auto& row : mat) {
                for (int val : row) {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    vector<vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> mat2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix m1(mat1);
    Matrix m2(mat2);

    Matrix result = m1 + m2;
    cout << "Addition:" << endl;
    result.display();

    result = m1 - m2;
    cout << "Subtraction:" << endl;
    result.display();

    result = m1 * m2;
    cout << "Multiplication:" << endl;
    result.display();

    result = m1 * 2;
    cout << "Scalar Multiplication by 2:" << endl;
    result.display();
   
    cout << "Transpose of first matrix:" << endl;
    m1.transpose();
    m1.display();

    return 0;
}