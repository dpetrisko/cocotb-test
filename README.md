This is an example repo for cocotb.

```
README.md # This document
Makefile # Used to create the prerequisite environment
         #   all: install all dependencies and create .venv/
         #   bleach: delete environment
Makefile.common # Environment variables
Makefile.coverage # Target for code coverage in verilator
example # An example cocotb testbench demonstrating
        #   constrained random drivers,
        #   cocotb assertions
        #   cocotb coverage,
        #   and verilator line/toggle coverage
requirements.txt # pip requirements used for venv
<work> # Used during installation
<install> # Created during installation
<.venv> # The python 3.11 virtual environment created during installation
```

To set up the environment,
1. Build venv environment "make all <-j>" in root
2. activate venv in root with "source ./venv/bin/activate"

In example/ the directory is
```
dff.sv # Example systemverilog component
test_dff.py # Example cocotb testbench
Makefile # Used to run a test
         #   bsg-run: run a coco-tb test and generate coverage reports
         #   bsg-view: open up a waveform in gtkwave (verilator) or dve (vcs)
         #   bsg-clean: clean up the example directory
         # There are also cocotb targets linked here, but we suggest to use the
         #    bsg-* wrappers instead
         # NOTE: Change SIM=vcs / SIM=verilator to switch simulators
gold.vcs # Example of golden results to check if your environment is set up correctly
gold.verilator # Example of golden results to check if your environment is set up correctly
```

Additional info can be found at:
* https://docs.cocotb.org/en/stable/
* https://cocotb-coverage.readthedocs.io/en/latest/
* https://verilator.org/guide/latest/

