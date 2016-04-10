#include <future>
#include "application/doorbell.h"

#include "application/ipoll.h"

namespace Module {

Doorbell::Doorbell(IPoll & button)
  : _button(button)
  , _subscribers()
  , _listener()
{
}

Doorbell::~Doorbell() {
  _listener.join();
}

void Doorbell::subscribe(ISubscriber & subscriber) {
  _subscribers.emplace_back(subscriber);
}

void Doorbell::start() {
  _listener = std::thread([&]{
    if (_button.poll()) {
      _subscribers.front().get().notify();
    }
  });
}

}
