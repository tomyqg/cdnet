/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2017, DUKELEC, Inc.
 * All rights reserved.
 *
 * Author: Duke Fong <duke@dukelec.com>
 */

#ifndef __CDCTL_BX_H__
#define __CDCTL_BX_H__

#include "common.h"
#include "cdnet.h"


typedef struct {
    cd_intf_t   cd_intf;
    list_head_t *free_head;
    list_head_t rx_head;
    list_head_t tx_head;

    bool        is_pending;

#ifdef CDCTL_I2C
    i2c_t       *i2c;
#else
    spi_t       *spi;
#endif
} cdctl_intf_t;


#ifdef CDCTL_I2C
void cdctl_intf_init(cdctl_intf_t *intf, list_head_t *free_head, i2c_t *i2c);
#else
void cdctl_intf_init(cdctl_intf_t *intf, list_head_t *free_head, spi_t *spi);
#endif

void cdctl_task(cdctl_intf_t *intf);

#endif
