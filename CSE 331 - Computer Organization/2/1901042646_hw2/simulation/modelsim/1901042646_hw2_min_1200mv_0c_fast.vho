-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"

-- DATE "12/08/2022 20:07:13"

-- 
-- Device: Altera EP4CGX22CF19C6 Package FBGA324
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIV;
LIBRARY IEEE;
USE CYCLONEIV.CYCLONEIV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	alu32 IS
    PORT (
	A : IN std_logic_vector(31 DOWNTO 0);
	B : IN std_logic_vector(31 DOWNTO 0);
	ALUop : IN std_logic_vector(2 DOWNTO 0);
	Result : BUFFER std_logic_vector(31 DOWNTO 0)
	);
END alu32;

-- Design Ports Information
-- Result[0]	=>  Location: PIN_C15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[1]	=>  Location: PIN_A14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[2]	=>  Location: PIN_D9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[3]	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[4]	=>  Location: PIN_T11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[5]	=>  Location: PIN_B10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[6]	=>  Location: PIN_R11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[7]	=>  Location: PIN_A10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[8]	=>  Location: PIN_A9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[9]	=>  Location: PIN_V15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[10]	=>  Location: PIN_D10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[11]	=>  Location: PIN_J16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[12]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[13]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[14]	=>  Location: PIN_H16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[15]	=>  Location: PIN_R12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[16]	=>  Location: PIN_U18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[17]	=>  Location: PIN_V16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[18]	=>  Location: PIN_P16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[19]	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[20]	=>  Location: PIN_R18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[21]	=>  Location: PIN_T15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[22]	=>  Location: PIN_M17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[23]	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[24]	=>  Location: PIN_M18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[25]	=>  Location: PIN_G18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[26]	=>  Location: PIN_D17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[27]	=>  Location: PIN_K16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[28]	=>  Location: PIN_J17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[29]	=>  Location: PIN_C17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[30]	=>  Location: PIN_A17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Result[31]	=>  Location: PIN_V14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[31]	=>  Location: PIN_H18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[31]	=>  Location: PIN_J18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[30]	=>  Location: PIN_C18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[29]	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[28]	=>  Location: PIN_V11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[27]	=>  Location: PIN_V12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[26]	=>  Location: PIN_G16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[25]	=>  Location: PIN_F17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[24]	=>  Location: PIN_L18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[23]	=>  Location: PIN_R17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[22]	=>  Location: PIN_T18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[21]	=>  Location: PIN_R15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[20]	=>  Location: PIN_P15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[19]	=>  Location: PIN_N15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[18]	=>  Location: PIN_L15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[17]	=>  Location: PIN_V17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[16]	=>  Location: PIN_V18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[15]	=>  Location: PIN_N18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[14]	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[13]	=>  Location: PIN_P12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[12]	=>  Location: PIN_A18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[11]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[10]	=>  Location: PIN_E18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[9]	=>  Location: PIN_R13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[8]	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[7]	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[6]	=>  Location: PIN_D12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[5]	=>  Location: PIN_C9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[4]	=>  Location: PIN_D18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[4]	=>  Location: PIN_B9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[3]	=>  Location: PIN_C10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[2]	=>  Location: PIN_B13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[1]	=>  Location: PIN_C14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[0]	=>  Location: PIN_C12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[0]	=>  Location: PIN_B15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[1]	=>  Location: PIN_A8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[2]	=>  Location: PIN_B16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[3]	=>  Location: PIN_C11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[5]	=>  Location: PIN_D11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[6]	=>  Location: PIN_F18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[7]	=>  Location: PIN_A13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[8]	=>  Location: PIN_E10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[9]	=>  Location: PIN_C13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[10]	=>  Location: PIN_D14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[11]	=>  Location: PIN_T14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[12]	=>  Location: PIN_U15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[13]	=>  Location: PIN_F16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[14]	=>  Location: PIN_E12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[15]	=>  Location: PIN_U16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[16]	=>  Location: PIN_T16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[17]	=>  Location: PIN_T17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[18]	=>  Location: PIN_P18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[19]	=>  Location: PIN_R14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[20]	=>  Location: PIN_L16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[21]	=>  Location: PIN_R16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[22]	=>  Location: PIN_K15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[23]	=>  Location: PIN_N17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[24]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[25]	=>  Location: PIN_B12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[26]	=>  Location: PIN_G17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[27]	=>  Location: PIN_C16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[28]	=>  Location: PIN_P13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[29]	=>  Location: PIN_D15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B[30]	=>  Location: PIN_D16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ALUop[0]	=>  Location: PIN_E16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ALUop[1]	=>  Location: PIN_D13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ALUop[2]	=>  Location: PIN_A16,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF alu32 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_A : std_logic_vector(31 DOWNTO 0);
SIGNAL ww_B : std_logic_vector(31 DOWNTO 0);
SIGNAL ww_ALUop : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_Result : std_logic_vector(31 DOWNTO 0);
SIGNAL \Result[0]~output_o\ : std_logic;
SIGNAL \Result[1]~output_o\ : std_logic;
SIGNAL \Result[2]~output_o\ : std_logic;
SIGNAL \Result[3]~output_o\ : std_logic;
SIGNAL \Result[4]~output_o\ : std_logic;
SIGNAL \Result[5]~output_o\ : std_logic;
SIGNAL \Result[6]~output_o\ : std_logic;
SIGNAL \Result[7]~output_o\ : std_logic;
SIGNAL \Result[8]~output_o\ : std_logic;
SIGNAL \Result[9]~output_o\ : std_logic;
SIGNAL \Result[10]~output_o\ : std_logic;
SIGNAL \Result[11]~output_o\ : std_logic;
SIGNAL \Result[12]~output_o\ : std_logic;
SIGNAL \Result[13]~output_o\ : std_logic;
SIGNAL \Result[14]~output_o\ : std_logic;
SIGNAL \Result[15]~output_o\ : std_logic;
SIGNAL \Result[16]~output_o\ : std_logic;
SIGNAL \Result[17]~output_o\ : std_logic;
SIGNAL \Result[18]~output_o\ : std_logic;
SIGNAL \Result[19]~output_o\ : std_logic;
SIGNAL \Result[20]~output_o\ : std_logic;
SIGNAL \Result[21]~output_o\ : std_logic;
SIGNAL \Result[22]~output_o\ : std_logic;
SIGNAL \Result[23]~output_o\ : std_logic;
SIGNAL \Result[24]~output_o\ : std_logic;
SIGNAL \Result[25]~output_o\ : std_logic;
SIGNAL \Result[26]~output_o\ : std_logic;
SIGNAL \Result[27]~output_o\ : std_logic;
SIGNAL \Result[28]~output_o\ : std_logic;
SIGNAL \Result[29]~output_o\ : std_logic;
SIGNAL \Result[30]~output_o\ : std_logic;
SIGNAL \Result[31]~output_o\ : std_logic;
SIGNAL \B[28]~input_o\ : std_logic;
SIGNAL \A[28]~input_o\ : std_logic;
SIGNAL \B[27]~input_o\ : std_logic;
SIGNAL \A[27]~input_o\ : std_logic;
SIGNAL \A[26]~input_o\ : std_logic;
SIGNAL \B[25]~input_o\ : std_logic;
SIGNAL \B[24]~input_o\ : std_logic;
SIGNAL \A[24]~input_o\ : std_logic;
SIGNAL \B[23]~input_o\ : std_logic;
SIGNAL \A[21]~input_o\ : std_logic;
SIGNAL \B[18]~input_o\ : std_logic;
SIGNAL \B[17]~input_o\ : std_logic;
SIGNAL \A[17]~input_o\ : std_logic;
SIGNAL \A[14]~input_o\ : std_logic;
SIGNAL \B[14]~input_o\ : std_logic;
SIGNAL \A[8]~input_o\ : std_logic;
SIGNAL \B[8]~input_o\ : std_logic;
SIGNAL \A[7]~input_o\ : std_logic;
SIGNAL \B[7]~input_o\ : std_logic;
SIGNAL \A[6]~input_o\ : std_logic;
SIGNAL \B[6]~input_o\ : std_logic;
SIGNAL \A[5]~input_o\ : std_logic;
SIGNAL \B[5]~input_o\ : std_logic;
SIGNAL \A[4]~input_o\ : std_logic;
SIGNAL \B[4]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA4|HA1|G2~combout\ : std_logic;
SIGNAL \A[2]~input_o\ : std_logic;
SIGNAL \B[1]~input_o\ : std_logic;
SIGNAL \B[0]~input_o\ : std_logic;
SIGNAL \A[0]~input_o\ : std_logic;
SIGNAL \A[1]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA1|Cout~combout\ : std_logic;
SIGNAL \B[2]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA2|Cout~combout\ : std_logic;
SIGNAL \B[3]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA4|HA1|G1~0_combout\ : std_logic;
SIGNAL \A[3]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA4|HA2|G2~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA5|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA6|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA7|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA8|Cout~combout\ : std_logic;
SIGNAL \B[9]~input_o\ : std_logic;
SIGNAL \A[9]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA9|Cout~combout\ : std_logic;
SIGNAL \B[10]~input_o\ : std_logic;
SIGNAL \A[10]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA10|Cout~combout\ : std_logic;
SIGNAL \B[11]~input_o\ : std_logic;
SIGNAL \A[11]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA11|Cout~combout\ : std_logic;
SIGNAL \B[12]~input_o\ : std_logic;
SIGNAL \A[12]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA12|Cout~combout\ : std_logic;
SIGNAL \A[13]~input_o\ : std_logic;
SIGNAL \B[13]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA13|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA14|Cout~combout\ : std_logic;
SIGNAL \B[15]~input_o\ : std_logic;
SIGNAL \A[15]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA15|Cout~combout\ : std_logic;
SIGNAL \B[16]~input_o\ : std_logic;
SIGNAL \A[16]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA16|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA17|Cout~combout\ : std_logic;
SIGNAL \A[18]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA18|Cout~combout\ : std_logic;
SIGNAL \B[19]~input_o\ : std_logic;
SIGNAL \A[19]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA19|Cout~combout\ : std_logic;
SIGNAL \A[20]~input_o\ : std_logic;
SIGNAL \B[20]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA20|Cout~combout\ : std_logic;
SIGNAL \B[21]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA21|Cout~combout\ : std_logic;
SIGNAL \A[22]~input_o\ : std_logic;
SIGNAL \B[22]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA22|Cout~combout\ : std_logic;
SIGNAL \A[23]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA23|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA24|Cout~combout\ : std_logic;
SIGNAL \A[25]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA25|Cout~combout\ : std_logic;
SIGNAL \B[26]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA26|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA27|Cout~combout\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA28|Cout~combout\ : std_logic;
SIGNAL \B[29]~input_o\ : std_logic;
SIGNAL \A[29]~input_o\ : std_logic;
SIGNAL \slt_nums|sub|A0|FA29|Cout~combout\ : std_logic;
SIGNAL \B[30]~input_o\ : std_logic;
SIGNAL \A[30]~input_o\ : std_logic;
SIGNAL \M0|M6|O0~0_combout\ : std_logic;
SIGNAL \B[31]~input_o\ : std_logic;
SIGNAL \A[31]~input_o\ : std_logic;
SIGNAL \M0|M6|O0~1_combout\ : std_logic;
SIGNAL \ALUop[1]~input_o\ : std_logic;
SIGNAL \ALUop[2]~input_o\ : std_logic;
SIGNAL \ALUop[0]~input_o\ : std_logic;
SIGNAL \M0|M6|O0~3_combout\ : std_logic;
SIGNAL \M0|M6|O0~4_combout\ : std_logic;
SIGNAL \M0|M6|O0~2_combout\ : std_logic;
SIGNAL \M0|M6|O0~5_combout\ : std_logic;
SIGNAL \M1|M6|O0~0_combout\ : std_logic;
SIGNAL \M1|M6|O0~2_combout\ : std_logic;
SIGNAL \M1|M6|O0~1_combout\ : std_logic;
SIGNAL \M1|M6|O0~7_combout\ : std_logic;
SIGNAL \M1|M6|O0~8_combout\ : std_logic;
SIGNAL \M1|M6|O0~5_combout\ : std_logic;
SIGNAL \M1|M6|O0~6_combout\ : std_logic;
SIGNAL \M1|M6|O0~3_combout\ : std_logic;
SIGNAL \M1|M6|O0~4_combout\ : std_logic;
SIGNAL \add_nums|FA1|Cout~0_combout\ : std_logic;
SIGNAL \M2|M6|O0~0_combout\ : std_logic;
SIGNAL \M2|M6|O0~1_combout\ : std_logic;
SIGNAL \M2|M6|O0~2_combout\ : std_logic;
SIGNAL \M2|M6|O0~3_combout\ : std_logic;
SIGNAL \M3|M6|O0~2_combout\ : std_logic;
SIGNAL \M3|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA2|Cout~0_combout\ : std_logic;
SIGNAL \M3|M6|O0~0_combout\ : std_logic;
SIGNAL \M3|M6|O0~3_combout\ : std_logic;
SIGNAL \M4|M6|O0~0_combout\ : std_logic;
SIGNAL \M4|M6|O0~1_combout\ : std_logic;
SIGNAL \M4|M6|O0~2_combout\ : std_logic;
SIGNAL \M4|M6|O0~3_combout\ : std_logic;
SIGNAL \M4|M6|O0~4_combout\ : std_logic;
SIGNAL \M4|M6|O0~5_combout\ : std_logic;
SIGNAL \add_nums|FA4|Cout~1_combout\ : std_logic;
SIGNAL \add_nums|FA4|Cout~0_combout\ : std_logic;
SIGNAL \M5|M6|O0~0_combout\ : std_logic;
SIGNAL \M5|M6|O0~1_combout\ : std_logic;
SIGNAL \M5|M6|O0~3_combout\ : std_logic;
SIGNAL \M5|M6|O0~2_combout\ : std_logic;
SIGNAL \M5|M6|O0~4_combout\ : std_logic;
SIGNAL \add_nums|FA5|Cout~0_combout\ : std_logic;
SIGNAL \M6|M6|O0~0_combout\ : std_logic;
SIGNAL \M6|M6|O0~1_combout\ : std_logic;
SIGNAL \M6|M6|O0~2_combout\ : std_logic;
SIGNAL \M6|M6|O0~3_combout\ : std_logic;
SIGNAL \M7|M6|O0~2_combout\ : std_logic;
SIGNAL \M7|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA6|Cout~0_combout\ : std_logic;
SIGNAL \M7|M6|O0~0_combout\ : std_logic;
SIGNAL \M7|M6|O0~3_combout\ : std_logic;
SIGNAL \M8|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA7|Cout~0_combout\ : std_logic;
SIGNAL \M8|M6|O0~0_combout\ : std_logic;
SIGNAL \M8|M6|O0~2_combout\ : std_logic;
SIGNAL \M8|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA8|Cout~0_combout\ : std_logic;
SIGNAL \M9|M6|O0~0_combout\ : std_logic;
SIGNAL \M9|M6|O0~1_combout\ : std_logic;
SIGNAL \M9|M6|O0~2_combout\ : std_logic;
SIGNAL \M9|M6|O0~3_combout\ : std_logic;
SIGNAL \M10|M6|O0~2_combout\ : std_logic;
SIGNAL \M10|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA9|Cout~0_combout\ : std_logic;
SIGNAL \M10|M6|O0~0_combout\ : std_logic;
SIGNAL \M10|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA10|Cout~0_combout\ : std_logic;
SIGNAL \M11|M6|O0~0_combout\ : std_logic;
SIGNAL \M11|M6|O0~2_combout\ : std_logic;
SIGNAL \M11|M6|O0~1_combout\ : std_logic;
SIGNAL \M11|M6|O0~3_combout\ : std_logic;
SIGNAL \M12|M6|O0~2_combout\ : std_logic;
SIGNAL \add_nums|FA11|Cout~0_combout\ : std_logic;
SIGNAL \M12|M6|O0~0_combout\ : std_logic;
SIGNAL \M12|M6|O0~1_combout\ : std_logic;
SIGNAL \M12|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA12|Cout~0_combout\ : std_logic;
SIGNAL \M13|M6|O0~0_combout\ : std_logic;
SIGNAL \M13|M6|O0~2_combout\ : std_logic;
SIGNAL \M13|M6|O0~1_combout\ : std_logic;
SIGNAL \M13|M6|O0~3_combout\ : std_logic;
SIGNAL \M14|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA13|Cout~0_combout\ : std_logic;
SIGNAL \M14|M6|O0~0_combout\ : std_logic;
SIGNAL \M14|M6|O0~2_combout\ : std_logic;
SIGNAL \M14|M6|O0~3_combout\ : std_logic;
SIGNAL \M15|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA14|Cout~0_combout\ : std_logic;
SIGNAL \M15|M6|O0~0_combout\ : std_logic;
SIGNAL \M15|M6|O0~2_combout\ : std_logic;
SIGNAL \M15|M6|O0~3_combout\ : std_logic;
SIGNAL \M16|M6|O0~1_combout\ : std_logic;
SIGNAL \M16|M6|O0~2_combout\ : std_logic;
SIGNAL \add_nums|FA15|Cout~0_combout\ : std_logic;
SIGNAL \M16|M6|O0~0_combout\ : std_logic;
SIGNAL \M16|M6|O0~3_combout\ : std_logic;
SIGNAL \M17|M6|O0~2_combout\ : std_logic;
SIGNAL \M17|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA16|Cout~0_combout\ : std_logic;
SIGNAL \M17|M6|O0~0_combout\ : std_logic;
SIGNAL \M17|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA17|Cout~0_combout\ : std_logic;
SIGNAL \M18|M6|O0~0_combout\ : std_logic;
SIGNAL \M18|M6|O0~2_combout\ : std_logic;
SIGNAL \M18|M6|O0~1_combout\ : std_logic;
SIGNAL \M18|M6|O0~3_combout\ : std_logic;
SIGNAL \M19|M6|O0~2_combout\ : std_logic;
SIGNAL \M19|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA18|Cout~0_combout\ : std_logic;
SIGNAL \M19|M6|O0~0_combout\ : std_logic;
SIGNAL \M19|M6|O0~3_combout\ : std_logic;
SIGNAL \M20|M6|O0~1_combout\ : std_logic;
SIGNAL \M20|M6|O0~2_combout\ : std_logic;
SIGNAL \add_nums|FA19|Cout~0_combout\ : std_logic;
SIGNAL \M20|M6|O0~0_combout\ : std_logic;
SIGNAL \M20|M6|O0~3_combout\ : std_logic;
SIGNAL \M21|M6|O0~2_combout\ : std_logic;
SIGNAL \M21|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA20|Cout~0_combout\ : std_logic;
SIGNAL \M21|M6|O0~0_combout\ : std_logic;
SIGNAL \M21|M6|O0~3_combout\ : std_logic;
SIGNAL \M22|M6|O0~2_combout\ : std_logic;
SIGNAL \M22|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA21|Cout~0_combout\ : std_logic;
SIGNAL \M22|M6|O0~0_combout\ : std_logic;
SIGNAL \M22|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA22|Cout~0_combout\ : std_logic;
SIGNAL \M23|M6|O0~0_combout\ : std_logic;
SIGNAL \M23|M6|O0~1_combout\ : std_logic;
SIGNAL \M23|M6|O0~2_combout\ : std_logic;
SIGNAL \M23|M6|O0~3_combout\ : std_logic;
SIGNAL \M24|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA23|Cout~0_combout\ : std_logic;
SIGNAL \M24|M6|O0~0_combout\ : std_logic;
SIGNAL \M24|M6|O0~2_combout\ : std_logic;
SIGNAL \M24|M6|O0~3_combout\ : std_logic;
SIGNAL \M25|M6|O0~1_combout\ : std_logic;
SIGNAL \M25|M6|O0~2_combout\ : std_logic;
SIGNAL \add_nums|FA24|Cout~0_combout\ : std_logic;
SIGNAL \M25|M6|O0~0_combout\ : std_logic;
SIGNAL \M25|M6|O0~3_combout\ : std_logic;
SIGNAL \M26|M6|O0~2_combout\ : std_logic;
SIGNAL \M26|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA25|Cout~0_combout\ : std_logic;
SIGNAL \M26|M6|O0~0_combout\ : std_logic;
SIGNAL \M26|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA26|Cout~0_combout\ : std_logic;
SIGNAL \M27|M6|O0~0_combout\ : std_logic;
SIGNAL \M27|M6|O0~1_combout\ : std_logic;
SIGNAL \M27|M6|O0~2_combout\ : std_logic;
SIGNAL \M27|M6|O0~3_combout\ : std_logic;
SIGNAL \M28|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA27|Cout~0_combout\ : std_logic;
SIGNAL \M28|M6|O0~0_combout\ : std_logic;
SIGNAL \M28|M6|O0~2_combout\ : std_logic;
SIGNAL \M28|M6|O0~3_combout\ : std_logic;
SIGNAL \M29|M6|O0~1_combout\ : std_logic;
SIGNAL \add_nums|FA28|Cout~0_combout\ : std_logic;
SIGNAL \M29|M6|O0~0_combout\ : std_logic;
SIGNAL \M29|M6|O0~2_combout\ : std_logic;
SIGNAL \M29|M6|O0~3_combout\ : std_logic;
SIGNAL \add_nums|FA29|Cout~0_combout\ : std_logic;
SIGNAL \M30|M6|O0~0_combout\ : std_logic;
SIGNAL \M30|M6|O0~1_combout\ : std_logic;
SIGNAL \M30|M6|O0~2_combout\ : std_logic;
SIGNAL \M30|M6|O0~3_combout\ : std_logic;
SIGNAL \M31|M6|O0~1_combout\ : std_logic;
SIGNAL \M31|M6|O0~2_combout\ : std_logic;
SIGNAL \M31|M6|O0~5_combout\ : std_logic;
SIGNAL \M31|M6|O0~6_combout\ : std_logic;
SIGNAL \M31|M6|O0~3_combout\ : std_logic;
SIGNAL \M31|M6|O0~0_combout\ : std_logic;
SIGNAL \M31|M6|O0~4_combout\ : std_logic;

