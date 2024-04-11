#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

void show_container(stack<int> container) {
  while (!container.empty()) {
    std::cout << container.top() << " "; // Muestra el elemento superior
    container.pop(); // Elimina el elemento superior
  }
  cout << endl;
}

int countStudents(vector<int>& students, vector<int>& sandwiches) {
  vector<int> s_students;
  vector<int> s_sandwiches;
  for (int s : students) s_students.push_back(s);
  for (int s : sandwiches) s_sandwiches.push_back(s);
  int no_eat=0;
  while (s_sandwiches.size()>0 && no_eat < students.size()) {
    if (s_students[0] == s_sandwiches[0]) {
      s_students.erase(s_students.begin());
      s_sandwiches.erase(s_sandwiches.begin());
      no_eat=0;
    } else {
      s_students.push_back(s_students[0]);
      s_students.erase(s_students.begin());
      no_eat++;
    }
  }
  return s_students.size();
}

int Solution::solve() {  
  vector<int> students = {1,1,0,0};
  vector<int> sandwiches = {0,1,0,1};
  students={1,1,1,0,0,1};
  sandwiches = {1,0,0,0,1,1};
  cout << countStudents(students, sandwiches);
  return 0;
}

// Solution with queue

// int countStudents(vector<int>& students, vector<int>& sandwiches) {
//     int n=students.size();
//     queue<int> q;
//     for(int i=0;i<n;i++){
//         q.push(students[i]);
//     }
//     int count=0;
//     int i=0;
//     while(q.size()>0 && count!=q.size()){
//         if(q.front()==sandwiches[i]){
//             q.pop();
//             i++;
//             count=0;
//         }
//         else{
//             q.push(q.front());
//             q.pop();
//             count++;
//         }
//     }
//     return q.size();
// } 