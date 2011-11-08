/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "../drv/hdmi_tx.h"

extern int ips_hdmi_stream(void);
//extern void init_data(unsigned int enc_in_format,int height, int width);
extern int init_dma_data(int sample_rate, int ch);
extern const unsigned char gAudio_sample[];
void init_hdmi_interrupt(void);
void hdmi_tx_ISR(void);


/*! ------------------------------------------------------------
 * HDMI TX Video Test (force output of FSL logo)
 *  ------------------------------------------------------------
 */
void hdmi_video_test(void){
  
    printf("\n---- Running HDMI video test ----\n");
    
    hdmi_data_info_s myHDMI_info = { 0 };  // declare new hdmi module object instance
    hdmi_vmode_s myHDMI_vmode_info = { 0 };  // declare new hdmi module object instance
    myHDMI_info.video_mode = &myHDMI_vmode_info;
    
    myHDMI_info.enc_in_format = eRGB;
    myHDMI_info.enc_out_format = eRGB;
    myHDMI_info.enc_color_depth = 8;
    myHDMI_info.colorimetry = eITU601;
    myHDMI_info.pix_repet_factor = 0;
    myHDMI_info.hdcp_enable = 0;
//    myHDMI_info.video_mode->mCode = 4;  //1280x720p @ 59.94/60Hz 16:9
    myHDMI_info.video_mode->mCode = 16;  //1920x1080p @ 59.94/60Hz 16:9
    myHDMI_info.video_mode->mHdmiDviSel = TRUE;
    myHDMI_info.video_mode->mRVBlankInOSC = FALSE;
    myHDMI_info.video_mode->mRefreshRate = 60000;
    myHDMI_info.video_mode->mDataEnablePolarity = TRUE;
    
    //hdmi_config_forced_pixels(82, 151, 7); // set to a forest greenish color
    //hdmi_config_force_video(TRUE);
    
    hdmi_av_frame_composer(&myHDMI_info);
    hdmi_video_packetize(myHDMI_info);
    hdmi_video_csc(myHDMI_info);
    hdmi_video_sample(myHDMI_info);
    
    hdmi_audio_mute(TRUE);
    hdmi_tx_hdcp_config(myHDMI_info.video_mode->mDataEnablePolarity);
    
    hdmi_phy_init(TRUE, myHDMI_info.video_mode->mPixelClock);
    
    hdmi_config_input_source(IPU1_DI0); // configure input source to HDMI block
    
 
    // configure IPU to output stream for hdmi input
    if(ips_hdmi_stream()){ // set up ipu1 disp0  1080P60 display stream 
        printf("HDMI video test PASS\n");
    }
    else{
        printf("HDMI video test FAIL\n");    
    }
}

/*! -----------------------------------------------------------------------
 * HDMI TX Audio Test (force color bar vid output + sine wave audio output)
 *  -----------------------------------------------------------------------
 */
