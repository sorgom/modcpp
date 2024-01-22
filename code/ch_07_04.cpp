//  ============================================================
//  chapter 7.4
//  ============================================================

#include "coding.h"

#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

void ch_07_04()
{
    chap(7.4);

    return;

    std::queue<int> produced_nums;
    std::mutex mtx;
    std::condition_variable cv;
    
    bool notified = false; // notification sign
    auto producer = [&]()
    {
        for (int i = 0; ; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::unique_lock<std::mutex> lock(mtx);
            cout << "+ " << i << endl;
            produced_nums.push(i);
            notified = true;
            cv.notify_all();
        }
    };
    auto consumer = [&]() 
    {
        while (true)
        {
            std::unique_lock<std::mutex> lock(mtx);
            while (!notified)
            { // avoid spurious wakeup
                cv.wait(lock);
            }
            // temporal unlock to allow producer produces more rather than
            // let consumer hold the lock until its consumed.
            lock.unlock();
            // consumer is slower
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            lock.lock();
            if (!produced_nums.empty())
            {
                cout << "- " << produced_nums.front() << endl;
                produced_nums.pop();
            }
            notified = false;
        }
    };
    std::thread p(producer);
    std::thread cs[2];
    for (int i = 0; i < 2; ++i)
    {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < 2; ++i)
    {
        cs[i].join();
    }
}
