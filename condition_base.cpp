#include "condition_base.hpp"


void ConditionBase::PrintSpot () const {
  std::vector<int> spot_list( num_dice_ );
  PrintSpot( 0, spot_list );
}


void ConditionBase::PrintSpot ( int depth, std::vector<int>& spot_list ) const {
  assert( spot_list.size() == num_spot_list_.size() );
  if ( depth == num_dice_ ) {
    if ( Satisfy( spot_list ) ) {
      for ( const auto& spot : spot_list ) {
        std::cout << spot << " ";
      }
      std::cout << "\n";
    }
  } else {
    for ( int i = 1; i <= num_spot_list_[depth]; ++i ) {
      spot_list[depth] = i;
      PrintSpot( depth + 1, spot_list );
    }
  }
}


boost::rational<int> ConditionBase::Probability () const {
  std::vector<int> spot_list( num_dice_ );
  boost::rational<int> probability(0);
  Probability( 0, spot_list, probability );
  return probability;
}


void ConditionBase::Probability ( int depth, std::vector<int>& spot_list, boost::rational<int>& probability ) const {
  assert( spot_list.size() == num_spot_list_.size() );
  if ( depth == num_dice_ ) {
    if ( Satisfy( spot_list ) ) {
      boost::rational<int> buff_probability(1);
      for ( int i_dice = 0; i_dice < num_dice_; ++i_dice ) {
        buff_probability *= dice_list_[i_dice].GetProbability( spot_list[i_dice] );
      }
      probability += buff_probability;
    }
  } else {
    for ( int i = 1; i <= num_spot_list_[depth]; ++i ) {
      spot_list[depth] = i;
      Probability( depth + 1, spot_list, probability );
    }
  }
}
