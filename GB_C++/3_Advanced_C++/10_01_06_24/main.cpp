#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::vector<std::string> history;
std::mutex history_access;

void wait_for_call(int time, std::string name)
{
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "Id: " << std::this_thread::get_id() << std::endl;
    std::cout << "RING! RING! RING! (" << name << ")" << std::endl;

    history_access.lock();
    history.push_back(name);
    history_access.unlock();
}

int main()
{
    int time;
    std::cout << "Enter the time: ";
    std::cin >> time;
    std::string name;
    std::cout << "Enter the name: ";
    std::cin >> name;

    std::cout << "Id: " << std::this_thread::get_id() << std::endl;

    std::thread call(wait_for_call, time, name);
    std::thread call_two(wait_for_call, 5, "Ksyusha");
    std::thread call2(wait_for_call, 7, "John");
    call.detach();
    call_two.detach();
    call2.detach();

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Id: " << std::this_thread::get_id() << std::endl;
    std::cout << "Answering the phone\n";

    if(call.joinable()) call.join();
    if(call2.joinable()) call2.join();
    if(call_two.joinable()) call_two.join();

    // print history
    history_access.lock();
    std::cout << "History: ";
    for(auto i : history)
    {
        std::cout << i << " ";
    }
    history_access.unlock();

    return 0;
}