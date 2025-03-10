#include <stdio.h>
double perim(double side1,double side2,double side3){
    return side1+side2+side3;
    
}
int main(int argc, char *argv[]){
    double a=1, b=2, c=2.5 , p;
    p=perim(a,b,c);
    printf("P = %lf \n",p);

    return 0;

}