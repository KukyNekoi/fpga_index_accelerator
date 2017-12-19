/**
 * Proof of concept offloaded memcopy using AXI Direct Memory Access v7.1
 */

 #include <stdio.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <termios.h>
 #include <sys/mman.h>
 #include <string.h>
 #include <stdint.h>
 #include <time.h>
 #include <inttypes.h>
 

 struct timespec start, end;
 

 
 #define MM2S_CONTROL_REGISTER 0x00
 #define MM2S_STATUS_REGISTER 0x04
 #define MM2S_START_ADDRESS 0x18
 #define MM2S_LENGTH 0x28
 
 #define S2MM_CONTROL_REGISTER 0x30
 #define S2MM_STATUS_REGISTER 0x34
 #define S2MM_DESTINATION_ADDRESS 0x48
 #define S2MM_LENGTH 0x58

#define XACELERATOR_CRTL_BUS_ADDR_AP_CTRL 0x0
#define XACELERATOR_CRTL_BUS_ADDR_GIE     0x4
#define XACELERATOR_CRTL_BUS_ADDR_IER     0x8
#define XACELERATOR_CRTL_BUS_ADDR_ISR     0xc

 #define PHY_MEMORY_START 0x3e000000
 #define PHY_MEMORY_SIZE  0x01000000
 #define INTS_TO_GENERATE 10000
 #define BYTES_TO_TRANSFER   4*INTS_TO_GENERATE //importante transferir exactamente la cantidad especificada.
 
 unsigned int dma_set(unsigned int* dma_virtual_address, int offset, unsigned int value) {
     dma_virtual_address[offset>>2] = value;
     return 0;
 }
 
 unsigned int dma_get(unsigned int* dma_virtual_address, int offset) {
     return dma_virtual_address[offset>>2];
 }

 // CRTL_BUS
// 0x0 : Control signals
//       bit 0  - ap_start (Read/Write/COH)
//       bit 1  - ap_done (Read/COR)
//       bit 2  - ap_idle (Read)
//       bit 3  - ap_ready (Read)
//       bit 7  - auto_restart (Read/Write)
//       others - reserved
 void dma_crtl_status(unsigned int* dma_virtual_address) {
    // unsigned int status = dma_get(dma_virtual_address, XACELERATOR_CRTL_BUS_ADDR_AP_CTRL);
    // printf("AXILite Control signal status  (0x%08x@0x%02x):", status, XACELERATOR_CRTL_BUS_ADDR_AP_CTRL);
    // if (status & 0x00000001) printf(" ap_start");
    // if (status & 0x00000002) printf(" ap_done");
    // if (status & 0x00000004) printf(" ap_idle");
    // if (status & 0x00000008) printf(" ap_ready");
    // if (status & 0x00000128) printf(" auto_restart");
    // printf("\n");
}

 void dma_s2mm_status(unsigned int* dma_virtual_address) {
    // unsigned int status = dma_get(dma_virtual_address, S2MM_STATUS_REGISTER);
    // printf("Stream to memory-mapped status (0x%08x@0x%02x):", status, S2MM_STATUS_REGISTER);
    // if (status & 0x00000001) printf(" halted"); else printf(" running");
    // if (status & 0x00000002) printf(" idle");
    // if (status & 0x00000008) printf(" SGIncld");
    // if (status & 0x00000010) printf(" DMAIntErr");
    // if (status & 0x00000020) printf(" DMASlvErr");
    // if (status & 0x00000040) printf(" DMADecErr");
    // if (status & 0x00000100) printf(" SGIntErr");
    // if (status & 0x00000200) printf(" SGSlvErr");
    // if (status & 0x00000400) printf(" SGDecErr");
    // if (status & 0x00001000) printf(" IOC_Irq");
    // if (status & 0x00002000) printf(" Dly_Irq");
    // if (status & 0x00004000) printf(" Err_Irq");
    // printf("\n");
}

