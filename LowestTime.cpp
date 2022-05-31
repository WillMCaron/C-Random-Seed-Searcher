#include <vector>
#include <fstream>
#include <iostream>

std::vector<long> get_times (std::string filename) {
  std::ifstream myfile (filename);
  std::string line;
  std::vector<long> times;
  while (myfile.good()) {
    myfile >> line;
    times.push_back(std::stol(line));
    //std::cout << "1" <<std::endl;
  }
  //std::cout << seeds[0];
  myfile.close();
  return times;
}

void maximum (std::vector<long> times) {
  long max = 9223372036854775807;
  long news;
  for (int i = 0; i < times.size(); i++) {
    news = times[i];
    if (news < max) {
      max = news;
    }
  }
  std::cout << max << std::endl;
}

int main () {
  maximum(get_times("/home/runner/ShockedSeveralCoins/texts/times.txt"));
}
