//=============================================================================
//init script for MX28 EVK/Armadillo DDR2 CPU board (ddr2-EDE1116)
//Date:     DEC-03 2009
//Author:   Freescale-MAD
//Version:  0.2
//=============================================================================

//****************************
// VDDD setting
//****************************
//set VDDD =1.55V =(0.8v + TRIG x 0.025v), TRIG=0x1e
setmem /32 0x80044040=0x0022071e


//****************************
// CLOCK set up
//****************************
// Power up PLL0 HW_CLKCTRL_PLL0CTRL0
setmem /32 0x80040000=0x00020000
// Set up fractional dividers for CPU and EMI - HW_CLKCTRL_FRAC0
// EMI - first set DIV_EMI to div-by-2 before programming frac divider
setmem /32 0x800400F0 = 0x80000002


// CPU: CPUFRAC=20 480*18/20=432MHz, EMI: EMIFRAC=22, (480/2)*18/22=196.4MHz
setmem /32 0x800401B0=0x92921614

// HCLK = CLK_P/3,HW_CLKCTRL_HBUS DIV =0x3 
setmem /32 0x80040060=0x00000003

// Clear the bypass bits for CPU and EMI clocks in HW_CLKCTRL_CLKSEQ_CLR
setmem /32 0x800401D8=0x00040080

//****************************
// POWER up DCDD_VDDA (DDR2)
//****************************
// Now set the voltage level to 1.8V HW_POWER_VDDACTRL bits TRC=0xC
setmem /32 0x80044050=0x0000270C

//****************************
// DDR2 DCDD_VDDA
//****************************
// First set up pin muxing and drive strength 
// Ungate module clock and bring out of reset HW_PINCTRL_CTRL_CLR
setmem /32 0x80018008=0xC0000000


//****************************
// EMI PAD setting
//****************************
// Set up drive strength for EMI pins
//setmem /32 0x80019B80=0x0032AAA //  drive is 20mA
setmem /32 0x80019B80=0x0030000 //  drive is 5mA
// Set up pin muxing for EMI, HW_PINCTRL_MUXSEL10, 11, 12, 13
setmem /32 0x800181A8=0xFFFFFFFF
setmem /32 0x800181B8=0xFFFFFFFF
setmem /32 0x800181C8=0xFFFFFFFF
setmem /32 0x800181D8=0xFFFFFFFF

//** Ungate EMI clock in CCM
setmem /32 0x800400F0 = 0x00000002

//****************************
// EMI DDR2 Initialization
//****************************
// DRAM_REG[0] =  0x00000000 ;  //00000000000000000000000000000000 user_def_reg_0(RW); set CKE_SELECT=0 for DDR2; SREFRESH_ENTER=0; BRESP_TIMING=0
setmem /32 0x800E0000=0x00000000

// DRAM_REG[16] = 0x00000000 ;  //0000000_0 write_modereg(WR) 0000000_0 power_down(RW) 000000000000000_0 start(RW) (don't activate EMI yet, wait till after init)
setmem /32 0x800E0040=0x00000000

// DRAM_REG[21] = 0x00000000 ;  //00000_000 cke_delay(RW) 00000000 dll_lock(RD) 0000000_0 dlllockreg(RD) 0000000_0 dll_bypass_mode(RW)
setmem /32 0x800E0054 = 0x00000000

// DRAM_REG[22] = 0x00000000 ;  //000000000000_0000 lowpower_refresh_enable(RW) 000_00000 lowpower_control(RW) 000_00000 lowpower_auto_enable(RW)
setmem /32 0x800E0058=0x00000000

// DRAM_REG[23] = 0x00000000 ;  //0000000000000000 lowpower_internal_cnt(RW) 0000000000000000 lowpower_external_cnt(RW)
setmem /32 0x800E005C=0x00000000

// DRAM_REG[24] = 0x00000000 ;  //0000000000000000 lowpower_self_refresh_cnt(RW) 0000000000000000 lowpower_refresh_hold(RW)
setmem /32 0x800E0060=0x00000000

// DRAM_REG[25] = 0x00000000 ;  //00000000000000000000000000000000 lowpower_power_down_cnt(RW)
setmem /32 0x800E0064=0x00000000

