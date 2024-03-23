// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtop___024root___configure_coverage(Vtop___024root* vlSelf, bool first) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___configure_coverage\n"); );
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 7, 30, ".dff", "v_toggle/dff", "q[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 7, 30, ".dff", "v_toggle/dff", "q[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 7, 30, ".dff", "v_toggle/dff", "q[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 7, 30, ".dff", "v_toggle/dff", "q[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 8, 17, ".dff", "v_toggle/dff", "clk", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 9, 29, ".dff", "v_toggle/dff", "d[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 9, 29, ".dff", "v_toggle/dff", "d[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 9, 29, ".dff", "v_toggle/dff", "d[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 9, 29, ".dff", "v_toggle/dff", "d[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "/mnt/users/ssd0/homes/petrisko/scratch/cocotb_test/example/dff.sv", 12, 1, ".dff", "v_line/dff", "block", "12-13");
}