BEGIN

ww_A <= A;
ww_B <= B;
ww_ALUop <= ALUop;
Result <= ww_Result;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X41_Y41_N9
\Result[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M0|M6|O0~5_combout\,
	devoe => ww_devoe,
	o => \Result[0]~output_o\);

-- Location: IOOBUF_X34_Y41_N2
\Result[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M1|M6|O0~4_combout\,
	devoe => ww_devoe,
	o => \Result[1]~output_o\);

-- Location: IOOBUF_X18_Y41_N9
\Result[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M2|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[2]~output_o\);

-- Location: IOOBUF_X31_Y0_N9
\Result[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M3|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[3]~output_o\);

-- Location: IOOBUF_X31_Y0_N16
\Result[4]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M4|M6|O0~5_combout\,
	devoe => ww_devoe,
	o => \Result[4]~output_o\);

-- Location: IOOBUF_X21_Y41_N9
\Result[5]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M5|M6|O0~4_combout\,
	devoe => ww_devoe,
	o => \Result[5]~output_o\);

-- Location: IOOBUF_X31_Y0_N23
\Result[6]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M6|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[6]~output_o\);

-- Location: IOOBUF_X23_Y41_N2
\Result[7]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M7|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[7]~output_o\);

-- Location: IOOBUF_X16_Y41_N9
\Result[8]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M8|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[8]~output_o\);

-- Location: IOOBUF_X34_Y0_N2
\Result[9]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M9|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[9]~output_o\);

-- Location: IOOBUF_X29_Y41_N2
\Result[10]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M10|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[10]~output_o\);

-- Location: IOOBUF_X52_Y23_N2
\Result[11]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M11|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[11]~output_o\);

-- Location: IOOBUF_X52_Y32_N9
\Result[12]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M12|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[12]~output_o\);

-- Location: IOOBUF_X52_Y32_N2
\Result[13]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M13|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[13]~output_o\);

-- Location: IOOBUF_X52_Y28_N2
\Result[14]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M14|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[14]~output_o\);

-- Location: IOOBUF_X36_Y0_N9
\Result[15]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M15|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[15]~output_o\);

-- Location: IOOBUF_X46_Y0_N23
\Result[16]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M16|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[16]~output_o\);

-- Location: IOOBUF_X43_Y0_N9
\Result[17]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M17|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[17]~output_o\);

-- Location: IOOBUF_X52_Y10_N9
\Result[18]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M18|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[18]~output_o\);

-- Location: IOOBUF_X52_Y9_N2
\Result[19]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M19|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[19]~output_o\);

-- Location: IOOBUF_X52_Y12_N2
\Result[20]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M20|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[20]~output_o\);

-- Location: IOOBUF_X48_Y0_N2
\Result[21]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M21|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[21]~output_o\);

-- Location: IOOBUF_X52_Y15_N9
\Result[22]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M22|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[22]~output_o\);

-- Location: IOOBUF_X52_Y15_N2
\Result[23]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M23|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[23]~output_o\);

-- Location: IOOBUF_X52_Y19_N2
\Result[24]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M24|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[24]~output_o\);

-- Location: IOOBUF_X52_Y25_N9
\Result[25]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M25|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[25]~output_o\);

-- Location: IOOBUF_X52_Y31_N2
\Result[26]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M26|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[26]~output_o\);

-- Location: IOOBUF_X52_Y18_N9
\Result[27]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M27|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[27]~output_o\);

-- Location: IOOBUF_X52_Y23_N9
\Result[28]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M28|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[28]~output_o\);

-- Location: IOOBUF_X48_Y41_N9
\Result[29]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M29|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[29]~output_o\);

-- Location: IOOBUF_X46_Y41_N16
\Result[30]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M30|M6|O0~3_combout\,
	devoe => ww_devoe,
	o => \Result[30]~output_o\);

-- Location: IOOBUF_X34_Y0_N9
\Result[31]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \M31|M6|O0~4_combout\,
	devoe => ww_devoe,
	o => \Result[31]~output_o\);

-- Location: IOIBUF_X38_Y0_N1
\B[28]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(28),
	o => \B[28]~input_o\);

-- Location: IOIBUF_X27_Y0_N8
\A[28]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(28),
	o => \A[28]~input_o\);

-- Location: IOIBUF_X48_Y41_N1
\B[27]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(27),
	o => \B[27]~input_o\);

-- Location: IOIBUF_X27_Y0_N1
\A[27]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(27),
	o => \A[27]~input_o\);

-- Location: IOIBUF_X52_Y27_N1
\A[26]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(26),
	o => \A[26]~input_o\);

-- Location: IOIBUF_X27_Y41_N8
\B[25]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(25),
	o => \B[25]~input_o\);

-- Location: IOIBUF_X27_Y41_N1
\B[24]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(24),
	o => \B[24]~input_o\);

-- Location: IOIBUF_X52_Y19_N8
\A[24]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(24),
	o => \A[24]~input_o\);

-- Location: IOIBUF_X52_Y16_N1
\B[23]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(23),
	o => \B[23]~input_o\);

-- Location: IOIBUF_X50_Y0_N1
\A[21]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(21),
	o => \A[21]~input_o\);

-- Location: IOIBUF_X52_Y12_N8
\B[18]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(18),
	o => \B[18]~input_o\);

-- Location: IOIBUF_X46_Y0_N1
\B[17]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(17),
	o => \B[17]~input_o\);

-- Location: IOIBUF_X43_Y0_N1
\A[17]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(17),
	o => \A[17]~input_o\);

-- Location: IOIBUF_X41_Y0_N22
\A[14]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(14),
	o => \A[14]~input_o\);

-- Location: IOIBUF_X41_Y41_N22
\B[14]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(14),
	o => \B[14]~input_o\);

-- Location: IOIBUF_X23_Y41_N8
\A[8]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(8),
	o => \A[8]~input_o\);

-- Location: IOIBUF_X29_Y41_N8
\B[8]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(8),
	o => \B[8]~input_o\);

-- Location: IOIBUF_X34_Y41_N8
\A[7]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(7),
	o => \A[7]~input_o\);

-- Location: IOIBUF_X31_Y41_N15
\B[7]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(7),
	o => \B[7]~input_o\);

-- Location: IOIBUF_X31_Y41_N8
\A[6]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(6),
	o => \A[6]~input_o\);

-- Location: IOIBUF_X52_Y30_N1
\B[6]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(6),
	o => \B[6]~input_o\);

-- Location: IOIBUF_X18_Y41_N1
\A[5]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(5),
	o => \A[5]~input_o\);

-- Location: IOIBUF_X31_Y41_N1
\B[5]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(5),
	o => \B[5]~input_o\);

-- Location: IOIBUF_X52_Y31_N8
\A[4]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(4),
	o => \A[4]~input_o\);

-- Location: IOIBUF_X21_Y41_N1
\B[4]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(4),
	o => \B[4]~input_o\);

-- Location: LCCOMB_X32_Y30_N16
\slt_nums|sub|A0|FA4|HA1|G2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA4|HA1|G2~combout\ = (\A[4]~input_o\ & !\B[4]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \A[4]~input_o\,
	datad => \B[4]~input_o\,
	combout => \slt_nums|sub|A0|FA4|HA1|G2~combout\);

-- Location: IOIBUF_X31_Y41_N22
\A[2]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(2),
	o => \A[2]~input_o\);

-- Location: IOIBUF_X16_Y41_N1
\B[1]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(1),
	o => \B[1]~input_o\);

-- Location: IOIBUF_X41_Y41_N1
\B[0]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(0),
	o => \B[0]~input_o\);

-- Location: IOIBUF_X36_Y41_N1
\A[0]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(0),
	o => \A[0]~input_o\);

-- Location: IOIBUF_X43_Y41_N1
\A[1]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(1),
	o => \A[1]~input_o\);

