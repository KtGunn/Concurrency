

#include <iostream>
#include <thread>
#include <chrono>

#include "thread_guard.h"

void foo () {
    std::this_thread::sleep_for (std::chrono::milliseconds(5));
    std::cout << "Hello from foo" << std::endl;
}
void other_operations () {
    std::cout << " Throwing in other_operations()\n";
    throw std::runtime_error (" Sumd ding wong!\n");
    return;
}

void run () {

    std::thread foo_thread (foo);
    CThread_guard TG (foo_thread);

    
    try {
	other_operations();
	// This works but is cumbersome
	//foo_thread.join();
    } catch (...) {
	//foo_thread.join();
	std::cout << " Error has been caught!\n";
    }

    foo_thread.join();
    
    return;
}



int main () {
    run ();
    return 1;
}
