#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


class FootballTeam {
public:
  std::string name_;
  std::string city_;
  std::string stadium_;
  double level_;
  int points_;
  int wins_;
  int losses_;
  int draws_;

public:
  FootballTeam(std::string name = "", std::string city = "", std::string stadium = "", double level = 0) {
    this->name_ = name;
    this->city_ = city;
    this->stadium_ = stadium; 
    this->level_ = level;
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
  {  
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

  double GetLevel()
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
    int bound = ceil(abs(localTeam.GetLevel() - visitorTeam.GetLevel())) * 10;
    int goals = (rand() % bound) + 1;
    
    for (size_t i = 0; i < goals; i++) {
      double score = (rand() % (int(ceil(abs(localTeam.GetLevel() - visitorTeam.GetLevel())) + 1) * 10)) / 10 - localTeam.GetLevel();

      if (score > 0) 
        localGoals++;
      else 
        visitorGoals++;

      std::cout << goals << " " << score << " " << localGoals << " " << visitorGoals << '\n';
    }

    if (localGoals > visitorGoals) {
      localTeam.AddWin();
      localTeam.SetPoints(localTeam.GetPoints() + 3);
      visitorTeam.AddLoss();
    }
    else if (visitorGoals > localGoals) {
      visitorTeam.AddWin();
      visitorTeam.SetPoints(visitorTeam.GetPoints() + 3);
      localTeam.AddLoss();
    }
    else {
      visitorTeam.AddDraw();
      visitorTeam.SetPoints(visitorTeam.GetPoints() + 1);
      localTeam.AddDraw();
      localTeam.SetPoints(localTeam.GetPoints() + 1);
    }
  }
};


std::ostream& operator<<(std::ostream& out, Match match)
{
  out << "localTeam = " << match.localTeam.GetName() << " " << "visitorTeam = " << match.visitorTeam.GetName() << " "<< "stadium = " << match.localTeam.GetStadium() << " " << "result = " << match.localGoals << "-" << match.visitorGoals << '\n';
  
  return out;
}

struct Tournament
{
  std::vector<FootballTeam> teams;
  int round = 0;

  void SimulateRound()
  {
    for (size_t i = 0; i < teams.size() / 2; i++) {
      std::cout << i + 1 << '\n';
      int remaining = teams.size() - i - 1;
      Match match = {teams[i], teams[remaining], 0, 0};
      match.Play();
      std::cout << match << '\n';
    }

    FootballTeam TT = teams.back();

    for (size_t i = 1; i < teams.size(); i++) {
      FootballTeam tmp = teams[i];
      teams[i] = TT;
      TT = tmp;
    }
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

      FootballTeam t = FootballTeam(name, city, stadium, level);
      teams.push_back(t);
  }
}


int main()
{
  srand(time(NULL));
  const std::string FILENAME = "football.csv";
  std::ifstream inputFile;
  inputFile.open(FILENAME);
  
  std::vector<FootballTeam> teams;

  loadTeams(inputFile, teams);

  std::cout << teams.size() << '\n';
  Tournament tournament = {teams, 0};
  tournament.SimulateRound();
  
  return 0;
}