void dma_mm2s_status(unsigned int* dma_virtual_address) {
    // unsigned int status = dma_get(dma_virtual_address, MM2S_STATUS_REGISTER);
    // printf("Memory-mapped to stream status (0x%08x@0x%02x):", status, MM2S_STATUS_REGISTER);
    // if (status & 0x00000001) printf(" halted"); else printf(" running");
    // if (status & 0x00000002) printf(" idle");
    // if (status & 0x00000008) printf(" SGIncld");
    // if (status & 0x00000010) printf(" DMAIntErr");
    // if (status & 0x00000020) printf(" DMASlvErr");
    // if (status & 0x00000040) printf(" DMADecErr");
    // if (status & 0x00000100) printf(" SGIntErr");
    // if (status & 0x00000200) printf(" SGSlvErr");
    // if (status & 0x00000400) printf(" SGDecErr");
    // if (status & 0x00001000) printf(" IOC_Irq");
    // if (status & 0x00002000) printf(" Dly_Irq");
    // if (status & 0x00004000) printf(" Err_Irq");
    // printf("\n");
}

 
 int dma_mm2s_sync(unsigned int* dma_virtual_address, unsigned int* dma_ip_control) {
     unsigned int mm2s_status =  dma_get(dma_virtual_address, MM2S_STATUS_REGISTER);
     while(!(mm2s_status & 1<<12) || !(mm2s_status & 1<<1) ){
         dma_s2mm_status(dma_virtual_address);
         dma_mm2s_status(dma_virtual_address);
         dma_crtl_status(dma_ip_control);
         mm2s_status =  dma_get(dma_virtual_address, MM2S_STATUS_REGISTER);
     }
     return 0;
 }
 
 int dma_s2mm_sync(unsigned int* dma_virtual_address, unsigned int* dma_ip_control) {
     unsigned int s2mm_status = dma_get(dma_virtual_address, S2MM_STATUS_REGISTER);
     while(!(s2mm_status & 1<<12) || !(s2mm_status & 1<<1)){
         dma_s2mm_status(dma_virtual_address);
         dma_mm2s_status(dma_virtual_address);
         dma_crtl_status(dma_ip_control);
         s2mm_status = dma_get(dma_virtual_address, S2MM_STATUS_REGISTER);
     }
     return 0;
 }
 
 void memdump(void* virtual_address, int byte_count) {
     char *p = virtual_address;
     int offset;
     for (offset = 0; offset < byte_count; offset++) {
        printf("%02x", p[offset]);
        if (offset % 4 == 3) { printf(" "); }
    }

    //int conversion
    printf("\n\t\t\t\t");
    unsigned int *int_p = virtual_address;
    for (offset = 0; offset < byte_count/4; offset++) {
        printf("%d\t", int_p[offset]);
    }
     printf("\n");
 }
 
 
 int main() {
     //printf("Stage1: Init\n");
     int dh = open("/dev/mem", O_RDWR | O_SYNC); // Open /dev/mem which represents the whole physical memory
     //printf("Stage1: Opened /dev/mem\n");
     unsigned int* virtual_address = mmap(NULL, 65535, PROT_READ | PROT_WRITE, MAP_SHARED, dh, 0x40400000); // Memory map AXI Lite register block//printf("Stage1: Opened /dev/mem\n");
     unsigned int* virtual_address_ctrl = mmap(NULL, 65535, PROT_READ | PROT_WRITE, MAP_SHARED, dh, 0x43C00000); // Memory map AXI Lite control block
     //printf("Stage1: Allocated AXI memblock\n");
     unsigned int* virtual_source_address  = mmap(NULL, 65535, PROT_READ | PROT_WRITE, MAP_SHARED, dh, PHY_MEMORY_START); // Memory map source address
     //printf("Stage1: Allocated AXIDMA source\n");
     unsigned int* virtual_destination_address = mmap(NULL, 65535, PROT_READ | PROT_WRITE, MAP_SHARED, dh, PHY_MEMORY_START + (PHY_MEMORY_SIZE/2)); // Memory map destination address
     //printf("Stage1: Allocated AXIDMA destination\n");
 
     //printf("Stage2: Clearing destination blocks\n");
     int i;
     for(i=0; i<INTS_TO_GENERATE;i++){
        virtual_source_address[i]= rand()%INTS_TO_GENERATE; // Write random stuff to source block
     }
     memset(virtual_destination_address, 0, BYTES_TO_TRANSFER); // Clear destination block
 
     //printf("Stage3: Dumping!\n");
    //  printf("Source memory block:      "); memdump(virtual_source_address, BYTES_TO_TRANSFER);
    //  printf("Destination memory block: "); memdump(virtual_destination_address, BYTES_TO_TRANSFER);
 
     clock_gettime(CLOCK_MONOTONIC_RAW, &start);
     //printf("Resetting DMA\n");
     dma_set(virtual_address, S2MM_CONTROL_REGISTER, 4);
     dma_set(virtual_address, MM2S_CONTROL_REGISTER, 4);
     dma_s2mm_status(virtual_address);
     dma_mm2s_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Halting DMA\n");
     dma_set(virtual_address, S2MM_CONTROL_REGISTER, 0);
     dma_set(virtual_address, MM2S_CONTROL_REGISTER, 0);
     dma_s2mm_status(virtual_address);
     dma_mm2s_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Starting AP...\n");
     dma_set(virtual_address_ctrl, XACELERATOR_CRTL_BUS_ADDR_AP_CTRL, 1);
     dma_crtl_status(virtual_address_ctrl);

     //printf("Writing destination address\n");
     dma_set(virtual_address, S2MM_DESTINATION_ADDRESS, PHY_MEMORY_START + (PHY_MEMORY_SIZE/2)); // Write destination address
     dma_s2mm_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Writing source address...\n");
     dma_set(virtual_address, MM2S_START_ADDRESS, PHY_MEMORY_START); // Write source address
     dma_mm2s_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Starting S2MM channel with all interrupts masked...\n");
     dma_set(virtual_address, S2MM_CONTROL_REGISTER, 0xf001);
     dma_s2mm_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Starting MM2S channel with all interrupts masked...\n");
     dma_set(virtual_address, MM2S_CONTROL_REGISTER, 0xf001);
     dma_mm2s_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Writing S2MM transfer length...\n");
     dma_set(virtual_address, S2MM_LENGTH, BYTES_TO_TRANSFER);
     dma_s2mm_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);
 
     //printf("Writing MM2S transfer length...\n");
     dma_set(virtual_address, MM2S_LENGTH, BYTES_TO_TRANSFER);
     dma_mm2s_status(virtual_address);
     dma_crtl_status(virtual_address_ctrl);


     //printf("Waiting for MM2S synchronization...\n");
     dma_mm2s_sync(virtual_address, virtual_address_ctrl);
 
     //printf("Waiting for S2MM sychronization...\n");
     dma_s2mm_sync(virtual_address, virtual_address_ctrl); // If this locks up make sure all memory ranges are assigned under Address Editor!

     dma_s2mm_status(virtual_address);
     dma_mm2s_status(virtual_address);
     clock_gettime(CLOCK_MONOTONIC_RAW, &end);

     uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
     printf("Elapsed time: %" PRIu64 "\n", delta_us);
    //  printf("Destination memory block: "); memdump(virtual_destination_address, BYTES_TO_TRANSFER);
     return 0;
 }

 