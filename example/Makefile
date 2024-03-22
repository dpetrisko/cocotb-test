## Set common environment variables
TOP ?= $(shell git rev-parse --show-toplevel)
include $(TOP)/Makefile.coverage

# Directory setup
MODULE      := test_dff
TOPLEVEL    := dff
RTL_SOURCES := dff.sv

# cocotb setup
SIM := verilator
TOPLEVEL_LANG := verilog
VERILOG_SOURCES := $(addprefix $(shell pwd)/, $(RTL_SOURCES))

# Extra args for verilator
EXTRA_ARGS += --assert --coverage --coverage-line --coverage-toggle
EXTRA_ARGS += --trace --trace-fst --trace-structs

# Add cocotb targets (must be last)
ifeq (,$(shell which cocotb-config))
$(info "cocotb-config not found, please run 'source ../.venv/bin/activate'")
else
include $(shell cocotb-config --makefiles)/Makefile.sim
endif

bsg-run: $(COVERAGE_HTML)

bsg-clean:
	rm -rf __pycache__
	rm -rf coverage
	rm -rf coverage.dat
	rm -rf dump.fst
	rm -rf results_coverage.xml
	rm -rf results_coverage.yaml
	rm -rf results.xml
	rm -rf sim_build

