#ifndef PIN_GPIO_H
#define PIN_GPIO_H

#include "gpio.h"
#include "../main.h"

class PinGPIO {
public:
  /**
   * GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
   */
  GPIO_TypeDef* unit;

  /**
   * Specifies the port bit to be written.
   * This parameter can be one of GPIO_PIN_x where x can be (0..15).
   */
  uint16_t pin;

  PinGPIO(GPIO_TypeDef* unit, uint16_t pin) :unit(unit), pin(pin) {};

  inline void setState(bool state) {
    HAL_GPIO_WritePin(unit, pin, static_cast<GPIO_PinState>(state));
  }
  bool getState(bool state);
};

#endif /* PIN_GPIO_H */
