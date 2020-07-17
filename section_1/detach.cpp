

#include <iostream>
#include <thread>
#include <chrono>


void foo () {
    std::this_thread::sleep_for (std::chrono::milliseconds(5000));
    std::cout << "Hell from foo" << std::endl;
}
void bar () {
    std::this_thread::sleep_for (std::chrono::milliseconds(4000));
    std::cout << "Hell from bar" << std::endl;
}



void run () {
    std::thread foo_thread (foo);
    std::thread bar_thread (bar);

    bar_thread.detach();
    std::cout << "After bar thread is detached\n";

    foo_thread.join();
    std::cout << "After foo thread is joined\n";

    return;
}



int main () {
    run ();
    return 1;
}