-- Location: LCCOMB_X38_Y34_N8
\slt_nums|sub|A0|FA1|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA1|Cout~combout\ = (\B[1]~input_o\ & (\A[1]~input_o\ & ((\A[0]~input_o\) # (!\B[0]~input_o\)))) # (!\B[1]~input_o\ & (((\A[0]~input_o\) # (\A[1]~input_o\)) # (!\B[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111011101010001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[1]~input_o\,
	datab => \B[0]~input_o\,
	datac => \A[0]~input_o\,
	datad => \A[1]~input_o\,
	combout => \slt_nums|sub|A0|FA1|Cout~combout\);

-- Location: IOIBUF_X38_Y41_N8
\B[2]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(2),
	o => \B[2]~input_o\);

-- Location: LCCOMB_X35_Y30_N8
\slt_nums|sub|A0|FA2|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA2|Cout~combout\ = (\A[2]~input_o\ & ((\slt_nums|sub|A0|FA1|Cout~combout\) # (!\B[2]~input_o\))) # (!\A[2]~input_o\ & (\slt_nums|sub|A0|FA1|Cout~combout\ & !\B[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[2]~input_o\,
	datac => \slt_nums|sub|A0|FA1|Cout~combout\,
	datad => \B[2]~input_o\,
	combout => \slt_nums|sub|A0|FA2|Cout~combout\);

-- Location: IOIBUF_X25_Y41_N8
\B[3]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(3),
	o => \B[3]~input_o\);

-- Location: LCCOMB_X32_Y30_N26
\slt_nums|sub|A0|FA4|HA1|G1~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA4|HA1|G1~0_combout\ = \A[4]~input_o\ $ (\B[4]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \A[4]~input_o\,
	datad => \B[4]~input_o\,
	combout => \slt_nums|sub|A0|FA4|HA1|G1~0_combout\);

-- Location: IOIBUF_X25_Y41_N1
\A[3]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(3),
	o => \A[3]~input_o\);

-- Location: LCCOMB_X32_Y30_N20
\slt_nums|sub|A0|FA4|HA2|G2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA4|HA2|G2~combout\ = (!\slt_nums|sub|A0|FA4|HA1|G1~0_combout\ & ((\slt_nums|sub|A0|FA2|Cout~combout\ & ((\A[3]~input_o\) # (!\B[3]~input_o\))) # (!\slt_nums|sub|A0|FA2|Cout~combout\ & (!\B[3]~input_o\ & \A[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101100000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA2|Cout~combout\,
	datab => \B[3]~input_o\,
	datac => \slt_nums|sub|A0|FA4|HA1|G1~0_combout\,
	datad => \A[3]~input_o\,
	combout => \slt_nums|sub|A0|FA4|HA2|G2~combout\);

-- Location: LCCOMB_X34_Y30_N8
\slt_nums|sub|A0|FA5|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA5|Cout~combout\ = (\A[5]~input_o\ & (((\slt_nums|sub|A0|FA4|HA1|G2~combout\) # (\slt_nums|sub|A0|FA4|HA2|G2~combout\)) # (!\B[5]~input_o\))) # (!\A[5]~input_o\ & (!\B[5]~input_o\ & ((\slt_nums|sub|A0|FA4|HA1|G2~combout\) # 
-- (\slt_nums|sub|A0|FA4|HA2|G2~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101110110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[5]~input_o\,
	datab => \B[5]~input_o\,
	datac => \slt_nums|sub|A0|FA4|HA1|G2~combout\,
	datad => \slt_nums|sub|A0|FA4|HA2|G2~combout\,
	combout => \slt_nums|sub|A0|FA5|Cout~combout\);

-- Location: LCCOMB_X35_Y30_N18
\slt_nums|sub|A0|FA6|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA6|Cout~combout\ = (\A[6]~input_o\ & ((\slt_nums|sub|A0|FA5|Cout~combout\) # (!\B[6]~input_o\))) # (!\A[6]~input_o\ & (!\B[6]~input_o\ & \slt_nums|sub|A0|FA5|Cout~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[6]~input_o\,
	datac => \B[6]~input_o\,
	datad => \slt_nums|sub|A0|FA5|Cout~combout\,
	combout => \slt_nums|sub|A0|FA6|Cout~combout\);

-- Location: LCCOMB_X35_Y33_N8
\slt_nums|sub|A0|FA7|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA7|Cout~combout\ = (\A[7]~input_o\ & ((\slt_nums|sub|A0|FA6|Cout~combout\) # (!\B[7]~input_o\))) # (!\A[7]~input_o\ & (!\B[7]~input_o\ & \slt_nums|sub|A0|FA6|Cout~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[7]~input_o\,
	datac => \B[7]~input_o\,
	datad => \slt_nums|sub|A0|FA6|Cout~combout\,
	combout => \slt_nums|sub|A0|FA7|Cout~combout\);

-- Location: LCCOMB_X36_Y33_N8
\slt_nums|sub|A0|FA8|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA8|Cout~combout\ = (\A[8]~input_o\ & ((\slt_nums|sub|A0|FA7|Cout~combout\) # (!\B[8]~input_o\))) # (!\A[8]~input_o\ & (!\B[8]~input_o\ & \slt_nums|sub|A0|FA7|Cout~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \A[8]~input_o\,
	datac => \B[8]~input_o\,
	datad => \slt_nums|sub|A0|FA7|Cout~combout\,
	combout => \slt_nums|sub|A0|FA8|Cout~combout\);

-- Location: IOIBUF_X36_Y41_N8
\B[9]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(9),
	o => \B[9]~input_o\);

-- Location: IOIBUF_X36_Y0_N1
\A[9]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(9),
	o => \A[9]~input_o\);

-- Location: LCCOMB_X36_Y33_N10
\slt_nums|sub|A0|FA9|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA9|Cout~combout\ = (\slt_nums|sub|A0|FA8|Cout~combout\ & ((\A[9]~input_o\) # (!\B[9]~input_o\))) # (!\slt_nums|sub|A0|FA8|Cout~combout\ & (!\B[9]~input_o\ & \A[9]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \slt_nums|sub|A0|FA8|Cout~combout\,
	datac => \B[9]~input_o\,
	datad => \A[9]~input_o\,
	combout => \slt_nums|sub|A0|FA9|Cout~combout\);

-- Location: IOIBUF_X43_Y41_N8
\B[10]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(10),
	o => \B[10]~input_o\);

-- Location: IOIBUF_X52_Y30_N8
\A[10]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(10),
	o => \A[10]~input_o\);

-- Location: LCCOMB_X42_Y30_N16
\slt_nums|sub|A0|FA10|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA10|Cout~combout\ = (\slt_nums|sub|A0|FA9|Cout~combout\ & ((\A[10]~input_o\) # (!\B[10]~input_o\))) # (!\slt_nums|sub|A0|FA9|Cout~combout\ & (!\B[10]~input_o\ & \A[10]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101100100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA9|Cout~combout\,
	datab => \B[10]~input_o\,
	datad => \A[10]~input_o\,
	combout => \slt_nums|sub|A0|FA10|Cout~combout\);

-- Location: IOIBUF_X41_Y0_N15
\B[11]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(11),
	o => \B[11]~input_o\);

-- Location: IOIBUF_X52_Y28_N8
\A[11]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(11),
	o => \A[11]~input_o\);

-- Location: LCCOMB_X42_Y30_N26
\slt_nums|sub|A0|FA11|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA11|Cout~combout\ = (\slt_nums|sub|A0|FA10|Cout~combout\ & ((\A[11]~input_o\) # (!\B[11]~input_o\))) # (!\slt_nums|sub|A0|FA10|Cout~combout\ & (!\B[11]~input_o\ & \A[11]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \slt_nums|sub|A0|FA10|Cout~combout\,
	datac => \B[11]~input_o\,
	datad => \A[11]~input_o\,
	combout => \slt_nums|sub|A0|FA11|Cout~combout\);

-- Location: IOIBUF_X41_Y0_N8
\B[12]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(12),
	o => \B[12]~input_o\);

-- Location: IOIBUF_X46_Y41_N22
\A[12]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(12),
	o => \A[12]~input_o\);

-- Location: LCCOMB_X42_Y30_N4
\slt_nums|sub|A0|FA12|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA12|Cout~combout\ = (\slt_nums|sub|A0|FA11|Cout~combout\ & ((\A[12]~input_o\) # (!\B[12]~input_o\))) # (!\slt_nums|sub|A0|FA11|Cout~combout\ & (!\B[12]~input_o\ & \A[12]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011001010110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA11|Cout~combout\,
	datab => \B[12]~input_o\,
	datac => \A[12]~input_o\,
	combout => \slt_nums|sub|A0|FA12|Cout~combout\);

-- Location: IOIBUF_X38_Y0_N8
\A[13]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(13),
	o => \A[13]~input_o\);

-- Location: IOIBUF_X52_Y32_N15
\B[13]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(13),
	o => \B[13]~input_o\);

-- Location: LCCOMB_X42_Y30_N14
\slt_nums|sub|A0|FA13|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA13|Cout~combout\ = (\slt_nums|sub|A0|FA12|Cout~combout\ & ((\A[13]~input_o\) # (!\B[13]~input_o\))) # (!\slt_nums|sub|A0|FA12|Cout~combout\ & (\A[13]~input_o\ & !\B[13]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \slt_nums|sub|A0|FA12|Cout~combout\,
	datac => \A[13]~input_o\,
	datad => \B[13]~input_o\,
	combout => \slt_nums|sub|A0|FA13|Cout~combout\);

-- Location: LCCOMB_X41_Y28_N8
\slt_nums|sub|A0|FA14|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA14|Cout~combout\ = (\A[14]~input_o\ & ((\slt_nums|sub|A0|FA13|Cout~combout\) # (!\B[14]~input_o\))) # (!\A[14]~input_o\ & (!\B[14]~input_o\ & \slt_nums|sub|A0|FA13|Cout~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \A[14]~input_o\,
	datac => \B[14]~input_o\,
	datad => \slt_nums|sub|A0|FA13|Cout~combout\,
	combout => \slt_nums|sub|A0|FA14|Cout~combout\);

-- Location: IOIBUF_X41_Y0_N1
\B[15]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(15),
	o => \B[15]~input_o\);

-- Location: IOIBUF_X52_Y16_N8
\A[15]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(15),
	o => \A[15]~input_o\);

-- Location: LCCOMB_X41_Y16_N16
\slt_nums|sub|A0|FA15|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA15|Cout~combout\ = (\slt_nums|sub|A0|FA14|Cout~combout\ & ((\A[15]~input_o\) # (!\B[15]~input_o\))) # (!\slt_nums|sub|A0|FA14|Cout~combout\ & (!\B[15]~input_o\ & \A[15]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101100100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA14|Cout~combout\,
	datab => \B[15]~input_o\,
	datad => \A[15]~input_o\,
	combout => \slt_nums|sub|A0|FA15|Cout~combout\);

-- Location: IOIBUF_X46_Y0_N8
\B[16]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(16),
	o => \B[16]~input_o\);

-- Location: IOIBUF_X46_Y0_N15
\A[16]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(16),
	o => \A[16]~input_o\);

-- Location: LCCOMB_X46_Y13_N0
\slt_nums|sub|A0|FA16|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA16|Cout~combout\ = (\slt_nums|sub|A0|FA15|Cout~combout\ & ((\A[16]~input_o\) # (!\B[16]~input_o\))) # (!\slt_nums|sub|A0|FA15|Cout~combout\ & (!\B[16]~input_o\ & \A[16]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101100100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA15|Cout~combout\,
	datab => \B[16]~input_o\,
	datad => \A[16]~input_o\,
	combout => \slt_nums|sub|A0|FA16|Cout~combout\);

-- Location: LCCOMB_X46_Y13_N26
\slt_nums|sub|A0|FA17|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA17|Cout~combout\ = (\B[17]~input_o\ & (\A[17]~input_o\ & \slt_nums|sub|A0|FA16|Cout~combout\)) # (!\B[17]~input_o\ & ((\A[17]~input_o\) # (\slt_nums|sub|A0|FA16|Cout~combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010101010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[17]~input_o\,
	datac => \A[17]~input_o\,
	datad => \slt_nums|sub|A0|FA16|Cout~combout\,
	combout => \slt_nums|sub|A0|FA17|Cout~combout\);

-- Location: IOIBUF_X52_Y13_N1
\A[18]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(18),
	o => \A[18]~input_o\);

-- Location: LCCOMB_X51_Y13_N0
\slt_nums|sub|A0|FA18|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA18|Cout~combout\ = (\B[18]~input_o\ & (\slt_nums|sub|A0|FA17|Cout~combout\ & \A[18]~input_o\)) # (!\B[18]~input_o\ & ((\slt_nums|sub|A0|FA17|Cout~combout\) # (\A[18]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001100110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \B[18]~input_o\,
	datac => \slt_nums|sub|A0|FA17|Cout~combout\,
	datad => \A[18]~input_o\,
	combout => \slt_nums|sub|A0|FA18|Cout~combout\);

-- Location: IOIBUF_X48_Y0_N8
\B[19]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(19),
	o => \B[19]~input_o\);

-- Location: IOIBUF_X52_Y9_N8
\A[19]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(19),
	o => \A[19]~input_o\);

-- Location: LCCOMB_X51_Y13_N2
\slt_nums|sub|A0|FA19|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA19|Cout~combout\ = (\slt_nums|sub|A0|FA18|Cout~combout\ & ((\A[19]~input_o\) # (!\B[19]~input_o\))) # (!\slt_nums|sub|A0|FA18|Cout~combout\ & (!\B[19]~input_o\ & \A[19]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \slt_nums|sub|A0|FA18|Cout~combout\,
	datac => \B[19]~input_o\,
	datad => \A[19]~input_o\,
	combout => \slt_nums|sub|A0|FA19|Cout~combout\);

-- Location: IOIBUF_X50_Y0_N8
\A[20]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(20),
	o => \A[20]~input_o\);

-- Location: IOIBUF_X52_Y13_N8
\B[20]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(20),
	o => \B[20]~input_o\);

-- Location: LCCOMB_X50_Y13_N0
\slt_nums|sub|A0|FA20|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA20|Cout~combout\ = (\slt_nums|sub|A0|FA19|Cout~combout\ & ((\A[20]~input_o\) # (!\B[20]~input_o\))) # (!\slt_nums|sub|A0|FA19|Cout~combout\ & (\A[20]~input_o\ & !\B[20]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000100011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA19|Cout~combout\,
	datab => \A[20]~input_o\,
	datad => \B[20]~input_o\,
	combout => \slt_nums|sub|A0|FA20|Cout~combout\);

-- Location: IOIBUF_X52_Y10_N1
\B[21]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(21),
	o => \B[21]~input_o\);

-- Location: LCCOMB_X50_Y13_N2
\slt_nums|sub|A0|FA21|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA21|Cout~combout\ = (\A[21]~input_o\ & ((\slt_nums|sub|A0|FA20|Cout~combout\) # (!\B[21]~input_o\))) # (!\A[21]~input_o\ & (\slt_nums|sub|A0|FA20|Cout~combout\ & !\B[21]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000111010001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[21]~input_o\,
	datab => \slt_nums|sub|A0|FA20|Cout~combout\,
	datac => \B[21]~input_o\,
	combout => \slt_nums|sub|A0|FA21|Cout~combout\);

-- Location: IOIBUF_X52_Y11_N8
\A[22]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(22),
	o => \A[22]~input_o\);

-- Location: IOIBUF_X52_Y18_N1
\B[22]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(22),
	o => \B[22]~input_o\);

