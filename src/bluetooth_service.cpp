#include "bluetooth_service.h"

static const char* TAG = "bluetooth_service";

void bluetooth_service_init() {
  // Initialize the NimBLE device
  NimBLEDevice::init("LVS-Gateway01");

  // Create a new server
  NimBLEServer *pServer = NimBLEDevice::createServer();

  // NimBLE-Arduino 2.x manages advertising parameters differently from 1.x.
  // The old setScanResponse()/setMinPreferred() APIs are no longer available.
  // Service UUIDs are added by lovense_init() before advertising starts.
}

void bluetooth_service_start() {
  NimBLEDevice::startAdvertising();
}

void bluetooth_service_stop() {
  NimBLEDevice::stopAdvertising();
}
