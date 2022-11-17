// SPDX-License-Identifier: GPL-2.0-only
/*
 * Phytium I2C stub driver
 *
 * Copyright (C) 2022 Soha Jin <soha@lohu.info>
 */

#include <linux/module.h>
#include <linux/acpi.h>
#include <linux/device/driver.h>
#include <linux/platform_device.h>

static const struct acpi_device_id phytium_i2c_acpi_match[] = {
	{ .id = "PHYT0003" },
	{}
};
MODULE_DEVICE_TABLE(acpi, phytium_i2c_acpi_match);

// filled at init, don't use this when prove is NULL
static struct platform_driver phytium_i2c_stub_driver = {
	.driver = {
		.name = "phytium-i2c-stub",
		.acpi_match_table = phytium_i2c_acpi_match
	}
};

static int __init phytium_i2c_stub_driver_init(void)
{
	struct platform_driver *dwp;
	struct device_driver *dwd;
	if (phytium_i2c_stub_driver.probe)
		goto inited;

	request_module("i2c-designware-platform");
	dwd = driver_find("i2c_designware", &platform_bus_type);
	if (dwd == NULL)
		return -ENOENT;
	dwp = to_platform_driver(dwd);

	// memcpy(&phytium_i2c_stub_driver, dwp, sizeof(*dwp));
	phytium_i2c_stub_driver.probe = dwp->probe;
	phytium_i2c_stub_driver.remove = dwp->remove;
	phytium_i2c_stub_driver.driver.pm = dwd->pm;

inited:
	return platform_driver_register(&phytium_i2c_stub_driver);
}
module_init(phytium_i2c_stub_driver_init);

static void __exit phytium_i2c_stub_driver_exit(void)
{
	if (phytium_i2c_stub_driver.probe)
		platform_driver_unregister(&phytium_i2c_stub_driver);
}
module_exit(phytium_i2c_stub_driver_exit);

MODULE_DESCRIPTION("Phytium I2C stub driver");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Soha Jin <soha@lohu.info>");
MODULE_VERSION("v1.0.0");
// MODULE_SOFTDEP("pre: i2c-designware-platform");
