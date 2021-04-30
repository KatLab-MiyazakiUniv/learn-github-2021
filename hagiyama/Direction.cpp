#include"Direction.h"
#include"iostream"
using namespace std;

int main(void){
  enum class Direction{N,NE,E,SE,S,SW,W,NW};
  struct Coordinate{
  private:
    int x;
    int y;
  public:
    int calcNextDirection(Coordinate &now,Coordinate &next){
      int gx = next.x - now.x;
      int gy = next.y - now.y;
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


    int NextDirection1(Coordinate &now,Coordinate &next){
      float gx = next.x - now.x;
      float gy = next.y - now.y;
      double dig = atan2(gx,gy)*180/M_PI;
      printf("%lf\n",dig);
      for(int i=0;i<=7;i++){
        if(abs(dig)==i*45){
          return i;
        }
      }
    }


    void setValue(int sx,int sy){
      x =  sx;
      y  = sy;
    }
  };

  Coordinate now;
  Coordinate next;
  now.setValue(1,1);
  next.setValue(0,0);
  cout<<now.calcNextDirection(now,next)<<endl;
  // cout<<now.NextDirection1(now,next)<<endl;
  return 0;
}
