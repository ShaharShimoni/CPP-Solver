//
// Created by shahar on 24/04/2020.
//
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include "solver.hpp"
#include <complex.h>

using namespace solver;
double simple_func(string left,string right){

//    cout<<"left="<<left<<endl;
//    cout<<"right="<<right<<endl;
//    cout<<"simple"<<endl;
    string a = right;
    double r;
    stringstream dstream(a);
    dstream >> r;

    string b = left;
    stringstream dstream2(b);
    double l;
    dstream2 >> l;

    r = r / l;
    return r;
}
double make_it_simple(string equation){

    string tillchar;
    string fromchar;
    string right;

    int i=0;
    while(equation.at(i)!='+' && equation.at(i)!='-'){
        tillchar=+equation.at(i);
    }
    i++;
    while(equation.at(i)!='='){
        fromchar=+equation.at(i);
    }
    i++;
    i++;
    while(i!=equation.size()-1){
        right=+equation.at(i);
    }
    string in="x";
    double c=0;
    if (tillchar.find(in) == std::string::npos){   //pass from tillchar to the other side-doesnt contain x

        double save;
        stringstream dstream(tillchar);
        dstream >> save;

        double save2;
        stringstream dstream2(right);
        dstream2 >> save2;

        save2=save2+save*-1;
        string send=to_string(save2);

         c=simple_func(fromchar,send);
    }
    else{    //pass from fromchar to the other side-doesnt contain x
        double save;
        stringstream dstream(fromchar);
        dstream >> save;

        double save2;
        stringstream dstream2(right);
        dstream2 >> save2;

        save2=save2+save*-1;
        string send=to_string(save2);

        c=simple_func(fromchar,send);
    }

    return c;
}
static int flag=0;
double make_it_simple_for(string equation){   //(x^2)==16 example

  //  cout<<"in make it simple for===     "<<equation<<endl;
    double a;   //for the x1,1=-b+- (b^2-4ac)/2a
    double b=0;
    double c;
    int i=0;
    string save;
    string aa;
    int num_for_sign=0;
    while(equation.at(i)!='='){  //left side -everything is simple
        char sign;
        while(equation.at(i)!='+'&& equation.at(i)!='-' &&equation.at(i)!='='){
           save+=equation.at(i);
           i++;
        }
        sign=equation.at(i);

        if (save.find("x^2") != std::string::npos){  //  a

            string ans;
            int j=0;
            while(save.at(j)!='x'){
                ans+=save.at(j);
                j++;
            }
            double temp;
            int minos=0;
            if(ans.at(0)=='-'){
                minos=1;
                ans=ans.substr(1, ans.size());
            }

            stringstream dstream(ans);
            dstream >> temp;
            if(minos==1){
                temp=temp*-1;
            }


//                if (sign == '-') {
//                    temp = temp * -1;
//
//
//                }

            a=a+temp;
//            save="";
//            i=i+1;
            save=equation.at(i);
            i=i+1;


        }
        else
        if (save.find("x") != std::string::npos){  //   b
           // cout<<"find x"<<endl;
            string ans;
            int j=0;
            while(save.at(j)!='x'){
                ans+=save.at(j);
                j++;
            }
            double temp;
            int minos=0;
            if(ans.at(0)=='-'){
                minos=1;
                ans=ans.substr(1, ans.size());
            }
            stringstream dstream(ans);
            dstream >> temp;
                if(minos==1) {
                    temp = temp * -1;

                }

            b=b+temp;
            save=equation.at(i);
            i=i+1;
        }
        else{  //c

           // cout<<"finf c"<<endl;
            double temp;
            int minos=0;
            if(save.at(0)=='-'){
                minos=1;
                save=save.substr(1, save.size());
            }
            stringstream dstream(save);
            dstream >> temp;
            if(minos==1){
                temp=temp*-1;
            }
            c=c+temp;
            save=equation.at(i);

            i=i+1;
        }

    }

    i=i+1;
    save="";
    char sign;

//    cout<<"a="<<a<<endl;
//    cout<<"b="<<b<<endl;
//    cout<<"c="<<c<<endl;

    while(i<equation.size()-1){   //right side of equation
        while(equation.at(i)!='+'&& equation.at(i)!='-' && i<equation.size()-1){
            save+=equation.at(i);
            i++;

        }
       if(equation.at(equation.size()-1)=='x' && i==equation.size()-1){
           save+="x";
       }

//       cout<<"after while  "<<save<<endl;
       if(save==""){
           save+="-";
           i++;
       }
       else {

           if (save.find("x^2") != std::string::npos) {  //  a
               string ans;
               int j = 0;
               while (save.at(j) != 'x') {
                   ans += save.at(j);
                   j++;
               }
               int minos = 0;
               double temp;
               if (ans.at(0) == '-') {
                   minos = 1;
                   ans = ans.substr(1, ans.size());
               }
               if (ans.at(0) == '+') {
                   ans = ans.substr(1, ans.size());
               }
               stringstream dstream(ans);
               dstream >> temp;
               a = a + temp * -1;
               save = equation.at(i);
               //    cout<<"save="<<save<<endl;
               i = i + 1;
           } else if (save.find("x") != std::string::npos) {  //   b
               // cout<<"find x"<<endl;
               string ans;
               int j = 0;
               while (save.at(j) != 'x') {
                   ans += save.at(j);
                   j++;
               }
               double temp;
               int minos = 0;
               if (ans.at(0) == '-') {
                   minos = 1;
                   ans = ans.substr(1, ans.size());
               }
               if (ans.at(0) == '+') {
                   ans = ans.substr(1, ans.size());
               }


               stringstream dstream(ans);
               dstream >> temp;
               if (minos == 1) {
                   temp = temp * -1;
               }
               b = b + temp * -1;
               save = equation.at(i);

               i = i + 1;
           } else {  //c
             //  cout<<"save "<<save<<endl;

               int minos = 0;
               if (save.at(0) == '-') {
                   minos = 1;
                   save = save.substr(1, save.size());
                 //  cout<<"save "<<save<<endl;
               }
               if (save.at(0) == '+') {
                   save = save.substr(1, save.size());
               }
               double temp;
               stringstream dstream(save);
               dstream >> temp;
               if (minos == 1) {
                   temp = temp * -1;

               }
               // temp = temp * -1;
               c += temp * -1;
               save = equation.at(i);
               i = i + 1;
           }
       }



    }



//    i=i+2;
//    string cc="";
//    while(i!=equation.size()){
//        cc+=(equation.at(i));  //here
//        i++;
//    }
//
//
//    double t;
//    stringstream s(cc);  //stoped here why c=0??????
//    s >> t;
//    c=c+t;

//    c=c*-1;
//    cout<<"cc="<<cc<<endl;
//    cout<<"c="<<c<<endl;

//    cout<<"a="<<a<<endl;
//    cout<<"b="<<b<<endl;
//    cout<<"c="<<c<<endl;

    double w= sqrt(b*b-4*a*c);
   // cout<<"w="<<w<<endl;
    if(w!=double(w)){
        throw std::runtime_error("There is no real solution");
    }
    double ans=-b+w/(2*a);
    return ans;

}