// DRAM_REG[26] = 0x00010101 ;  //000000000000000_1 priority_en(RW) 0000000_1 addr_cmp_en(RW) 0000000_1 placement_en(RW)
setmem /32 0x800E0068=0x00010101 

// DRAM_REG[27] = 0x01010101 ;  //0000000_1 swap_port_rw_same_en(RW) 0000000_1 swap_en(RW) 0000000_1 bank_split_en(RW) 0000000_1 rw_same_en(RW)
setmem /32 0x800E006C=0x01010101 

// DRAM_REG[28] = 0x000f0f01 ;  //00000_000 q_fullness(RW) 0000_1111 age_count(RW) 0000_1111 command_age_count(RW) 0000000_1 active_aging(RW)
setmem /32 0x800E0070=0x000f0f01 

// DRAM_REG[29] = 0x0302020A;  //0000 0001 0000 0010 0000 0010 0000 1010; CS=CS0/1 (0011); COL=12-10 (0010); ROW=15-13 (0010); APREBIT=DRAM_A10 (1010)
setmem /32 0x800E0074=0x0302020A

// DRAM_REG[31] = 0x00010101 ;  //000000000000000_1 eight_bank_mode(RW) 0000000_1 drive_dq_dqs(RW) 0000000_1 dqs_n_en(RW); EIGHT_BANK_MODE=1; DRIVE_DQ_DQS=1; DQS_N_EN=1
setmem /32 0x800E007C=0x00010101 

// DRAM_REG[32] = 0x00000100 ;  //00000000000000000000000_1 reduc(RW) 0000000_0 reg_dimm_enable(RW); for 16-bit data width
setmem /32 0x800E0080=0x00000100 

// DRAM_REG[33] = 0x00000100 ;  //00000000000000000000000_1 concurrentap(RW) 0000000_0 ap(RW); leave as is for now, no auto pre-charge
setmem /32 0x800E0084=0x00000100 

// DRAM_REG[34] = 0x00000000 ;  //0000000_0 writeinterp(RW) 0000000_0 intrptwritea(RW) 0000000_0 intrptreada(RW) 0000000_0 intrptapburst(RW)
setmem /32 0x800E0088=0x00000000 

// DRAM_REG[35] = 0x00000002 ;  //000000000000000_0 pwrup_srefresh_exit(RW) 0000000_0 no_cmd_init(RW) 0000_0010 initaref(RW)
setmem /32 0x800E008C=0x00000002 

// DRAM_REG[36] = 0x01010000 ;  //0000000_1 tref_enable(RW) 0000000_1 tras_lockout(RW) 000000000000000_0 fast_write(RW);
setmem /32 0x800E0090=0x01010000 

// DRAM_REG[37] = 0x07080403 ;  // 0000 0110 0000 0110 0000 0011 0000 0010; CASLAT_LIN_GATE=0x6 and CASLAT_LIN=0x6 (spec says to set each to value of 3); CASLAT=0x3; WRLAT=0x2? (from design init)
setmem /32 0x800E0094=0x07080403 

//**  ddr2 timings **//
// DRAM_REG[38] = 0x06005003 ;  // TDAL=0110; TCPD=0000 0000 0101 0000; TCKE=011
setmem /32 0x800E0098=0x06005003 

// DRAM_REG[39] = 0x0a0000c8 ; // TFAW=1010; TDLL=1100 1000
setmem /32 0x800E009C=0x0a0000c8 

// DRAM_REG[40] = 0x02009c40 ; // TMRD=0010; TINIT=1001 1100 0100 0000
setmem /32 0x800E00A0=0x02009c40 

// DRAM_REG[41] = 0x0002030c ; // TPEDX=0000 0000 0000 0010; TRCD_INT=0000 0011; TRC=00 1100
setmem /32 0x800E00A4=0x0002030c 

// DRAM_REG[42] = 0x0036a609 ;  // TRAS_MAX=0011 0110 1011 0000; TRAS_MIN=0000 1001
setmem /32 0x800E00A8=0x0036a609 

// DRAM_REG[43] = 0x031a0612 ;  // TRP=0011; TRFC=0001 1010; TREF=00 0110 0001 1000
setmem /32 0x800E00AC=0x031a0612 

