// virtual members
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    virtual void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area ()
      { return 0; }
    virtual int perimeter () 
      { return 0; }
};

class Rectangle: public Polygon {
  public:
    virtual void set_values (int a, int b)
      { width = 2 * a; height = 2 * b; }
    int area ()
      { return width * height; }
    int perimeter () 
      { return 2 * (width + height); }
};

class Triangle: public Rectangle {
  public:
    int area ()
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon* ppoly1 = &rect;
  Polygon* ppoly2 = &trgl;
  Polygon* ppoly3 = &poly;
  ppoly1->set_values (13,2);
  ppoly2->set_values (1,2);
  ppoly3->set_values (7,9);
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  cout << ppoly3->area() << '\n';

  cout << ppoly1->perimeter() << '\n';

  Rectangle* rect2 = &trgl;
  cout << rect2->perimeter() << '\n';

  return 0;
  
}