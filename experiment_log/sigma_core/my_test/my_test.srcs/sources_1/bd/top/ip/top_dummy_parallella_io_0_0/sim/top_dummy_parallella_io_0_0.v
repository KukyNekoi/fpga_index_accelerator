// (c) Copyright 1995-2017 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: k88k:user:dummy_parallella_io:1.0
// IP Revision: 1

`timescale 1ns/1ps

(* DowngradeIPIdentifiedWarnings = "yes" *)
module top_dummy_parallella_io_0_0 (
  CCLK_P,
  CCLK_N,
  DSP_RESET_N,
  RX_WR_WAIT_P,
  RX_WR_WAIT_N,
  RX_RD_WAIT_P,
  RX_RD_WAIT_N,
  RX_LCLK_P,
  RX_LCLK_N,
  RX_FRAME_P,
  RX_FRAME_N,
  RX_DATA_P,
  RX_DATA_N,
  TX_LCLK_P,
  TX_LCLK_N,
  TX_FRAME_P,
  TX_FRAME_N,
  TX_DATA_P,
  TX_DATA_N,
  TX_WR_WAIT_P,
  TX_WR_WAIT_N,
  TX_RD_WAIT_P,
  TX_RD_WAIT_N,
  PS_GPIO_I,
  GPIO_P,
  GPIO_N,
  PS_GPIO_O,
  PS_GPIO_T,
  I2C_SDA_I,
  I2C_SCL_I,
  I2C_SDA,
  I2C_SCL,
  I2C_SDA_O,
  I2C_SDA_T,
  I2C_SCL_O,
  I2C_SCL_T
);

output wire CCLK_P;
output wire CCLK_N;
output wire [0 : 0] DSP_RESET_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX wr_wait_p" *)
output wire RX_WR_WAIT_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX wr_wait_n" *)
output wire RX_WR_WAIT_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX rd_wait_p" *)
output wire RX_RD_WAIT_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX rd_wait_n" *)
output wire RX_RD_WAIT_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX lclk_p" *)
input wire RX_LCLK_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX lclk_n" *)
input wire RX_LCLK_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX frame_p" *)
input wire RX_FRAME_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX frame_n" *)
input wire RX_FRAME_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX data_p" *)
input wire [7 : 0] RX_DATA_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 RX data_n" *)
input wire [7 : 0] RX_DATA_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX lclk_p" *)
output wire TX_LCLK_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX lclk_n" *)
output wire TX_LCLK_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX frame_p" *)
output wire TX_FRAME_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX frame_n" *)
output wire TX_FRAME_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX data_p" *)
output wire [7 : 0] TX_DATA_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX data_n" *)
output wire [7 : 0] TX_DATA_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX wr_wait_p" *)
input wire TX_WR_WAIT_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX wr_wait_n" *)
input wire TX_WR_WAIT_N;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX rd_wait_p" *)
input wire TX_RD_WAIT_P;
(* X_INTERFACE_INFO = "adapteva.com:interface:eLink:1.0 TX rd_wait_n" *)
input wire TX_RD_WAIT_N;
(* X_INTERFACE_INFO = "xilinx.com:interface:gpio:1.0 GPIO TRI_I" *)
output wire [63 : 0] PS_GPIO_I;
inout wire [11 : 0] GPIO_P;
inout wire [11 : 0] GPIO_N;
(* X_INTERFACE_INFO = "xilinx.com:interface:gpio:1.0 GPIO TRI_O" *)
input wire [63 : 0] PS_GPIO_O;
(* X_INTERFACE_INFO = "xilinx.com:interface:gpio:1.0 GPIO TRI_T" *)
input wire [63 : 0] PS_GPIO_T;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SDA_I" *)
output wire I2C_SDA_I;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SCL_I" *)
output wire I2C_SCL_I;
inout wire I2C_SDA;
inout wire I2C_SCL;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SDA_O" *)
input wire I2C_SDA_O;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SDA_T" *)
input wire I2C_SDA_T;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SCL_O" *)
input wire I2C_SCL_O;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SCL_T" *)
input wire I2C_SCL_T;

  dummy_parallella_io #(
    .IOSTD_ELINK("LVDS_25"),
    .NUM_GPIO_PAIRS(12),
    .DIFF_GPIO(0),
    .NUM_PS_SIGS(64)
  ) inst (
    .CCLK_P(CCLK_P),
    .CCLK_N(CCLK_N),
    .DSP_RESET_N(DSP_RESET_N),
    .RX_WR_WAIT_P(RX_WR_WAIT_P),
    .RX_WR_WAIT_N(RX_WR_WAIT_N),
    .RX_RD_WAIT_P(RX_RD_WAIT_P),
    .RX_RD_WAIT_N(RX_RD_WAIT_N),
    .RX_LCLK_P(RX_LCLK_P),
    .RX_LCLK_N(RX_LCLK_N),
    .RX_FRAME_P(RX_FRAME_P),
    .RX_FRAME_N(RX_FRAME_N),
    .RX_DATA_P(RX_DATA_P),
    .RX_DATA_N(RX_DATA_N),
    .TX_LCLK_P(TX_LCLK_P),
    .TX_LCLK_N(TX_LCLK_N),
    .TX_FRAME_P(TX_FRAME_P),
    .TX_FRAME_N(TX_FRAME_N),
    .TX_DATA_P(TX_DATA_P),
    .TX_DATA_N(TX_DATA_N),
    .TX_WR_WAIT_P(TX_WR_WAIT_P),
    .TX_WR_WAIT_N(TX_WR_WAIT_N),
    .TX_RD_WAIT_P(TX_RD_WAIT_P),
    .TX_RD_WAIT_N(TX_RD_WAIT_N),
    .PS_GPIO_I(PS_GPIO_I),
    .GPIO_P(GPIO_P),
    .GPIO_N(GPIO_N),
    .PS_GPIO_O(PS_GPIO_O),
    .PS_GPIO_T(PS_GPIO_T),
    .I2C_SDA_I(I2C_SDA_I),
    .I2C_SCL_I(I2C_SCL_I),
    .I2C_SDA(I2C_SDA),
    .I2C_SCL(I2C_SCL),
    .I2C_SDA_O(I2C_SDA_O),
    .I2C_SDA_T(I2C_SDA_T),
    .I2C_SCL_O(I2C_SCL_O),
    .I2C_SCL_T(I2C_SCL_T)
  );
endmodule