// DRAM_REG[44] = 0x02030202 ;  // TWTR=0010; TWR_INT=0011; TRTP=010; TRRD=010
setmem /32 0x800E00B0=0x02030202 

// DRAM_REG[45] = 0x00c8001c ;  // TXSR=0000 0000 1100 1000; TXSNR=0000 0000 0001 1100
setmem /32 0x800E00B4=0x00c8001c 

// DRAM_REG[48] = 0x00011900 ;  //0_0000000 axi0_current_bdw(RD) 0000000_1 axi0_bdw_ovflow(RW) 0_0100001 axi0_bdw(RW) 000000_00 axi0_fifo_type_reg(RW); keep as set by design
setmem /32 0x800E00C0=0x00011900 

// DRAM_REG[49] = 0xffff0303 ;  // axi0_en_size_lt_width_instr(RW)  axi0_w_priority(RW)  axi0_r_priority(RW)keep as set by design
setmem /32 0x800E00C4=0xffff0303 

// DRAM_REG[50] = 0x00012100 ; 
setmem /32 0x800E00C8=0x00012100 

//DRAM_REG[51] =  0xffff0303;
setmem /32 0x800E00CC=0xffff0303

// DRAM_REG[52] = 0x00012100 ;  //0_0000000 axi2_current_bdw(RD) 0000000_1 axi2_bdw_ovflow(RW) 0_0100001 axi2_bdw(RW) 000000_00 axi2_fifo_type_reg(RW); keep as set by design
setmem /32 0x800E00D0=0x00012100 

// DRAM_REG[53] = 0xffff0303 ; // axi2_en_size_lt_width_instr(RW)  axi2_w_priority(RW)  axi2_r_priority(RW) keep as set by design
setmem /32 0x800E00D4=0xffff0303 

// DRAM_REG[54] = 0x00012100  ;  //0_0000000 axi3_current_bdw(RD) 0000000_1 axi3_bdw_ovflow(RW) 0_0100001 axi3_bdw(RW) 000000_00 axi3_fifo_type_reg(RW; keep as set by design
setmem /32 0x800E00D8=0x00012100 

// DRAM_REG[55] = 0xffff0303 ; // axi3_en_size_lt_width_instr(RW)  axi3_w_priority(RW)  axi3_r_priority(RW); keep as set by design
setmem /32 0x800E00DC=0xffff0303 

// DRAM_REG[56] = 0x00000003 ;  //00000000000000000000000000000_011 arb_cmd_q_threshold(RW); keep as set by design
setmem /32 0x800E00E0=0x00000003 

// DRAM_REG[58] = 0x00000000 ;  //00000_00000000000 int_status(RD) 00000_00000000000 int_mask(RW); keep
setmem /32 0x800E00E8=0x00000000 

// DRAM_REG[66] = 0x00000612 ; //000000000000_0000 tdfi_ctrlupd_min(RD) 00_00010010001011 tdfi_ctrlupd_max(RW) 
setmem /32 0x800E0108=0x00000612 

// DRAM_REG[67] = 0x01000f02; // TDFI_DRAM_CLK_ENABLE=0000 (spec says unused); TDFI_DRAM_CLK_DISABLE=0000;// DRAM_CLK_ENABLE=0001 (enable clock for CS0); TDFI_CTRL_DELAY=0010 (set by design)
setmem /32 0x800E010C=0x01000f02

// DRAM_REG[69] = 0x00000200 ;  //00000000000000000000_0010 tdfi_phy_wrlat_base(RW) 0000_0000 tdfi_phy_wrlat(RD); keep as set by design
setmem /32 0x800E0114=0x00000200 

// DRAM_REG[70] = 0x00020007 ;  //000000000000_0010 tdfi_rddata_en_base(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0111 tdfi_phy_rdlat(RW); keep as set by design
setmem /32 0x800E0118=0x00020007 

// DRAM_REG[71] = 0xf5004a27;  //11110100000000010100101100100111 phy_ctrl_reg_0_0(RW); keep as set be design
//setmem /32 0x800E011C=0xf5004a27
//*!*//
// This setting works for 131MHz and for 200MHz
setmem /32 0x800E011C=0xf4004a27

// DRAM_REG[72] = 0xf5004a27;  //11110100000000010100101100100111 phy_ctrl_reg_0_1(RW); keep as set be design
//setmem /32 0x800E0120=0xf5004a27
//*!*//
// This setting works for 131MHz and for 200MHz
setmem /32 0x800E0120=0xf4004a27

