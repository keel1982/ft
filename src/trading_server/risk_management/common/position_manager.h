// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_TRADING_SERVER_RISK_MANAGEMENT_COMMON_POSITION_MANAGER_H_
#define FT_SRC_TRADING_SERVER_RISK_MANAGEMENT_COMMON_POSITION_MANAGER_H_

#include <map>

#include "trading_server/risk_management/risk_rule.h"
#include "utils/portfolio.h"

namespace ft {

class PositionManager : public RiskRule {
 public:
  bool Init(RiskRuleParams* params) override;

  int CheckOrderRequest(const Order* order) override;

  void OnOrderSent(const Order* order) override;

  void OnOrderTraded(const Order* order, const Trade* trade) override;

  void OnOrderCanceled(const Order* order, int canceled) override;

  void OnOrderRejected(const Order* order, int error_code) override;

 private:
  Portfolio* portfolio_;
};

};  // namespace ft

#endif  // FT_SRC_TRADING_SERVER_RISK_MANAGEMENT_COMMON_POSITION_MANAGER_H_
