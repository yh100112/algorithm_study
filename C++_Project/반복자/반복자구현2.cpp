#include<iostream>
using namespace std;

class Point{
private:
  int x,y;
public:
  Point(int _x = 0, int _y = 0):x(_x),y(_y){}
  void ShowPosition();
  Point operator + (const Point& p);
  bool operator == (const Point& p);
  Point operator - (const Point& p);
  friend bool operator != (const Point&, const Point&);
  friend Point& operator -- (Point& p);
};

void Point::ShowPosition(){
  cout << "(" << x << ", " << y << ")" << endl;
}

Point Point::operator+(const Point& p){
  return Point(x+p.x,y+p.y);
}

bool Point::operator==(const Point& p){
  if(x == p.x&& y == p.y) return true;
  else return false;
}

Point Point::operator-(const Point& p){
  return Point(x - p.x,y - p.y);
}
bool operator !=(const Point& p1, const Point& p2){
  return (p1 != p2);
}

Point& operator--(Point& p){
  p.x--;
  p.y--;
  return p;
}

int main(){
  Point p1 = Point(1,6);
  Point p2(2,4);
  Point p3 = p1.operator+(p2); // p1 + p2
  Point p4 = p3 - p2;

  p1.ShowPosition();
  p2.ShowPosition();
  p3.ShowPosition();
  p4.ShowPosition();

  --p2;
  p2.ShowPosition();

}

