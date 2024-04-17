

#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
  Citation(const std::string& title, int year)
      : _title(title), _year(year) {};

  virtual ~Citation() {}
  virtual void printCitation(std::ostream& ostr) const = 0;
  virtual std::string getInlineCitation() const = 0;
  virtual std::string getType() const = 0;
  virtual std::string getData() const = 0;

protected:
  std::string _title;
  int _year;
};

// example 1 - Web Page
// you will need to modify it
class WebPage : public Citation
{
public:
  WebPage(const std::string& title, int year, const std::string& url)
      : Citation(title, year),
        _url(url) {};
  virtual ~WebPage() {};

  virtual void printCitation(std::ostream& ostr) const override {
      ostr << "Title: " << _title << '\n';
      ostr << "Year: " << _year << '\n';
      ostr << "URL: " << _url << '\n';
  }
  virtual std::string getInlineCitation() const override {
    return "[Web page, " + std::to_string(_year) + "]";
  }
  virtual std::string getType() const override {
    return "WebPage";
  }
  virtual std::string getData() const override {
    return _title;
  }


protected:
  std::string _url;
};


class PublishedWork : public Citation
{
protected:
  std::string _firstname;
  std::string _lastname;

public:
  PublishedWork(const std::string& title, int year,
                const std::string& firstname, const std::string& lastname) 
                : Citation(title, year), _firstname(firstname), _lastname(lastname) {};
  virtual ~PublishedWork() {};
  virtual void printCitation(std::ostream &ostr) const override {
    ostr << "Title: " << _title << '\n';
    ostr << "Year: " << _year << '\n';
    ostr << "Author: " << _firstname << " " << _lastname << '\n';
  }

};


class Article : public PublishedWork
{
protected:
  std::string _journal;

public:
  Article(const std::string& title, int year, 
          const std::string& firstname, const std::string& lastname, 
          const std::string& journal) 
            : PublishedWork(title, year, firstname, lastname), _journal(journal) {};
  virtual ~Article() {};
  virtual void printCitation(std::ostream &ostr) const override {
    ostr << "Title: " << _title << '\n';
    ostr << "Year: " << _year << '\n';
    ostr << "Author: " << _firstname << " " << _lastname << '\n';
    ostr << "Journal: " << _journal << '\n';
  }
  virtual std::string getInlineCitation() const override {
    return "[" + _lastname + ", " + std::to_string(_year) + "]";
  }
  virtual std::string getType() const override {
    return "Article";
  }
  virtual std::string getData() const override {
    return _lastname;
  }
  
};

// example 2 - Book
// included only as an example, not used in the tasks
// class Book : public PublishedWork
// {
// public:
//     Book(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& publisher)
//         : PublishedWork(title, year, firstname, lastname),
//           _publisher(publisher)
//     {
//     }

//     void printCitation(std::ostream& ostr) const override
//     {
//         PublishedWork::printCitation(ostr);
//         ostr << "Publisher:" << _publisher << std::endl;
//     }

// protected:
//     std::string _publisher;
// };


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations,
                      CitationType type,
                      const std::map<std::string, std::string> data)
{
  Citation* citationToAdd;
  std::string title = data.at("title");
  int year = stoi(data.at("year"));

  if (type == CitationType::WebPage) {
    std::string url = data.at("url");
    citationToAdd = new WebPage{title, year, url};
    citations[data.at("key")] = citationToAdd;
  }
  else if (type == CitationType::Article) {
    std::string journal = data.at("journal");
    std::string firstname = data.at("firstname");
    std::string lastname = data.at("lastname");
    citationToAdd = new Article{title, year, firstname, lastname, journal};
    citations[data.at("key")] = citationToAdd;
  }

  return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
  for (const std::map<std::string, Citation*>::value_type& citation: citations) {
    std::string key = citation.first;
    // std::cout << citation.first << '\n';
    while (text.find(key) != std::string::npos) {
      text.replace(text.find(key), key.size(), citation.second->getInlineCitation());
    }
  }
}


// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
  std::string tmp_key = "";
  bool flag = false;
  std::vector<std::string> data;
  std::set<std::string> unique_data;

  for (char c: text) {
    if (c == '{') {
      flag = true;
    }
    else if (c == '}') {
      tmp_key += c;

      if (unique_data.find(tmp_key) == unique_data.end()) {
        data.push_back(tmp_key);
        unique_data.insert(tmp_key);
      }

      tmp_key = "";
      flag = false;
    }

    if (flag)
      tmp_key += c;
  }

  int cnt = 1;
  for (auto& ele: data) {
    for (auto& citation: citations) {
      if (ele == citation.first) {
        std::cout << cnt << '.' << '\n';
        citation.second->printCitation(std::cout);
        cnt++;
      }
    }
  }
}


// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions
int getIndex(std::vector<std::string> v, std::string K) 
{ 
    auto it = find(v.begin(), v.end(), K); 
  
    if (it != v.end())  
    { 
        int index = it - v.begin(); 
        return index;
    } 
    else { 
        return 1;
    } 
} 
void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
  std::string tmp_key = "";
  bool flag = false;
  std::vector<std::string> data_web;
  std::set<std::string> data_key;
  std::vector<std::string> data_art;

  for (char c: text) {
    if (c == '{') {
      flag = true;
    }
    else if (c == '}') {
      tmp_key += c;

      for (auto& citation: citations) {
        if (tmp_key == citation.first && citation.second->getType() == "Article") {
          if (data_key.find(tmp_key) == data_key.end()) {
            data_art.push_back(citation.second->getData());
            data_key.insert(tmp_key);
          }
        };
      }

      tmp_key = "";
      flag = false;
    }

    if (flag)
      tmp_key += c;
  }

  for (char c: text) {
    if (c == '{') {
      flag = true;
    }
    else if (c == '}') {
      tmp_key += c;

      for (auto& citation: citations) {
        if (tmp_key == citation.first && citation.second->getType() == "WebPage") {
          if (data_key.find(tmp_key) == data_key.end()) {
            data_web.push_back(citation.second->getData());
            data_key.insert(tmp_key);
          }
        };
      }

      tmp_key = "";
      flag = false;
    }

    if (flag)
      tmp_key += c;
  }

  std::sort(data_web.begin(), data_web.end());
  std::sort(data_art.begin(), data_art.end());

  // for (auto& ele: data_art) {
  //   std::cout << ele << '\n';
  // }
  //
  // for (auto& ele: data_web) {
  //   std::cout << ele << '\n';
  // }

  int unique_ele = std::set<std::string>(data_art.begin(), data_art.end()).size();

  for (auto& ele: data_key) {
    int cnt = 0;
    // std::cout << ele << '\n';
    std::string data = "";
    std::string type = "";
    for (auto& citation: citations) {
      if (ele == citation.first) {
        type = citation.second->getType();
        data = citation.second->getData();
        // std::cout << type << " " << data << '\n';
      }
    }

    if (type == "WebPage") {
      while (text.find(ele) != std::string::npos) {
        text.replace(text.find(ele), ele.size(),
                    "[" + std::to_string(getIndex(data_web, data)+unique_ele+1) + "]");
      }
    }
    else if (type == "Article") {
      while (text.find(ele) != std::string::npos) {
        text.replace(text.find(ele), ele.size(),
                    "[" + std::to_string(getIndex(data_art, data) + 1) + "]");
      }
    }

  }

  // std::cout << data_web.size() << " " << data_art.size() << '\n';
}

#endif
