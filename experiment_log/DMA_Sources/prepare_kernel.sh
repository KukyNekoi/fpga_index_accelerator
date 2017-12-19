#!/bin/bash
modprobe uio_dmem_genirq
modprobe uio_pdrv_genirq 
modprobe uio_xilinx_apm
    ls -l /dev/uio?
    ls -l /sys/class/uio/uio?/
    cat /sys/class/uio/uio?/name
    ls -l /dev/dma?
    ls -l /sys/class/uio/dma?/
    cat /sys/class/uio/dma?/name

