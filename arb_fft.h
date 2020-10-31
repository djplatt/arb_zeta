#ifndef ARB_FFT
#define ARB_FFT
#include "inttypes.h"
#include "acb.h"

void initfft(unsigned int , acb_t *, int64_t);

/* perform an in place FFT */ 
void fft(acb_t *,unsigned int, acb_t *, int64_t); 

/* perform an in place inverse FFT */
void ifft(acb_t *,unsigned int , acb_t *, int64_t);

/* perform a non-normalised inverse FFT */
void nifft(acb_t *,unsigned int, acb_t *, int64_t);

/* circular convolution; f and g must be distinct */
void convolve(acb_t *, acb_t *, acb_t *, unsigned int, acb_t *, int64_t );

/* Do iDFT on a Hermitian vector of length 2N, i.e. one that produces real values */
/* N is the reduced length and the ws relate to that N */
/* ws[n]=e(n/N) for n=0..N/2-1 */
/* x is of length 2N with 0..N input values and (N+1..2N-1) anything */
/* omega=exp(2 pi I/2/N) */
/* on exit x[n]->re are set, x[n]->im are garbage. */
void hermidft(acb_t *, int, acb_t *, acb_ptr, int64_t);
#endif
