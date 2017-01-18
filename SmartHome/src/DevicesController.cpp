#include "../include/DevicesController.hpp"

void DevicesController::action(Device *device, const TypeOfAction &type) {
  device->connect();
  type == TypeOfAction::on ? device->on() : device->off();
  device->disconnect();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
