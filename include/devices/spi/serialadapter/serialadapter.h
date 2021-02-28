#ifndef SERIALADAPTER_H
#define SERIALADAPTER_H

#include <cstdint>
#include <vector>

class SerialAdapter
{
public:
    SerialAdapter(unsigned baud_rate = 0);
    uint32_t read32bit(uint8_t address);
    std::vector<uint32_t> read32bit(std::vector<uint8_t> &address);
    uint16_t read16bit(uint8_t address);
    std::vector<uint16_t> read16bit(std::vector<uint8_t> &address);
    uint8_t read8bit(uint8_t address);
    std::vector<uint8_t> read8bit(std::vector<uint8_t> &address);
    bool write32bit(uint8_t address, uint32_t data);
    bool write32bit(std::vector<uint8_t> &address, std::vector<uint32_t> &data);
    bool write16bit(uint8_t address, uint16_t data);
    bool write16bit(std::vector<uint8_t> &address, std::vector<uint16_t> &data);
    bool write8bit(uint8_t address, uint8_t data);
    bool write8bit(std::vector<uint8_t> &address, std::vector<uint8_t> &data);
    uint32_t read_versionregister();
    std::vector<uint8_t> init_Asic(unsigned number_of_chips = 1);
    uint8_t read_i2c_general_config();
    void write_i2c_address_register(uint16_t data);
    uint16_t read_i2c_address_register();
    void write_i2c_data_count(uint8_t data);
    uint8_t read_i2c_data_count();
    void write_i2c_bit_rate(uint8_t data);
    uint8_t read_i2c_bit_rate();
    uint8_t read_i2c_data_memory(uint8_t address);
    void write_i2c_data_memory(uint8_t address, uint8_t data);
    void write_dac(uint8_t channel_number, uint16_t value);
    uint16_t read_dac(uint8_t channel_number);
    uint8_t read_apfel_clk();
    void set_apfel_clk(uint8_t interface_mode_reg);
    uint32_t read_apfel_interface_data();
    void write_apfel_interface_data(uint32_t data);
    uint16_t read_hamming();
    void write_io_conf(uint8_t conf);
    uint8_t read_io_conf();
    void write_io_data(uint8_t conf);
    uint8_t read_io_data();
};

#endif // SERIALADAPTER_H
