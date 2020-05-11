#include "wifi_setup.h"
#include "matrix_display_helper.h"
#include <ESP32-RGB64x32MatrixPanel-I2S-DMA.h>

#include "pb.h"
#include "pb_decode.h"
#include "pb_encode.h"

#include "messagedata.pb.h"
#include "heaat_message.pb.h"

// Objects to deal with actual connection and mqtt stuff. 
WiFiClient client;

// MATRIX VARIABLES BEGIN //
RGB64x32MatrixPanel_I2S_DMA dma_display;
MatrixHelper matrix_helper; 
// MATRIX VARIABLES END //

// UDP handler. 
WiFiUDP udp; 

// UDP Array holding all relevant information
uint8_t udp_packet_buffer[8192];

void setup_matrix(void){
  dma_display.begin();
  // Will help us do animations. 
  matrix_helper.begin(&dma_display); 
}

void setup() {
  // Setting up low level libraries and wifi.  
  Serial.begin(115200);
  setup_matrix();
  setup_wifi();
  // Set up the udp interface. 
  udp.begin(4040);
}

void loop() {
  int packet_size = udp.parsePacket();
  if(packet_size){
    int len = udp.read(udp_packet_buffer, sizeof(udp_packet_buffer));
    if(len > 0){
      MessageData message_data;
      {
      uint8_t message_proto[16];
      for(int i = 0; i < 16; i++)
        message_proto[i] = udp_packet_buffer[i]; 
      pb_istream_t msg_in = pb_istream_from_buffer(message_proto, 16);
      pb_decode(&msg_in, MessageData_fields, &message_data);
      }

      switch(message_data.message_type){
        case(MessageData_MessageType_GENERAL_INSTRUCTIONS):
          break;
        
        case(MessageData_MessageType_LED_STRIP_DATA):
          break;
        
        case(MessageData_MessageType_HEAAT_CONTROL_DATA):
          break;

        case(MessageData_MessageType_MATRIX_DATA):{
            // Draw out the matrix data from the buffer. 
            for(uint8_t x = 0; x < 64; x++){
              for(uint8_t y = 0; y < 32; y++){
                // Trying to figure out which spot we should be in. 
                uint32_t spot = (y * 64 + x) * 3;
                dma_display.drawPixelRGB888(x, y, udp_packet_buffer[spot + 16], udp_packet_buffer[spot+17], udp_packet_buffer[spot+18]);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
  delay(10);
}
