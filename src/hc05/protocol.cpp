#include "protocol.h"

Protocol::Protocol(UART_HandleTypeDef *huart) :huart(huart), currentState(Protocol::CurrentState::INITAL) {}

void Protocol::sendHello() {
  uint16_t pack = 0x6969;
  HAL_UART_Transmit(this->huart, (uint8_t*)&pack, 2, 0xFFFF);
}

void Protocol::sendError(uint16_t code) {
  uint32_t pack = 0x20f00000 | code;
  HAL_UART_Transmit(this->huart, (uint8_t*)&pack, 4, 0xFFFF);
}