void hdmi_audio_test(void)
{
    hdmi_data_info_s myHDMI_info = { 0 };  // declare new hdmi module object instance
    hdmi_vmode_s myHDMI_vmode_info = { 0 };  // declare new hdmi module object instance
    myHDMI_info.video_mode = &myHDMI_vmode_info;
    hdmi_audioparam_s myHDMI_audio_info = { 0 };  // declare new hdmi module object instance
    
    
    
	
	  myHDMI_info.enc_in_format = eRGB;
    myHDMI_info.enc_out_format = eRGB;
	  myHDMI_info.enc_color_depth = 8;
	  myHDMI_info.colorimetry = eITU709;
	  myHDMI_info.pix_repet_factor = 0;
	  myHDMI_info.hdcp_enable = 0;
		myHDMI_info.video_mode->mCode = 16; //1080p@60Hz
	  myHDMI_info.video_mode->mHdmiDviSel = TRUE;
	  myHDMI_info.video_mode->mRVBlankInOSC = FALSE;
	  myHDMI_info.video_mode->mRefreshRate = 60000;
	  myHDMI_info.video_mode->mDataEnablePolarity = TRUE;

		myHDMI_audio_info.IecCgmsA = 0;
		myHDMI_audio_info.IecCopyright = TRUE;
		myHDMI_audio_info.IecCategoryCode = 0;
		myHDMI_audio_info.IecPcmMode = 0;
		myHDMI_audio_info.IecSourceNumber = 1;
		myHDMI_audio_info.IecClockAccuracy = 0;
		myHDMI_audio_info.OriginalSamplingFrequency = 0;
		myHDMI_audio_info.ChannelAllocation = 0xf;
		myHDMI_audio_info.SamplingFrequency = 32000;
		myHDMI_audio_info.SampleSize = 16;
	

	  //init_data(myHDMI_info.enc_in_format,1080,1920);
    
    init_dma_data(32000,4);
    
    //enable HDMI_TX interrupt
    register_interrupt_routine(IMX_INT_HDMI_TX, hdmi_tx_ISR);
	  init_hdmi_interrupt(); //interrupt_init(0xff);
	  enable_interrupt(IMX_INT_HDMI_TX, CPU_0, 0);    // to cpu0, max priority (0)
		
	  audio_Configure(myHDMI_audio_info, 14850, 100);  //audio_Configure(14850,100);
	  writeb(0x00, HDMI_IH_MUTE_AHBDMAAUD_STAT0); //reg8_write(HDMI_IH_MUTE_AHBDMAAUD_STAT0,0x00);
	  audio_Configure_DMA(HDMI_AUDIO_BUF_START,(HDMI_AUDIO_BUF_START+0x17ff),1,4,64,4,0x7f);
	  void audio_Configure_DMA(uint32_t startAddr, uint32_t stopAddr, uint8_t hlockEn, uint8_t incrType,uint8_t threshold, uint32_t audioChnl, uint8_t intMask);

	  writeb(0x2, HDMI_IH_MUTE); //reg8_write(HDMI_IH_MUTE,0x2);
	  hal_delay_us(2000000); // play hdmi audio for 2 seconds
}


void hdmi_test(void){
    hdmi_video_test();
    printf("Check HDMI output to see Freescale logo\n");
    hal_delay_us(1000000); // wait second for HDMI audio test to start
    hdmi_audio_test();  
}

void init_hdmi_interrupt(void){
    writeb(0xff, HDMI_IH_MUTE_FC_STAT0);         // reg8_write(HDMI_IH_MUTE_FC_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_FC_STAT1);         // reg8_write(HDMI_IH_MUTE_FC_STAT1,mask);
	  writeb(0xff, HDMI_IH_MUTE_FC_STAT2);         // reg8_write(HDMI_IH_MUTE_FC_STAT2,mask);
	  writeb(0xff, HDMI_IH_MUTE_AS_STAT0);         // reg8_write(HDMI_IH_MUTE_AS_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_PHY_STAT0);        // reg8_write(HDMI_IH_MUTE_PHY_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_I2CM_STAT0);       // reg8_write(HDMI_IH_MUTE_I2CM_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_CEC_STAT0);        // reg8_write(HDMI_IH_MUTE_CEC_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_VP_STAT0);         // reg8_write(HDMI_IH_MUTE_VP_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_I2CMPHY_STAT0);    // reg8_write(HDMI_IH_MUTE_I2CMPHY_STAT0,mask);
	  writeb(0xff, HDMI_IH_MUTE_AHBDMAAUD_STAT0);  // reg8_write(HDMI_IH_MUTE_AHBDMAAUD_STAT0,mask);
}

int cnt = 0;

void hdmi_tx_ISR(void){
   char status;
	
	status = readb(HDMI_IH_AHBDMAAUD_STAT0);
	init_hdmi_interrupt();
	
  writeb(0x00, HDMI_IH_MUTE_AHBDMAAUD_STAT0);   // reg8_write(HDMI_IH_MUTE_AHBDMAAUD_STAT0,0x00);

	if(status&0x4)
	{
		writeb(0x4, HDMI_IH_AHBDMAAUD_STAT0); //reg8_write(HDMI_IH_AHBDMAAUD_STAT0,0x4);
		audio_Configure_DMA(HDMI_AUDIO_BUF_START,(HDMI_AUDIO_BUF_START+0x17ff),1,4,64,4,0x7f);
		if(cnt<32)
			{
				cnt++;
			}
		else
			{
				cnt=0;
			}
	}
	else
	{
	}
}
