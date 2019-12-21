/*
 * File:   protocol.h
 * Author: kshar
 *
 * Created on 20 ноября 2019 г., 20:47
 */
/**
 * hello
пакет от контроллера к клиенту
0x6969

hello + pass
пакет от клиента, внутри пароль
0x9696[1 длинна пароля][пароль]


get values
пакет от клиента, внутри ключи переменных
0x1001[4 count][4xcount guids]

set values
пакет от клиента, внутри ключи переменных
0x1001[4 count][4xcount guids][data]

get values meta
пакет от сервера, внутри ключи переменных, типы и описание
0x2001[4 data size][4 values count]{
  2x type
  4x guid
  4x idSize
  idSize id
}

get values
пакет от сервера, внутри ключ переменной и её значение
0x2002[4 count][4xcount guids][data]*/

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "main.h"
#include <array>
#include <vector>

using namespace std;

class Protocol {
public:
  typedef uint16_t VatueGUID;
  enum ValueType : uint16_t {
    INT,
    UINT
  };

  Protocol(UART_HandleTypeDef *huart);
  /**
   * Передать клиенту информацию о доступных переменных
   */
  void sendValuesMeta();
  /**
   * Передать клиенту значения переменных
   */
  void sendValuesData(VatueGUID* guids, size_t count);
  /**
   * Передать клиенту приветствие(ничего не значит)
   */
  void sendHello();
  /**
   * Передать клиенту код ошибки
   */
  void sendError(uint16_t code);
private:
  enum CurrentState {
    INITAL
  };
  struct ValueConfig {
    VatueGUID id;
    ValueType type;
  };
  UART_HandleTypeDef *huart;
  CurrentState currentState;
  vector<ValueConfig> values;
};

#endif /* PROTOCOL_H */
