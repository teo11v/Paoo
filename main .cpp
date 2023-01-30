#include<iostream>
using namespace std;


class Figure {

    public:
        Figure::Figure(int perimeter,const std::string&color)
        :perimeter(perimeter),
         color(color)
        {cout<<"Figure constructor"<<endl;}
        Figure::Figure(const Figure& p1){
            perimeter=p1.perimeter;
            color=p1.color;
        }

        // copy assignment operator
        Figure& operator= (const Figure& d1) {
            
            cout << "copy assignment of Figure \n";
            return *this; 
        }

    private:
        int perimeter;
        std::string color; 
};


class Circle:private Figure{
    public:
        Circle(int diameter)::Figure(int perimeter,const std::string&color)
            :perimter(perimeter),
             color(color)
             diameter(diameter)
            {cout<<"Circle constructor"<<endl;}
        Circle::~Circle(){
            delete[] diameter;
            cout<<"Circle destructor"<<endl;
        }
    private:
        int diameter;
};


class Uncopyable {

    protected:

        Uncopyable() {}
        ~Uncopyable() {}

    private:

        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};


class Mozaic {
    
    public:

        Mozaic::Mozaic(int length, Figure *figure)
            :length(length)
            figure(figure) {}

        Mozaic::Mozaic(const Mozaic& moz1) {

            length = moz1.length;
            figure = moz1.figure;
        }

    private:

        int legth;
        Figure figure;

};

class Triangle: private Uncopyable{
    public:
        Triangle()::Uncopyable(){}
    private:
        int triangle_perimeter;
}   

int main() {

    Figure figure1("Circle", "Red");
    Mozaic moz1(10, figure1);

    Mozaic moz2;
    Mozaic moz3;

    //item 10 
    moz3 = moz2 = moz1; //moz3=(moz2=(moz1))
    moz2.to_string();
    cout << endl;
    moz3.to_string();
    cout << endl;

    //item 11
    moz1 = moz1;  //handle assignment to self in operator =

    Figure* f1;
    f1 = &figure1;

    
    Mozaic moz4(15, f1);
    moz4.to_string();
    
    //item 12
    moz1 = moz4;
    moz1.to_string();
    cout << endl;


    Circle c1;

    Triangle t1();
    Triangle t2();
    Triangle t3(t1);
    t1 = t2;

}