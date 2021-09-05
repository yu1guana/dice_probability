#pragma once

#include <vector>
#include <numeric>
#include <boost/rational.hpp>


//] Class
class Dice final {
  private:
    //] Variable
    const int num_spot_;
    const boost::rational<int> zero_ = boost::rational<int>(0);
    std::vector<boost::rational<int>> probability_;
  public:
    //] Constructor
    Dice ( const std::vector<int>& rate );
    //] Getter
    int                         GetNumSpot     ()                   const { return num_spot_; }
    const boost::rational<int>& GetProbability ( const int i_spot ) const { return ( 1 <= i_spot && i_spot <= num_spot_ ) ?  probability_[i_spot-1] : zero_; }
};

//] Support function
std::vector<int> GetNumSpotList ( const std::vector<Dice>& dice_list );