double solver::solve(string equation) {
    string in = "^";

    if (equation.find(in) == std::string::npos) {    //simple equation without x^2

        string in2 = "+";
        string in3 = "-";
        string in4="==-";
        if (equation.find(in2) == std::string::npos)  {
            if (equation.find(in3) == std::string::npos ||equation.find(in4) != std::string::npos ) { //and wothout + -
                string saveleft = "";
                string saveright = "";
                string savex = "";
                int i = 0;
                while (equation.at(i) != 'x') {
                    saveleft += equation.at(i);
                    i++;
                }
                while (equation.at(i) != '=') {
                    savex += equation.at(i);
                    i++;
                }
                i++;
                i++;
                while (i != equation.size()) {
                    saveright += equation.at(i);
                    i++;
                }
                    cout<<"saveleft="<<saveleft<<endl;
                   cout<<"right="<<saveright<<endl;
                    cout<<"simple"<<endl;
                double ans = simple_func(saveleft, saveright);
                return ans;
            } // there is minos

        }
        else
        {    //there is +/-

            double c = make_it_simple(equation);
            return c;
        }
    }
    else{

        double c=make_it_simple_for(equation);
        return c;
    }


}

solver::RealVariable& solver::operator* (double y,solver::RealVariable x){
    double in_front_temp=y*x.in_front;
    solver::RealVariable temp;
    temp.x=x.x;
    temp.in_front=in_front_temp;
    solver::RealVariable temp2=temp;
    return temp2;


}
solver::mystring solver::operator*(double x, solver::mystring y){
    string ans;
    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());
    ans.append("*");
    ans+=(y.save);
    mystring q;
    q.save=ans;
    return q;
}
string operator* (double y,string x){
    string ans;

    double n2 = y;
    ostringstream oss;
    oss.precision(1);
    oss << fixed << n2;
    ans.append(oss.str());
    ans.append("*");
    ans.append(x);
    return ans;

}
string& solver::operator^ (solver::RealVariable x,double y){
//    cout<<"y="<<y<<endl;

    if(y!=2){
        throw exception();
    }
    string a;
    double n2 = x.in_front;
    ostringstream oss;
    oss.precision(1);
    oss << fixed << n2;

    a.append(oss.str());
    a.append("x^");
    double n3 = y;
    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed << n3;

    a.append(oss2.str());
   // cout<<"return"<<a;
    string ans=a;
    return ans;



}
//double operator- (double y) {
//    y=y*-1;
//    return y;
//}
solver::RealVariable solver::operator- (solver::RealVariable y){
    y.in_front=y.in_front*-1;
    return y;
}
string solver::operator- (solver::RealVariable y,double x){

    double n2 = y.in_front;
    ostringstream oss;
    oss.precision(2);
    oss << fixed << n2;

    double n3 = x;
    ostringstream oss2;
    oss2.precision(2);
    oss2 << fixed << n3;


    string answer=oss.str();

    answer+="x";
    answer+="-";
    answer+= oss2.str();
    string tamp=answer;

    return tamp;
}
string solver::operator- (double x,solver::RealVariable y){
    double n3 = x;
    ostringstream oss2;
    oss2.precision(2);
    oss2 << fixed << n3;
    string answer=oss2.str();
    answer.append("-");

    double n2 = y.in_front;
    ostringstream oss;
    oss.precision(2);
    oss << fixed << n2;
    answer+="x";

    answer+= oss.str();
    string tamp=answer;
    return tamp;
}