-- Location: LCCOMB_X51_Y15_N0
\slt_nums|sub|A0|FA22|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA22|Cout~combout\ = (\slt_nums|sub|A0|FA21|Cout~combout\ & ((\A[22]~input_o\) # (!\B[22]~input_o\))) # (!\slt_nums|sub|A0|FA21|Cout~combout\ & (\A[22]~input_o\ & !\B[22]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA21|Cout~combout\,
	datac => \A[22]~input_o\,
	datad => \B[22]~input_o\,
	combout => \slt_nums|sub|A0|FA22|Cout~combout\);

-- Location: IOIBUF_X52_Y11_N1
\A[23]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(23),
	o => \A[23]~input_o\);

-- Location: LCCOMB_X51_Y15_N26
\slt_nums|sub|A0|FA23|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA23|Cout~combout\ = (\B[23]~input_o\ & (\slt_nums|sub|A0|FA22|Cout~combout\ & \A[23]~input_o\)) # (!\B[23]~input_o\ & ((\slt_nums|sub|A0|FA22|Cout~combout\) # (\A[23]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101010011010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[23]~input_o\,
	datab => \slt_nums|sub|A0|FA22|Cout~combout\,
	datac => \A[23]~input_o\,
	combout => \slt_nums|sub|A0|FA23|Cout~combout\);

-- Location: LCCOMB_X50_Y23_N24
\slt_nums|sub|A0|FA24|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA24|Cout~combout\ = (\B[24]~input_o\ & (\A[24]~input_o\ & \slt_nums|sub|A0|FA23|Cout~combout\)) # (!\B[24]~input_o\ & ((\A[24]~input_o\) # (\slt_nums|sub|A0|FA23|Cout~combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010101010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[24]~input_o\,
	datac => \A[24]~input_o\,
	datad => \slt_nums|sub|A0|FA23|Cout~combout\,
	combout => \slt_nums|sub|A0|FA24|Cout~combout\);

-- Location: IOIBUF_X52_Y25_N1
\A[25]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(25),
	o => \A[25]~input_o\);

-- Location: LCCOMB_X49_Y23_N16
\slt_nums|sub|A0|FA25|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA25|Cout~combout\ = (\B[25]~input_o\ & (\slt_nums|sub|A0|FA24|Cout~combout\ & \A[25]~input_o\)) # (!\B[25]~input_o\ & ((\slt_nums|sub|A0|FA24|Cout~combout\) # (\A[25]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110101000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[25]~input_o\,
	datab => \slt_nums|sub|A0|FA24|Cout~combout\,
	datad => \A[25]~input_o\,
	combout => \slt_nums|sub|A0|FA25|Cout~combout\);

-- Location: IOIBUF_X52_Y27_N8
\B[26]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(26),
	o => \B[26]~input_o\);

-- Location: LCCOMB_X49_Y23_N2
\slt_nums|sub|A0|FA26|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA26|Cout~combout\ = (\A[26]~input_o\ & ((\slt_nums|sub|A0|FA25|Cout~combout\) # (!\B[26]~input_o\))) # (!\A[26]~input_o\ & (\slt_nums|sub|A0|FA25|Cout~combout\ & !\B[26]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000111010001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[26]~input_o\,
	datab => \slt_nums|sub|A0|FA25|Cout~combout\,
	datac => \B[26]~input_o\,
	combout => \slt_nums|sub|A0|FA26|Cout~combout\);

-- Location: LCCOMB_X42_Y23_N16
\slt_nums|sub|A0|FA27|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA27|Cout~combout\ = (\B[27]~input_o\ & (\A[27]~input_o\ & \slt_nums|sub|A0|FA26|Cout~combout\)) # (!\B[27]~input_o\ & ((\A[27]~input_o\) # (\slt_nums|sub|A0|FA26|Cout~combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110101000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[27]~input_o\,
	datab => \A[27]~input_o\,
	datad => \slt_nums|sub|A0|FA26|Cout~combout\,
	combout => \slt_nums|sub|A0|FA27|Cout~combout\);

-- Location: LCCOMB_X42_Y23_N18
\slt_nums|sub|A0|FA28|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA28|Cout~combout\ = (\B[28]~input_o\ & (\A[28]~input_o\ & \slt_nums|sub|A0|FA27|Cout~combout\)) # (!\B[28]~input_o\ & ((\A[28]~input_o\) # (\slt_nums|sub|A0|FA27|Cout~combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001100110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \B[28]~input_o\,
	datac => \A[28]~input_o\,
	datad => \slt_nums|sub|A0|FA27|Cout~combout\,
	combout => \slt_nums|sub|A0|FA28|Cout~combout\);

-- Location: IOIBUF_X46_Y41_N1
\B[29]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(29),
	o => \B[29]~input_o\);

-- Location: IOIBUF_X50_Y41_N8
\A[29]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(29),
	o => \A[29]~input_o\);

-- Location: LCCOMB_X46_Y34_N24
\slt_nums|sub|A0|FA29|Cout\ : cycloneiv_lcell_comb
-- Equation(s):
-- \slt_nums|sub|A0|FA29|Cout~combout\ = (\slt_nums|sub|A0|FA28|Cout~combout\ & ((\A[29]~input_o\) # (!\B[29]~input_o\))) # (!\slt_nums|sub|A0|FA28|Cout~combout\ & (!\B[29]~input_o\ & \A[29]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \slt_nums|sub|A0|FA28|Cout~combout\,
	datac => \B[29]~input_o\,
	datad => \A[29]~input_o\,
	combout => \slt_nums|sub|A0|FA29|Cout~combout\);

-- Location: IOIBUF_X46_Y41_N8
\B[30]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(30),
	o => \B[30]~input_o\);

-- Location: IOIBUF_X50_Y41_N1
\A[30]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(30),
	o => \A[30]~input_o\);

-- Location: LCCOMB_X46_Y34_N18
\M0|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M0|M6|O0~0_combout\ = (\slt_nums|sub|A0|FA29|Cout~combout\ & ((\A[30]~input_o\) # (!\B[30]~input_o\))) # (!\slt_nums|sub|A0|FA29|Cout~combout\ & (!\B[30]~input_o\ & \A[30]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \slt_nums|sub|A0|FA29|Cout~combout\,
	datac => \B[30]~input_o\,
	datad => \A[30]~input_o\,
	combout => \M0|M6|O0~0_combout\);

-- Location: IOIBUF_X52_Y21_N1
\B[31]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B(31),
	o => \B[31]~input_o\);

-- Location: IOIBUF_X52_Y21_N8
\A[31]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(31),
	o => \A[31]~input_o\);

-- Location: LCCOMB_X38_Y34_N10
\M0|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M0|M6|O0~1_combout\ = (\M0|M6|O0~0_combout\ & ((\B[31]~input_o\) # (!\A[31]~input_o\))) # (!\M0|M6|O0~0_combout\ & (\B[31]~input_o\ & !\A[31]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \M0|M6|O0~0_combout\,
	datac => \B[31]~input_o\,
	datad => \A[31]~input_o\,
	combout => \M0|M6|O0~1_combout\);

-- Location: IOIBUF_X41_Y41_N15
\ALUop[1]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_ALUop(1),
	o => \ALUop[1]~input_o\);

-- Location: IOIBUF_X38_Y41_N1
\ALUop[2]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_ALUop(2),
	o => \ALUop[2]~input_o\);

-- Location: IOIBUF_X52_Y32_N22
\ALUop[0]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_ALUop(0),
	o => \ALUop[0]~input_o\);

-- Location: LCCOMB_X38_Y34_N14
\M0|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M0|M6|O0~3_combout\ = (\ALUop[0]~input_o\ & (((\A[0]~input_o\ & \ALUop[2]~input_o\)))) # (!\ALUop[0]~input_o\ & ((\ALUop[1]~input_o\) # ((!\A[0]~input_o\ & \ALUop[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000010111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[1]~input_o\,
	datab => \A[0]~input_o\,
	datac => \ALUop[2]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M0|M6|O0~3_combout\);

-- Location: LCCOMB_X38_Y34_N24
\M0|M6|O0~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M0|M6|O0~4_combout\ = (\M0|M6|O0~3_combout\ & ((\ALUop[0]~input_o\))) # (!\M0|M6|O0~3_combout\ & (\B[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \B[0]~input_o\,
	datac => \M0|M6|O0~3_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M0|M6|O0~4_combout\);

-- Location: LCCOMB_X38_Y34_N20
\M0|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M0|M6|O0~2_combout\ = (\ALUop[2]~input_o\ & (\ALUop[1]~input_o\)) # (!\ALUop[2]~input_o\ & (\A[0]~input_o\ & ((\ALUop[0]~input_o\) # (!\ALUop[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110010100100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[1]~input_o\,
	datab => \A[0]~input_o\,
	datac => \ALUop[2]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M0|M6|O0~2_combout\);

-- Location: LCCOMB_X38_Y34_N2
\M0|M6|O0~5\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M0|M6|O0~5_combout\ = (\M0|M6|O0~4_combout\ & (((!\M0|M6|O0~2_combout\)))) # (!\M0|M6|O0~4_combout\ & (\M0|M6|O0~2_combout\ & ((!\M0|M6|O0~3_combout\) # (!\M0|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M0|M6|O0~1_combout\,
	datab => \M0|M6|O0~4_combout\,
	datac => \M0|M6|O0~3_combout\,
	datad => \M0|M6|O0~2_combout\,
	combout => \M0|M6|O0~5_combout\);

