#include <iostream>

void swap(double &a, double &b)
{
  double c = a;
  a = b;
  b = c;
}

int main()
{
  double x=100, y = .1;
  std::cout << "Prima     x = "<< x <<" e y = "<<y<<"\n";
  swap(x,y);
  std::cout << "Dopo swap x = "<< x <<" e y = "<<y<<"\n";
}