string solver::operator- (string y,solver::RealVariable x){
    string ans;
    ans.append(y);
    ans.append("-");

    double n2 = x.in_front;
    ostringstream oss;
    oss.precision(2);
    oss << fixed << n2;
    ans.append(oss.str());
    ans.append("x");
    return ans;

}

string solver::operator+ (solver::RealVariable y,double x){

    double n2 = y.in_front;
    ostringstream oss;
    oss.precision(1);
    oss << fixed << n2;

    double n3 = x;
    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed << n3;


    string answer=oss.str();

    answer.append("x+");
    answer.append(oss2.str());
    string tamp=answer;
//    cout<<"plus 4   "<<tamp<<endl;

    return tamp;
}
string solver::operator+ (string x,solver::RealVariable y){
//    cout<<"yessss"<<endl;
    string ans="";
    ans.append(x);
    ans.append("+");

    double n3 = y.in_front;
    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed << n3;

    ans.append(oss2.str());
    ans.append("*x");

    string b;
    b=ans;
    string &c=b;
    //cout<<"plus 3     "<<c<<endl;

    return c;

}
string solver::operator+ (double x,solver::RealVariable y){

    string a=operator+(y,x);  ///today
    string b=a;
//    cout<<"plus 2  "<<b<<endl;

    return b;
}
string operator+(string y, double x) {

    string ans="";
    ans.append(y);
    ans.append("+");


    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed <<x;
    //ans+=oss2.str();
    ans.append(oss2.str());

    string b=ans;
    string g=b;
//    cout<<"plus 1=  "<<g<<endl;
 //   cout<<"plus 1=  "<<g<<endl;

    return g;
}
string operator-(string y, double x) {
    string ans="";
    ans.append(y);
    ans.append("-");
    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed <<x;
    //ans+=oss2.str();
    ans.append(oss2.str());

    string b=ans;
    string g=b;

    return g;
}
string operator== (string y, double x){
    // cout<<" string y="<<y<< "=="<<x<< endl;
    string cansolve="x";
    if (y.find(cansolve) == std::string::npos){
        throw exception();
    }
        string in = "^";
    if (y.find(in) == std::string::npos) {   //no ^
        char sign;
        int i = 0;
        string left;
        while (y.at(i) != '-' && y.at(i) != '+') {
            left += y.at(i);
            i++;
        }
        sign = y.at(i);
        i++;
        string left2;
        while (i <= y.size() - 1) {
            left2 += y.at(i);
            i++;
        }

        double l2;
        stringstream dstream(left2);
        dstream >> l2;

        if (sign == '+')
            x = x + l2 * (-1);
        else
            x = x + l2;


        int j = 0;
        string inf = "";
        while (left.at(j) != 'x') {
            inf += left.at(j);
            j++;
        }

        double l;
        stringstream dstream2(inf);
        dstream2 >> l;


        solver::RealVariable z;
        z.in_front = l;

        string &temp = operator==(z, x);
        string a = temp;
        return a;
    }
    else {
       // cout<<"else y="<<y<<endl;
        string a;
        a.append(y);
        a.append("==");
        //cout<<"a y="<<a<<endl;
        ostringstream oss3;
        oss3.precision(1);
        oss3 << fixed << x;
        a.append(oss3.str());

        // string b=string_copy(a);
        string b=a;
      //cout<<"going return =="<<b<<endl;
        return b;
    }

}


