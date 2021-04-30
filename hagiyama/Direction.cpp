#include<stdio.h>
#include"iostream"
using namespace std;

enum class Direction{N,NE,E,SE,S,SW,W,NW};
struct Coordinate{
private:
  int x;
  int y;
public:
  int calcNextDirection(int next_x,int next_y){
    int gx = next_x - x;
    int gy = next_y - y;
    if(gx==0){
      if(gy==0)return -1;
      else if(gy>0){
        return 2;
      }else{
        return 6;
      }
    }else if(gy==0){
      if(gx==0)return -1;
      else if(gx>0){
        return 4;
      }else{
        return 0;
      }
    }else{
      if(gx>0){
        if(gy>0){
          return 3;
        }else{
          return 5;
        }
      }else{
        if(gy>0){
          return 1;
        }else{
          return 7;
        }
      }
    }
  }
  Coordinate(int _x,int _y):x(_x),y(_y){
  }
};


int main(void){
  Coordinate now(1,1);
  cout<<now.calcNextDirection(0,0)<<endl;
  return 0;
}
