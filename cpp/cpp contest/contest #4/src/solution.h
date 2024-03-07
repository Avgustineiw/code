#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

struct Task {
  std::string text;
  std::string date;
  std::map<std::string, int> workloads;
  using Workload = std::map<std::string, int>::value_type;

  Task(const std::string& _text, const std::string& _date, const std::map<std::string, int>& _workloads);
  int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& _text, const std::string& _date, const std::map<std::string, int>& _workloads)
{
  text = _text;
  date = _date;
  workloads = _workloads;
}


struct Worker {
  std::string name;
  std::string login;
  int maxLoad;

  Worker(const std::string& _name, const std::string& _login, int _maxLoad);

  // might be needed for task 5
  bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& _name, const std::string& _login, int _maxLoad)
{
  name = _name;
  login = _login;
  maxLoad = _maxLoad;
}


// task 2
int Task::getTotalLoad() const
{
  int res = 0;

  for (const Task::Workload& w: workloads) {
      res += w.second;
  }
  
  return res;
}

bool comp(Task a, Task b)
{
  if (a.getTotalLoad() < b.getTotalLoad()) 
    return true;
  else if (a.getTotalLoad() > b.getTotalLoad()) 
    return false;
  else {
    if (a.date < b.date) 
      return true;
    else if (a.date > b.date) 
      return false;
    else {
      if (a.text < b.text) 
        return true;
      else 
        return false;
    }
   }
}

// task 3
void sortTasks(std::vector<Task>& tasks)
{
  sort(tasks.begin(), tasks.end(), comp);
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
  int res = 0;

  for (int i = 0; i < allTasks.size(); i++) {
    Task task = allTasks[i];
    for (std::map<std::string, int>::iterator it = task.workloads.begin(); it != task.workloads.end(); it++) {
      std::pair<std::string, int> x;
      x = *it;
      if (x.first == worker.login) {
        res += x.second;
      }
    }
  }

  return res;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
  std::string name; 
  for (int i = 0; i < workers.size(); i++) {

    std::string login = workers[i].login;
    std::map<std::string, int> data = newTask.workloads;

    for (std::map<std::string, int>::iterator it = data.begin(); it != data.end(); it++) {
        std::pair<std::string, int> x;
        x = *it;
        if (x.first == login) {
          if (workers[i].maxLoad < getWorkerLoad(tasks, workers[i]) + x.second) {
            throw std::runtime_error("Overworked");
          }
          else {
            tasks.push_back(newTask);
          }
      }
    }
  }
}

bool compText(const std::vector<std::string>& name_1, const std::vector<std::string>& name_2) 
{
  return name_1[0] <= name_2[0];
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{ 
  tasks.push_back(newTask);
  std::string name; 
  std::vector<std::vector<std::string>> error;

  for (int i = 0; i < workers.size(); i++) {
    std::string login = workers[i].login;
    int load = getWorkerLoad(tasks, workers[i]);
    int max_load = workers[i].maxLoad;

    if (max_load < load) {
      error.push_back({login, std::to_string(load - max_load)});
    }
  }

  sort(error.begin(), error.end(), compText);

  if (error.size() > 0) {
    std::string message = "Overworked: ";
    for (int i = 0; i < error.size(); i++) {
      message += error[i][0] + " by " + error[i][1];
      if (i + 1 != error.size()) {
        message += ", ";
      }
    }

    throw std::runtime_error(message);
  }
}
