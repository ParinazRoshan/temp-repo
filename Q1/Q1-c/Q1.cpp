#include <iostream>
#include "map.h"

int main (){
  int n{};
  std::cout<<"enter the desired length of map"<<std::endl;
  std::cin>>n;
  Map map1{n};
  map1.showMap();
  map1.findRoutes();
  map1.bestRoute();
}
