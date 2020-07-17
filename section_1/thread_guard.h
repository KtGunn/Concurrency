
#pragma once

#include <vector>
#include <thread>


class CThread_guard {
 public:
    std::thread& t;

 public:
    explicit CThread_guard (std::thread& _t) : t(_t) {}
    ~CThread_guard () {
	if (t.joinable()) {
	    t.join();
	}
    }

    CThread_guard (CThread_guard& cont) = delete;
    CThread_guard& operator = (CThread_guard& cont) = delete;
    
};
