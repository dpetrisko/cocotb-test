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

DFF_Coverage = coverage_section(
    CoverPoint("dut.q_all", xf = lambda d: d, bins=list(range(16))),
    CoverPoint("dut.q_even", xf = lambda d: d % 2 == 0, bins=[True, False]),
    CoverPoint("dut.q_large", xf = lambda d: d > 8, bins=[True, False]),
    CoverCross("dut.q_large_even", items = ["dut.q_even", "dut.q_large"], ign_bins = [(False, False)])
)


@cocotb.test()
async def dff_simple_test(dut):
    """Test that d propagates to q"""

    log = cocotb.logging.getLogger("cocotb.test")

    # Assert initial output is unknown
    # verilator does not support 4-state signals
    # see https://veripool.org/guide/latest/languages.html#unknown-states
    initial = (
        LogicArray("0000")
        if cocotb.SIM_NAME.lower().startswith("verilator")
        else (
            LogicArray("UUUU")
            if LANGUAGE.lower().startswith("vhdl")
            else LogicArray("XXXX")
        )
    )
    assert LogicArray(dut.q.value) == initial
    # Set initial input value to prevent it from floating
    dut.d.value = 0000

    class SimpleRandomized(crv.Randomized):
        """Constrained Random input"""

        def __init__(self):
            crv.Randomized.__init__(self)

            self.A = 0

            self.add_rand("A", list(range(0, 16)))
            self.add_constraint(lambda A: A % 3 == 0)

    clock = Clock(dut.clk, 10, units="us")  # Create a 10us period clock on port clk
    # Start the clock. Start it low to avoid issues on the first RisingEdge
    cocotb.start_soon(clock.start(start_high=False))

    # Synchronize with the clock. This will regisiter the initial `d` value
    await RisingEdge(dut.clk)

    @DFF_Coverage
    async def send_data(d):
        #log.info("Sending d=={} into dut".format(d))
        await FallingEdge(dut.clk)
        dut.d.value = d  # Input the new d value
        await FallingEdge(dut.clk)
        q = dut.q.value # Get the propagated value
        assert q == d, f"output q was incorrect {q}!={d}"

    cg = coverage_db["dut.q_large_even"]

    val = SimpleRandomized()
    expected = 0
    for i in range(100):
        val.randomize()
        d = val.A
        q = await send_data(d)
        #if cg.cover_percentage == 100:
        #    log.info("dut.q_large_even full coverage!")
        #    log.info(cg.detailed_coverage)
        #    break

    coverage_db.report_coverage(log.info, bins=True)
    coverage_db.export_to_xml("results_coverage.xml")
    coverage_db.export_to_yaml("results_coverage.yaml")

