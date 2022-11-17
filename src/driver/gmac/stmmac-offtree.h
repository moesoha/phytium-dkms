// SPDX-License-Identifier: GPL-2.0-only
/*
 * off-tree workaround for stmmac drivers
 *
 * Copyright (C) 2022 Soha Jin <soha@lohu.info>
 */

#ifndef __STMMAC_OFFTREE_H__
#define __STMMAC_OFFTREE_H__

// FROM /drivers/net/ethernet/stmicro/stmmac/common.h
#define JUMBO_LEN		9000
#define HASH_TABLE_SIZE		64
#define DEFAULT_DMA_PBL		8

// FROM /drivers/net/ethernet/stmicro/stmmac/stmmac.h
struct stmmac_resources {
	void __iomem *addr;
	u8 mac[ETH_ALEN];
	int wol_irq;
	int lpi_irq;
	int irq;
	int sfty_ce_irq;
	int sfty_ue_irq;
	int rx_irq[MTL_MAX_RX_QUEUES];
	int tx_irq[MTL_MAX_TX_QUEUES];

};

// FROM /drivers/net/ethernet/stmicro/stmmac/stmmac.h
int stmmac_dvr_probe(struct device *device,
		     struct plat_stmmacenet_data *plat_dat,
		     struct stmmac_resources *res);

// FROM /drivers/net/ethernet/stmicro/stmmac/stmmac_platform.h
int stmmac_pltfr_remove(struct platform_device *pdev);

// FROM /drivers/net/ethernet/stmicro/stmmac/stmmac_platform.h
extern const struct dev_pm_ops stmmac_pltfr_pm_ops;

#endif /* __STMMAC_OFFTREE_H__ */
