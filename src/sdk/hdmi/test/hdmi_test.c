/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>

extern int ips_hdmi_stream(void);

void hdmi_test(void){
  
  printf("\n---- Running HDMI test ----\n");
  
  // configure IPU to output stream for hdmi input
  if(ips_hdmi_stream()){ // set up ipu1 disp0  1080P60 display stream 
      printf("HDMI test PASS\n");
  }
  else{
      printf("HDMI test FAIL\n");    
  }
}
