#define mod8k           // IF NOT DEFINE, THE SAMPLING RATE OF MODULATOR IS 48KHz
#define demod8k          // IF NOT DEFINE, THE SAMPLING RATE OF DEMODULATOR IS 48KHz

int Modulate(unsigned char* data, short* frame);
int Demodulate( short* frame, unsigned char* data);