// DRAM_REG[75] = 0x07400300 ;  //00000111010000000000001100000000 phy_ctrl_reg_1_0(RW); keep as set be design
setmem /32 0x800E012C=0x07400300 

// DRAM_REG[76] = 0x07400300 ;  //00000111010000000000001100000000 phy_ctrl_reg_1_1(RW); keep as set be design
setmem /32 0x800E0130=0x07400300 

// DRAM_REG[79] = 0x00000006 ;  //Bit 23=0 (disable DFI control for Mobile MCs); dfi_rddatra_valid delay = 5
//setmem /32 0x800E013C=0x00000006 
//*!*//
// This setting works for 131MHz and for 200MHz
setmem /32 0x800E013C=0x00000005 

// DRAM_REG[80] = 0x00000000 ;  //00000000000000000000000000000000 dft_ctrl_reg(RW); keep
setmem /32 0x800E0140=0x00000000 

// DRAM_REG[81] = 0x00000000 ;  //0000000000000000000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW); keep
setmem /32 0x800E0144=0x00000000 

// DRAM_REG[82] = 0x01000000 ;  //0000000_1 odt_alt_en(RW) 000000000000000000000000; keep as set be design
setmem /32 0x800E0148=0x01000000 

// DRAM_REG[83] = 0x01020408 ;  //0000_0001 odt_rd_map_cs3(RW) 0000_0010 odt_rd_map_cs2(RW) 0000_0100 odt_rd_map_cs1(RW) 0000_1000 odt_rd_map_cs0(RW); keep as set be design
setmem /32 0x800E014C=0x01020408 

// DRAM_REG[84] = 0x08040201 ;  //0000_1000 odt_wr_map_cs3(RW) 0000_0100 odt_wr_map_cs2(RW) 0000_0010 odt_wr_map_cs1(RW) 0000_0001 odt_wr_map_cs0(RW); keep as set be design
setmem /32 0x800E0150=0x08040201 

// DRAM_REG[85] = 0x000f1133 ;  //00000000000011110001000100110011 pad_ctrl_reg_0(RW); keep as set be design
setmem /32 0x800E0154=0x000f1133 

// DRAM_REG[87] = 0x00001f04 ;  //00000000000001100001110100100100 dll_ctrl_reg_0_0(RW); keep as set be design
setmem /32 0x800E015C=0x00001f04 

// DRAM_REG[88] = 0x00001f04 ;  //00000000000001100001110100100100 dll_ctrl_reg_0_1(RW); keep as set be design
setmem /32 0x800E0160=0x00001f04 

// DRAM_REG[91] = 0x00001f04 ;  //00000000000001100001111100001010 dll_ctrl_reg_1_0(RW); keep as set be design
setmem /32 0x800E016C=0x00001f04 

// DRAM_REG[92] = 0x00001f04 ;  //00000000000001100001111100001010 dll_ctrl_reg_1_1(RW); keep as set be design
setmem /32 0x800E0170=0x00001f04 

// DRAM_REG[162] =0x00010000 ;  //00000_000 w2r_samecs_dly(RW) 00000_000 w2r_diffcs_dly(RW) 0000000_000000000; other init file shows to zero out
setmem /32 0x800E0288=0x00010000 

// DRAM_REG[163] =0x00030404 ;  //00000000 dll_rst_adj_dly(RW) 0000_0010 wrlat_adj(RW) 0000_0011 rdlat_adj(RW) 0000_0100// DRAM_class(RW); keep as set by design
setmem /32 0x800E028C=0x00030404 

// DRAM_REG[164] =0x00000003 ;  //00000000000000_0000000000 int_ack(WR) 00000011 tmod(RW); keep as set by design
setmem /32 0x800E0290=0x00000003 

// DRAM_REG[171] =0x01010000 ;  //0000000_1 axi5_bdw_ovflow(RW) 0000000_1 axi4_bdw_ovflow(RW) 0000000000000000 dll_rst_delay(RW); keep as set by design
setmem /32 0x800E02AC=0x01010000 

