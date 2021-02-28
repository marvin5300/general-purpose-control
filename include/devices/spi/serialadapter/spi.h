#ifndef SPI_H
#define SPI_H

#include <string>

class SPI
{
public:
    static bool initialise(unsigned baud_rate = 32000, unsigned word_size = 10, unsigned spi_mode = 1);
    static bool writeSpi(std::string data);
    static std::string readSpi(std::string data_in, unsigned int bytesToRead = 0, unsigned int readOffset = 0);
private:
    static int spiHandle;
    static bool spiInitialised;
    static const unsigned baudRate;
    static const unsigned spiFlags;
};

#endif // SPI_H
