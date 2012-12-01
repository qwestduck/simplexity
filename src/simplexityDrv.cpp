#include "game.h"
#include <string>

void usage() {
  std::cout << "./simplexity <game_type>" << std::endl;
  std::cout << std::endl;
  std::cout << "  game_type:" << std::endl;
  std::cout << "  -rvr for random vs random" << std::endl;
  std::cout << "  -rvs for random vs smart" << std::endl;
  std::cout << "  -svs for smart vs smart" << std::endl;
}

int main(int argc, char* argv[]) {
  RvRGame rvrg;
  RvSGame rvsg;
  SvSGame svsg;

  if(argc != 2)
    usage();
  else {
    std::string arg = argv[1];
    if(arg == "-rvr")
      rvrg.play();
    else if(arg == "-rvs")
      rvsg.play();
    else if(arg == "-svs")
      svsg.play();
    else
      usage();
  }

  return 0;
}
