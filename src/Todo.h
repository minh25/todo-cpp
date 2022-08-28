#include <string>
using namespace std;

struct Todo{
    int id;
    string task;
    string note;
    string isDone;
    int typeId;
};

struct TodoType{
    int id;
    string name;
};