#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>


class FootballTeam {
  std::string name_;
  std::string city_;
  std::string stadium_;
  double level_;
  int points_;
  int wins_;
  int losses_;
  int draws_;

  public:
  FootballTeam(std::string name, std::string city, std::string stadium, double level) {
    name_ = name;
    city_ = city;
    stadium_ = stadium; 
    level_ = level;
    points_ = 0;
    wins_ = 0;
    losses_ = 0;
    draws_ = 0;
  }

  std::string GetName() 
  {
    return name_;
  }

  std::string GetCity() 
  {
    return city_;
  }

  std::string GetStadium()
  {
    return stadium_;
  }

  void AddWin()
  {
    wins_++;
  }

  void AddDraw()
  {
    draws_++;
  }

  void AddLoss()
  
    losses_++;
  }

  void SetPoints(int points) 
  {
    points_ = points;
  }

  int GetPoints()
  {
    return points_;
  }

  int GetLevel()
  {
    return level_;
  }
};

struct Match
{
  FootballTeam& localTeam;
  FootballTeam& visitorTeam;
  int localGoals;
  int visitorGoals;

  void Play()
  {
    int k = (rand() % ceil(abs(localTeam.level_ - visitorTeam.level_)) * 10);
    std::cout << k;
  }
};


struct Tournament
{
  std::vector<FootballTeam> teams;
  int round;

  void SimulateRound()
  {
    
  }
};


void parseLineTeam(const std::string& line, std::string& name, std::string& city, std::string& stadium, double& level)
{
    size_t posName = line.find(',');
    name = line.substr(0, posName);
    
    size_t posCity = line.find(',', posName + 1);
    city = line.substr(posName + 1, posCity - posName - 1);
    
    size_t posStadium = line.find(',', posCity + 1);
    stadium = line.substr(posCity + 1, posStadium - posCity - 1);

    size_t posLevel = line.size() - 1;
    std::string levelString = line.substr(posStadium + 1, posLevel - posStadium);
    std::stringstream ss(levelString);
    ss >> level;
}


void loadTeams(std::istream& in, std::vector<FootballTeam>& teams)
{
  std::string buffer;
  getline(in, buffer);
  
  while(getline(in, buffer)) {
      std::string name;
      std::string city;
      std::string stadium;
      double level;

      parseLineTeam(buffer, name, city, stadium, level);

      std::cout << "name = " << name << '\n';
      std::cout << "city = " << city << '\n';
      std::cout << "stadium = " << stadium << '\n';
      std::cout << "level = " << level << "\n\n";

      FootballTeam team = {name, city, stadium, level};
      teams.push_back(team);
  }
}


int main()
{
  const std::string FILENAME = "football.csv";
  std::ifstream inputFile;
  inputFile.open(FILENAME);
  
  std::vector<FootballTeam> teams;

  loadTeams(inputFile, teams);
  
  return 0;
}