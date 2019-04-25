#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.h"

//this code is mostly the same as the previous part and the difference is explained in the code

Map::Map (int N) : n{N} , H{new int* [n]} , R{new int* [n]}
{
  for(int i{}; i < n;i++)
    {
      *(H+i) = new int[n] {};
      *(R+i) = new int [n] {};
    }
}


Map::~Map()
{
  delete[] H;
  delete[] R;
  std::cout<<"goodbye !"<<std::endl;
}


void Map::showMap ()
{
  std::cout<<"here are the heights :"<<std::endl;
  std::srand ( (int)time(0) );  //for generating different numbers each time
  for(int i{}; i < n;i++)
    {
      for(int j{}; j < n;j++)
	{
	  H[i][j] = (rand() % 100);  //random numbers from 0 to 99
	  if(H[i][j] - 10 >= 0)
	    std::cout<<H[i][j]<<"  ";
	  else
	    std::cout<<"0"<<H[i][j]<<"  ";
	}
      std::cout<<std::endl;
    }
}


void Map::findRoute ()
{
  std::cout<<"my suggested route is :"<<std::endl;
  int i{},j{};
  R[0][0] = 1;
  while(i != n-1 && j != n-1)
    {
      //this part has an extra subtraction compared to the previous part to enable diagonal moving
      if(std::abs(H[i+1][j] - H[i][j]) <= std::abs(H[i][j+1] - H [i][j]) && std::abs(H[i+1][j] - H[i][j]) <= std::abs(H[i+1][j+1] - H[i][j]))
	{
	  R[i+1][j] = 1;
	  i++;
	}
      else if( std::abs(H[i+1][j+1] - H[i][j]) <= std::abs(H[i][j+1] - H [i][j]) && std::abs(H[i+1][j+1] - H[i][j]) <= std::abs(H[i+1][j] - H[i][j])) 
	{
	  R[i+1][j+1] = 1; //diagonal moving
	  j++;
	  i++;
	}
      else if( std::abs(H[i][j+1] - H[i][j]) <= std::abs(H[i+1][j+1] - H [i][j]) && std::abs(H[i][j+1] - H[i][j]) <= std::abs(H[i+1][j] - H[i][j]))
	{
	  R[i][j+1] = 1;
	  j++;
	}
    }
      while (i == n-1 && j != n-1)
	{
	  j++;
	  R[i][j] = 1;
	}
      while (j == n-1 && i != n-1)
	{
	  i++;
	  R[i][j] = 1;
	}
}


void Map::showRoute()
{
  for (int i{};i < n;i++)
    {
      for (int j{};j < n;j++)
	{
	  std::cout<<R[i][j]<<" ";
	}
      std::cout<<std::endl;
    }
}
