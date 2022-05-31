#include <iostream>
#include <vector>
#include <fstream>

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

void dupes (std::string filename) {
  std::vector<long> seeds = get_seed(filename);
  std::ofstream myfile;
  myfile.open(filename, std::ios::trunc);
  //std::cout << seeds.size() << std::endl;

  for (int i = 0; i < seeds.size(); i++){
    //std::cout << "i: " <<  i << std::endl;

    for (int o = i+1; o < (seeds.size()); o++) {
      //std::cout << "o: " <<  o << std::endl;
      
      if (seeds[i] == seeds[o]) {
        //std::cout << "Same\n";
        //std::cout << seeds[i] << ":"<<seeds[0]<<std::endl;
        std::cout << seeds.size() << std::endl;
        seeds.erase(seeds.begin()+o);
        o--;
      }
    }
  }
  for (int i = 0; i != seeds.size(); i++) {
    //std::cout << "i2: " <<  i << std::endl;
    myfile << seeds[i] << "\n";
  }
  //myfile << "Input\n";
  myfile.close();
  }

int main() {
  dupes("/home/runner/ShockedSeveralCoins/texts/ones.txt");
}
