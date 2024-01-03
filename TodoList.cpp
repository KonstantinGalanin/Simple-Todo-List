#include <iostream>
#include <list>

class TodoItem {
private:
    int id;
    std::string description;
    bool status;
public:
    TodoItem() : id(0), description(""), status(false) {}
    ~TodoItem() = default;

    void create(std::string& description, int id) {
        this->description = description;
        this->id = id;
    }

    void set_completed() {
        status = true;
    }

    int get_id() {
        return id;
    }
    std::string& get_description() {
        return description;
    }
    bool get_status() {
        return status;
    }

};

int main() {
    std::list<TodoItem> TodoItems;
    std::list<TodoItem>::iterator it;
    int id_counter = 0;
    TodoItems.clear();
    while(true) {
        std::system("clear");
        std::cout << "-------- Todo List --------" << std::endl;

        for(it = TodoItems.begin(); it != TodoItems.end(); ++it) {
            std::string completed = it->get_status() ? "Done" : "Not Done";
            std::cout << it->get_id() << "\t" << it->get_description() << "\t" << completed << std::endl;
        }

        if(TodoItems.empty()) {
            std::cout << "Add your first Todo !" << std::endl;
        }

        std::cout << std::endl << std::endl;
        std::cout << "Choose option" << std::endl;
        std::cout << "\t 1. Add a new Todo" << std::endl;
        std::cout << "\t 2. Complete a Todo" << std::endl;
        std::cout << "\t 3. Quit" << std::endl;

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if(choice == 1) {
            std::cout << "Write new description" << std::endl;
            TodoItem newItem;
            std::string description;
            std::getline(std::cin, description);
            newItem.create(description, ++id_counter);
            TodoItems.push_back(newItem);
        }
        else if(choice == 2) {
            std::cout << "Enter id to complete Todo" <<std::endl;
            int id;
            std::cin >> id;
            for(it = TodoItems.begin(); it != TodoItems.end(); ++it) {
                if(it->get_id() == id) {
                    it->set_completed();
                    break;
                }
            }
        }
        else if(choice == 3) {
            break;
        }
    }
}