//Amylea
//1123552
//2024.11.28
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Task {
    string name;
    int priority;
    
    // Overload < operator to prioritize higher priority tasks
    bool operator<(const Task& other) const {
        return priority < other.priority;  // higher priority comes first
    }
};

int main() {
    priority_queue<Task> pq;
    map<string, int> remainingTasks;

    int n;
    cout << "Enter the number of operations: ";
    cin >> n;
    cin.ignore();  // to ignore the newline after reading the integer

    while (n--) {
        string command;
        cout << "Enter operation: ";
        getline(cin, command);
        
        if (command.substr(0, 3) == "ADD") {
            string taskName;
            int priority;
            size_t pos = command.find(' ', 4);  // Find the first space after "ADD"
            taskName = command.substr(4, pos - 4);  // Extract the task name
            priority = stoi(command.substr(pos + 1));  // Extract the priority
            
            // Add task to the priority queue and map
            pq.push({taskName, priority});
            remainingTasks[taskName] = priority;
        }
        else if (command == "GET") {
            if (pq.empty()) {
                cout << "No tasks available" << endl;
            } else {
                Task top = pq.top();
                pq.pop();
                cout << top.name << endl;  // Output the task with the highest priority
                remainingTasks.erase(top.name);  // Remove from remaining tasks map
            }
        }
    }

    // Output remaining tasks
    cout << "Remaining tasks: ";
    bool first = true;
    for (const auto& task : remainingTasks) {
        if (!first) {
            cout << " ";
        }
        first = false;
        cout << "(" << task.first << ", " << task.second << ")";
    }
    cout << endl;

    return 0;
}

