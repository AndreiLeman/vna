#ifndef __XAVNA_H
#define __XAVNA_H
extern "C" {
	// dev: path to the serial device
	// returns: handle to the opened device, or NULL if failed; check errno
	void* xavna_open(const char* dev);
	
	// Returns true if dev is a T/R VNA, otherwise false
	bool xavna_is_tr(void* dev);

	// Set the RF frequency and attenuation.
	// freq_khz: frequency in kHz
	// atten: attenuation in dB (positive integer) of signal generator
	// port: which port to output the signal on
	// returns: 0 if success; -1 if failure
	int xavna_set_params(void* dev, int freq_khz, int atten, int port);

	// read vector values from device; applicable for T/R VNA only
	// out_values: array of size 4 holding the following values (in order):
	//				reflection real, reflection imag,
	//				thru real, thru imag
	// n_samples: number of samples to average over; typical 50
	// returns: number of samples read, or -1 if failure
	int xavna_read_values(void* dev, double* out_values, int n_samples);
	
	// read vector values from device; applicable for both T/R and full two port
	// out_values: array of size 8 holding the following values (in order):
	//				port 1 out real, port 1 out imag,
	//				port 1 in real, port 1 in imag
	//				port 2 out real, port 2 out imag,
	//				port 2 in real, port 2 in imag
	// n_samples: number of samples to average over; typical 50
	// returns: number of samples read, or -1 if failure
	int xavna_read_values_raw(void* dev, double* out_values, int n_samples);

	// close device handle
	void xavna_close(void* dev);
}
#endif
