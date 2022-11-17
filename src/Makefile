# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2022 Soha Jin <soha@lohu.info>. All Rights Reserved.

KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
