/** @file
 *	@brief MAVLink comm protocol testsuite generated from Lattepanda_shiled.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef LATTEPANDA_SHILED_TESTSUITE_H
#define LATTEPANDA_SHILED_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_Lattepanda_shiled(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_Lattepanda_shiled(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_measuring_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MEASURING_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_measuring_data_t packet_in = {
		17.0,45.0,73.0,101.0,129.0,157.0,18483,18587,89,156
    };
	mavlink_measuring_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Reg = packet_in.Reg;
        packet1.Cap = packet_in.Cap;
        packet1.Ind = packet_in.Ind;
        packet1.TC = packet_in.TC;
        packet1.kelvin_mV = packet_in.kelvin_mV;
        packet1.TC_mV = packet_in.TC_mV;
        packet1.ADC_ch1 = packet_in.ADC_ch1;
        packet1.ADC_ch2 = packet_in.ADC_ch2;
        packet1.DI = packet_in.DI;
        packet1.Set_Status = packet_in.Set_Status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_measuring_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_data_pack(system_id, component_id, &msg , packet1.Reg , packet1.Cap , packet1.Ind , packet1.TC , packet1.kelvin_mV , packet1.TC_mV , packet1.ADC_ch1 , packet1.ADC_ch2 , packet1.DI , packet1.Set_Status );
	mavlink_msg_measuring_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Reg , packet1.Cap , packet1.Ind , packet1.TC , packet1.kelvin_mV , packet1.TC_mV , packet1.ADC_ch1 , packet1.ADC_ch2 , packet1.DI , packet1.Set_Status );
	mavlink_msg_measuring_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_measuring_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_data_send(MAVLINK_COMM_1 , packet1.Reg , packet1.Cap , packet1.Ind , packet1.TC , packet1.kelvin_mV , packet1.TC_mV , packet1.ADC_ch1 , packet1.ADC_ch2 , packet1.DI , packet1.Set_Status );
	mavlink_msg_measuring_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dac_setting_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DAC_SETTING_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_dac_setting_data_t packet_in = {
		17235,17339
    };
	mavlink_dac_setting_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.DAC_ch1 = packet_in.DAC_ch1;
        packet1.DAC_ch2 = packet_in.DAC_ch2;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_setting_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_dac_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_setting_data_pack(system_id, component_id, &msg , packet1.DAC_ch1 , packet1.DAC_ch2 );
	mavlink_msg_dac_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_setting_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.DAC_ch1 , packet1.DAC_ch2 );
	mavlink_msg_dac_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_dac_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_setting_data_send(MAVLINK_COMM_1 , packet1.DAC_ch1 , packet1.DAC_ch2 );
	mavlink_msg_dac_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_digital_out_setting_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_digital_out_setting_data_t packet_in = {
		17.0,45.0,29
    };
	mavlink_digital_out_setting_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.L_Side_Freq = packet_in.L_Side_Freq;
        packet1.L_Side_Duty = packet_in.L_Side_Duty;
        packet1.DO = packet_in.DO;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_digital_out_setting_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_digital_out_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_digital_out_setting_data_pack(system_id, component_id, &msg , packet1.L_Side_Freq , packet1.L_Side_Duty , packet1.DO );
	mavlink_msg_digital_out_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_digital_out_setting_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.L_Side_Freq , packet1.L_Side_Duty , packet1.DO );
	mavlink_msg_digital_out_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_digital_out_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_digital_out_setting_data_send(MAVLINK_COMM_1 , packet1.L_Side_Freq , packet1.L_Side_Duty , packet1.DO );
	mavlink_msg_digital_out_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_measuring_setting(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MEASURING_SETTING >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_measuring_setting_t packet_in = {
		{ 5, 6, 7, 8, 9, 10 },151,218,29,96
    };
	mavlink_measuring_setting_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Kelvin_mode_set = packet_in.Kelvin_mode_set;
        packet1.Kelvin_Range = packet_in.Kelvin_Range;
        packet1.LC_mode_set = packet_in.LC_mode_set;
        packet1.L_C_Range = packet_in.L_C_Range;
        
        mav_array_memcpy(packet1.Display_speed, packet_in.Display_speed, sizeof(uint8_t)*6);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_setting_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_measuring_setting_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_setting_pack(system_id, component_id, &msg , packet1.Display_speed , packet1.Kelvin_mode_set , packet1.Kelvin_Range , packet1.LC_mode_set , packet1.L_C_Range );
	mavlink_msg_measuring_setting_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_setting_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Display_speed , packet1.Kelvin_mode_set , packet1.Kelvin_Range , packet1.LC_mode_set , packet1.L_C_Range );
	mavlink_msg_measuring_setting_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_measuring_setting_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_measuring_setting_send(MAVLINK_COMM_1 , packet1.Display_speed , packet1.Kelvin_mode_set , packet1.Kelvin_Range , packet1.LC_mode_set , packet1.L_C_Range );
	mavlink_msg_measuring_setting_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_can_bus_config_setting_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_can_bus_config_setting_data_t packet_in = {
		963497464,17,84
    };
	mavlink_can_bus_config_setting_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Base_ID = packet_in.Base_ID;
        packet1.Baud = packet_in.Baud;
        packet1.Protocol_set = packet_in.Protocol_set;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_can_bus_config_setting_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_can_bus_config_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_can_bus_config_setting_data_pack(system_id, component_id, &msg , packet1.Base_ID , packet1.Baud , packet1.Protocol_set );
	mavlink_msg_can_bus_config_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_can_bus_config_setting_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Base_ID , packet1.Baud , packet1.Protocol_set );
	mavlink_msg_can_bus_config_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_can_bus_config_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_can_bus_config_setting_data_send(MAVLINK_COMM_1 , packet1.Base_ID , packet1.Baud , packet1.Protocol_set );
	mavlink_msg_can_bus_config_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_system_config_setting_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SYSTEM_CONFIG_SETTING_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_system_config_setting_data_t packet_in = {
		5
    };
	mavlink_system_config_setting_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sys_id = packet_in.sys_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SYSTEM_CONFIG_SETTING_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SYSTEM_CONFIG_SETTING_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_config_setting_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_system_config_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_config_setting_data_pack(system_id, component_id, &msg , packet1.sys_id );
	mavlink_msg_system_config_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_config_setting_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.sys_id );
	mavlink_msg_system_config_setting_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_system_config_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_config_setting_data_send(MAVLINK_COMM_1 , packet1.sys_id );
	mavlink_msg_system_config_setting_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_receive_can_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RECEIVE_CAN_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_receive_can_data_t packet_in = {
		963497464,{ 17, 18, 19, 20, 21, 22, 23, 24 },41
    };
	mavlink_receive_can_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.CAN_ID = packet_in.CAN_ID;
        packet1.CAN_RTR = packet_in.CAN_RTR;
        
        mav_array_memcpy(packet1.CAN_Data, packet_in.CAN_Data, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RECEIVE_CAN_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RECEIVE_CAN_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receive_can_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_receive_can_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receive_can_data_pack(system_id, component_id, &msg , packet1.CAN_ID , packet1.CAN_Data , packet1.CAN_RTR );
	mavlink_msg_receive_can_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receive_can_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.CAN_ID , packet1.CAN_Data , packet1.CAN_RTR );
	mavlink_msg_receive_can_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_receive_can_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_receive_can_data_send(MAVLINK_COMM_1 , packet1.CAN_ID , packet1.CAN_Data , packet1.CAN_RTR );
	mavlink_msg_receive_can_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_transmit_can_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TRANSMIT_CAN_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_transmit_can_data_t packet_in = {
		963497464,{ 17, 18, 19, 20, 21, 22, 23, 24 },41
    };
	mavlink_transmit_can_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.CAN_ID = packet_in.CAN_ID;
        packet1.CAN_RTR = packet_in.CAN_RTR;
        
        mav_array_memcpy(packet1.CAN_Data, packet_in.CAN_Data, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_transmit_can_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_transmit_can_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_transmit_can_data_pack(system_id, component_id, &msg , packet1.CAN_ID , packet1.CAN_Data , packet1.CAN_RTR );
	mavlink_msg_transmit_can_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_transmit_can_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.CAN_ID , packet1.CAN_Data , packet1.CAN_RTR );
	mavlink_msg_transmit_can_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_transmit_can_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_transmit_can_data_send(MAVLINK_COMM_1 , packet1.CAN_ID , packet1.CAN_Data , packet1.CAN_RTR );
	mavlink_msg_transmit_can_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_real_time_clock_set(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_real_time_clock_set_t packet_in = {
		963497464,17443,151,218,29,96,163,230,41,108
    };
	mavlink_real_time_clock_set_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.subsec = packet_in.subsec;
        packet1.year = packet_in.year;
        packet1.month = packet_in.month;
        packet1.mday = packet_in.mday;
        packet1.wday = packet_in.wday;
        packet1.hour = packet_in.hour;
        packet1.min = packet_in.min;
        packet1.sec = packet_in.sec;
        packet1.timeFormat = packet_in.timeFormat;
        packet1.DayLightSaving = packet_in.DayLightSaving;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_real_time_clock_set_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_real_time_clock_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_real_time_clock_set_pack(system_id, component_id, &msg , packet1.subsec , packet1.year , packet1.month , packet1.mday , packet1.wday , packet1.hour , packet1.min , packet1.sec , packet1.timeFormat , packet1.DayLightSaving );
	mavlink_msg_real_time_clock_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_real_time_clock_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.subsec , packet1.year , packet1.month , packet1.mday , packet1.wday , packet1.hour , packet1.min , packet1.sec , packet1.timeFormat , packet1.DayLightSaving );
	mavlink_msg_real_time_clock_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_real_time_clock_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_real_time_clock_set_send(MAVLINK_COMM_1 , packet1.subsec , packet1.year , packet1.month , packet1.mday , packet1.wday , packet1.hour , packet1.min , packet1.sec , packet1.timeFormat , packet1.DayLightSaving );
	mavlink_msg_real_time_clock_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_alarm_set_a(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ALARM_SET_A >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_alarm_set_a_t packet_in = {
		5,72,139,206,17,84,151,218,29
    };
	mavlink_alarm_set_a_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.AL_Mask_week = packet_in.AL_Mask_week;
        packet1.AL_Mask_hour = packet_in.AL_Mask_hour;
        packet1.AL_Mask_min = packet_in.AL_Mask_min;
        packet1.AL_Mask_sec = packet_in.AL_Mask_sec;
        packet1.AL_date_week_day_sel = packet_in.AL_date_week_day_sel;
        packet1.AL_date = packet_in.AL_date;
        packet1.AL_hour = packet_in.AL_hour;
        packet1.AL_min = packet_in.AL_min;
        packet1.AL_sec = packet_in.AL_sec;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_alarm_set_a_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_alarm_set_a_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_alarm_set_a_pack(system_id, component_id, &msg , packet1.AL_Mask_week , packet1.AL_Mask_hour , packet1.AL_Mask_min , packet1.AL_Mask_sec , packet1.AL_date_week_day_sel , packet1.AL_date , packet1.AL_hour , packet1.AL_min , packet1.AL_sec );
	mavlink_msg_alarm_set_a_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_alarm_set_a_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.AL_Mask_week , packet1.AL_Mask_hour , packet1.AL_Mask_min , packet1.AL_Mask_sec , packet1.AL_date_week_day_sel , packet1.AL_date , packet1.AL_hour , packet1.AL_min , packet1.AL_sec );
	mavlink_msg_alarm_set_a_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_alarm_set_a_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_alarm_set_a_send(MAVLINK_COMM_1 , packet1.AL_Mask_week , packet1.AL_Mask_hour , packet1.AL_Mask_min , packet1.AL_Mask_sec , packet1.AL_date_week_day_sel , packet1.AL_date , packet1.AL_hour , packet1.AL_min , packet1.AL_sec );
	mavlink_msg_alarm_set_a_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_adc_calibration_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ADC_CALIBRATION_Data >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_adc_calibration_data_t packet_in = {
		{ 17.0, 18.0 },{ 73.0, 74.0 },129.0,157.0
    };
	mavlink_adc_calibration_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Vref_ADC_mV = packet_in.Vref_ADC_mV;
        packet1.Vref_SDADC_mV = packet_in.Vref_SDADC_mV;
        
        mav_array_memcpy(packet1.Gain_ADC, packet_in.Gain_ADC, sizeof(float)*2);
        mav_array_memcpy(packet1.Offset_ADC_mV, packet_in.Offset_ADC_mV, sizeof(float)*2);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_calibration_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_adc_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_calibration_data_pack(system_id, component_id, &msg , packet1.Gain_ADC , packet1.Offset_ADC_mV , packet1.Vref_ADC_mV , packet1.Vref_SDADC_mV );
	mavlink_msg_adc_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_calibration_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Gain_ADC , packet1.Offset_ADC_mV , packet1.Vref_ADC_mV , packet1.Vref_SDADC_mV );
	mavlink_msg_adc_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_adc_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_calibration_data_send(MAVLINK_COMM_1 , packet1.Gain_ADC , packet1.Offset_ADC_mV , packet1.Vref_ADC_mV , packet1.Vref_SDADC_mV );
	mavlink_msg_adc_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tc_calibration_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TC_CALIBRATION_Data >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_tc_calibration_data_t packet_in = {
		17.0,45.0,73.0,101.0,129.0,{ 18275, 18276, 18277, 18278, 18279, 18280, 18281, 18282, 18283, 18284, 18285, 18286 }
    };
	mavlink_tc_calibration_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Gain_TCV = packet_in.Gain_TCV;
        packet1.Offset_mV_TCV = packet_in.Offset_mV_TCV;
        packet1.Gain_TC_degC = packet_in.Gain_TC_degC;
        packet1.Offset_TC_degC = packet_in.Offset_TC_degC;
        packet1.Vref_mV_TC = packet_in.Vref_mV_TC;
        
        mav_array_memcpy(packet1.Table_degC, packet_in.Table_degC, sizeof(int16_t)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tc_calibration_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_tc_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tc_calibration_data_pack(system_id, component_id, &msg , packet1.Gain_TCV , packet1.Offset_mV_TCV , packet1.Gain_TC_degC , packet1.Offset_TC_degC , packet1.Vref_mV_TC , packet1.Table_degC );
	mavlink_msg_tc_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tc_calibration_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Gain_TCV , packet1.Offset_mV_TCV , packet1.Gain_TC_degC , packet1.Offset_TC_degC , packet1.Vref_mV_TC , packet1.Table_degC );
	mavlink_msg_tc_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_tc_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tc_calibration_data_send(MAVLINK_COMM_1 , packet1.Gain_TCV , packet1.Offset_mV_TCV , packet1.Gain_TC_degC , packet1.Offset_TC_degC , packet1.Vref_mV_TC , packet1.Table_degC );
	mavlink_msg_tc_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_kelvin_calibration_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_kelvin_calibration_data_t packet_in = {
		{ 17.0, 18.0 },{ 73.0, 74.0 }
    };
	mavlink_kelvin_calibration_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.Gain_Kelvin, packet_in.Gain_Kelvin, sizeof(float)*2);
        mav_array_memcpy(packet1.Offset_Kelvin, packet_in.Offset_Kelvin, sizeof(float)*2);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_kelvin_calibration_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_kelvin_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_kelvin_calibration_data_pack(system_id, component_id, &msg , packet1.Gain_Kelvin , packet1.Offset_Kelvin );
	mavlink_msg_kelvin_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_kelvin_calibration_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Gain_Kelvin , packet1.Offset_Kelvin );
	mavlink_msg_kelvin_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_kelvin_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_kelvin_calibration_data_send(MAVLINK_COMM_1 , packet1.Gain_Kelvin , packet1.Offset_Kelvin );
	mavlink_msg_kelvin_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dac_calibration_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DAC_CALIBRATION_Data >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_dac_calibration_data_t packet_in = {
		{ 17.0, 18.0 },{ 73.0, 74.0 }
    };
	mavlink_dac_calibration_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.Gain_DAC, packet_in.Gain_DAC, sizeof(float)*2);
        mav_array_memcpy(packet1.Offset_DAC, packet_in.Offset_DAC, sizeof(float)*2);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_calibration_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_dac_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_calibration_data_pack(system_id, component_id, &msg , packet1.Gain_DAC , packet1.Offset_DAC );
	mavlink_msg_dac_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_calibration_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Gain_DAC , packet1.Offset_DAC );
	mavlink_msg_dac_calibration_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_dac_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dac_calibration_data_send(MAVLINK_COMM_1 , packet1.Gain_DAC , packet1.Offset_DAC );
	mavlink_msg_dac_calibration_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_system_control_set(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SYSTEM_CONTROL_SET >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_system_control_set_t packet_in = {
		5,72,139
    };
	mavlink_system_control_set_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.save_config = packet_in.save_config;
        packet1.Reboot = packet_in.Reboot;
        packet1.default_set = packet_in.default_set;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_control_set_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_system_control_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_control_set_pack(system_id, component_id, &msg , packet1.save_config , packet1.Reboot , packet1.default_set );
	mavlink_msg_system_control_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_control_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.save_config , packet1.Reboot , packet1.default_set );
	mavlink_msg_system_control_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_system_control_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_system_control_set_send(MAVLINK_COMM_1 , packet1.save_config , packet1.Reboot , packet1.default_set );
	mavlink_msg_system_control_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_Lattepanda_shiled(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_measuring_data(system_id, component_id, last_msg);
	mavlink_test_dac_setting_data(system_id, component_id, last_msg);
	mavlink_test_digital_out_setting_data(system_id, component_id, last_msg);
	mavlink_test_measuring_setting(system_id, component_id, last_msg);
	mavlink_test_can_bus_config_setting_data(system_id, component_id, last_msg);
	mavlink_test_system_config_setting_data(system_id, component_id, last_msg);
	mavlink_test_receive_can_data(system_id, component_id, last_msg);
	mavlink_test_transmit_can_data(system_id, component_id, last_msg);
	mavlink_test_real_time_clock_set(system_id, component_id, last_msg);
	mavlink_test_alarm_set_a(system_id, component_id, last_msg);
	mavlink_test_adc_calibration_data(system_id, component_id, last_msg);
	mavlink_test_tc_calibration_data(system_id, component_id, last_msg);
	mavlink_test_kelvin_calibration_data(system_id, component_id, last_msg);
	mavlink_test_dac_calibration_data(system_id, component_id, last_msg);
	mavlink_test_system_control_set(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // LATTEPANDA_SHILED_TESTSUITE_H
