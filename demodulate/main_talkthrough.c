// Welch, Wright, & Morrow, 
// Real-time Digital Signal Processing, 2017
 
///////////////////////////////////////////////////////////////////////
// Filename: main.c
//
// Synopsis: Main program file for frame-based processing using EDMA
//
///////////////////////////////////////////////////////////////////////
#define fileout "C:\\ti\\workspace_v7\\demodulate\\file\\test.demodout"
#define filein "C:\\ti\\workspace_v7\\demodulate\\file\\test.demodin"

#include <ISRs_talkthrough.h>
#include "DSP_Config.h" 
#include <stdio.h>
#include "define.h"

//profiling
#include <stdint.h> // defines uint64_t
#include <c6x.h> // defines _itoll, TSCH, TSCL

#ifdef READFILE
static short frame[540];
#endif
int main()
{
#ifdef READFILE
    FILE *fin;
    fin = fopen(filein, "rb");
#endif

    // profiling
    uint64_t start_time, end_time, overhead, cyclecount;

    FILE *fout;
    fout = fopen(fileout, "wb");
    unsigned char *p;

	// initialize all buffers to 0
	ZeroBuffers();
	InitLEDs();
	// initialize EDMA controller 
	EDMA_Init();
	
	// initialize DSP for EDMA operation
  	DSP_Init_EDMA();
  	int i = 0;
	// call to StartUp not needed here

	// main loop here, process buffer when ready 
  	while(1)
  	{
        // In the initialization portion of the code:
        TSCL = 0; //enable TSC
        start_time = _itoll(TSCH, TSCL);
        end_time = _itoll(TSCH, TSCL);
        overhead = end_time-start_time; //Calculating the overhead of the method.
        // Code to be profiled
        start_time = _itoll(TSCH, TSCL);

        if(IsBufferReady())
        {   // process buffers in background
//            WriteDigitalOutputs(0);
#ifdef READFILE
            if(fread(buffin,sizeof(char),540,fin) < 540)break;
            printf("%d: %d\n",++i,frame[0]);
#endif
            p = ProcessBuffer();
            printf("%d: %d\n",++i,*p);
//            WriteDigitalOutputs(1);
            //fwrite(p,sizeof(unsigned char),12,fout);
        }

        //profiling
        end_time = _itoll(TSCH, TSCL);
        cyclecount = end_time-start_time-overhead;
        printf("The code section took: %lld CPU cycles\n", cyclecount);
  	}   
#ifdef READFILE
  	fclose(fin);
#endif
  	fclose(fout);
}


