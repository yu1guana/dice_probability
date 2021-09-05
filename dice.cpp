#include "dice.hpp"


Dice::Dice ( const std::vector<int>& rate )
  : num_spot_    ( rate.size() ),
    probability_ ( rate.size() )
{
  const boost::rational<int> renormalize_factor = std::accumulate( rate.begin(), rate.end(), 0 );
  for ( int i_spot = 0; i_spot < num_spot_; ++i_spot ) {
    probability_[i_spot] = rate[i_spot] / renormalize_factor;
  }
}


std::vector<int> GetNumSpotList ( const std::vector<Dice>& dice_list ) {
  const int num_dice = dice_list.size();
  std::vector<int> num_spot_list( num_dice );
  for ( int i_dice = 0; i_dice < num_dice; ++i_dice ) {
    num_spot_list[i_dice] = dice_list[i_dice].GetNumSpot();
  };
  return num_spot_list;
}
