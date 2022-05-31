#include <iostream>
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <fstream>
#include <cmath>
#include <cstdint>

std::pair<int, long> lucas(int goal) {
  using namespace std::chrono;
  auto ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  long seed = time(NULL)*ms*rand();
  srand(seed);
  int num;
  int count = 0;
  do {
    count ++;
    num = rand()%100001;
    //std::cout << num << std::endl;
  } while (num != goal && count < 2);
 //std::cout << "It took: " << count << " tries!" <<std::endl;
  return std::make_pair(count, seed);
}

void save(long seed, std::string filename) {
  std::ofstream outfile;
  outfile.open(filename, std::ios_base::app);
  outfile << seed << "\n";
  outfile.close();
}

void will (int goal) {
  typedef std::chrono::high_resolution_clock time;
  auto t_start = time::now();
  long seed;
  int lapses = 0;
  int count;
  do {
    lapses ++;
    std::pair<int, long> r = lucas(goal);
    count = r.first;
    seed = r.second;
  // Originally one
  } while (count > 1);
  auto t_end = time::now();

  std::chrono::duration<double, std::milli> elapsed = t_end-t_start;
  auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(t_end-t_start);
  int passed = elapsed_time.count();
  int ms_passed = elapsed.count();
  int minutes = (passed-(passed%60))/60;
  int seconds = (passed-(minutes)*60)%60;
  float milliseconds = ms_passed - (1000*seconds) - (60000*minutes);

  std::cout << "Time Elapsed: " << minutes << "mins\n";
  std::cout << "Time Elapsed: " << seconds << " s\n";
  std::cout << "Time Elapsed: " << milliseconds << " ms\n";
  std::cout << "I searched " << lapses << " seeds!" << std::endl;
  std::cout << "The seed was " << seed << std::endl;
  std::cout << "It found " << goal << " in "<< count << " tries!" << std::endl;
  std::cout <<std::endl;
  save(seed, 
  "/home/runner/ShockedSeveralCoins/texts/ones.txt");
  long secs = std::floor(ms_passed/1000);
  save(secs, "/home/runner/ShockedSeveralCoins/texts/times.txt");
}

int main() {
  for (int i = 0; i < 5000; i++) {
    will(72727);
  }
} 
