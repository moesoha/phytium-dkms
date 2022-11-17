# DKMS package for Phytium CPU

## Drivers

These are working:

- GMAC (`dwmac-phytium`, ACPI HID: `PHYT0004`)
- MailBox (`phytium-mailbox`, ACPI HID: `PHYT0009`)

## How to install

### Debian

Just download and install the `.deb` package from Release page.

### Generic

Download the tarball `phytium-<version>.tar.gz` from Release page and install it via DKMS:

```shell
wget <link to the tarball>
tar zxvf ./phytium-1.0.0.tar.gz -C /usr/src/
dkms install phytium/1.0.0 # or simply use: dkms autoinstall, check usage by `man dkms`
```

Reboot or `modprobe <module-name>` to use the kernel modules.

## More

### I2C (`i2c-designware-platform`, ACPI HID: `PHYT0003`)

*Not working yet.* This affects temperature sensors on SoC.

## Thanks to

  - [Icenowy's patch](https://github.com/torvalds/linux/compare/master...Icenowy:linux:ftd2k-wip).