-- Location: LCCOMB_X38_Y34_N12
\M1|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~0_combout\ = (\ALUop[1]~input_o\ & (\ALUop[2]~input_o\ & (!\A[1]~input_o\ & \ALUop[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[1]~input_o\,
	datab => \ALUop[2]~input_o\,
	datac => \A[1]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M1|M6|O0~0_combout\);

-- Location: LCCOMB_X38_Y34_N6
\M1|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~2_combout\ = (\ALUop[2]~input_o\) # ((!\ALUop[1]~input_o\ & \ALUop[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[1]~input_o\,
	datab => \ALUop[2]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M1|M6|O0~2_combout\);

-- Location: LCCOMB_X39_Y34_N16
\M1|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~1_combout\ = (\ALUop[2]~input_o\) # (\ALUop[1]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[2]~input_o\,
	datad => \ALUop[1]~input_o\,
	combout => \M1|M6|O0~1_combout\);

-- Location: LCCOMB_X38_Y34_N28
\M1|M6|O0~7\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~7_combout\ = \B[1]~input_o\ $ (\A[1]~input_o\ $ (((\B[0]~input_o\ & \A[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001010101101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[1]~input_o\,
	datab => \B[0]~input_o\,
	datac => \A[0]~input_o\,
	datad => \A[1]~input_o\,
	combout => \M1|M6|O0~7_combout\);

-- Location: LCCOMB_X38_Y34_N30
\M1|M6|O0~8\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~8_combout\ = (\M1|M6|O0~1_combout\ & (\M1|M6|O0~2_combout\)) # (!\M1|M6|O0~1_combout\ & (\M1|M6|O0~7_combout\ $ (((\M1|M6|O0~2_combout\ & \B[0]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001101010111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \M1|M6|O0~7_combout\,
	datad => \B[0]~input_o\,
	combout => \M1|M6|O0~8_combout\);

-- Location: LCCOMB_X38_Y34_N16
\M1|M6|O0~5\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~5_combout\ = (\A[1]~input_o\ & ((\B[1]~input_o\ & (\M1|M6|O0~8_combout\)) # (!\B[1]~input_o\ & ((\ALUop[0]~input_o\))))) # (!\A[1]~input_o\ & (((\B[1]~input_o\ & \ALUop[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011110010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~8_combout\,
	datab => \A[1]~input_o\,
	datac => \B[1]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M1|M6|O0~5_combout\);

-- Location: LCCOMB_X38_Y34_N18
\M1|M6|O0~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~6_combout\ = (\M1|M6|O0~1_combout\ & (\M1|M6|O0~5_combout\)) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~8_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \M1|M6|O0~5_combout\,
	datac => \M1|M6|O0~8_combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M1|M6|O0~6_combout\);

-- Location: LCCOMB_X39_Y34_N18
\M1|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~3_combout\ = (\ALUop[2]~input_o\ & \ALUop[1]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[2]~input_o\,
	datad => \ALUop[1]~input_o\,
	combout => \M1|M6|O0~3_combout\);

-- Location: LCCOMB_X38_Y34_N0
\M1|M6|O0~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M1|M6|O0~4_combout\ = (\M1|M6|O0~0_combout\ & (((\M1|M6|O0~6_combout\ & !\M1|M6|O0~3_combout\)) # (!\B[1]~input_o\))) # (!\M1|M6|O0~0_combout\ & (\M1|M6|O0~6_combout\ & ((!\M1|M6|O0~3_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101011001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~0_combout\,
	datab => \M1|M6|O0~6_combout\,
	datac => \B[1]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M1|M6|O0~4_combout\);

-- Location: LCCOMB_X38_Y34_N26
\add_nums|FA1|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA1|Cout~0_combout\ = (\B[1]~input_o\ & ((\A[1]~input_o\) # ((\B[0]~input_o\ & \A[0]~input_o\)))) # (!\B[1]~input_o\ & (\B[0]~input_o\ & (\A[0]~input_o\ & \A[1]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110101010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[1]~input_o\,
	datab => \B[0]~input_o\,
	datac => \A[0]~input_o\,
	datad => \A[1]~input_o\,
	combout => \add_nums|FA1|Cout~0_combout\);

-- Location: LCCOMB_X35_Y30_N12
\M2|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M2|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & ((!\slt_nums|sub|A0|FA1|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA1|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA1|Cout~0_combout\,
	datab => \slt_nums|sub|A0|FA1|Cout~combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \M1|M6|O0~2_combout\,
	combout => \M2|M6|O0~0_combout\);

-- Location: LCCOMB_X35_Y30_N14
\M2|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M2|M6|O0~1_combout\ = (\B[2]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[2]~input_o\)))) # (!\B[2]~input_o\ & (\A[2]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110110011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[2]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[2]~input_o\,
	combout => \M2|M6|O0~1_combout\);

-- Location: LCCOMB_X35_Y30_N0
\M2|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M2|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[2]~input_o\) # (!\B[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[2]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[2]~input_o\,
	combout => \M2|M6|O0~2_combout\);

-- Location: LCCOMB_X35_Y30_N2
\M2|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M2|M6|O0~3_combout\ = (\M2|M6|O0~2_combout\ & (((!\M2|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M2|M6|O0~2_combout\ & (\M2|M6|O0~0_combout\ $ ((\M2|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000001100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M2|M6|O0~0_combout\,
	datab => \M2|M6|O0~1_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M2|M6|O0~2_combout\,
	combout => \M2|M6|O0~3_combout\);

-- Location: LCCOMB_X32_Y30_N18
\M3|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M3|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[3]~input_o\) # (!\A[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101111111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[3]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[3]~input_o\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M3|M6|O0~2_combout\);

-- Location: LCCOMB_X32_Y30_N0
\M3|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M3|M6|O0~1_combout\ = (\A[3]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\B[3]~input_o\ & !\M1|M6|O0~1_combout\)))) # (!\A[3]~input_o\ & (\B[3]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100100111011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[3]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[3]~input_o\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M3|M6|O0~1_combout\);

-- Location: LCCOMB_X35_Y30_N4
\add_nums|FA2|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA2|Cout~0_combout\ = (\A[2]~input_o\ & ((\add_nums|FA1|Cout~0_combout\) # (\B[2]~input_o\))) # (!\A[2]~input_o\ & (\add_nums|FA1|Cout~0_combout\ & \B[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[2]~input_o\,
	datac => \add_nums|FA1|Cout~0_combout\,
	datad => \B[2]~input_o\,
	combout => \add_nums|FA2|Cout~0_combout\);

-- Location: LCCOMB_X32_Y30_N14
\M3|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M3|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA2|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA2|Cout~0_combout\ & ((!\M1|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101001001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA2|Cout~0_combout\,
	datac => \slt_nums|sub|A0|FA2|Cout~combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M3|M6|O0~0_combout\);

-- Location: LCCOMB_X32_Y30_N4
\M3|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M3|M6|O0~3_combout\ = (\M3|M6|O0~2_combout\ & (!\M3|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M3|M6|O0~2_combout\ & (\M3|M6|O0~1_combout\ $ ((\M3|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011011000010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M3|M6|O0~2_combout\,
	datab => \M3|M6|O0~1_combout\,
	datac => \M3|M6|O0~0_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M3|M6|O0~3_combout\);

-- Location: LCCOMB_X32_Y30_N6
\M4|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M4|M6|O0~0_combout\ = (!\A[4]~input_o\ & !\B[4]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \A[4]~input_o\,
	datad => \B[4]~input_o\,
	combout => \M4|M6|O0~0_combout\);

-- Location: LCCOMB_X32_Y30_N24
\M4|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M4|M6|O0~1_combout\ = (\B[4]~input_o\ & ((\A[4]~input_o\ & (\M1|M6|O0~2_combout\)) # (!\A[4]~input_o\ & ((\ALUop[0]~input_o\))))) # (!\B[4]~input_o\ & (((\A[4]~input_o\ & \ALUop[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011110010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \B[4]~input_o\,
	datac => \A[4]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M4|M6|O0~1_combout\);

-- Location: LCCOMB_X32_Y30_N2
\M4|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M4|M6|O0~2_combout\ = (\M1|M6|O0~2_combout\ & ((\slt_nums|sub|A0|FA2|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA2|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111001000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA2|Cout~0_combout\,
	datad => \slt_nums|sub|A0|FA2|Cout~combout\,
	combout => \M4|M6|O0~2_combout\);

-- Location: LCCOMB_X32_Y30_N28
\M4|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M4|M6|O0~3_combout\ = (\A[3]~input_o\ & ((\M4|M6|O0~2_combout\ & ((!\M1|M6|O0~2_combout\))) # (!\M4|M6|O0~2_combout\ & (\B[3]~input_o\)))) # (!\A[3]~input_o\ & ((\M4|M6|O0~2_combout\ & (\B[3]~input_o\)) # (!\M4|M6|O0~2_combout\ & 
-- ((\M1|M6|O0~2_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100111011011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[3]~input_o\,
	datab => \B[3]~input_o\,
	datac => \M1|M6|O0~2_combout\,
	datad => \M4|M6|O0~2_combout\,
	combout => \M4|M6|O0~3_combout\);

-- Location: LCCOMB_X32_Y30_N22
\M4|M6|O0~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M4|M6|O0~4_combout\ = (\M1|M6|O0~1_combout\ & (\M4|M6|O0~1_combout\)) # (!\M1|M6|O0~1_combout\ & ((\slt_nums|sub|A0|FA4|HA1|G1~0_combout\ $ (\M4|M6|O0~3_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000110111011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M4|M6|O0~1_combout\,
	datac => \slt_nums|sub|A0|FA4|HA1|G1~0_combout\,
	datad => \M4|M6|O0~3_combout\,
	combout => \M4|M6|O0~4_combout\);

-- Location: LCCOMB_X32_Y30_N8
\M4|M6|O0~5\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M4|M6|O0~5_combout\ = (\M1|M6|O0~3_combout\ & (\M4|M6|O0~0_combout\ & ((\ALUop[0]~input_o\)))) # (!\M1|M6|O0~3_combout\ & (((\M4|M6|O0~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011100000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M4|M6|O0~0_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M4|M6|O0~4_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M4|M6|O0~5_combout\);

-- Location: LCCOMB_X32_Y30_N12
\add_nums|FA4|Cout~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA4|Cout~1_combout\ = (!\M4|M6|O0~0_combout\ & ((\A[3]~input_o\ & ((\add_nums|FA2|Cout~0_combout\) # (\B[3]~input_o\))) # (!\A[3]~input_o\ & (\add_nums|FA2|Cout~0_combout\ & \B[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[3]~input_o\,
	datab => \add_nums|FA2|Cout~0_combout\,
	datac => \B[3]~input_o\,
	datad => \M4|M6|O0~0_combout\,
	combout => \add_nums|FA4|Cout~1_combout\);

-- Location: LCCOMB_X32_Y30_N10
\add_nums|FA4|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA4|Cout~0_combout\ = (\A[4]~input_o\ & \B[4]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \A[4]~input_o\,
	datad => \B[4]~input_o\,
	combout => \add_nums|FA4|Cout~0_combout\);

-- Location: LCCOMB_X34_Y30_N2
\M5|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M5|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\slt_nums|sub|A0|FA4|HA2|G2~combout\)))) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA4|Cout~1_combout\) # ((\add_nums|FA4|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA4|Cout~1_combout\,
	datab => \slt_nums|sub|A0|FA4|HA2|G2~combout\,
	datac => \add_nums|FA4|Cout~0_combout\,
	datad => \M1|M6|O0~2_combout\,
	combout => \M5|M6|O0~0_combout\);

-- Location: LCCOMB_X34_Y30_N12
\M5|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M5|M6|O0~1_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M5|M6|O0~0_combout\ & ((!\M1|M6|O0~2_combout\))) # (!\M5|M6|O0~0_combout\ & (!\slt_nums|sub|A0|FA4|HA1|G2~combout\ & \M1|M6|O0~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101101000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M5|M6|O0~0_combout\,
	datac => \slt_nums|sub|A0|FA4|HA1|G2~combout\,
	datad => \M1|M6|O0~2_combout\,
	combout => \M5|M6|O0~1_combout\);

-- Location: LCCOMB_X34_Y30_N0
\M5|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M5|M6|O0~3_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[5]~input_o\) # (!\A[5]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111011111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[5]~input_o\,
	datab => \B[5]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M5|M6|O0~3_combout\);

-- Location: LCCOMB_X34_Y30_N6
\M5|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M5|M6|O0~2_combout\ = (\A[5]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\B[5]~input_o\ & !\M1|M6|O0~1_combout\)))) # (!\A[5]~input_o\ & (\B[5]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000111100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[5]~input_o\,
	datab => \B[5]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M5|M6|O0~2_combout\);

-- Location: LCCOMB_X34_Y30_N18
\M5|M6|O0~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M5|M6|O0~4_combout\ = (\M5|M6|O0~3_combout\ & (((\ALUop[0]~input_o\ & !\M5|M6|O0~2_combout\)))) # (!\M5|M6|O0~3_combout\ & (\M5|M6|O0~1_combout\ $ (((\M5|M6|O0~2_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M5|M6|O0~1_combout\,
	datab => \M5|M6|O0~3_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M5|M6|O0~2_combout\,
	combout => \M5|M6|O0~4_combout\);

-- Location: LCCOMB_X34_Y30_N20
\add_nums|FA5|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA5|Cout~0_combout\ = (\A[5]~input_o\ & ((\B[5]~input_o\) # ((\add_nums|FA4|Cout~0_combout\) # (\add_nums|FA4|Cout~1_combout\)))) # (!\A[5]~input_o\ & (\B[5]~input_o\ & ((\add_nums|FA4|Cout~0_combout\) # (\add_nums|FA4|Cout~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[5]~input_o\,
	datab => \B[5]~input_o\,
	datac => \add_nums|FA4|Cout~0_combout\,
	datad => \add_nums|FA4|Cout~1_combout\,
	combout => \add_nums|FA5|Cout~0_combout\);

-- Location: LCCOMB_X35_Y30_N30
\M6|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M6|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA5|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA5|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010100001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA5|Cout~combout\,
	datab => \add_nums|FA5|Cout~0_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \M1|M6|O0~2_combout\,
	combout => \M6|M6|O0~0_combout\);

-- Location: LCCOMB_X35_Y30_N24
\M6|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M6|M6|O0~1_combout\ = (\B[6]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[6]~input_o\)))) # (!\B[6]~input_o\ & (\A[6]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101000010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[6]~input_o\,
	datab => \M1|M6|O0~1_combout\,
	datac => \A[6]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M6|M6|O0~1_combout\);

-- Location: LCCOMB_X35_Y30_N10
\M6|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M6|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[6]~input_o\) # (!\B[6]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[6]~input_o\,
	datab => \M1|M6|O0~1_combout\,
	datac => \A[6]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M6|M6|O0~2_combout\);

-- Location: LCCOMB_X35_Y30_N28
\M6|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M6|M6|O0~3_combout\ = (\M6|M6|O0~2_combout\ & (((!\M6|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M6|M6|O0~2_combout\ & (\M6|M6|O0~0_combout\ $ ((\M6|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000001100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M6|M6|O0~0_combout\,
	datab => \M6|M6|O0~1_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M6|M6|O0~2_combout\,
	combout => \M6|M6|O0~3_combout\);

-- Location: LCCOMB_X35_Y33_N6
\M7|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M7|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[7]~input_o\) # (!\A[7]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101111111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[7]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[7]~input_o\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M7|M6|O0~2_combout\);

-- Location: LCCOMB_X35_Y33_N20
\M7|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M7|M6|O0~1_combout\ = (\A[7]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\B[7]~input_o\ & !\M1|M6|O0~1_combout\)))) # (!\A[7]~input_o\ & (\B[7]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100100111011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[7]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[7]~input_o\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M7|M6|O0~1_combout\);

-- Location: LCCOMB_X35_Y30_N6
\add_nums|FA6|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA6|Cout~0_combout\ = (\B[6]~input_o\ & ((\add_nums|FA5|Cout~0_combout\) # (\A[6]~input_o\))) # (!\B[6]~input_o\ & (\add_nums|FA5|Cout~0_combout\ & \A[6]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[6]~input_o\,
	datab => \add_nums|FA5|Cout~0_combout\,
	datac => \A[6]~input_o\,
	combout => \add_nums|FA6|Cout~0_combout\);

-- Location: LCCOMB_X35_Y33_N26
\M7|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M7|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\)) # (!\slt_nums|sub|A0|FA6|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (((!\M1|M6|O0~1_combout\ & \add_nums|FA6|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010011110100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \slt_nums|sub|A0|FA6|Cout~combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \add_nums|FA6|Cout~0_combout\,
	combout => \M7|M6|O0~0_combout\);

-- Location: LCCOMB_X35_Y33_N0
\M7|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M7|M6|O0~3_combout\ = (\M7|M6|O0~2_combout\ & (!\M7|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M7|M6|O0~2_combout\ & (\M7|M6|O0~1_combout\ $ ((\M7|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011011000010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M7|M6|O0~2_combout\,
	datab => \M7|M6|O0~1_combout\,
	datac => \M7|M6|O0~0_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M7|M6|O0~3_combout\);

-- Location: LCCOMB_X36_Y33_N30
\M8|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M8|M6|O0~1_combout\ = (\B[8]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\A[8]~input_o\ & !\M1|M6|O0~1_combout\)))) # (!\B[8]~input_o\ & (\A[8]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000111100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[8]~input_o\,
	datab => \A[8]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M8|M6|O0~1_combout\);

-- Location: LCCOMB_X35_Y33_N2
\add_nums|FA7|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA7|Cout~0_combout\ = (\A[7]~input_o\ & ((\B[7]~input_o\) # (\add_nums|FA6|Cout~0_combout\))) # (!\A[7]~input_o\ & (\B[7]~input_o\ & \add_nums|FA6|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[7]~input_o\,
	datac => \B[7]~input_o\,
	datad => \add_nums|FA6|Cout~0_combout\,
	combout => \add_nums|FA7|Cout~0_combout\);

-- Location: LCCOMB_X36_Y33_N28
\M8|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M8|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA7|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA7|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001011001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA7|Cout~0_combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA7|Cout~combout\,
	combout => \M8|M6|O0~0_combout\);

-- Location: LCCOMB_X36_Y33_N0
\M8|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M8|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[8]~input_o\) # (!\B[8]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111011111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[8]~input_o\,
	datab => \A[8]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M8|M6|O0~2_combout\);

-- Location: LCCOMB_X36_Y33_N2
\M8|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M8|M6|O0~3_combout\ = (\M8|M6|O0~2_combout\ & (!\M8|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M8|M6|O0~2_combout\ & (\M8|M6|O0~1_combout\ $ ((\M8|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000001100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M8|M6|O0~1_combout\,
	datab => \M8|M6|O0~0_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M8|M6|O0~2_combout\,
	combout => \M8|M6|O0~3_combout\);

-- Location: LCCOMB_X36_Y33_N20
\add_nums|FA8|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA8|Cout~0_combout\ = (\A[8]~input_o\ & ((\B[8]~input_o\) # (\add_nums|FA7|Cout~0_combout\))) # (!\A[8]~input_o\ & (\B[8]~input_o\ & \add_nums|FA7|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \A[8]~input_o\,
	datac => \B[8]~input_o\,
	datad => \add_nums|FA7|Cout~0_combout\,
	combout => \add_nums|FA8|Cout~0_combout\);

-- Location: LCCOMB_X36_Y33_N22
\M9|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M9|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA8|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA8|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101101010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \slt_nums|sub|A0|FA8|Cout~combout\,
	datac => \add_nums|FA8|Cout~0_combout\,
	datad => \M1|M6|O0~2_combout\,
	combout => \M9|M6|O0~0_combout\);

-- Location: LCCOMB_X36_Y33_N24
\M9|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M9|M6|O0~1_combout\ = (\A[9]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[9]~input_o\)))) # (!\A[9]~input_o\ & (\B[9]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[9]~input_o\,
	datac => \B[9]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M9|M6|O0~1_combout\);

-- Location: LCCOMB_X36_Y33_N18
\M9|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M9|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[9]~input_o\) # (!\A[9]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[9]~input_o\,
	datac => \B[9]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M9|M6|O0~2_combout\);

-- Location: LCCOMB_X36_Y33_N12
\M9|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M9|M6|O0~3_combout\ = (\M9|M6|O0~2_combout\ & (((!\M9|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M9|M6|O0~2_combout\ & (\M9|M6|O0~0_combout\ $ ((\M9|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000001100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M9|M6|O0~0_combout\,
	datab => \M9|M6|O0~1_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M9|M6|O0~2_combout\,
	combout => \M9|M6|O0~3_combout\);

-- Location: LCCOMB_X35_Y30_N20
\M10|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M10|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[10]~input_o\) # (!\B[10]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[10]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[10]~input_o\,
	combout => \M10|M6|O0~2_combout\);

-- Location: LCCOMB_X35_Y30_N26
\M10|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M10|M6|O0~1_combout\ = (\B[10]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[10]~input_o\)))) # (!\B[10]~input_o\ & (\A[10]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110110011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[10]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[10]~input_o\,
	combout => \M10|M6|O0~1_combout\);

