#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>


// #include <sys/wait.h>
#ifdef __linux__
    #include <sys/wait.h>
    #include <unistd.h>
#endif



#include "../encryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement() {}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task)
{
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks()
{
    while (!taskQueue.empty())
    {
        std::unique_ptr<Task> tasktoExcecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout << "Excecuting Tasks : " << tasktoExcecute->toString() << std::endl;
        executeCryption(tasktoExcecute->toString());
    }
}
