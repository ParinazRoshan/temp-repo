#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <cmath>
#include "map.h"

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
  delete[] roadmap;
  delete[] sum;
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




int Map::fact (int a)    //factorial
{return (a==1 || a==0) ? 1 : (fact(a-1)) * a;}




void Map::findRoutes ()
{
  int k{},r{},m{},z{};
  //k is the number of all possible routes
  k = fact(2*(n - 1))/(fact(n -1)*fact(n -1));
  //roadmap elements are the routes
  roadmap = new int* [k];
  //sum shows the summation of height differences in each route
  sum = new int [k] {};
  for(int j{};j < k;j++)
    {
      *(roadmap+j) = new int [2*(n-1)] {};
    }
  std::bitset<20> bset;
  for (int i = (std::pow(2,n-1) - 1);i <= (std::pow(2,2*(n-1)) - std::pow(2,n-1));i++)
    {
      bset = i;
      if (bset.count() == n-1) // means that it shows a route
	{
	  for(int j{};j < 2*(n-1);j++)
	    {
	      roadmap[r][j] = bset[j] ;
	    }
	  r++;
	}
    }
  //forming the sums
  for(int i{};i < k;i++)
    {
      for (int j{};j < 2*(n-1);j++)
	{
	  if(roadmap[i][j] == 0) //means that we have moved down
	    {
	      sum [i] += std::abs(H[m+1][z] - H[m][z]);
	      m++;
	    }
	  if(roadmap[i][j] == 1)  //means that we have moved right
	    {
	      sum [i] += std::abs(H[m][z+1] - H[m][z]);
	      z++;
	    }
	}
      m = 0;
      z = 0;
    }
}



void Map::bestRoute()
{ 
  int k{},temp{};
  k = fact(2*(n - 1))/(fact(n -1)*fact(n -1));
  int sample[k];
  for (int i{};i < k;i++)
    {
      sample[i] = sum [i];
    }
  //ordering sums
  bool swapped;
 for (int i{};i < k-1;i++)
    {
      swapped=false;
      for (int j{}; j< k-1-i ;j++)
	{
	  if (sum[j] > sum[j+1])
	    {
	      temp = sum[j];
	      sum[j] = sum[j+1];
	      sum[j+1] = temp;
	      swapped=true;
	    }
	}
      if (swapped ==false)
	break;
    }
 //sample is the unordered list indicating which sum is  for which route
 for (int i{};i < k;i++)
   {
     if(sum[0] == sample [i])
       {
	 std::cout<<"best route(s) is :"<<std::endl;
	 for(int j{};j < 2*(n-1);j++)
	   {
	     std::cout<<roadmap[i][j];
	   }
	 std::cout<<std::endl;
	 std::cout<<"(0 means moving down and 1 means moving right)"<<std::endl;
	 std::cout<<"totall height traveled through this route is :";
	 std::cout<<sum[0]<<std::endl;
       }
   }
}