-- Location: LCCOMB_X36_Y33_N6
\add_nums|FA9|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA9|Cout~0_combout\ = (\A[9]~input_o\ & ((\B[9]~input_o\) # (\add_nums|FA8|Cout~0_combout\))) # (!\A[9]~input_o\ & (\B[9]~input_o\ & \add_nums|FA8|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \A[9]~input_o\,
	datac => \B[9]~input_o\,
	datad => \add_nums|FA8|Cout~0_combout\,
	combout => \add_nums|FA9|Cout~0_combout\);

-- Location: LCCOMB_X35_Y30_N16
\M10|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M10|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA9|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA9|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001011001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA9|Cout~0_combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA9|Cout~combout\,
	combout => \M10|M6|O0~0_combout\);

-- Location: LCCOMB_X35_Y30_N22
\M10|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M10|M6|O0~3_combout\ = (\M10|M6|O0~2_combout\ & (\ALUop[0]~input_o\ & (!\M10|M6|O0~1_combout\))) # (!\M10|M6|O0~2_combout\ & ((\M10|M6|O0~1_combout\ $ (\M10|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101100111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[0]~input_o\,
	datab => \M10|M6|O0~2_combout\,
	datac => \M10|M6|O0~1_combout\,
	datad => \M10|M6|O0~0_combout\,
	combout => \M10|M6|O0~3_combout\);

-- Location: LCCOMB_X42_Y30_N0
\add_nums|FA10|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA10|Cout~0_combout\ = (\add_nums|FA9|Cout~0_combout\ & ((\B[10]~input_o\) # (\A[10]~input_o\))) # (!\add_nums|FA9|Cout~0_combout\ & (\B[10]~input_o\ & \A[10]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA9|Cout~0_combout\,
	datab => \B[10]~input_o\,
	datad => \A[10]~input_o\,
	combout => \add_nums|FA10|Cout~0_combout\);

-- Location: LCCOMB_X42_Y23_N12
\M11|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M11|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA10|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA10|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA10|Cout~0_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA10|Cout~combout\,
	combout => \M11|M6|O0~0_combout\);

-- Location: LCCOMB_X42_Y23_N24
\M11|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M11|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[11]~input_o\) # (!\B[11]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \B[11]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[11]~input_o\,
	combout => \M11|M6|O0~2_combout\);

-- Location: LCCOMB_X42_Y23_N22
\M11|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M11|M6|O0~1_combout\ = (\B[11]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[11]~input_o\)))) # (!\B[11]~input_o\ & (\A[11]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \B[11]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[11]~input_o\,
	combout => \M11|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y23_N26
\M11|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M11|M6|O0~3_combout\ = (\M11|M6|O0~2_combout\ & (((!\M11|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M11|M6|O0~2_combout\ & (\M11|M6|O0~0_combout\ $ ((\M11|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111000010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M11|M6|O0~0_combout\,
	datab => \M11|M6|O0~2_combout\,
	datac => \M11|M6|O0~1_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M11|M6|O0~3_combout\);

-- Location: LCCOMB_X42_Y30_N24
\M12|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M12|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[12]~input_o\) # (!\A[12]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \A[12]~input_o\,
	datad => \B[12]~input_o\,
	combout => \M12|M6|O0~2_combout\);

-- Location: LCCOMB_X42_Y30_N2
\add_nums|FA11|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA11|Cout~0_combout\ = (\add_nums|FA10|Cout~0_combout\ & ((\B[11]~input_o\) # (\A[11]~input_o\))) # (!\add_nums|FA10|Cout~0_combout\ & (\B[11]~input_o\ & \A[11]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \add_nums|FA10|Cout~0_combout\,
	datac => \B[11]~input_o\,
	datad => \A[11]~input_o\,
	combout => \add_nums|FA11|Cout~0_combout\);

-- Location: LCCOMB_X42_Y30_N28
\M12|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M12|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (\M1|M6|O0~2_combout\)) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA11|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA11|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001110110001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \slt_nums|sub|A0|FA11|Cout~combout\,
	datad => \add_nums|FA11|Cout~0_combout\,
	combout => \M12|M6|O0~0_combout\);

-- Location: LCCOMB_X42_Y30_N30
\M12|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M12|M6|O0~1_combout\ = (\A[12]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[12]~input_o\)))) # (!\A[12]~input_o\ & (\B[12]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110111010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \A[12]~input_o\,
	datad => \B[12]~input_o\,
	combout => \M12|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y30_N10
\M12|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M12|M6|O0~3_combout\ = (\M12|M6|O0~2_combout\ & (((!\M12|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M12|M6|O0~2_combout\ & (\M12|M6|O0~0_combout\ $ ((\M12|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111000010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M12|M6|O0~2_combout\,
	datab => \M12|M6|O0~0_combout\,
	datac => \M12|M6|O0~1_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M12|M6|O0~3_combout\);

-- Location: LCCOMB_X42_Y30_N12
\add_nums|FA12|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA12|Cout~0_combout\ = (\B[12]~input_o\ & ((\A[12]~input_o\) # (\add_nums|FA11|Cout~0_combout\))) # (!\B[12]~input_o\ & (\A[12]~input_o\ & \add_nums|FA11|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \B[12]~input_o\,
	datac => \A[12]~input_o\,
	datad => \add_nums|FA11|Cout~0_combout\,
	combout => \add_nums|FA12|Cout~0_combout\);

-- Location: LCCOMB_X42_Y30_N22
\M13|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M13|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (\M1|M6|O0~2_combout\)) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA12|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA12|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001110110001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \slt_nums|sub|A0|FA12|Cout~combout\,
	datad => \add_nums|FA12|Cout~0_combout\,
	combout => \M13|M6|O0~0_combout\);

-- Location: LCCOMB_X42_Y30_N18
\M13|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M13|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[13]~input_o\) # (!\A[13]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \A[13]~input_o\,
	datad => \B[13]~input_o\,
	combout => \M13|M6|O0~2_combout\);

-- Location: LCCOMB_X42_Y30_N8
\M13|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M13|M6|O0~1_combout\ = (\A[13]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[13]~input_o\)))) # (!\A[13]~input_o\ & (\B[13]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110111010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \A[13]~input_o\,
	datad => \B[13]~input_o\,
	combout => \M13|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y30_N20
\M13|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M13|M6|O0~3_combout\ = (\M13|M6|O0~2_combout\ & (((!\M13|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M13|M6|O0~2_combout\ & (\M13|M6|O0~0_combout\ $ ((\M13|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111000010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M13|M6|O0~0_combout\,
	datab => \M13|M6|O0~2_combout\,
	datac => \M13|M6|O0~1_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M13|M6|O0~3_combout\);

-- Location: LCCOMB_X41_Y28_N12
\M14|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M14|M6|O0~1_combout\ = (\A[14]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[14]~input_o\)))) # (!\A[14]~input_o\ & (\B[14]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[14]~input_o\,
	datac => \B[14]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M14|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y30_N6
\add_nums|FA13|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA13|Cout~0_combout\ = (\add_nums|FA12|Cout~0_combout\ & ((\A[13]~input_o\) # (\B[13]~input_o\))) # (!\add_nums|FA12|Cout~0_combout\ & (\A[13]~input_o\ & \B[13]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA12|Cout~0_combout\,
	datac => \A[13]~input_o\,
	datad => \B[13]~input_o\,
	combout => \add_nums|FA13|Cout~0_combout\);

-- Location: LCCOMB_X41_Y28_N2
\M14|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M14|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA13|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA13|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011010110110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \slt_nums|sub|A0|FA13|Cout~combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \add_nums|FA13|Cout~0_combout\,
	combout => \M14|M6|O0~0_combout\);

-- Location: LCCOMB_X41_Y28_N6
\M14|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M14|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[14]~input_o\) # (!\A[14]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[14]~input_o\,
	datac => \B[14]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M14|M6|O0~2_combout\);

-- Location: LCCOMB_X41_Y28_N24
\M14|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M14|M6|O0~3_combout\ = (\M14|M6|O0~2_combout\ & (!\M14|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M14|M6|O0~2_combout\ & (\M14|M6|O0~1_combout\ $ ((\M14|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101011000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M14|M6|O0~1_combout\,
	datab => \M14|M6|O0~0_combout\,
	datac => \M14|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M14|M6|O0~3_combout\);

-- Location: LCCOMB_X41_Y16_N12
\M15|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M15|M6|O0~1_combout\ = (\B[15]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[15]~input_o\)))) # (!\B[15]~input_o\ & (\A[15]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110111010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[15]~input_o\,
	datad => \A[15]~input_o\,
	combout => \M15|M6|O0~1_combout\);

-- Location: LCCOMB_X41_Y28_N18
\add_nums|FA14|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA14|Cout~0_combout\ = (\A[14]~input_o\ & ((\B[14]~input_o\) # (\add_nums|FA13|Cout~0_combout\))) # (!\A[14]~input_o\ & (\B[14]~input_o\ & \add_nums|FA13|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \A[14]~input_o\,
	datac => \B[14]~input_o\,
	datad => \add_nums|FA13|Cout~0_combout\,
	combout => \add_nums|FA14|Cout~0_combout\);

-- Location: LCCOMB_X41_Y16_N2
\M15|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M15|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA14|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA14|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110100110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA14|Cout~combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \add_nums|FA14|Cout~0_combout\,
	datad => \M1|M6|O0~2_combout\,
	combout => \M15|M6|O0~0_combout\);

-- Location: LCCOMB_X41_Y16_N6
\M15|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M15|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[15]~input_o\) # (!\B[15]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[15]~input_o\,
	datad => \A[15]~input_o\,
	combout => \M15|M6|O0~2_combout\);

-- Location: LCCOMB_X41_Y16_N24
\M15|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M15|M6|O0~3_combout\ = (\M15|M6|O0~2_combout\ & (!\M15|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M15|M6|O0~2_combout\ & (\M15|M6|O0~1_combout\ $ ((\M15|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101011000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M15|M6|O0~1_combout\,
	datab => \M15|M6|O0~0_combout\,
	datac => \M15|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M15|M6|O0~3_combout\);

-- Location: LCCOMB_X46_Y13_N22
\M16|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M16|M6|O0~1_combout\ = (\B[16]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[16]~input_o\)))) # (!\B[16]~input_o\ & (\A[16]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000111000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \B[16]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \A[16]~input_o\,
	combout => \M16|M6|O0~1_combout\);

-- Location: LCCOMB_X46_Y13_N24
\M16|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M16|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[16]~input_o\) # (!\B[16]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \B[16]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \A[16]~input_o\,
	combout => \M16|M6|O0~2_combout\);

-- Location: LCCOMB_X41_Y16_N10
\add_nums|FA15|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA15|Cout~0_combout\ = (\add_nums|FA14|Cout~0_combout\ & ((\B[15]~input_o\) # (\A[15]~input_o\))) # (!\add_nums|FA14|Cout~0_combout\ & (\B[15]~input_o\ & \A[15]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA14|Cout~0_combout\,
	datab => \B[15]~input_o\,
	datad => \A[15]~input_o\,
	combout => \add_nums|FA15|Cout~0_combout\);

-- Location: LCCOMB_X46_Y13_N12
\M16|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M16|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\)) # (!\slt_nums|sub|A0|FA15|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (((!\M1|M6|O0~1_combout\ & \add_nums|FA15|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100011111000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA15|Cout~combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \add_nums|FA15|Cout~0_combout\,
	combout => \M16|M6|O0~0_combout\);

-- Location: LCCOMB_X46_Y13_N18
\M16|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M16|M6|O0~3_combout\ = (\M16|M6|O0~2_combout\ & (!\M16|M6|O0~1_combout\ & (\ALUop[0]~input_o\))) # (!\M16|M6|O0~2_combout\ & (\M16|M6|O0~1_combout\ $ (((\M16|M6|O0~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000101100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M16|M6|O0~1_combout\,
	datab => \M16|M6|O0~2_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M16|M6|O0~0_combout\,
	combout => \M16|M6|O0~3_combout\);

-- Location: LCCOMB_X46_Y13_N10
\M17|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M17|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[17]~input_o\) # (!\A[17]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[17]~input_o\,
	datac => \B[17]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M17|M6|O0~2_combout\);

-- Location: LCCOMB_X46_Y13_N16
\M17|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M17|M6|O0~1_combout\ = (\A[17]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[17]~input_o\)))) # (!\A[17]~input_o\ & (\B[17]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[17]~input_o\,
	datac => \B[17]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M17|M6|O0~1_combout\);

-- Location: LCCOMB_X46_Y13_N20
\add_nums|FA16|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA16|Cout~0_combout\ = (\add_nums|FA15|Cout~0_combout\ & ((\B[16]~input_o\) # (\A[16]~input_o\))) # (!\add_nums|FA15|Cout~0_combout\ & (\B[16]~input_o\ & \A[16]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA15|Cout~0_combout\,
	datab => \B[16]~input_o\,
	datad => \A[16]~input_o\,
	combout => \add_nums|FA16|Cout~0_combout\);

-- Location: LCCOMB_X46_Y13_N30
\M17|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M17|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & ((!\slt_nums|sub|A0|FA16|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA16|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010011110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \add_nums|FA16|Cout~0_combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \slt_nums|sub|A0|FA16|Cout~combout\,
	combout => \M17|M6|O0~0_combout\);

-- Location: LCCOMB_X46_Y13_N4
\M17|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M17|M6|O0~3_combout\ = (\M17|M6|O0~2_combout\ & (!\M17|M6|O0~1_combout\ & (\ALUop[0]~input_o\))) # (!\M17|M6|O0~2_combout\ & (\M17|M6|O0~1_combout\ $ (((\M17|M6|O0~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000101100100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M17|M6|O0~2_combout\,
	datab => \M17|M6|O0~1_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M17|M6|O0~0_combout\,
	combout => \M17|M6|O0~3_combout\);

-- Location: LCCOMB_X46_Y13_N6
\add_nums|FA17|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA17|Cout~0_combout\ = (\B[17]~input_o\ & ((\A[17]~input_o\) # (\add_nums|FA16|Cout~0_combout\))) # (!\B[17]~input_o\ & (\A[17]~input_o\ & \add_nums|FA16|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[17]~input_o\,
	datac => \A[17]~input_o\,
	datad => \add_nums|FA16|Cout~0_combout\,
	combout => \add_nums|FA17|Cout~0_combout\);

-- Location: LCCOMB_X51_Y13_N12
\M18|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M18|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & ((\M1|M6|O0~1_combout\) # ((!\slt_nums|sub|A0|FA17|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (!\M1|M6|O0~1_combout\ & ((\add_nums|FA17|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001101110001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \slt_nums|sub|A0|FA17|Cout~combout\,
	datad => \add_nums|FA17|Cout~0_combout\,
	combout => \M18|M6|O0~0_combout\);

-- Location: LCCOMB_X51_Y13_N24
\M18|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M18|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[18]~input_o\) # (!\B[18]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \B[18]~input_o\,
	datad => \A[18]~input_o\,
	combout => \M18|M6|O0~2_combout\);

-- Location: LCCOMB_X51_Y13_N14
\M18|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M18|M6|O0~1_combout\ = (\B[18]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[18]~input_o\)))) # (!\B[18]~input_o\ & (\A[18]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \B[18]~input_o\,
	datad => \A[18]~input_o\,
	combout => \M18|M6|O0~1_combout\);

