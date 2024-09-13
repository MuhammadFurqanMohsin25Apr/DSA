#include <iostream>
#include <vector>
using namespace std;


vector<int> scalarVectorOperation(const vector<int>& A, const vector<int>& B, int X, int Y) {
    int n = A.size();
    vector<int> result(n);
    
    for (int i = 0; i < n; i++) {
        result[i] = X * A[i] + Y * B[i];
    }
    
    return result;
}


int dotProduct(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    int product = 0;
    
    for (int i = 0; i < n; i++) {
        product += A[i] * B[i];
    }
    
    return product;
}

int main() {
    
    vector<int> A = {16, -6, 7};
    vector<int> B = {4, 2, -3};
 
    int X = 2;
    int Y = -5;
    

    vector<int> result = scalarVectorOperation(A, B, X, Y);
    

    cout << "Result of XA + YB: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    

    int dotProductResult = dotProduct(A, B);
    
    
    cout << "Result of A . B (Dot Product): " << dotProductResult << endl;

    return 0;
}