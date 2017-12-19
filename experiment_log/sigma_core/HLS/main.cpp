// Enforce you to
#include <hls_stream.h>
#include <ap_axi_sdata.h>

// Declare 32-bit integer with side-channel (Includes TLAST signal)
typedef ap_axis<32,2,5,6> intSdCh;
#define INTS_TO_PROCESS 10000

void doGain(hls::stream<intSdCh> &inStream,hls::stream<intSdCh> &outStream)
{
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream
//#pragma HLS INTERFACE s_axilite port=gain bundle=CRTL_BUS
//#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS

	intSdCh valIn[INTS_TO_PROCESS];
	int idx;
	// We need to indicate a size of this stream
	for (idx = 0; idx < (INTS_TO_PROCESS); idx++){
	#pragma HLS PIPELINE
		// Read and cache (Block here if FIFO sender is empty)
		valIn[idx] = inStream.read();
		intSdCh valOut;
	}

	int i, stage , temp;
	for (int stage = 0 ; stage < INTS_TO_PROCESS ; stage++){
	#pragma HLS UNROLL factor=2
 // stage is odd
		if (stage & 1){
			even: for(i=2; i<INTS_TO_PROCESS; i+=2){
			#pragma HLS PIPELINE
			//#pragma HLS UNROLL factor=10
				if (valIn[i].data < valIn[i-1].data){
					//Swap elements
					temp = valIn[i].data;
					valIn[i].data = valIn[i-1].data;
					valIn[i-1].data = temp;
				}
			}
		}
		else{
			odd: for(i=1; i<INTS_TO_PROCESS; i+=2){
			#pragma HLS PIPELINE
			//#pragma HLS UNROLL factor=10
				if (valIn[i].data < valIn[i-1].data){
					//Swap elements
					temp = valIn[i].data;
					valIn[i].data = valIn[i-1].data;
					valIn[i-1].data = temp;
				}
			}
		}
	}
	for (int idx = 0; idx < (INTS_TO_PROCESS); idx++){
	#pragma HLS PIPELINE
		outStream.write(valIn[idx]);
	}

}
