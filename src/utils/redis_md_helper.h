// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_UTILS_REDIS_MD_HELPER_H_
#define FT_SRC_UTILS_REDIS_MD_HELPER_H_

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <string>
#include <vector>

#include "component/contract_table/contract_table.h"
#include "protocol/data_types.h"
#include "utils/redis.h"

namespace ft {

class RedisMdPusher {
 public:
  RedisMdPusher() {}

  void Push(const std::string& ticker, const TickData& tick) {
    std::string binary;
    if (!tick.SerializeToString(&binary)) {
      spdlog::error("RedisMdPusher::Push: failed to serialize tick data");
      abort();  // bug
    }
    redis_.publish(fmt::format("quote-{}", ticker), binary.data(), binary.size());
  }

 private:
  RedisSession redis_;
};

class RedisTERspPuller {
 public:
  RedisTERspPuller() {}

  void SubscribeOrderResponse(const std::string strategy_id) { redis_.subscribe({strategy_id}); }

  void SubscribeMarketData(const std::vector<std::string> ticker_vec) {
    for (const auto& ticker : ticker_vec) redis_.subscribe({fmt::format("quote-{}", ticker)});
  }

  RedisReply Pull() { return redis_.get_sub_reply(); }

 private:
  RedisSession redis_;
};

}  // namespace ft

#endif  // FT_SRC_UTILS_REDIS_MD_HELPER_H_
