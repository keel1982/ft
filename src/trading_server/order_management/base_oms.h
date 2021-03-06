// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_TRADING_SERVER_ORDER_MANAGEMENT_BASE_OMS_H_
#define FT_SRC_TRADING_SERVER_ORDER_MANAGEMENT_BASE_OMS_H_

#include <string>

#include "protocol/data_types.h"

namespace ft {

class BaseOrderManagementSystem {
 public:
  /*
   * 有新的tick数据到来时回调
   */
  virtual void OnTick(TickData* tick) {}

  /*
   * 订单被交易所接受时回调（如果只是被柜台而非交易所接受则不回调）
   */
  virtual void OnOrderAccepted(OrderAcceptance* rsp) {}

  /*
   * 订单被拒时回调
   */
  virtual void OnOrderRejected(OrderRejection* rsp) {}

  /*
   * 订单成交时回调
   */
  virtual void OnOrderTraded(Trade* rsp) {}

  /*
   * 撤单成功时回调
   */
  virtual void OnOrderCanceled(OrderCancellation* rsp) {}

  /*
   * 撤单被拒时回调
   */
  virtual void OnOrderCancelRejected(OrderCancelRejection* rsp) {}
};

}  // namespace ft

#endif  // FT_SRC_TRADING_SERVER_ORDER_MANAGEMENT_BASE_OMS_H_
