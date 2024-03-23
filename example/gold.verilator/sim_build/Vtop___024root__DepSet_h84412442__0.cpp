// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->dff__DOT__clk = vlSelf->clk;
    vlSelf->dff__DOT__d = vlSelf->d;
    if (((IData)(vlSelf->clk) ^ (IData)(vlSelf->dff__DOT____Vtogcov__clk))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlSelf->dff__DOT____Vtogcov__clk = vlSelf->clk;
    }
    vlSelf->q = vlSelf->dff__DOT__q;
    if ((1U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelf->dff__DOT____Vtogcov__q = ((0xeU & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (1U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((2U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelf->dff__DOT____Vtogcov__q = ((0xdU & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (2U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((4U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelf->dff__DOT____Vtogcov__q = ((0xbU & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (4U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((8U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelf->dff__DOT____Vtogcov__q = ((7U & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (8U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((1U & ((IData)(vlSelf->d) ^ (IData)(vlSelf->dff__DOT____Vtogcov__d)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlSelf->dff__DOT____Vtogcov__d = ((0xeU & (IData)(vlSelf->dff__DOT____Vtogcov__d)) 
                                          | (1U & (IData)(vlSelf->d)));
    }
    if ((2U & ((IData)(vlSelf->d) ^ (IData)(vlSelf->dff__DOT____Vtogcov__d)))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlSelf->dff__DOT____Vtogcov__d = ((0xdU & (IData)(vlSelf->dff__DOT____Vtogcov__d)) 
                                          | (2U & (IData)(vlSelf->d)));
    }
    if ((4U & ((IData)(vlSelf->d) ^ (IData)(vlSelf->dff__DOT____Vtogcov__d)))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlSelf->dff__DOT____Vtogcov__d = ((0xbU & (IData)(vlSelf->dff__DOT____Vtogcov__d)) 
                                          | (4U & (IData)(vlSelf->d)));
    }
    if ((8U & ((IData)(vlSelf->d) ^ (IData)(vlSelf->dff__DOT____Vtogcov__d)))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlSelf->dff__DOT____Vtogcov__d = ((7U & (IData)(vlSelf->dff__DOT____Vtogcov__d)) 
                                          | (8U & (IData)(vlSelf->d)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    ++(vlSymsp->__Vcoverage[9]);
    vlSelf->dff__DOT__q = vlSelf->d;
    vlSelf->q = vlSelf->dff__DOT__q;
    if ((1U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelf->dff__DOT____Vtogcov__q = ((0xeU & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (1U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((2U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelf->dff__DOT____Vtogcov__q = ((0xdU & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (2U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((4U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelf->dff__DOT____Vtogcov__q = ((0xbU & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (4U & (IData)(vlSelf->dff__DOT__q)));
    }
    if ((8U & ((IData)(vlSelf->dff__DOT__q) ^ (IData)(vlSelf->dff__DOT____Vtogcov__q)))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelf->dff__DOT____Vtogcov__q = ((7U & (IData)(vlSelf->dff__DOT____Vtogcov__q)) 
                                          | (8U & (IData)(vlSelf->dff__DOT__q)));
    }
}
