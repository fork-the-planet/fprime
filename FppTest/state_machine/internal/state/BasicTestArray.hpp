// ======================================================================
//
// \title  BasicTestArray.hpp
// \author R. Bocchino
// \brief  Test class for basic state machine with TestArray actions (header)
//
// \copyright
// Copyright 2024, by the California Institute of Technology.
// ALL RIGHTS RESERVED. United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef FppTest_State_BasicTestArray_HPP
#define FppTest_State_BasicTestArray_HPP

#include "FppTest/state_machine/internal/harness/Harness.hpp"
#include "FppTest/state_machine/internal/state/BasicTestArrayStateMachineAc.hpp"

namespace FppTest {

namespace SmState {

//! A basic state machine with TestArray actions
class BasicTestArray final : public BasicTestArrayStateMachineBase {
  public:
    //! The history size
    static constexpr FwSizeType historySize = 10;

  public:
    //! Constructor
    BasicTestArray();

  private:
    //! Implementation of action a
    void action_a(Signal signal  //!< The signal
                  ) final;

    //! Implementation of action b
    void action_b(Signal signal,                     //!< The signal
                  const SmHarness::TestArray& value  //!< The value
                  ) final;

  public:
    //! Run the test
    void test();

  private:
    //! The history associated with action a
    SmHarness::History<Signal, historySize> m_action_a_history;

    //! The history associated with action b
    SmHarness::SignalValueHistory<Signal, SmHarness::TestArray, historySize> m_action_b_history;
};

}  // namespace SmState

}  // end namespace FppTest

#endif