#ifndef SKELETON_SCHEDULER_H
#define SKELETON_SCHEDULER_H

#include "ischeduler.h"

namespace Module {

class Scheduler : public IScheduler {
public:

  void start();

  virtual std::future<uint32_t> schedule(std::function<uint32_t()> request) override final;
};

}

#endif //SKELETON_SCHEDULER_H