-- Location: LCCOMB_X51_Y13_N18
\M18|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M18|M6|O0~3_combout\ = (\M18|M6|O0~2_combout\ & (((!\M18|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M18|M6|O0~2_combout\ & (\M18|M6|O0~0_combout\ $ ((\M18|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111000010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M18|M6|O0~0_combout\,
	datab => \M18|M6|O0~2_combout\,
	datac => \M18|M6|O0~1_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M18|M6|O0~3_combout\);

-- Location: LCCOMB_X51_Y13_N10
\M19|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M19|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[19]~input_o\) # (!\B[19]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[19]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[19]~input_o\,
	combout => \M19|M6|O0~2_combout\);

-- Location: LCCOMB_X51_Y13_N16
\M19|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M19|M6|O0~1_combout\ = (\B[19]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[19]~input_o\)))) # (!\B[19]~input_o\ & (\A[19]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110110011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[19]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \A[19]~input_o\,
	combout => \M19|M6|O0~1_combout\);

-- Location: LCCOMB_X51_Y13_N4
\add_nums|FA18|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA18|Cout~0_combout\ = (\add_nums|FA17|Cout~0_combout\ & ((\B[18]~input_o\) # (\A[18]~input_o\))) # (!\add_nums|FA17|Cout~0_combout\ & (\B[18]~input_o\ & \A[18]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA17|Cout~0_combout\,
	datac => \B[18]~input_o\,
	datad => \A[18]~input_o\,
	combout => \add_nums|FA18|Cout~0_combout\);

-- Location: LCCOMB_X51_Y13_N22
\M19|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M19|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA18|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA18|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA18|Cout~0_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA18|Cout~combout\,
	combout => \M19|M6|O0~0_combout\);

-- Location: LCCOMB_X51_Y13_N20
\M19|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M19|M6|O0~3_combout\ = (\M19|M6|O0~2_combout\ & (!\M19|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M19|M6|O0~2_combout\ & (\M19|M6|O0~1_combout\ $ ((\M19|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011011000010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M19|M6|O0~2_combout\,
	datab => \M19|M6|O0~1_combout\,
	datac => \M19|M6|O0~0_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M19|M6|O0~3_combout\);

-- Location: LCCOMB_X51_Y13_N26
\M20|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M20|M6|O0~1_combout\ = (\A[20]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[20]~input_o\)))) # (!\A[20]~input_o\ & (\B[20]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110110011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[20]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[20]~input_o\,
	combout => \M20|M6|O0~1_combout\);

-- Location: LCCOMB_X51_Y13_N28
\M20|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M20|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[20]~input_o\) # (!\A[20]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[20]~input_o\,
	datab => \M1|M6|O0~3_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[20]~input_o\,
	combout => \M20|M6|O0~2_combout\);

-- Location: LCCOMB_X51_Y13_N6
\add_nums|FA19|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA19|Cout~0_combout\ = (\add_nums|FA18|Cout~0_combout\ & ((\B[19]~input_o\) # (\A[19]~input_o\))) # (!\add_nums|FA18|Cout~0_combout\ & (\B[19]~input_o\ & \A[19]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \add_nums|FA18|Cout~0_combout\,
	datac => \B[19]~input_o\,
	datad => \A[19]~input_o\,
	combout => \add_nums|FA19|Cout~0_combout\);

-- Location: LCCOMB_X51_Y13_N8
\M20|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M20|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA19|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA19|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA19|Cout~0_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA19|Cout~combout\,
	combout => \M20|M6|O0~0_combout\);

-- Location: LCCOMB_X51_Y13_N30
\M20|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M20|M6|O0~3_combout\ = (\M20|M6|O0~2_combout\ & (!\M20|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M20|M6|O0~2_combout\ & (\M20|M6|O0~1_combout\ $ ((\M20|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101011000010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M20|M6|O0~1_combout\,
	datab => \M20|M6|O0~2_combout\,
	datac => \M20|M6|O0~0_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M20|M6|O0~3_combout\);

-- Location: LCCOMB_X50_Y13_N10
\M21|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M21|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[21]~input_o\) # (!\B[21]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \B[21]~input_o\,
	datac => \A[21]~input_o\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M21|M6|O0~2_combout\);

-- Location: LCCOMB_X50_Y13_N24
\M21|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M21|M6|O0~1_combout\ = (\B[21]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\A[21]~input_o\ & !\M1|M6|O0~1_combout\)))) # (!\B[21]~input_o\ & (\A[21]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010100110111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \B[21]~input_o\,
	datac => \A[21]~input_o\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M21|M6|O0~1_combout\);

-- Location: LCCOMB_X50_Y13_N12
\add_nums|FA20|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA20|Cout~0_combout\ = (\add_nums|FA19|Cout~0_combout\ & ((\A[20]~input_o\) # (\B[20]~input_o\))) # (!\add_nums|FA19|Cout~0_combout\ & (\A[20]~input_o\ & \B[20]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA19|Cout~0_combout\,
	datab => \A[20]~input_o\,
	datad => \B[20]~input_o\,
	combout => \add_nums|FA20|Cout~0_combout\);

-- Location: LCCOMB_X50_Y13_N22
\M21|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M21|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA20|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA20|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001011001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA20|Cout~0_combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA20|Cout~combout\,
	combout => \M21|M6|O0~0_combout\);

-- Location: LCCOMB_X50_Y13_N4
\M21|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M21|M6|O0~3_combout\ = (\M21|M6|O0~2_combout\ & (!\M21|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M21|M6|O0~2_combout\ & (\M21|M6|O0~1_combout\ $ ((\M21|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011011000010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M21|M6|O0~2_combout\,
	datab => \M21|M6|O0~1_combout\,
	datac => \M21|M6|O0~0_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M21|M6|O0~3_combout\);

-- Location: LCCOMB_X51_Y15_N24
\M22|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M22|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[22]~input_o\) # (!\A[22]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \A[22]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[22]~input_o\,
	combout => \M22|M6|O0~2_combout\);

-- Location: LCCOMB_X51_Y15_N14
\M22|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M22|M6|O0~1_combout\ = (\A[22]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[22]~input_o\)))) # (!\A[22]~input_o\ & (\B[22]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \A[22]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[22]~input_o\,
	combout => \M22|M6|O0~1_combout\);

-- Location: LCCOMB_X50_Y13_N6
\add_nums|FA21|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA21|Cout~0_combout\ = (\add_nums|FA20|Cout~0_combout\ & ((\B[21]~input_o\) # (\A[21]~input_o\))) # (!\add_nums|FA20|Cout~0_combout\ & (\B[21]~input_o\ & \A[21]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \add_nums|FA20|Cout~0_combout\,
	datab => \B[21]~input_o\,
	datac => \A[21]~input_o\,
	combout => \add_nums|FA21|Cout~0_combout\);

-- Location: LCCOMB_X51_Y15_N20
\M22|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M22|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\)) # (!\slt_nums|sub|A0|FA21|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (((!\M1|M6|O0~1_combout\ & \add_nums|FA21|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100011111000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA21|Cout~combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \add_nums|FA21|Cout~0_combout\,
	combout => \M22|M6|O0~0_combout\);

-- Location: LCCOMB_X51_Y15_N2
\M22|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M22|M6|O0~3_combout\ = (\M22|M6|O0~2_combout\ & (\ALUop[0]~input_o\ & (!\M22|M6|O0~1_combout\))) # (!\M22|M6|O0~2_combout\ & ((\M22|M6|O0~1_combout\ $ (\M22|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101100111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[0]~input_o\,
	datab => \M22|M6|O0~2_combout\,
	datac => \M22|M6|O0~1_combout\,
	datad => \M22|M6|O0~0_combout\,
	combout => \M22|M6|O0~3_combout\);

-- Location: LCCOMB_X51_Y15_N28
\add_nums|FA22|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA22|Cout~0_combout\ = (\add_nums|FA21|Cout~0_combout\ & ((\A[22]~input_o\) # (\B[22]~input_o\))) # (!\add_nums|FA21|Cout~0_combout\ & (\A[22]~input_o\ & \B[22]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \add_nums|FA21|Cout~0_combout\,
	datac => \A[22]~input_o\,
	datad => \B[22]~input_o\,
	combout => \add_nums|FA22|Cout~0_combout\);

-- Location: LCCOMB_X51_Y15_N6
\M23|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M23|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA22|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA22|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011010110110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \slt_nums|sub|A0|FA22|Cout~combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \add_nums|FA22|Cout~0_combout\,
	combout => \M23|M6|O0~0_combout\);

-- Location: LCCOMB_X51_Y15_N16
\M23|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M23|M6|O0~1_combout\ = (\A[23]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[23]~input_o\)))) # (!\A[23]~input_o\ & (\B[23]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000111000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[23]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \B[23]~input_o\,
	combout => \M23|M6|O0~1_combout\);

-- Location: LCCOMB_X51_Y15_N10
\M23|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M23|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[23]~input_o\) # (!\A[23]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \A[23]~input_o\,
	datac => \M1|M6|O0~3_combout\,
	datad => \B[23]~input_o\,
	combout => \M23|M6|O0~2_combout\);

-- Location: LCCOMB_X51_Y15_N12
\M23|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M23|M6|O0~3_combout\ = (\M23|M6|O0~2_combout\ & (((!\M23|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M23|M6|O0~2_combout\ & (\M23|M6|O0~0_combout\ $ ((\M23|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011011000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M23|M6|O0~0_combout\,
	datab => \M23|M6|O0~1_combout\,
	datac => \M23|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M23|M6|O0~3_combout\);

-- Location: LCCOMB_X50_Y23_N12
\M24|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M24|M6|O0~1_combout\ = (\A[24]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[24]~input_o\)))) # (!\A[24]~input_o\ & (\B[24]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \A[24]~input_o\,
	datad => \B[24]~input_o\,
	combout => \M24|M6|O0~1_combout\);

-- Location: LCCOMB_X51_Y15_N22
\add_nums|FA23|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA23|Cout~0_combout\ = (\B[23]~input_o\ & ((\add_nums|FA22|Cout~0_combout\) # (\A[23]~input_o\))) # (!\B[23]~input_o\ & (\add_nums|FA22|Cout~0_combout\ & \A[23]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[23]~input_o\,
	datab => \add_nums|FA22|Cout~0_combout\,
	datac => \A[23]~input_o\,
	combout => \add_nums|FA23|Cout~0_combout\);

-- Location: LCCOMB_X50_Y23_N26
\M24|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M24|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & ((!\slt_nums|sub|A0|FA23|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA23|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010011110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \add_nums|FA23|Cout~0_combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \slt_nums|sub|A0|FA23|Cout~combout\,
	combout => \M24|M6|O0~0_combout\);

-- Location: LCCOMB_X50_Y23_N6
\M24|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M24|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[24]~input_o\) # (!\A[24]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \A[24]~input_o\,
	datad => \B[24]~input_o\,
	combout => \M24|M6|O0~2_combout\);

-- Location: LCCOMB_X50_Y23_N8
\M24|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M24|M6|O0~3_combout\ = (\M24|M6|O0~2_combout\ & (!\M24|M6|O0~1_combout\ & (\ALUop[0]~input_o\))) # (!\M24|M6|O0~2_combout\ & (\M24|M6|O0~1_combout\ $ (((\M24|M6|O0~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100010001011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M24|M6|O0~1_combout\,
	datab => \ALUop[0]~input_o\,
	datac => \M24|M6|O0~0_combout\,
	datad => \M24|M6|O0~2_combout\,
	combout => \M24|M6|O0~3_combout\);

-- Location: LCCOMB_X49_Y23_N30
\M25|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M25|M6|O0~1_combout\ = (\B[25]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[25]~input_o\)))) # (!\B[25]~input_o\ & (\A[25]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000110100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[25]~input_o\,
	datab => \M1|M6|O0~1_combout\,
	datac => \M1|M6|O0~3_combout\,
	datad => \A[25]~input_o\,
	combout => \M25|M6|O0~1_combout\);

-- Location: LCCOMB_X49_Y23_N24
\M25|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M25|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[25]~input_o\) # (!\B[25]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[25]~input_o\,
	datab => \M1|M6|O0~1_combout\,
	datac => \M1|M6|O0~3_combout\,
	datad => \A[25]~input_o\,
	combout => \M25|M6|O0~2_combout\);

-- Location: LCCOMB_X50_Y23_N18
\add_nums|FA24|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA24|Cout~0_combout\ = (\B[24]~input_o\ & ((\A[24]~input_o\) # (\add_nums|FA23|Cout~0_combout\))) # (!\B[24]~input_o\ & (\A[24]~input_o\ & \add_nums|FA23|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[24]~input_o\,
	datac => \A[24]~input_o\,
	datad => \add_nums|FA23|Cout~0_combout\,
	combout => \add_nums|FA24|Cout~0_combout\);

-- Location: LCCOMB_X49_Y23_N12
\M25|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M25|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA24|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA24|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101001111010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA24|Cout~combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \add_nums|FA24|Cout~0_combout\,
	combout => \M25|M6|O0~0_combout\);

-- Location: LCCOMB_X49_Y23_N18
\M25|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M25|M6|O0~3_combout\ = (\M25|M6|O0~2_combout\ & (!\M25|M6|O0~1_combout\ & (\ALUop[0]~input_o\))) # (!\M25|M6|O0~2_combout\ & (\M25|M6|O0~1_combout\ $ (((\M25|M6|O0~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000101100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M25|M6|O0~1_combout\,
	datab => \M25|M6|O0~2_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M25|M6|O0~0_combout\,
	combout => \M25|M6|O0~3_combout\);

-- Location: LCCOMB_X49_Y23_N10
\M26|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M26|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[26]~input_o\) # (!\B[26]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \B[26]~input_o\,
	datad => \A[26]~input_o\,
	combout => \M26|M6|O0~2_combout\);

-- Location: LCCOMB_X49_Y23_N0
\M26|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M26|M6|O0~1_combout\ = (\B[26]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[26]~input_o\)))) # (!\B[26]~input_o\ & (\A[26]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \B[26]~input_o\,
	datad => \A[26]~input_o\,
	combout => \M26|M6|O0~1_combout\);

-- Location: LCCOMB_X49_Y23_N20
\add_nums|FA25|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA25|Cout~0_combout\ = (\B[25]~input_o\ & ((\add_nums|FA24|Cout~0_combout\) # (\A[25]~input_o\))) # (!\B[25]~input_o\ & (\add_nums|FA24|Cout~0_combout\ & \A[25]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[25]~input_o\,
	datab => \add_nums|FA24|Cout~0_combout\,
	datad => \A[25]~input_o\,
	combout => \add_nums|FA25|Cout~0_combout\);

-- Location: LCCOMB_X49_Y23_N6
\M26|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M26|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA25|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA25|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101001111010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \slt_nums|sub|A0|FA25|Cout~combout\,
	datab => \M1|M6|O0~1_combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \add_nums|FA25|Cout~0_combout\,
	combout => \M26|M6|O0~0_combout\);

