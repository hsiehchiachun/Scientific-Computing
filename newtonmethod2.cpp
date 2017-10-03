//
//  main.cpp
//  newtonmethod
//
//  Created by 謝嘉竣 on 2017/10/2.
//  Copyright © 2017年 謝嘉竣. All rights reserved.
//
//Newton-Raphson Method
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double* f(double x,double y);    //declare the function for the given equation
double* f(double x,double y)    //define the function here, ie give the equation
{
    static double a[2];
    a[0] = pow(y,2.0)*exp(x)-3;
    a[1] = 2*y*exp (x)+10*pow(y,4.0);//write the equation whose roots are to be determined
    return a;
}
double* Dfinv(double x, double y);
double* Dfinv(double x, double y)
{
    double ex= exp(x);
    static double b[4];
    double det = (-2*pow(y, 2.0)*exp(2*x)+40*pow(y, 5)*exp(x));
    b[0] = (1/det)*(2*ex+40*pow(y, 3));//b11
    b[1] = (1/det)*(-2*y*ex);//b12
    b[2] = b[1];//b21
    b[3] = (1/det)*pow(y, 2)*ex;//b22
    //write the first derivative of the equation
    return b;
}
int main()
{
    double *x = new double,*x1,e,*fx,*fx1;
    cout.precision(9);        //set the precision
    cout.setf(ios::fixed);
    cout<<"Enter the initial guess\n";    //take an intial guess
    cin >> x1[0] >> x1[1];
    cout<<"Enter desired accuracy\n";    //take the desired accuracy
    cin>>e;
    fx=f(x[0],x[1]);
    fx1=Dfinv(x[0],x[1]);
    cout <<"x{i}"<<"    "<<"y{i}"<<"    "<<"x{i+1}"<<"    "<<"y{i+1}"<<"   "<<"|x{i+1}-x{i}|"<<"    "<<"|y{i+1}-y{i}|"<<endl;
    
    do
    {
        *x=*x1;                /*make x equal to the last calculated value of                             x1*/
        fx=f(x[0],x[1]);            //simplifying f(x)to fx
        fx1=Dfinv(x[0],x[1]);            //simplifying fprime(x) to fx1
        x1[0] = x[0]-fx1[0]*fx[0]-fx1[1]*fx[1];
        x1[1] = x[1]-fx1[2]*fx[0]-fx1[3]*fx[1];
        /*calculate x{1} from x, fx and fx1*/
        cout<<x[0]<<"           "<<x[1]<<"     "<<x1[0]<<"       "<<x1[1]<<"           "<<abs(x1[0]-x[0])<<"           "<<abs(x1[1]-x[1])<<endl;
    }while ((fabs(x1[0]-x[0])>=e)||(fabs(x1[1]-x[1])>=e));            /*if |x{i+1}-x{i}| remains greater than the desired accuracy, continue the loop*/
    cout<<"The root of the equation is "<<x1<<endl;
    return 0;
}
