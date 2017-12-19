-- (c) Copyright 1995-2017 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: k88k:user:dummy_parallella_io:1.0
-- IP Revision: 1

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT top_dummy_parallella_io_0_0
  PORT (
    CCLK_P : OUT STD_LOGIC;
    CCLK_N : OUT STD_LOGIC;
    DSP_RESET_N : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
    RX_WR_WAIT_P : OUT STD_LOGIC;
    RX_WR_WAIT_N : OUT STD_LOGIC;
    RX_RD_WAIT_P : OUT STD_LOGIC;
    RX_RD_WAIT_N : OUT STD_LOGIC;
    RX_LCLK_P : IN STD_LOGIC;
    RX_LCLK_N : IN STD_LOGIC;
    RX_FRAME_P : IN STD_LOGIC;
    RX_FRAME_N : IN STD_LOGIC;
    RX_DATA_P : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    RX_DATA_N : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    TX_LCLK_P : OUT STD_LOGIC;
    TX_LCLK_N : OUT STD_LOGIC;
    TX_FRAME_P : OUT STD_LOGIC;
    TX_FRAME_N : OUT STD_LOGIC;
    TX_DATA_P : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    TX_DATA_N : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    TX_WR_WAIT_P : IN STD_LOGIC;
    TX_WR_WAIT_N : IN STD_LOGIC;
    TX_RD_WAIT_P : IN STD_LOGIC;
    TX_RD_WAIT_N : IN STD_LOGIC;
    PS_GPIO_I : OUT STD_LOGIC_VECTOR(63 DOWNTO 0);
    GPIO_P : INOUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    GPIO_N : INOUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    PS_GPIO_O : IN STD_LOGIC_VECTOR(63 DOWNTO 0);
    PS_GPIO_T : IN STD_LOGIC_VECTOR(63 DOWNTO 0);
    I2C_SDA_I : OUT STD_LOGIC;
    I2C_SCL_I : OUT STD_LOGIC;
    I2C_SDA : INOUT STD_LOGIC;
    I2C_SCL : INOUT STD_LOGIC;
    I2C_SDA_O : IN STD_LOGIC;
    I2C_SDA_T : IN STD_LOGIC;
    I2C_SCL_O : IN STD_LOGIC;
    I2C_SCL_T : IN STD_LOGIC
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : top_dummy_parallella_io_0_0
  PORT MAP (
    CCLK_P => CCLK_P,
    CCLK_N => CCLK_N,
    DSP_RESET_N => DSP_RESET_N,
    RX_WR_WAIT_P => RX_WR_WAIT_P,
    RX_WR_WAIT_N => RX_WR_WAIT_N,
    RX_RD_WAIT_P => RX_RD_WAIT_P,
    RX_RD_WAIT_N => RX_RD_WAIT_N,
    RX_LCLK_P => RX_LCLK_P,
    RX_LCLK_N => RX_LCLK_N,
    RX_FRAME_P => RX_FRAME_P,
    RX_FRAME_N => RX_FRAME_N,
    RX_DATA_P => RX_DATA_P,
    RX_DATA_N => RX_DATA_N,
    TX_LCLK_P => TX_LCLK_P,
    TX_LCLK_N => TX_LCLK_N,
    TX_FRAME_P => TX_FRAME_P,
    TX_FRAME_N => TX_FRAME_N,
    TX_DATA_P => TX_DATA_P,
    TX_DATA_N => TX_DATA_N,
    TX_WR_WAIT_P => TX_WR_WAIT_P,
    TX_WR_WAIT_N => TX_WR_WAIT_N,
    TX_RD_WAIT_P => TX_RD_WAIT_P,
    TX_RD_WAIT_N => TX_RD_WAIT_N,
    PS_GPIO_I => PS_GPIO_I,
    GPIO_P => GPIO_P,
    GPIO_N => GPIO_N,
    PS_GPIO_O => PS_GPIO_O,
    PS_GPIO_T => PS_GPIO_T,
    I2C_SDA_I => I2C_SDA_I,
    I2C_SCL_I => I2C_SCL_I,
    I2C_SDA => I2C_SDA,
    I2C_SCL => I2C_SCL,
    I2C_SDA_O => I2C_SDA_O,
    I2C_SDA_T => I2C_SDA_T,
    I2C_SCL_O => I2C_SCL_O,
    I2C_SCL_T => I2C_SCL_T
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

