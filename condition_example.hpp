#pragma once

#include "condition_base.hpp"

class Condition_Example final : public ConditionBase {
  private:
    //] Function
    bool Satisfy ( const std::vector<int>& spot_list ) const override {
      constexpr const int max_product = 9;
      int product = 1;
      for ( const auto& spot : spot_list ) {
        product *= spot;
      }
      return ( product <= max_product );
    }
  public:
    //] Constructor
    Condition_Example ( const std::vector<Dice>& dice_list ) : ConditionBase ( dice_list ) {}
};
