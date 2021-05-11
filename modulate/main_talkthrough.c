// Welch, Wright, & Morrow, 
// Real-time Digital Signal Processing, 2017
 
///////////////////////////////////////////////////////////////////////
// Filename: main.c
//
// Synopsis: Main program file for frame-based processing using EDMA
//
///////////////////////////////////////////////////////////////////////
#define filein "C:\\ti\\workspace_v7\\modulate\\file\\test.modin"
#define fileout "C:\\ti\\workspace_v7\\modulate\\file\\test.modout"

#include <ISRs_talkthrough.h>
#include "DSP_Config.h" 
#include <stdio.h>

//profiling
#include <stdint.h> // defines uint64_t
#include <c6x.h> // defines _itoll, TSCH, TSCL

#include "file\test.h"
//static Uint8 buffin[12];

int main()
{    
    // profiling
    uint64_t start_time, end_time, overhead, cyclecount;


    //varibale
    FILE *fin, *fout;
    fin = fopen(filein, "rb");
    fout = fopen(fileout, "wb");
    short *p;
    uint8_t *buffin = bufftest;

    //int i = 0;
	// initialize all buffers to 0
	ZeroBuffers();
	
	// initialize EDMA controller 
	EDMA_Init();
	InitLEDs();
	 WriteDigitalOutputs(1);
	// initialize DSP for EDMA operation
  	DSP_Init_EDMA();

	// call to StartUp not needed here

	// main loop here, process buffer when ready 
  	while(1) {
//  	    // In the initialization portion of the code:
//  	    TSCL = 0; //enable TSC
//  	    start_time = _itoll(TSCH, TSCL);
//  	    end_time = _itoll(TSCH, TSCL);
//  	    overhead = end_time-start_time; //Calculating the overhead of the method.
//  	    // Code to be profiled
//  	    start_time = _itoll(TSCH, TSCL);
        if(IsBufferReady())
        {
            // process buffers in background
            //WriteDigitalOutputs(1);
//            if(fread(buffin,sizeof(char),12,fin) < 12)
//                {
//                printf("end");
//                break;
//                }
            if (buffin > bufftest + BUFF_LEN)
            {
                printf("end"); break;
            }
            else
            {
                buffin += 12;
            }

            //printf("%d\n",buffin[0]);
            p = ProcessBuffer(buffin);
            //fwrite(p,sizeof(short),540,fout);
            //WriteDigitalOutputs(0);

        }
//        end_time = _itoll(TSCH, TSCL);
//        cyclecount = end_time-start_time-overhead;
//        printf("The code section took: %lld CPU cycles\n", cyclecount);
  	}   
  	fclose(fin);
  	fclose(fout);

  	//profiling

}


