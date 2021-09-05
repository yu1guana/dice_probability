#pragma once

#include <iostream>
#include <vector>

#include "dice.hpp"

class ConditionBase {
  private:
    //] Variable
    int               num_dice_;
    std::vector<int>  num_spot_list_;
    std::vector<Dice> dice_list_;

    //] Function
    virtual
    bool Satisfy     ( const std::vector<int>& spot_list ) const = 0;

    void PrintSpot   ( int               depth,
                       std::vector<int>& spot_list ) const;

    void Probability ( int                   depth,
                       std::vector<int>&     spot_list,
                       boost::rational<int>& probability ) const;
  public:
    //] Constructor
    ConditionBase ( const std::vector<Dice>& dice_list )
      : num_dice_ ( dice_list.size() ),
        num_spot_list_( GetNumSpotList( dice_list ) ),
        dice_list_( dice_list )
    {}

    //] Destructor
    virtual
    ~ConditionBase () = default;

    //] Function
    void                   PrintSpot () const;
    boost::rational<int> Probability () const;
};


//] Support function
template <class C_Condition>
void Solve ( const std::vector<Dice>& dice_list, const bool flag ) {
  static_assert( std::is_base_of<ConditionBase, C_Condition>::value, "C_Condition must be ConditionBase." );
  C_Condition condition( dice_list );
  if ( flag ) {
    std::cout << "Candidates are as follows:\n";
    condition.PrintSpot();
    std::cout << "\n";
  }
  std::cout << "Anser is as follows:\n";
  std::cout << condition.Probability() << "\n";
}
