#include <serialadapter.h>
#include <spi.h>
#include <iostream>
#include <unistd.h>
#include <vector>

SerialAdapter::SerialAdapter(unsigned baud_rate)
{
    if (baud_rate!=0){
        SPI::initialise(baud_rate);
    }else{
        SPI::initialise();
    }
    init_Asic();
    usleep(2000);
}

uint32_t SerialAdapter::read32bit(uint8_t address){
    std::string data_out = "";
    data_out += (char)0x0e;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)address;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)0x00;
    data_out += (char)0x01;
    std::string data_in = "";
    for (int i = 0; i < 5; i++){
        data_in += SPI::readSpi(data_out,0,0);
    }
    uint32_t data = 0;
    for (unsigned i = 0; i < data_in.size(); i = i+2){
        data = data << 8;
        data |= (uint32_t)data_in[i];
    }
    return data;
}

std::vector<uint32_t> SerialAdapter::read32bit(std::vector<uint8_t> &address){
    // address.size() is number of serial adapter asics in the daisy chain
    std::string data_out = "";
    for (unsigned i = 0; i < address.size(); i++){
        data_out += (char)0x0e;
        data_out += (char)0x01;
    }
    SPI::writeSpi(data_out);
    data_out = "";
    for (unsigned i = 0; i < address.size(); i++){
        data_out += (char)address[i];
        data_out += (char)0x01;
    }
    SPI::writeSpi(data_out);
    data_out = "";
    for (unsigned i = 0; i < address.size(); i++){
        data_out += (char)0x00;
        data_out += (char)0x01;
    }
    std::string data_in = "";
    for (unsigned i = 0; i < 5; i++){
        data_in += SPI::readSpi(data_out,0,0);
    }
    std::string data_string = "";
    printf("debug output: ");
    for (unsigned i = 0; i < data_in.size(); i = i+2){
        // filter out all lsbytes, they don't contain valuable data (for now it should contain 0x10)
        data_string += data_in[i];
        printf("0x%x ",(uint8_t)data_in[i]);
    }
    printf("\n");
    uint32_t data = 0;
    std::vector<uint32_t> return_values;
    for (unsigned i = 0; i < data_string.size(); i++){
        if (i%5 != 0){
            data = data << 8;
            data |= (uint32_t)data_string[i];
        }
        if (i%5 == 4){
            return_values.push_back(data);
            data = 0;
        }
    }
    return return_values;
}

uint16_t SerialAdapter::read16bit(uint8_t address){
    std::string data_out = "";
    data_out += (char)0x0c;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)address;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)0x00;
    data_out += (char)0x01;
    std::string data_in = "";
    for (unsigned i = 0; i < 3; i++){
        data_in += SPI::readSpi(data_out,0,0);
    }
    uint16_t data = 0;
    for (unsigned i = 0; i < data_in.size(); i = i+2){
        data = data << 8;
        data |= (uint16_t)data_in[i];
    }
    return data;
}

std::vector<uint16_t> SerialAdapter::read16bit(std::vector<uint8_t> &address){
    std::vector<uint16_t> val;
    return val;
}

uint8_t SerialAdapter::read8bit(uint8_t address){
    std::string data_out = "";
    data_out += (char)0x0a;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)address;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)0x00;
    data_out += (char)0x01;
    std::string data_in = "";

    data_in += SPI::readSpi(data_out,0,0);

    uint8_t data = 0;
    data |= (uint8_t)data_in[0];
    return data;
}

std::vector<uint8_t> SerialAdapter::read8bit(std::vector<uint8_t> &address){
    std::vector<uint8_t> val;
    return val;
}

