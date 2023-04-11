// algorithms-STL-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <string>
#include <iomanip>

class Person {
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}
    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person& rhs) const {
        return(this->name == rhs.name && this->age == rhs.age);
    }
};

void find_test() {
    std::cout << std::setw(33) << "\n" << std::setfill('-') << std::endl;
    std::vector<int> vec{ 1,2,3,4,5 };
    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number." << std::endl;
    std::list<Person> players{
        {"Jenny", 22},
        {"Liz", 21},
        {"Gabriel", 24}
    };
    auto loc1 = std::find(players.begin(), players.end(), Person{ "Liz", 21 });
    if (loc1 != players.end())
        std::cout << "Found the player Liz" << std::endl;
    else
        std::cout << "Couldn't find Player." << std::endl;
}

void count_test() {
    std::cout << std::setw(33) << "\n" << std::setfill('-') << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,1,2,1 };
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurences found." << std::endl;
}

void count_if_test() {
    std::cout << std::setw(33) << "\n" << std::setfill('-') << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };
    int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; });
    std::cout << num << " even numbers found." << std::endl;
    num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0; });
    std::cout << num << " odd numbers found." << std::endl;
    num = std::count_if(vec.begin(), vec.end(), [](int x) {return x >= 5; });
    std::cout << num << " numbers are greater than or equal to 5." << std::endl;
}

void replace_test() {
    std::cout << std::setw(33) << "\n" << std::setfill('-') << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test() {
    std::cout << std::setw(33) << "\n" << std::setfill('-') << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,101,6,7,8,9,11,23 };
    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10; }))
        std::cout << "All the elements are > 10 " << std::endl;
    else
        std::cout << "Not all the elements are > 10 " << std::endl;
    if (std::any_of(vec.begin(), vec.end(), [](int x) {return x > 100; }))
        std::cout << "Any of the elements are > 100 " << std::endl;
    else
        std::cout << "Not any of the elements are > 100 " << std::endl;
}

void string_transform_test() {
    std::cout << std::setw(33) << "\n" << std::setfill('-') << std::endl;
    std::string str1{ "This is a transform test." };
    std::cout << "Before the transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After the transform: " << str1 << std::endl;
}

int main()
{
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
    return 0;
}

