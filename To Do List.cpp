#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(std::string d, bool c) : description(d), completed(c) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.emplace_back(desc, false);
    }

    void viewTasks() {
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                std::cout << " - Completed";
            }
            std::cout << std::endl;
        }
    }

    void markAsCompleted(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList list;
    int choice;
    std::string taskInput;

    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter task description: ";
            std::cin.ignore();
            std::getline(std::cin, taskInput);
            list.addTask(taskInput);
            break;
        case 2:
            list.viewTasks();
            break;
        case 3:
            std::cout << "Enter task index to mark as completed: ";
            int completeIndex;
            std::cin >> completeIndex;
            list.markAsCompleted(completeIndex);
            break;
        case 4:
            std::cout << "Enter task index to remove: ";
            int removeIndex;
            std::cin >> removeIndex;
            list.removeTask(removeIndex);
            break;
        case 5:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 5);

    return 0;
}