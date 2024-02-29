#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

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

// task 3
void sortTasks(std::vector<Task>& tasks)
{
  
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
  // replace with your own return
  return 0;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
}
