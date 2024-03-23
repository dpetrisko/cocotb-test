# test_dff.py

import random

import cocotb
from cocotb.clock import Clock, Timer
from cocotb.triggers import RisingEdge, FallingEdge
from cocotb.types import LogicArray

import random
from cocotb_coverage import crv
from cocotb_coverage.coverage import coverage_db, coverage_section
from cocotb_coverage.coverage import CoverPoint, CoverCross

@cocotb.test()
async def dff_simple_test(dut):
    """Test that d propagates to q"""

    log = cocotb.logging.getLogger("cocotb.test")

    dut.d.a.value = 0
    dut.d.b.value = 0
    dut.d.c.value = 0
    dut.d.d.value = 0

    class SimpleRandomized(crv.Randomized):
        """Constrained Random input"""

        def __init__(self):
            crv.Randomized.__init__(self)

            self.A = 0
            self.B = 0
            self.C = 0
            self.D = 0

            self.add_rand("A", [0, 1])
            self.add_rand("B", [0, 1])
            self.add_rand("C", [0, 1])
            self.add_rand("D", [0, 1])

    clock = Clock(dut.clk, 10, units="us")  # Create a 10us period clock on port clk
    # Start the clock. Start it low to avoid issues on the first RisingEdge
    cocotb.start_soon(clock.start(start_high=False))

    # Synchronize with the clock. This will regisiter the initial `d` value
    await RisingEdge(dut.clk)

    async def send_data(a, b, c, d):
        #log.info("Sending d=={} into dut".format(d))
        await FallingEdge(dut.clk)
        dut.d.a.value = a  # Input the new d value
        dut.d.b.value = b  # Input the new d value
        dut.d.c.value = c  # Input the new d value
        dut.d.d.value = d  # Input the new d value
        await FallingEdge(dut.clk)
        qa = dut.q.a.value # Get the propagated value
        qb = dut.q.b.value # Get the propagated value
        qc = dut.q.c.value # Get the propagated value
        qd = dut.q.d.value # Get the propagated value
        assert qa == a, f"output q was incorrect {qa}!={a}"
        assert qb == b, f"output q was incorrect {qb}!={b}"
        assert qc == c, f"output q was incorrect {qc}!={c}"
        assert qd == d, f"output q was incorrect {qd}!={d}"

    val = SimpleRandomized()
    expected = 0
    for i in range(100):
        val.randomize()
        a = val.A
        b = val.B
        c = val.C
        d = val.D
        q = await send_data(a, b, c, d)