bool SerialAdapter::write32bit(uint8_t address, uint32_t data){
    // initialise asic, this means send 6 10bit words -> 12 8bit chars lsbyte first
    uint8_t buffer[4];
    buffer[3]= data & 0xff;
    buffer[2]=(data>>8);
    buffer[1]=(data>>16);
    buffer[0]=(data>>24);

    std::string data_string ="";
    data_string += (char)0x0f;
    data_string += (char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string += (char)address;
    data_string += (char)0x01;
    SPI::writeSpi(data_string);
    for(int i = 0; i < 4; i++){
        data_string = "";
        data_string +=(char)buffer[i];
        data_string +=(char)0x01;
        SPI::writeSpi(data_string);
    }

    return true;
}

bool SerialAdapter::write32bit(std::vector<uint8_t> &address, std::vector<uint32_t> &data){
    return true;
}

bool SerialAdapter::write16bit(uint8_t address, uint16_t data){
    // initialise asic, this means send 6 10bit words -> 12 8bit chars lsbyte first
    uint8_t buffer[2];
    buffer[0]= data & 0xff;
    buffer[1]=(data>>8);

    std::string data_string ="";
    data_string += (char)0x0d;
    data_string += (char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string += (char)address;
    data_string += (char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string +=(char)buffer[0];
    data_string +=(char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string +=(char)buffer[1];
    data_string +=(char)0x01;
    SPI::writeSpi(data_string);
    //data_string = "";
    //data_string +=(char)0x00;
    //data_string +=(char)0x00;
    SPI::writeSpi(data_string);
    return true;
}

bool SerialAdapter::write16bit(std::vector<uint8_t> &address, std::vector<uint16_t> &data){
    return true;
}

bool SerialAdapter::write8bit(uint8_t address,uint8_t data){
    // initialise asic, this means send 6 10bit words -> 12 8bit chars lsbyte first
    std::string data_string ="";
    data_string += (char)0x0b;
    data_string += (char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string += (char)address;
    data_string += (char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string +=(char)data;
    data_string +=(char)0x01;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string +=(char)0x00;
    data_string +=(char)0x00;
    SPI::writeSpi(data_string);
    data_string = "";
    data_string +=(char)0x00;
    data_string +=(char)0x00;
    SPI::writeSpi(data_string);
    return true;
}

bool SerialAdapter::write8bit(std::vector<uint8_t> &address, std::vector<uint8_t> &data){
    return true;
}

std::vector<uint8_t> SerialAdapter::init_Asic(unsigned number_of_chips){
    // initialise asic, this means send 6 10bit words -> 12 8bit chars lsbyte first
    std::string init_string ="";
    for (unsigned i = 0; i < number_of_chips; i++){
        init_string += (char)0x10;
        init_string += (char)0x01;
    }
    SPI::writeSpi(init_string);
    init_string = "";
    for (unsigned i = 0; i < number_of_chips; i++){
        init_string += (char)0x00;
        init_string += (char)0x01;
    }
    SPI::writeSpi(init_string);
    init_string = "";
    for (unsigned i = 0; i < number_of_chips; i++){
        init_string +=(char)0x00;
        init_string +=(char)0x00;
    }
    std::string data_in = "";
    for (unsigned i = 0; i < number_of_chips; i++){
        data_in += SPI::readSpi(init_string,0,0);
    }
    std::vector<uint8_t> response_codes;
    printf("response codes: ");
    for (unsigned i = 0; i < data_in.size(); i = i+2){
        response_codes.push_back((uint8_t)data_in[i]);
        printf("0x%x ",data_in[i]);
    }
    printf("\n");
    for (int i = 0; i < 2; i++){
        SPI::writeSpi(init_string);
    }
    return response_codes;
}

uint32_t SerialAdapter::read_versionregister(){
    return read32bit(0xff);
}
/*uint32_t SerialAdapter::read_versionregister(){
    std::string data_out = "";
    data_out += (char)0x0e;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)0xff;
    data_out += (char)0x01;
    SPI::writeSpi(data_out);
    data_out = "";
    data_out += (char)0x00;
    data_out += (char)0x01;
    std::string data_in = "";
    for (int i = 0; i < 5; i++){
        data_in += SPI::readSpi(data_out,0,0);
    }
    uint32_t version = 0;
    for (int i = 0; i < data_in.size(); i = i+2){
        version = version << 8;
        version |= (uint32_t)data_in[i];
    }
    return version;
}
*/
uint8_t SerialAdapter::read_i2c_general_config(){
    return read8bit(0x00);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_i2c_address_register(uint16_t data){
    write16bit(0x01,data);
}
//////////////////////////////////////////////////////////////////////////////////////
uint16_t SerialAdapter::read_i2c_address_register(){
    return read16bit(0x01);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_i2c_data_count(uint8_t data){
    write8bit(0x02,data);
}
//////////////////////////////////////////////////////////////////////////////////////
uint8_t SerialAdapter::read_i2c_data_count(){
    return read8bit(0x02);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_i2c_bit_rate(uint8_t data){
    write8bit(0x03,data);
}
/*
* f_bit=125MBit/s /(2*(2+16rate))
*/
//////////////////////////////////////////////////////////////////////////////////////
uint8_t SerialAdapter::read_i2c_bit_rate(){
    return read8bit(0x03);
}
//////////////////////////////////////////////////////////////////////////////////////
uint8_t SerialAdapter::read_i2c_data_memory(uint8_t address){
    if(address>0x23 | address<0x04){
        printf("Not a i2c wishbone address. \n");
        return 0xff;
    }
    return 	read8bit(address);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_i2c_data_memory(uint8_t address,uint8_t data){
    if(address>0x23 | address<0x04)
    {printf("Not a i2c wishbone address. \n"); return;}
    write8bit(address,data);
}
//////////////////////////////////////////////////////////////////////////////////////
// End I2C part //
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_dac(uint8_t channel_number,uint16_t value){
    channel_number=channel_number+0x40;
    /*
    uint8_t channel=0x40;
    if(channel_number==0){channel=0x40;}
    else if(channel_number==1){channel=0x41;}
    else if(channel_number==2){channel=0x42;}
    else if(channel_number==3){channel=0x43;}
    else if(channel_number==4){channel=0x44;}
    else if(channel_number==5){channel=0x45;}
    else if(channel_number==6){channel=0x46;}
    else if(channel_number==7){channel=0x47;}
    else if(channel_number<0||channel_number>7){return;}
    */
    write16bit(channel_number,value);
}
//////////////////////////////////////////////////////////////////////////////////////
uint16_t SerialAdapter::read_dac(uint8_t channel_number){
    channel_number=channel_number+0x40;
    /*Debugstuff
     * uint8_t channel=0x40;
     * if(channel_number==0){channel=0x40;}
    else if(channel_number==1){channel=0x41;}
    else if(channel_number==2){channel=0x42;}
    else if(channel_number==3){channel=0x43;}
    else if(channel_number==4){channel=0x44;}
    else if(channel_number==5){channel=0x45;}
    else if(channel_number==6){channel=0x46;}
    else if(channel_number==7){channel=0x47;}
    */
    return 	read16bit(channel_number);
}
//////////////////////////////////////////////////////////////////////////////////////
uint8_t SerialAdapter::read_apfel_clk(){
    return read8bit(0x48);
}
//////////////////////////////////////////////////////////////////////////////////////
//maybe use modulo
void SerialAdapter::set_apfel_clk(uint8_t interface_mode_reg){
    uint8_t reg_entry=interface_mode_reg;
    if(interface_mode_reg==0||interface_mode_reg==8){
        printf("datarate will be set to 244kBit/s");}
    else if(interface_mode_reg==1||interface_mode_reg==9){
        printf("datarate will be set to 490kBit/s");}
    else if(interface_mode_reg==2||interface_mode_reg==10){
        printf("datarate will be set to 980kBit/s");}
    else if(interface_mode_reg==3||interface_mode_reg==11){
        printf("datarate will be set to 1900kBit/s");}
    else if(interface_mode_reg==4||interface_mode_reg==12){
        printf("datarate will be set to 3900kBit/s");}
    else if(interface_mode_reg==5||interface_mode_reg==13){
        printf("datarate will be set to 7800kBit/s");}
    else if(interface_mode_reg==6||interface_mode_reg==14){
        printf("datarate will be set to 15600KBit/s");}
    else if(interface_mode_reg==7||interface_mode_reg==15){
        printf("datarate will be set to 31300kBit/s");}
    else{
        printf("wrong dataratesetting \n");
        printf("datarate will be set to default (244kBit/s)");
        reg_entry=0x00;
    }
    write8bit(0x48,reg_entry);
}
//////////////////////////////////////////////////////////////////////////////////////
uint32_t SerialAdapter::read_apfel_interface_data(){
    return read32bit(0x49);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_apfel_interface_data(uint32_t data){
    write32bit(0x49,data);
}
//////////////////////////////////////////////////////////////////////////////////////
uint16_t SerialAdapter::read_hamming(){
    return read16bit(0x4a);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_io_conf(uint8_t conf){
    write8bit(0x4c,conf);
}
//////////////////////////////////////////////////////////////////////////////////////
uint8_t SerialAdapter::read_io_conf(){
    return read8bit(0x4c);
}
//////////////////////////////////////////////////////////////////////////////////////
void SerialAdapter::write_io_data(uint8_t conf){
    write8bit(0x4d,conf);
}
//////////////////////////////////////////////////////////////////////////////////////
uint8_t SerialAdapter::read_io_data(){
    return read8bit(0x4d);
}
