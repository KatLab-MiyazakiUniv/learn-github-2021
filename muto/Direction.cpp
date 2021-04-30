#include <stdio.h>
#include <cstdlib>

enum class Direction { N, NE, E, SE, S, SW, W, NW, none };

struct Coordinate {
  int x;
  int y;
};

Direction calcNextDirection(Coordinate _currentCoordinate, Coordinate _nextCoordinate);

Direction calcNextDirection2(Coordinate _currentCoordinate, Coordinate _nextCoordinate);

int main()
{
  Coordinate currentCoordinate{ 1, 1 };
  Coordinate nextCoordinate{ 0, 0 };

  Direction result = calcNextDirection(currentCoordinate, nextCoordinate);
  printf("result = %d", (int)result);
}

Direction calcNextDirection(Coordinate _currentCoordinate, Coordinate _nextCoordinate)
{
  /*
   * diff_x < 0 の場合右側に，diff_x > 0 の場合左側に移動
   * diff_x = 0 の場合は上か下のどちらかに移動
   */
  int diff_x = _nextCoordinate.x - _currentCoordinate.x;
  /*
   * diff_y < 0 の場合下側に，diff_y > 0 の場合上側に移動
   * diff_y = 0 の場合は右か左のどちらかに移動
   */
  int diff_y = _nextCoordinate.y - _currentCoordinate.y;

  // エラー処理
  if(std::abs(diff_x) > 1 || std::abs(diff_y) > 1 || 0 == diff_x == diff_y) {
    return (Direction)8;
  }

  if(diff_x < 0) {
    if(diff_y < 0) {
      return Direction::NW;
    } else if(diff_y == 0) {
      return Direction::W;
    } else {
      return Direction::SW;
    }
  } else if(diff_x == 0) {
    if(diff_y < 0) {
      return Direction::N;
    } else if(diff_y == 0) {
      return Direction::W;
    } else {
      return Direction::S;
    }
  } else if(diff_x > 0) {
    if(diff_y < 0) {
      return Direction::NE;
    } else if(diff_y == 0) {
      return Direction::E;
    } else {
      return Direction::SE;
    }
  }
}

// 不採用可読性最悪関数
Direction calcNextDirection2(Coordinate _currentCoordinate, Coordinate _nextCoordinate)
{
  int diff_x = _nextCoordinate.x - _currentCoordinate.x;
  int diff_y = _nextCoordinate.y - _currentCoordinate.y;

  if(std::abs(diff_x) > 1 || std::abs(diff_y) > 1 || 0 == diff_x == diff_y) {
    return (Direction)8;
  }

  if(diff_x < 0) {
    return (Direction)(6 - diff_y);
  } else {
    return (Direction)(2 + diff_y * (2 - diff_x));
  }
}