string operator== (string y, string x){
    string cansolve="x";
    if (y.find(cansolve) == std::string::npos && x.find(cansolve) == std::string::npos){
        throw exception();
    }
//    cout<<"left="<<y<<endl;
//    cout<<"right="<<x<<endl;

    string ans;
    ans.append(y);
    ans.append("==");
    ans.append(x);
    string g=ans;
    return g;
}
string operator+(string y, string x) {

    string ans="";
    ans.append(y);
    ans.append("+");
    ans.append(x);
    string g=ans;
    string t=g;
//    cout<<"g=    "<<t<<endl;
    return t;
}
string operator-(string y, string x) {
    string ans="";
    ans.append(y);
    ans.append("-");
    ans.append(x);
    string g=ans;
    string t=g;
    return t;
}

string solver::operator== (string x,solver::RealVariable y){
    string ans;
    ans.append(x);
    ans.append("==");

    double n2 = y.in_front;
    ostringstream oss;
    oss.precision(2);
    oss << fixed << n2;
    ans.append(oss.str());
    ans.append("x");
    string t=ans;
    return t;

}




 string& solver::operator== (solver::RealVariable y,double x){
    //cout<<"yep"<<endl;
    double n2 = y.in_front;
    ostringstream oss;
    oss.precision(2);
    oss << fixed << n2;
    string left= oss.str()+"x";
   // string left=to_string(y.in_front)+"x";


    double n = x;
    ostringstream oss2;
    oss2.precision(2);
    oss2 << fixed << n;
    string right = oss2.str();


    string in="==";
    string ret;
    ret+=left;
     ret+=in;
     ret+=right;

    string ret2=ret;

     return ret2;

}

solver::RealVariable& solver::operator/ (solver::RealVariable y,double x) {
    y.in_front=y.in_front/x;
    return y;
}

