/* Copyright (c) 2017, 2019 The Linux Foundation. All rights reserved.
 * Copyright (c) 2020 Microsoft Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __BATTERY_H
#define __BATTERY_H

// MSCHANGE lookup table for power distribution
enum power_distribution_ratio {
    RATIO_NONE = 0,
    RATIO_45_PERC   = 45,
    RATIO_50_PERC   = 50,
    RATIO_33_PERC   = 33,
    RATIO_MAX  = 4
};
struct power_distribution_table
{
	int TotalCurrent;                        // TotalCurrent(uA)
    enum power_distribution_ratio Ratio;   // Percentage alloted for slave charger based on total power available
};

struct charger_param {
	u32 fcc_step_delay_ms;
	u32 fcc_step_size_ua;
	u32 smb_version;
	u32 hvdcp3_max_icl_ua;
	u32 forced_main_fcc;
	u32 qc4_max_icl_ua;
};

int qcom_batt_init(struct charger_param *param);
void qcom_batt_deinit(void);
#endif /* __BATTERY_H */
