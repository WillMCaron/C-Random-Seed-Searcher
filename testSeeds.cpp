
#include <iostream>
#include <stdio.h>      // NULL 
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 
#include <chrono>
#include <vector>
#include <fstream>

int lucas(int goal, long seed) {
  srand(seed);
  int num;
  int count = 0;
  do {
    count ++;
    num = rand()%100001;
    //std::cout << num << std::endl;
  } while (num != goal);
 //std::cout << "It took: " << count << " tries!" <<std::endl;
  return count;
}

std::vector<long> get_seed (std::string filename) {
  std::ifstream myfile (filename);
  std::string line;
  std::vector<long> seeds;
  while (myfile.good()) {
    myfile >> line;
    seeds.push_back(std::stol(line));
    //std::cout << "1" <<std::endl;
  }
  //std::cout << seeds[0];
  myfile.close();
  return seeds;
}

int query (long seed) {
  srand(seed);
  return rand()%100001;

}

void randGuess (std::string filepath, int goal) {
  srand(time(NULL));
  long seed;
  int count;
  std::vector <long> seeds;
  seeds = get_seed(filepath);
  seed = seeds[rand()%(seeds.size())];

  count = lucas(goal, seed);
  
  std::cout << "The seed was " << seed << std::endl;
  std::cout << "It found " << goal << " in "<< count << " tries!" << std::endl;
  //std::cout << ms_passed;
}

int main() {
  //typedef std::vector<std::vector<std::vector<double>>> matrix;
  long seed;
  std::vector<long> seeds = get_seed("/home/runner/ShockedSeveralCoins/texts/ones.txt");
  for (int i=0; i < (seeds.size()); i++) {
    seed = seeds[i];
    std::cout << query (seed) << std::endl;
    //std::cout << i << "\n";
  }
  
  randGuess("/home/runner/ShockedSeveralCoins/texts/ones.txt", 72727);
} 
