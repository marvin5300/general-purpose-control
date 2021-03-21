#include <spi.h>
#include <iostream>
#include <unistd.h>

int SPI::spiHandle = -1;
bool SPI::spiInitialised = false;
const unsigned SPI::spiFlags = 0xa01e1; // 0b0010100000000111100000;
// Raspi: Core clock speed of 250MHz can be devided by any even number from 2 to 65536
// => 3.814kHz to 125MHz
/*
 * spi_flags consists of the least significant 22 bits.

        21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
        b  b  b  b  b  b  R  T  n  n  n  n  W  A u2 u1 u0 p2 p1 p0  m  m
        0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        word size bits  msb msb only-3wire 3wire aux CEx?  activ-low? spi-mode
*/

extern "C" {
//#include <pigpiod_if2.h> // if you use pigpiod
#include <pigpio.h>
}

static bool SPI::initialise(unsigned baud_rate, unsigned word_size, unsigned spi_mode){
    if (spiInitialised){
        return true;
    }
    baudRate = baud_rate;
    //uint32_t spiMode = spi_mode;
    //spiMode = spiMode << 16;
    //spiMode |= 0xffff;
    //spiFlags &= 0xffff;
    // spiHandle = spi_open(pi, 2, baudRate, spiFlags); // if you use pigpiod
    spiHandle = spiOpen(2, baudRate, spiFlags);
    if (spiHandle<0){
        std::cout << "could not initialise spi bus" <<std::endl;
        switch (spiHandle){
        case PI_BAD_CHANNEL:
            std::cout << "DMA channel not 0-15" <<std::endl;
            break;
        case PI_BAD_SPI_SPEED:
            std::cout << "bad SPI speed" <<std::endl;
            break;
        case PI_BAD_FLAGS:
            std::cout << "bad spi open flags" <<std::endl;
            break;
        case PI_NO_AUX_SPI:
            std::cout << "no auxiliary SPI on Pi A or B" <<std::endl;
            break;
        case PI_SPI_OPEN_FAILED:
            std::cout << "can't open SPI device" <<std::endl;
            break;
        default:
            break;
        }
        return false;
    }
    spiInitialised = true;
    return true;
}

static bool SPI::writeSpi(std::string data){
    if(!spiInitialised){
        if(!initialise()){
            return false;
        }
    }
    char txBuf[data.size()];
    for (int i = 0; i < data.size(); i++){
        txBuf[i] = data[i];
    }
    /*std::cout << "trying to write: ";
    for (int i = 0; i < data.size()+1; i++){
        std::cout << hex << (uint8_t)txBuf[i];
    }*/
    char rxBuf[data.size()];
    //spi_xfer(pi, spiHandle, txBuf, rxBuf, bytesToRead+1)!=1+bytesToRead // if you use pigpiod
    if (spiXfer(spiHandle, txBuf, rxBuf, data.size())!=data.size()){
        std::cout << "wrong number of bytes transfered" <<std::endl;
        return false;
    }
    return true;
}

static std::string SPI::readSpi(std::string data_in, unsigned int bytesToRead, unsigned int readOffset){
    // sends data_in bytes (or datawords that contain more than 8 bit) and returns data
    // readOffset=0 means simultaneous read while writing. readOffset=data_in.size()-1 means
    // only read data returned after data_in was sent
    if(!spiInitialised){
        if(!initialise()){
            return "";
        }
    }
    //char buf[bytesToRead];
    //char chardata_in = data_in;
    //spi_write(pi, spiHandle, &chardata_in, 1);
    //spi_read(pi, spiHandle, buf, bytesToRead);

    char rxBuf[data_in.size() + bytesToRead];
    char txBuf[data_in.size() + bytesToRead];
    for (int i = 0; i < data_in.size(); i++){
        txBuf[i] = data_in[i];
    }
    for (int i = data_in.size(); i < data_in.size() + bytesToRead; i++){
        txBuf[i] = 0;
    }
    //spi_xfer(pi, spiHandle, txBuf, rxBuf, bytesToRead+1)!=1+bytesToRead // if you use pigpiod
    if (spiXfer(spiHandle, txBuf, rxBuf, data_in.size() + bytesToRead)!=data_in.size() + bytesToRead){
        std::cout << "wrong number of bytes transfered" <<std::endl;
        return "";
    }

    std::string data_out;
    for (int i = readOffset; i < data_in.size() + bytesToRead; i++){
        data_out += rxBuf[i];
    }
    return data_out;
}
