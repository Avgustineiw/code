#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

//     Main task - to implement the function fillCountries to put countries into a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the container.
//     4. Add a country to the container or a city to an existing country.

struct Coordinate
{
  double longitude;
  double latitude;
};

struct City
{
  std::string name;
  int population;
  Coordinate coordinate;

  bool operator<(const City& _city) const {
    (*this).population < _city.population;
  }
};

struct Country
{
  std::string name;
  std::set<City> cities;

  bool operator<(const Country& _country) const {
    return (*this).cities < _country.cities;
  }
};


void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
  std::map<std::string, int> ec;
  std::string example;

  getline(inFile, example);

  while (!inFile.eof()) {
    std::string line, city_name, country_name, tmp;
    double lon, lat;
    int pop;

    getline(inFile, line);

    std::stringstream ss(line);

    getline(ss, city_name, ',');
    getline(ss, tmp, ',');
    lon = stod(tmp);
    getline(ss, tmp, ',');
    lat = stod(tmp);
    getline(ss, country_name, ',');
    getline(ss, tmp, ',');
    pop = stoi(tmp);

    City _city = {city_name, pop, {lon, lat}};

    if (ec.find(country_name) != ec.end()) {
      int ind = ec[country_name];
      countries[ind].cities.insert(_city);
    }
    else {
      std::set<City> C;
      Country Con = {country_name, C};
      Con.cities.insert(_city);
      countries.push_back(Con);
      // ec[country_name] = countries.size()-1;
    }
  }
}

std::ostream& operator<<(std::ostream& out, City _city) {
  out << "city = " << _city.name << ", population = " << _city.population << ", coordinates = " << "(" << _city.coordinate.latitude << " , " << _city.coordinate.longitude << ")";

  return out;
}

int main()
{
  const std::string FILENAME = "cities.csv";
  std::ifstream inputFile;
  std::vector<Country> countries;

  inputFile.open(FILENAME);

  if(inputFile) {
    std::cout<<"OK\n";
  }

  fillCountries(inputFile, countries);

  sort(countries.begin(), countries.end());

  for (int i = 0; i < countries.size(); i++) {
    // std::cout << countries[i].name << std::endl;

    for (City city: countries[i].cities) {
      std::cout << city << std::endl;
    }
  }
  
  return 0;
}