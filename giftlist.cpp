/*--------------------------------------------------------
 * Program that asks a user for a list of nice kid's names 
 and the toys they would like then displays them. 
 --------------------------------------------------------*/

#include <iostream>
#include <list>
#include <vector>

class Child {
private:
    std::string name;
    std::list<std::string> toys;

public:
    Child(){}

    Child(std::string n){
        name = n;
    }
    void insert(int newPosition, const std::string& newEntry){
        toys.push_back(newEntry);

    }

    void display(){
        std::cout << name << ": ";
        for(int i=0; i<toys.size(); i++)
        std::cout << *std::next(std::begin(toys), i) << " ";
        std::cout << std::endl;

    }

};

int main() {

    Child *childPtr;
    bool line = true;
    std::string name;
    std::string gift;
    int index;
    int moniker;
    std::vector<Child*> namelist;

    while(line) {

        std::cout << "name for nice list: ";
        std::getline(std::cin, name);
        if(name.length() > 0){

            childPtr = new Child(name);
            bool kid = true;
            namelist.push_back(childPtr);
            std::cout << "add gifts for " << name << std::endl;
            while(kid){
            std::cout << "gift: ";
            std::getline(std::cin, gift);
            if(gift.length() > 0){
                namelist[moniker]->insert(index, gift);
                index++;
            }else{
                kid = false;
                moniker++;
            }
            }

        }else{

            line = false;

        }

    }

    std::cout << "The list contains\n";

    for(int i=0; i<namelist.size(); i++)
        namelist[i]->display();

    return 0;
}
