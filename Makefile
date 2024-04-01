
## Set common environment variables
TOP ?= $(shell git rev-parse --show-toplevel)
include $(TOP)/Makefile.common

openssl_tag   := $(COCOTB_TOUCH_DIR)/openssl.any
python311_tag := $(COCOTB_TOUCH_DIR)/python311.any
venv_tag      := $(COCOTB_TOUCH_DIR)/venv.any
cocotb_tag    := $(COCOTB_TOUCH_DIR)/cocotb.any
verilator_tag := $(COCOTB_TOUCH_DIR)/verilator.any

all: | $(verilator_tag)

$(COCOTB_WORK_DIR) $(COCOTB_TOUCH_DIR) $(COCOTB_INSTALL_DIR):
	$(MKDIR) -p $@

OPENSSL_VERSION := 1.1.1w
OPENSSL := openssl-$(OPENSSL_VERSION)
OPENSSL_URL := https://www.openssl.org/source/$(OPENSSL).tar.gz
OPENSSL_INSTALL := $(COCOTB_INSTALL_DIR)/openssl
$(openssl_tag): | $(COCOTB_WORK_DIR) $(COCOTB_TOUCH_DIR) $(COCOTB_INSTALL_DIR)
	cd $(COCOTB_WORK_DIR); \
		$(WGET) -qO- $(OPENSSL_URL) | $(TAR) xzv
	cd $(COCOTB_WORK_DIR)/$(OPENSSL); \
		CROSS_COMPILE="" ./config shared --prefix=$(OPENSSL_INSTALL) --openssldir=$(OPENSSL_INSTALL)
	$(MAKE) -C $(COCOTB_WORK_DIR)/$(OPENSSL)
	$(MAKE) -C $(COCOTB_WORK_DIR)/$(OPENSSL) install
	touch $@

PYTHON311_VERSION := 3.11.4
PYTHON311_SHORT := 3.11
PYTHON311 := Python-$(PYTHON311_VERSION)
PYTHON311_URL := https://www.python.org/ftp/python/$(PYTHON311_VERSION)/$(PYTHON311).tgz
$(python311_tag): | $(openssl_tag)
	cd $(COCOTB_WORK_DIR); \
		$(WGET) -qO- $(PYTHON311_URL) | $(TAR) xzv
	cd $(COCOTB_WORK_DIR)/$(PYTHON311); \
		./configure \
			--enable-shared --enable-optimizations \
			LDFLAGS="-L$(OPENSSL_INSTALL)/lib" \
			--with-openssl=$(OPENSSL_INSTALL) \
			--with-openssl-rpath=auto \
			--prefix=$(COCOTB_INSTALL_DIR)
	$(MAKE) -C $(COCOTB_WORK_DIR)/$(PYTHON311) altinstall
	touch $@

ACTIVATE := $(COCOTB_VENV_DIR)/bin/activate
$(venv_tag): | $(python311_tag)
	LD_LIBRARY_PATH=$(COCOTB_INSTALL_DIR)/lib:$$LD_LIBRARY_PATH; \
		$(COCOTB_INSTALL_DIR)/bin/pip$(PYTHON311_SHORT) install env; \
		$(COCOTB_INSTALL_DIR)/bin/python$(PYTHON311_SHORT) -m venv --copies $(COCOTB_VENV_DIR)
	$(ECHO) 'LD_LIBRARY_PATH=$(COCOTB_INSTALL_DIR)/lib:$$LD_LIBRARY_PATH' >> $(ACTIVATE)
	$(ECHO) 'export LD_LIBRARY_PATH' >> $(ACTIVATE)
	touch $@

$(cocotb_tag): | $(venv_tag)
	source $(ACTIVATE); \
		$(PIP) install --no-cache-dir -r requirements.txt
	touch $@

VERILATOR_URL := http://github.com/verilator/verilator
VERILATOR_VERSION := v5.022
$(verilator_tag): | $(cocotb_tag)
	$(CLONE) -b $(VERILATOR_VERSION) $(VERILATOR_URL) $(COCOTB_WORK_DIR)/verilator || true
	cd $(COCOTB_WORK_DIR)/verilator; \
		autoconf; ./configure --prefix=$(COCOTB_VENV_DIR); $(MAKE) && $(MAKE) install;
	touch $@

bleach:
	rm -rf $(COCOTB_VENV_DIR)
	rm -rf $(COCOTB_WORK_DIR)
	rm -rf $(COCOTB_TOUCH_DIR)
	rm -rf $(COCOTB_INSTALL_DIR)