//string& operator== (string y, string x){
//    string ans;
//    ans+=y;
//    ans+="==";
//    ans+=x;
//    return ans;
//}
//string& solver::operator() (string y){    //take out the ()
//    string ans;
//    int i=1;
//    while(i!=y.size()-2){
//        ans+=t.at(i);
//    }
//    return ans;
//}

//ostream& operator<<(ostream& os,solver::RealVariable x)
//{
//    os << x.x;
//    return os;
//}

//////////////////////////////////////////////////
std::complex<double> solver::solve(mystring equation){
   std::complex<double> w;
   return w;

}
solver::ComplexVariable solver::operator*(double x,ComplexVariable y){
    ComplexVariable t;
    t.in_front=x*y.in_front;
    return t;
}
solver::ComplexVariable solver::operator*(ComplexVariable y, double x){
    ComplexVariable ans=operator*(x,y);
    return ans;
}
solver::mystring solver::operator+(ComplexVariable y, double x){
    string ans;
    ans.append("y+");

    double n3 = x;
    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed << n3;
    ans.append(oss2.str());
    mystring t;
    t.save=ans;
    return t;

}
solver::mystring solver::operator+(double x,ComplexVariable y ){
    mystring ans;
    ans=operator+(y,x);
    return ans;

}

solver::mystring solver::operator+(mystring y,double x ){
    string ans=y.save;
    ans.append("+");
    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());
    mystring g;
    g.save=ans;
    return g;

}
solver::mystring solver::operator+(solver::mystring x,ComplexVariable y ){
    string ans=x.save;
    ans.append("+y");
    mystring t;
    t.save=ans;
    return t;
}
solver::mystring solver::operator+(ComplexVariable y,std::complex<double> w){
    double re=real(w);
    double im=imag(w);

    ostringstream oss;
    oss.precision(1);
    oss << fixed << re;
    string t=oss.str();

    ostringstream oss2;
    oss2.precision(1);
    oss2 << fixed << im;
    string t2=oss2.str();

    string ans="y+";
    ans.append(t);
    ans.append("+");
    ans.append(t2);
    ans.append("i");
    mystring p;
    p.save=ans;
    return p;

}
solver::ComplexVariable solver::operator/(ComplexVariable x,double y ){
    ComplexVariable t;
    t.in_front=x.in_front/y;
    return t;

}
solver::mystring solver::operator== (solver::ComplexVariable y,double x){
    string ans="y==";

    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());

    mystring t;
    t.save=ans;
    return t;


}
solver::ComplexVariable solver::operator-(ComplexVariable y){
    y.in_front=y.in_front*-1;
    return y;
}
solver::mystring solver::operator-(ComplexVariable y, double x){
    string ans="y-";
    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());

    mystring t;
    t.save=ans;
    return t;


}
solver::mystring solver::operator-(double x,ComplexVariable y ){
    string ans;
    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());
    ans.append("-y");

    mystring t;
    t.save=ans;
    return t;

}
solver::mystring solver::operator-(solver::mystring x, ComplexVariable y){
    string ans=x.save;
    ans.append("-y");
    mystring t;
    t.save=ans;
    return t;

}
solver::mystring solver::operator^(ComplexVariable y, double x){
    if(x!=2){
        throw exception();
    }
    string ans="y^";
    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());
    mystring t;
    t.save=ans;
    return t;


}
solver::mystring solver::operator== (solver::mystring x,ComplexVariable y){
    string ans=x.save;
    ans.append("==y");
    mystring t;
    t.save=ans;
    return t;

}

solver::mystring solver::operator== (solver::mystring x,solver::mystring y){
    string ans=x.save;
    ans.append("==");
    ans.append(y.save);
    mystring t;
    t.save=ans;
    return t;

}
solver::mystring solver::operator== (solver::mystring y,double x){
    string ans=y.save;
    ans.append("==");

    ostringstream oss;
    oss.precision(1);
    oss << fixed << x;
    ans.append(oss.str());

    mystring t;
    t.save=ans;
    return t;
}


