#include <iostream>
#include <memory>

class Transport {
public:
  virtual void Send() = 0;
};

class Adapter : public Transport, std::enable_shared_from_this<Adapter>  {
public:
  virtual void Send() {
    std::cout << "Send" << std::endl;
    std::weak_ptr<Adapter> weak = shared_from_this();
  }
};

int main(void) {
  std::shared_ptr<Transport> transport = std::make_shared<Adapter>();

  // bad_weak_ptr
  transport->Send();
}
