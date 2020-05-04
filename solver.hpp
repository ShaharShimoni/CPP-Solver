//
// Created by shahar on 24/04/2020.
//

#ifndef OPERATING_SYSTEMS_SOLVER_H
#define OPERATING_SYSTEMS_SOLVER_H

#endif //OPERATING_SYSTEMS_SOLVER_H
#include <string>
#include <complex.h>
using namespace std;

string operator== (string y,double x);
string operator== (string y,string x);

string operator+ (string y,double x);
string operator+ (string y,string x);
string operator-(string y,double x);
string operator-(string y,string x);
string operator*(double x, string y);





double simple_func(string left,string right);
double make_it_simple(string equation);
double make_it_simple_for(string equation);


//double operator- (double y);






namespace solver{
    std::complex<double> make_it_simple_for_y(string equation);
    double solve(string equation);

    // string& operator()(string y);
    class mystring {
    public:
        string save;
        friend mystring operator== (mystring x,mystring y);
        friend mystring operator== (mystring y,double x);
        friend mystring operator+(mystring y,double x );
        friend std::complex<double> solve(mystring equation);
        friend mystring operator*(double x, mystring y);

    };
    class RealVariable {
    public:
        double x;
        double in_front;

        RealVariable() {
            this->x = 1;
            this->in_front = 1;
        }

        friend RealVariable &operator*(double y, RealVariable x);
        friend RealVariable &operator*(RealVariable x, double y);
        friend string operator+(RealVariable y, double x);
        friend string operator+(double x,RealVariable y );
        friend string operator+(string x,RealVariable y );
        friend RealVariable& operator/(RealVariable x,double y );
        friend string operator== (solver::RealVariable y,double x);
        friend RealVariable operator-(RealVariable y);
        friend string operator-(RealVariable y, double x);
        friend string operator-(RealVariable y, RealVariable x);

        friend string operator-(double x,RealVariable y );
        friend string operator-(string y, RealVariable x);
        friend string &operator^(RealVariable y, double x);
        friend string operator== (string x,solver::RealVariable y);






    };




     class ComplexVariable{
     public:
         double in_front;
         double y;

         ComplexVariable() {
             this->y = 1;
             this->in_front = 1;
         }

         friend ComplexVariable operator*(double x,ComplexVariable y);
         friend ComplexVariable operator*(ComplexVariable y, double x);
         friend std::complex<double> simplecomplex(string equation);
         friend mystring operator+(ComplexVariable y, double x);
         friend mystring operator+(double x,ComplexVariable y );
         friend mystring operator+(ComplexVariable y,std::complex<double> w);
         friend mystring operator+(mystring x,ComplexVariable y );
         friend ComplexVariable operator/(ComplexVariable x,double y );
         friend mystring operator== (solver::ComplexVariable y,double x);
         friend ComplexVariable operator-(ComplexVariable y);
         friend mystring operator-(ComplexVariable y, double x);
         friend mystring operator-(double x,ComplexVariable y );
         friend mystring operator-(mystring x, ComplexVariable y);
         friend mystring operator^(ComplexVariable y, double x);
         friend mystring operator== (mystring x,ComplexVariable y);

     };





};




//string operator+(string a,string b){
//    return a+"+"+b;
//}
//string operator-(string a,string b){
//    return a+"+"+b;
//}
//double& solver::operator()(ostream& os)
//{
//    string a = os.str();
//    double c=solver::solve(a);
//    return c;
//}



//double operator () (ostream& os) {
//    string a = os.str();
//    double c=solver::solve(a);
//    return c;
//
//}