-- Location: LCCOMB_X49_Y23_N4
\M26|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M26|M6|O0~3_combout\ = (\M26|M6|O0~2_combout\ & (!\M26|M6|O0~1_combout\ & (\ALUop[0]~input_o\))) # (!\M26|M6|O0~2_combout\ & (\M26|M6|O0~1_combout\ $ (((\M26|M6|O0~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000101100100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M26|M6|O0~2_combout\,
	datab => \M26|M6|O0~1_combout\,
	datac => \ALUop[0]~input_o\,
	datad => \M26|M6|O0~0_combout\,
	combout => \M26|M6|O0~3_combout\);

-- Location: LCCOMB_X49_Y23_N22
\add_nums|FA26|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA26|Cout~0_combout\ = (\A[26]~input_o\ & ((\add_nums|FA25|Cout~0_combout\) # (\B[26]~input_o\))) # (!\A[26]~input_o\ & (\add_nums|FA25|Cout~0_combout\ & \B[26]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A[26]~input_o\,
	datab => \add_nums|FA25|Cout~0_combout\,
	datac => \B[26]~input_o\,
	combout => \add_nums|FA26|Cout~0_combout\);

-- Location: LCCOMB_X42_Y23_N28
\M27|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M27|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA26|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA26|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA26|Cout~0_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA26|Cout~combout\,
	combout => \M27|M6|O0~0_combout\);

-- Location: LCCOMB_X42_Y23_N30
\M27|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M27|M6|O0~1_combout\ = (\A[27]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[27]~input_o\)))) # (!\A[27]~input_o\ & (\B[27]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \A[27]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[27]~input_o\,
	combout => \M27|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y23_N0
\M27|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M27|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[27]~input_o\) # (!\A[27]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \A[27]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[27]~input_o\,
	combout => \M27|M6|O0~2_combout\);

-- Location: LCCOMB_X42_Y23_N10
\M27|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M27|M6|O0~3_combout\ = (\M27|M6|O0~2_combout\ & (\ALUop[0]~input_o\ & ((!\M27|M6|O0~1_combout\)))) # (!\M27|M6|O0~2_combout\ & ((\M27|M6|O0~0_combout\ $ (\M27|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[0]~input_o\,
	datab => \M27|M6|O0~0_combout\,
	datac => \M27|M6|O0~1_combout\,
	datad => \M27|M6|O0~2_combout\,
	combout => \M27|M6|O0~3_combout\);

-- Location: LCCOMB_X42_Y23_N8
\M28|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M28|M6|O0~1_combout\ = (\A[28]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\B[28]~input_o\)))) # (!\A[28]~input_o\ & (\B[28]~input_o\ $ (((!\M1|M6|O0~3_combout\ & \M1|M6|O0~1_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101110011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \A[28]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[28]~input_o\,
	combout => \M28|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y23_N20
\add_nums|FA27|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA27|Cout~0_combout\ = (\B[27]~input_o\ & ((\A[27]~input_o\) # (\add_nums|FA26|Cout~0_combout\))) # (!\B[27]~input_o\ & (\A[27]~input_o\ & \add_nums|FA26|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[27]~input_o\,
	datab => \A[27]~input_o\,
	datad => \add_nums|FA26|Cout~0_combout\,
	combout => \add_nums|FA27|Cout~0_combout\);

-- Location: LCCOMB_X42_Y23_N14
\M28|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M28|M6|O0~0_combout\ = (\M1|M6|O0~2_combout\ & (((\M1|M6|O0~1_combout\) # (!\slt_nums|sub|A0|FA27|Cout~combout\)))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA27|Cout~0_combout\ & (!\M1|M6|O0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~2_combout\,
	datab => \add_nums|FA27|Cout~0_combout\,
	datac => \M1|M6|O0~1_combout\,
	datad => \slt_nums|sub|A0|FA27|Cout~combout\,
	combout => \M28|M6|O0~0_combout\);

-- Location: LCCOMB_X42_Y23_N2
\M28|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M28|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\B[28]~input_o\) # (!\A[28]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~3_combout\,
	datab => \A[28]~input_o\,
	datac => \M1|M6|O0~1_combout\,
	datad => \B[28]~input_o\,
	combout => \M28|M6|O0~2_combout\);

-- Location: LCCOMB_X42_Y23_N4
\M28|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M28|M6|O0~3_combout\ = (\M28|M6|O0~2_combout\ & (\ALUop[0]~input_o\ & (!\M28|M6|O0~1_combout\))) # (!\M28|M6|O0~2_combout\ & ((\M28|M6|O0~1_combout\ $ (\M28|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010001000111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[0]~input_o\,
	datab => \M28|M6|O0~1_combout\,
	datac => \M28|M6|O0~0_combout\,
	datad => \M28|M6|O0~2_combout\,
	combout => \M28|M6|O0~3_combout\);

-- Location: LCCOMB_X46_Y34_N22
\M29|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M29|M6|O0~1_combout\ = (\B[29]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[29]~input_o\)))) # (!\B[29]~input_o\ & (\A[29]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110111010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[29]~input_o\,
	datad => \A[29]~input_o\,
	combout => \M29|M6|O0~1_combout\);

-- Location: LCCOMB_X42_Y23_N6
\add_nums|FA28|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA28|Cout~0_combout\ = (\B[28]~input_o\ & ((\A[28]~input_o\) # (\add_nums|FA27|Cout~0_combout\))) # (!\B[28]~input_o\ & (\A[28]~input_o\ & \add_nums|FA27|Cout~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \B[28]~input_o\,
	datac => \A[28]~input_o\,
	datad => \add_nums|FA27|Cout~0_combout\,
	combout => \add_nums|FA28|Cout~0_combout\);

-- Location: LCCOMB_X46_Y34_N28
\M29|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M29|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (\M1|M6|O0~2_combout\)) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & ((!\slt_nums|sub|A0|FA28|Cout~combout\))) # (!\M1|M6|O0~2_combout\ & (\add_nums|FA28|Cout~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001100011011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~2_combout\,
	datac => \add_nums|FA28|Cout~0_combout\,
	datad => \slt_nums|sub|A0|FA28|Cout~combout\,
	combout => \M29|M6|O0~0_combout\);

-- Location: LCCOMB_X46_Y34_N8
\M29|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M29|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[29]~input_o\) # (!\B[29]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[29]~input_o\,
	datad => \A[29]~input_o\,
	combout => \M29|M6|O0~2_combout\);

-- Location: LCCOMB_X46_Y34_N10
\M29|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M29|M6|O0~3_combout\ = (\M29|M6|O0~2_combout\ & (!\M29|M6|O0~1_combout\ & ((\ALUop[0]~input_o\)))) # (!\M29|M6|O0~2_combout\ & (\M29|M6|O0~1_combout\ $ ((\M29|M6|O0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101011000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M29|M6|O0~1_combout\,
	datab => \M29|M6|O0~0_combout\,
	datac => \M29|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M29|M6|O0~3_combout\);

-- Location: LCCOMB_X46_Y34_N20
\add_nums|FA29|Cout~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \add_nums|FA29|Cout~0_combout\ = (\add_nums|FA28|Cout~0_combout\ & ((\B[29]~input_o\) # (\A[29]~input_o\))) # (!\add_nums|FA28|Cout~0_combout\ & (\B[29]~input_o\ & \A[29]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \add_nums|FA28|Cout~0_combout\,
	datac => \B[29]~input_o\,
	datad => \A[29]~input_o\,
	combout => \add_nums|FA29|Cout~0_combout\);

-- Location: LCCOMB_X46_Y34_N6
\M30|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M30|M6|O0~0_combout\ = (\M1|M6|O0~1_combout\ & (((\M1|M6|O0~2_combout\)))) # (!\M1|M6|O0~1_combout\ & ((\M1|M6|O0~2_combout\ & (!\slt_nums|sub|A0|FA29|Cout~combout\)) # (!\M1|M6|O0~2_combout\ & ((\add_nums|FA29|Cout~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011010110110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \slt_nums|sub|A0|FA29|Cout~combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \add_nums|FA29|Cout~0_combout\,
	combout => \M30|M6|O0~0_combout\);

-- Location: LCCOMB_X46_Y34_N0
\M30|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M30|M6|O0~1_combout\ = (\B[30]~input_o\ & ((\M1|M6|O0~3_combout\) # ((!\M1|M6|O0~1_combout\ & !\A[30]~input_o\)))) # (!\B[30]~input_o\ & (\A[30]~input_o\ $ (((\M1|M6|O0~1_combout\ & !\M1|M6|O0~3_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110111010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[30]~input_o\,
	datad => \A[30]~input_o\,
	combout => \M30|M6|O0~1_combout\);

-- Location: LCCOMB_X46_Y34_N2
\M30|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M30|M6|O0~2_combout\ = (\M1|M6|O0~3_combout\) # ((\M1|M6|O0~1_combout\ & ((!\A[30]~input_o\) # (!\B[30]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M1|M6|O0~1_combout\,
	datab => \M1|M6|O0~3_combout\,
	datac => \B[30]~input_o\,
	datad => \A[30]~input_o\,
	combout => \M30|M6|O0~2_combout\);

-- Location: LCCOMB_X46_Y34_N12
\M30|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M30|M6|O0~3_combout\ = (\M30|M6|O0~2_combout\ & (((!\M30|M6|O0~1_combout\ & \ALUop[0]~input_o\)))) # (!\M30|M6|O0~2_combout\ & (\M30|M6|O0~0_combout\ $ ((\M30|M6|O0~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011011000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M30|M6|O0~0_combout\,
	datab => \M30|M6|O0~1_combout\,
	datac => \M30|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M30|M6|O0~3_combout\);

-- Location: LCCOMB_X46_Y34_N30
\M31|M6|O0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~1_combout\ = (\B[31]~input_o\ & (!\A[31]~input_o\ & (\M1|M6|O0~2_combout\ $ (!\ALUop[0]~input_o\)))) # (!\B[31]~input_o\ & (\M1|M6|O0~2_combout\ $ (((\A[31]~input_o\ & !\ALUop[0]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111000000010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[31]~input_o\,
	datab => \A[31]~input_o\,
	datac => \M1|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M31|M6|O0~1_combout\);

-- Location: LCCOMB_X46_Y34_N16
\M31|M6|O0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~2_combout\ = (\B[31]~input_o\ & ((\A[31]~input_o\ & (\M1|M6|O0~2_combout\)) # (!\A[31]~input_o\ & ((\ALUop[0]~input_o\))))) # (!\B[31]~input_o\ & (\A[31]~input_o\ & ((\ALUop[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110011010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[31]~input_o\,
	datab => \A[31]~input_o\,
	datac => \M1|M6|O0~2_combout\,
	datad => \ALUop[0]~input_o\,
	combout => \M31|M6|O0~2_combout\);

-- Location: LCCOMB_X46_Y34_N4
\M31|M6|O0~5\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~5_combout\ = (\B[30]~input_o\ & (((\slt_nums|sub|A0|FA29|Cout~combout\ & \A[30]~input_o\)) # (!\M1|M6|O0~2_combout\))) # (!\B[30]~input_o\ & (\M1|M6|O0~2_combout\ & ((\slt_nums|sub|A0|FA29|Cout~combout\) # (\A[30]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101101001001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[30]~input_o\,
	datab => \slt_nums|sub|A0|FA29|Cout~combout\,
	datac => \M1|M6|O0~2_combout\,
	datad => \A[30]~input_o\,
	combout => \M31|M6|O0~5_combout\);

-- Location: LCCOMB_X46_Y34_N14
\M31|M6|O0~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~6_combout\ = (\B[30]~input_o\ & (\M31|M6|O0~5_combout\ & ((\add_nums|FA29|Cout~0_combout\) # (\A[30]~input_o\)))) # (!\B[30]~input_o\ & ((\M31|M6|O0~5_combout\) # ((\add_nums|FA29|Cout~0_combout\ & \A[30]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010011010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B[30]~input_o\,
	datab => \add_nums|FA29|Cout~0_combout\,
	datac => \M31|M6|O0~5_combout\,
	datad => \A[30]~input_o\,
	combout => \M31|M6|O0~6_combout\);

-- Location: LCCOMB_X46_Y34_N26
\M31|M6|O0~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~3_combout\ = \M31|M6|O0~2_combout\ $ (((!\M1|M6|O0~1_combout\ & (\M31|M6|O0~1_combout\ $ (\M31|M6|O0~6_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110010010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M31|M6|O0~1_combout\,
	datab => \M31|M6|O0~2_combout\,
	datac => \M31|M6|O0~6_combout\,
	datad => \M1|M6|O0~1_combout\,
	combout => \M31|M6|O0~3_combout\);

-- Location: LCCOMB_X38_Y34_N4
\M31|M6|O0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~0_combout\ = (\ALUop[1]~input_o\ & (!\A[31]~input_o\ & (\ALUop[2]~input_o\ & \ALUop[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ALUop[1]~input_o\,
	datab => \A[31]~input_o\,
	datac => \ALUop[2]~input_o\,
	datad => \ALUop[0]~input_o\,
	combout => \M31|M6|O0~0_combout\);

-- Location: LCCOMB_X38_Y34_N22
\M31|M6|O0~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \M31|M6|O0~4_combout\ = (\M31|M6|O0~3_combout\ & (((\M31|M6|O0~0_combout\ & !\B[31]~input_o\)) # (!\M1|M6|O0~3_combout\))) # (!\M31|M6|O0~3_combout\ & (\M31|M6|O0~0_combout\ & (!\B[31]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000110010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \M31|M6|O0~3_combout\,
	datab => \M31|M6|O0~0_combout\,
	datac => \B[31]~input_o\,
	datad => \M1|M6|O0~3_combout\,
	combout => \M31|M6|O0~4_combout\);

ww_Result(0) <= \Result[0]~output_o\;

ww_Result(1) <= \Result[1]~output_o\;

ww_Result(2) <= \Result[2]~output_o\;

ww_Result(3) <= \Result[3]~output_o\;

ww_Result(4) <= \Result[4]~output_o\;

ww_Result(5) <= \Result[5]~output_o\;

ww_Result(6) <= \Result[6]~output_o\;

ww_Result(7) <= \Result[7]~output_o\;

ww_Result(8) <= \Result[8]~output_o\;

ww_Result(9) <= \Result[9]~output_o\;

ww_Result(10) <= \Result[10]~output_o\;

ww_Result(11) <= \Result[11]~output_o\;

ww_Result(12) <= \Result[12]~output_o\;

ww_Result(13) <= \Result[13]~output_o\;

ww_Result(14) <= \Result[14]~output_o\;

ww_Result(15) <= \Result[15]~output_o\;

ww_Result(16) <= \Result[16]~output_o\;

ww_Result(17) <= \Result[17]~output_o\;

ww_Result(18) <= \Result[18]~output_o\;

ww_Result(19) <= \Result[19]~output_o\;

ww_Result(20) <= \Result[20]~output_o\;

ww_Result(21) <= \Result[21]~output_o\;

ww_Result(22) <= \Result[22]~output_o\;

ww_Result(23) <= \Result[23]~output_o\;

ww_Result(24) <= \Result[24]~output_o\;

ww_Result(25) <= \Result[25]~output_o\;

ww_Result(26) <= \Result[26]~output_o\;

ww_Result(27) <= \Result[27]~output_o\;

ww_Result(28) <= \Result[28]~output_o\;

ww_Result(29) <= \Result[29]~output_o\;

ww_Result(30) <= \Result[30]~output_o\;

ww_Result(31) <= \Result[31]~output_o\;
END structure;


