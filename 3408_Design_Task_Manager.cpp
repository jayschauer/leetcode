#include <bits/stdc++.h>
using namespace std;

/**
 * 3408. Design Task Manager
 *
 * https://leetcode.com/problems/design-task-manager/
 */

class Task {
 public:
  int userId;
  int taskId;
  int priority;

  Task(int userId, int taskId, int priority)
      : userId(userId), taskId(taskId), priority(priority) {}

  bool operator<(const Task& other) const {
    if (priority == other.priority) {
      return taskId > other.taskId;
    }

    return priority > other.priority;
  }
};

class TaskManager {
  unordered_map<int, int> taskPriorityMap;
  set<Task> taskSet;

 public:
  TaskManager(vector<vector<int>>& tasks) {
    // nlogn to insert all our tasks
    for (const vector<int>& v : tasks) {
      taskPriorityMap.insert({v[1], v[2]});
      taskSet.insert({v[0], v[1], v[2]});
    }
  }

  void add(int userId, int taskId, int priority) {
    // task is guaranteed to be unique so don't need to do anything special
    // here log n complexity
    taskPriorityMap.insert({taskId, priority});
    taskSet.insert({userId, taskId, priority});
  }

  void edit(int taskId, int newPriority) {
    // 1) Lookup old task (log n):
    Task oldTask{-1, taskId, taskPriorityMap[taskId]};
    auto oldTaskIterator = taskSet.find(oldTask);

    // 2) Save userId and delete old task (log n)
    int userId = oldTaskIterator->userId;
    taskSet.erase(oldTaskIterator);

    // 3) Insert with updated priority (log n)
    taskPriorityMap[taskId] = newPriority;
    taskSet.insert({userId, taskId, newPriority});
  }

  void rmv(int taskId) {
    Task task{-1, taskId, taskPriorityMap[taskId]};
    auto taskIterator = taskSet.find(task);
    taskPriorityMap.erase(taskId);
    taskSet.erase(taskIterator);
  }

  int execTop() {
    if (taskSet.empty()) return -1;

    auto taskIterator = taskSet.begin();

    int userId = taskIterator->userId;
    taskPriorityMap.erase(taskIterator->taskId);
    taskSet.erase(taskIterator);
    return userId;
  }
};
