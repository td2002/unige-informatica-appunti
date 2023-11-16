#include <iostream>
#include <cmath>

#include "geometry.h"

double dist(Point, Point);

int main()
{
  const int N = 5;
  Point spezzata[N];

  std::cout << "Scrivi le coordinate di "<<N<< "punti:\n";
  for (int i=0; i<N; i++) {
    std::cout << "Punto "<<i<<" -- ";
    std::cin>> spezzata[i].x >> spezzata[i].y;
  }
  
  double lung=0;
  for (int i=0; i<N-1; i++) {
    lung += dist(spezzata[i], spezzata[i+1]);
  }
  std::cout << "La spezzata è lunga "<<lung<< " in totale\n";
}

double dist(Point p1, Point p2)
{
  double lx = p1.x-p2.x;
  double ly = p1.y-p2.y;
  return sqrt(lx*lx+ly*ly);
}
