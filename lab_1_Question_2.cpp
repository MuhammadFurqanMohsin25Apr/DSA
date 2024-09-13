#include <iostream>
using namespace std;

double gpaCalculator(double gpa[],int validTotalGrades,int creditHours){
    double totalPoints=0;
    for(int i=0;i<validTotalGrades;i++){
        totalPoints+=gpa[i]*creditHours;
    }
    return totalPoints/(validTotalGrades*creditHours);
}
int main(){
    int valid=0;
    int credithours=3;
    string names[5]={"Ali","Hiba","Asma","Zain","Faisal"};
    double gpas[5][5]={{3.66,3.33,4.0,3.0,2.66},
                       {3.33,3.0,3.66,3.0,-1},
                       {4.0,3.66,2.66,-1,-1},
                       {2.66,2.33,4.0,-1,-1},
                       {3.33,3.66,4.0,3.0,3.33}};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(gpas[i][j]!=-1){
            valid++;
            }
        }
    
    
        double result=gpaCalculator(gpas[i],valid,credithours);
        cout<<"GPA of "<<names[i]<<" is "<<result;
        cout<<endl;
        valid=0;}
    return 0;}



