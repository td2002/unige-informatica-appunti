#include <iostream>
#include <cmath>
#include "geometry.h"

double dist(Point, Point);
double lungperimetro(Point [], int);

int main()
{
  const int N = 5;
  Point lati[N];

  std::cout << "Scrivi le coordinate di "<<N;
  std::cout <<" punti:\n";
  for (int i = 0; i < N; i++) {
    std::cout << "Punto n. "<<i<<"-- ";
    std::cin >> lati[i].x >> lati[i].y;
  }
  try {
    double lung = lungperimetro(lati, N);
    std::cout << "Il perimetro è lungo ";
    std::cout << lung << "\n";
  }
  catch (char const * messaggio) {
    std::cout << "ERRORE: " << messaggio <<"\n";
  }
  catch (int n) {
    std::cout << "ERRORE: lato di lunghezza " << n <<"\n";
  }
  catch (...) {
   std::cout << "ERRORE: eccezione non gestita\n";
  }
}

double lungperimetro(Point p[], int N)
{
  if (p[0].x != p[N-1].x || p[0].y != p[N-1].y )
    throw "Non e' un poligono, "
          "la linea non è chiusa\n";

  double lung = 0.0;
  for (int i = 0; i < N-1; i++)
    lung += dist(p[i],p[i+1]);
  return lung;
}


double dist(Point p1, Point p2)
{
  double lx = p1.x-p2.x;
  double ly = p1.y-p2.y;
  if (lx==0 && ly==0) throw 0;
  return sqrt(lx*lx + ly*ly);
}