// DRAM_REG[172] =0x01000000 ;  //0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 0000000_0 concurrentap_wr_only(RW) 0000000_0 cke_status(RD); keep as set by design
setmem /32 0x800E02B0=0x01000000 

// DRAM_REG[173] =0x03030000 ;  //00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 000000_00 axi5_fifo_type_reg(RW) 000000_00 axi4_fifo_type_reg(RW); keep as set by design
setmem /32 0x800E02B4=0x03030000 

// DRAM_REG[174] =0x00010303 ;  //00000_000 r2r_samecs_dly(RW) 00000_001 r2r_diffcs_dly(RW) 00000_011 axi5_w_priority(RW) 00000_011 axi5_r_priority(RW); keep as set by design
setmem /32 0x800E02B8=0x00010303 

// DRAM_REG[175] =0x01020202 ;  //00000_001 w2w_diffcs_dly(RW) 00000_010 tbst_int_interval(RW) 00000_010 r2w_samecs_dly(RW) 00000_010 r2w_diffcs_dly(RW); keep as set by design
setmem /32 0x800E02BC=0x01020202 

// DRAM_REG[176] =0x00000000 ;  //0000_0000 add_odt_clk_sametype_diffcs(RW) 0000_0000 add_odt_clk_difftype_samecs(RW) 0000_0000 add_odt_clk_difftype_diffcs(RW) 00000_000 w2w_samecs_dly(RW); keep as set by design
setmem /32 0x800E02C0=0x00000000 

// DRAM_REG[177] = 0x02040303 ; // TCCD=0 0010; TRP_AB=0011; CKSRX=0001; CKSRE=0001
setmem /32 0x800E02C4=0x02030303 

// DRAM_REG[178] =0x21002103 ;  // TCKESR=0 0011; other parameters set by design
setmem /32 0x800E02C8=0x21002103 

//DRAM_REG[179] = 0x00061200 ; //0000000000_00010010001011 tdfi_phyupd_type1(RW) 0_0000000 axi5_current_bdw(RD) 
setmem /32 0x800E02CC=0x00061200 

//DRAM_REG[180] = 0x06120612 ; //00_00010010001011 tdfi_phyupd_type3(RW) 00_00010010001011 tdfi_phyupd_type2(RW) 
setmem /32 0x800E02D0=0x06120612 

// DRAM_REG[181] =0x04420442 ;  // MR0_DATA_1=0; MR0_DATA_0=0000 0100 0011 0010
setmem /32 0x800E02D4=0x04420442 

// DRAM_REG[182] = 0x04420442 ; //0_000010000110010 mr0_data_3(RW) 0_000010000110010 mr0_data_2(RW) 
setmem /32 0x800E02D8=0x04420442 

// DRAM_REG[183] =0x00040004 ;  // MR1_DATA_1=0; MR1_DATA_0=0000 0000 0000 0100
setmem /32 0x800E02DC=0x00040004 

// DRAM_REG[184] = 0x00040004 ; //0_000000000000100 mr1_data_3(RW) 0_000000000000100 mr1_data_2(RW) 
setmem /32 0x800E02E0=0x00040004 

// DRAM_REG[185] =0x00000000 ;  //0_000000000000000 mr2_data_1(RW) 0_000000000000000 mr2_data_0(RW)
 setmem /32 0x800E02E4=0x00000000 

//DRAM_REG[186] = 0x00000000 ; //0_000000000000000 mr2_data_3(RW) 0_000000000000000 mr2_data_2(RW) 
setmem /32 0x800E02E8=0x00000000    

// DRAM_REG[187] =0x00000000 ;  //0_000000000000000 mr3_data_1(RW) 0_000000000000000 mr3_data_0(RW)
setmem /32 0x800E02EC=0x00000000 

 //DRAM_REG[188] = 0x00000000 ; //0_000000000000000 mr3_data_3(RW) 0_000000000000000 mr3_data_2(RW) 
setmem /32 0x800E02F0=0x00000000 

// DRAM_REG[189] =0xffffffff ;
setmem /32 0x800E02F4=0xffffffff 


//**  start controller **//
// DRAM_REG[16] = 0x00000001 ;  //0000000_0 write_modereg(WR) 0000000_0 power_down(RW) 000000000000000_1 start(RW); initiate initialization sequence
setmem /32 0x800E0040=0x00000001












