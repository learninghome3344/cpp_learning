#include <iostream>
#include<fstream>
#include "addressbook.pb.h"

// cmake -B build && cmake --build build
// ./build/pb_learning

void PrintInfo(const tutorial::Person & person) { 
	std::cout << person.name() << std::endl; 
	std::cout << person.age() << std::endl; 
	std::cout << person.email() << std::endl;
}

int main()
{
	{
        tutorial::Person person;
        person.set_name("lifeng");
        int32_t age = 26;
        person.set_age(age);
        person.set_email("feng.li@gmail.com");
        PrintInfo(person);

        // Write
        std::fstream output("./log", std::ios::out | std::ios::trunc | std::ios::binary);
        if (!person.SerializeToOstream(&output)) {
            std::cerr << "Failed to write msg." << std::endl;
            return -1;
        }
        std::cout << "write to log successfully." << std::endl;
    }

    {
        tutorial::Person person2;
        std::fstream input("./log", std::ios::in | std::ios::binary);
        if (!person2.ParseFromIstream(&input)) {
            std::cerr << "Failed to parse address book." << std::endl;
            return -1;
        }
        PrintInfo(person2);
    }
    

	return 0;
}