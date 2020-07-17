

#include <iostream>
#include <thread>


void test () {
    std::cout << "Hello from test \n";
}

std::thread C;
void funcA () {
    std::cout << "Hello from funcA \n";
    ::C = std::thread(::test);
}
void funcB() {
    std::cout << "Hello from funcB \n";
}

void run () {

    std::thread threadB (funcB);
    std::thread threadA (funcA);

    // ::C.join(); // Error! cannot join ::C ahead of A
    threadA.join();
    ::C.join();
    threadB.join();
    return;
}



int main () {
    run ();
    return 1;
}
