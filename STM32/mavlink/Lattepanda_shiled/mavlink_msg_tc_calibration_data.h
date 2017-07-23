// MESSAGE TC_CALIBRATION_Data PACKING

#define MAVLINK_MSG_ID_TC_CALIBRATION_Data 221

MAVPACKED(
typedef struct __mavlink_tc_calibration_data_t {
 float Gain_TCV; /*<  TCV Gain */
 float Offset_mV_TCV; /*<  TCV Offset mV*/
 float Gain_TC_degC; /*<  TC Gain degC */
 float Offset_TC_degC; /*<  TC Offset degC */
 float Vref_mV_TC; /*<  TC Verf mV*/
 int16_t Table_degC[12]; /*<  TC Calibration map Table*/
}) mavlink_tc_calibration_data_t;

#define MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN 44
#define MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN 44
#define MAVLINK_MSG_ID_221_LEN 44
#define MAVLINK_MSG_ID_221_MIN_LEN 44

#define MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC 138
#define MAVLINK_MSG_ID_221_CRC 138

#define MAVLINK_MSG_TC_CALIBRATION_Data_FIELD_TABLE_DEGC_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TC_CALIBRATION_Data { \
	221, \
	"TC_CALIBRATION_Data", \
	6, \
	{  { "Gain_TCV", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tc_calibration_data_t, Gain_TCV) }, \
         { "Offset_mV_TCV", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tc_calibration_data_t, Offset_mV_TCV) }, \
         { "Gain_TC_degC", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tc_calibration_data_t, Gain_TC_degC) }, \
         { "Offset_TC_degC", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tc_calibration_data_t, Offset_TC_degC) }, \
         { "Vref_mV_TC", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tc_calibration_data_t, Vref_mV_TC) }, \
         { "Table_degC", NULL, MAVLINK_TYPE_INT16_T, 12, 20, offsetof(mavlink_tc_calibration_data_t, Table_degC) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TC_CALIBRATION_Data { \
	"TC_CALIBRATION_Data", \
	6, \
	{  { "Gain_TCV", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tc_calibration_data_t, Gain_TCV) }, \
         { "Offset_mV_TCV", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tc_calibration_data_t, Offset_mV_TCV) }, \
         { "Gain_TC_degC", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tc_calibration_data_t, Gain_TC_degC) }, \
         { "Offset_TC_degC", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tc_calibration_data_t, Offset_TC_degC) }, \
         { "Vref_mV_TC", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tc_calibration_data_t, Vref_mV_TC) }, \
         { "Table_degC", NULL, MAVLINK_TYPE_INT16_T, 12, 20, offsetof(mavlink_tc_calibration_data_t, Table_degC) }, \
         } \
}
#endif

/**
 * @brief Pack a tc_calibration_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Gain_TCV  TCV Gain 
 * @param Offset_mV_TCV  TCV Offset mV
 * @param Gain_TC_degC  TC Gain degC 
 * @param Offset_TC_degC  TC Offset degC 
 * @param Vref_mV_TC  TC Verf mV
 * @param Table_degC  TC Calibration map Table
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tc_calibration_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float Gain_TCV, float Offset_mV_TCV, float Gain_TC_degC, float Offset_TC_degC, float Vref_mV_TC, const int16_t *Table_degC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN];
	_mav_put_float(buf, 0, Gain_TCV);
	_mav_put_float(buf, 4, Offset_mV_TCV);
	_mav_put_float(buf, 8, Gain_TC_degC);
	_mav_put_float(buf, 12, Offset_TC_degC);
	_mav_put_float(buf, 16, Vref_mV_TC);
	_mav_put_int16_t_array(buf, 20, Table_degC, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN);
#else
	mavlink_tc_calibration_data_t packet;
	packet.Gain_TCV = Gain_TCV;
	packet.Offset_mV_TCV = Offset_mV_TCV;
	packet.Gain_TC_degC = Gain_TC_degC;
	packet.Offset_TC_degC = Offset_TC_degC;
	packet.Vref_mV_TC = Vref_mV_TC;
	mav_array_memcpy(packet.Table_degC, Table_degC, sizeof(int16_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TC_CALIBRATION_Data;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
}

/**
 * @brief Pack a tc_calibration_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Gain_TCV  TCV Gain 
 * @param Offset_mV_TCV  TCV Offset mV
 * @param Gain_TC_degC  TC Gain degC 
 * @param Offset_TC_degC  TC Offset degC 
 * @param Vref_mV_TC  TC Verf mV
 * @param Table_degC  TC Calibration map Table
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tc_calibration_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float Gain_TCV,float Offset_mV_TCV,float Gain_TC_degC,float Offset_TC_degC,float Vref_mV_TC,const int16_t *Table_degC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN];
	_mav_put_float(buf, 0, Gain_TCV);
	_mav_put_float(buf, 4, Offset_mV_TCV);
	_mav_put_float(buf, 8, Gain_TC_degC);
	_mav_put_float(buf, 12, Offset_TC_degC);
	_mav_put_float(buf, 16, Vref_mV_TC);
	_mav_put_int16_t_array(buf, 20, Table_degC, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN);
#else
	mavlink_tc_calibration_data_t packet;
	packet.Gain_TCV = Gain_TCV;
	packet.Offset_mV_TCV = Offset_mV_TCV;
	packet.Gain_TC_degC = Gain_TC_degC;
	packet.Offset_TC_degC = Offset_TC_degC;
	packet.Vref_mV_TC = Vref_mV_TC;
	mav_array_memcpy(packet.Table_degC, Table_degC, sizeof(int16_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TC_CALIBRATION_Data;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
}

/**
 * @brief Encode a tc_calibration_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tc_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tc_calibration_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tc_calibration_data_t* tc_calibration_data)
{
	return mavlink_msg_tc_calibration_data_pack(system_id, component_id, msg, tc_calibration_data->Gain_TCV, tc_calibration_data->Offset_mV_TCV, tc_calibration_data->Gain_TC_degC, tc_calibration_data->Offset_TC_degC, tc_calibration_data->Vref_mV_TC, tc_calibration_data->Table_degC);
}

/**
 * @brief Encode a tc_calibration_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tc_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tc_calibration_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tc_calibration_data_t* tc_calibration_data)
{
	return mavlink_msg_tc_calibration_data_pack_chan(system_id, component_id, chan, msg, tc_calibration_data->Gain_TCV, tc_calibration_data->Offset_mV_TCV, tc_calibration_data->Gain_TC_degC, tc_calibration_data->Offset_TC_degC, tc_calibration_data->Vref_mV_TC, tc_calibration_data->Table_degC);
}

/**
 * @brief Send a tc_calibration_data message
 * @param chan MAVLink channel to send the message
 *
 * @param Gain_TCV  TCV Gain 
 * @param Offset_mV_TCV  TCV Offset mV
 * @param Gain_TC_degC  TC Gain degC 
 * @param Offset_TC_degC  TC Offset degC 
 * @param Vref_mV_TC  TC Verf mV
 * @param Table_degC  TC Calibration map Table
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tc_calibration_data_send(mavlink_channel_t chan, float Gain_TCV, float Offset_mV_TCV, float Gain_TC_degC, float Offset_TC_degC, float Vref_mV_TC, const int16_t *Table_degC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN];
	_mav_put_float(buf, 0, Gain_TCV);
	_mav_put_float(buf, 4, Offset_mV_TCV);
	_mav_put_float(buf, 8, Gain_TC_degC);
	_mav_put_float(buf, 12, Offset_TC_degC);
	_mav_put_float(buf, 16, Vref_mV_TC);
	_mav_put_int16_t_array(buf, 20, Table_degC, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TC_CALIBRATION_Data, buf, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
#else
	mavlink_tc_calibration_data_t packet;
	packet.Gain_TCV = Gain_TCV;
	packet.Offset_mV_TCV = Offset_mV_TCV;
	packet.Gain_TC_degC = Gain_TC_degC;
	packet.Offset_TC_degC = Offset_TC_degC;
	packet.Vref_mV_TC = Vref_mV_TC;
	mav_array_memcpy(packet.Table_degC, Table_degC, sizeof(int16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TC_CALIBRATION_Data, (const char *)&packet, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
#endif
}

/**
 * @brief Send a tc_calibration_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tc_calibration_data_send_struct(mavlink_channel_t chan, const mavlink_tc_calibration_data_t* tc_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tc_calibration_data_send(chan, tc_calibration_data->Gain_TCV, tc_calibration_data->Offset_mV_TCV, tc_calibration_data->Gain_TC_degC, tc_calibration_data->Offset_TC_degC, tc_calibration_data->Vref_mV_TC, tc_calibration_data->Table_degC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TC_CALIBRATION_Data, (const char *)tc_calibration_data, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
#endif
}

#if MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tc_calibration_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float Gain_TCV, float Offset_mV_TCV, float Gain_TC_degC, float Offset_TC_degC, float Vref_mV_TC, const int16_t *Table_degC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, Gain_TCV);
	_mav_put_float(buf, 4, Offset_mV_TCV);
	_mav_put_float(buf, 8, Gain_TC_degC);
	_mav_put_float(buf, 12, Offset_TC_degC);
	_mav_put_float(buf, 16, Vref_mV_TC);
	_mav_put_int16_t_array(buf, 20, Table_degC, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TC_CALIBRATION_Data, buf, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
#else
	mavlink_tc_calibration_data_t *packet = (mavlink_tc_calibration_data_t *)msgbuf;
	packet->Gain_TCV = Gain_TCV;
	packet->Offset_mV_TCV = Offset_mV_TCV;
	packet->Gain_TC_degC = Gain_TC_degC;
	packet->Offset_TC_degC = Offset_TC_degC;
	packet->Vref_mV_TC = Vref_mV_TC;
	mav_array_memcpy(packet->Table_degC, Table_degC, sizeof(int16_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TC_CALIBRATION_Data, (const char *)packet, MAVLINK_MSG_ID_TC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_TC_CALIBRATION_Data_CRC);
#endif
}
#endif

#endif

// MESSAGE TC_CALIBRATION_Data UNPACKING


/**
 * @brief Get field Gain_TCV from tc_calibration_data message
 *
 * @return  TCV Gain 
 */
static inline float mavlink_msg_tc_calibration_data_get_Gain_TCV(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field Offset_mV_TCV from tc_calibration_data message
 *
 * @return  TCV Offset mV
 */
static inline float mavlink_msg_tc_calibration_data_get_Offset_mV_TCV(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field Gain_TC_degC from tc_calibration_data message
 *
 * @return  TC Gain degC 
 */
static inline float mavlink_msg_tc_calibration_data_get_Gain_TC_degC(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Offset_TC_degC from tc_calibration_data message
 *
 * @return  TC Offset degC 
 */
static inline float mavlink_msg_tc_calibration_data_get_Offset_TC_degC(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field Vref_mV_TC from tc_calibration_data message
 *
 * @return  TC Verf mV
 */
static inline float mavlink_msg_tc_calibration_data_get_Vref_mV_TC(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field Table_degC from tc_calibration_data message
 *
 * @return  TC Calibration map Table
 */
static inline uint16_t mavlink_msg_tc_calibration_data_get_Table_degC(const mavlink_message_t* msg, int16_t *Table_degC)
{
	return _MAV_RETURN_int16_t_array(msg, Table_degC, 12,  20);
}

/**
 * @brief Decode a tc_calibration_data message into a struct
 *
 * @param msg The message to decode
 * @param tc_calibration_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_tc_calibration_data_decode(const mavlink_message_t* msg, mavlink_tc_calibration_data_t* tc_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tc_calibration_data->Gain_TCV = mavlink_msg_tc_calibration_data_get_Gain_TCV(msg);
	tc_calibration_data->Offset_mV_TCV = mavlink_msg_tc_calibration_data_get_Offset_mV_TCV(msg);
	tc_calibration_data->Gain_TC_degC = mavlink_msg_tc_calibration_data_get_Gain_TC_degC(msg);
	tc_calibration_data->Offset_TC_degC = mavlink_msg_tc_calibration_data_get_Offset_TC_degC(msg);
	tc_calibration_data->Vref_mV_TC = mavlink_msg_tc_calibration_data_get_Vref_mV_TC(msg);
	mavlink_msg_tc_calibration_data_get_Table_degC(msg, tc_calibration_data->Table_degC);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN? msg->len : MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN;
        memset(tc_calibration_data, 0, MAVLINK_MSG_ID_TC_CALIBRATION_Data_LEN);
	memcpy(tc_calibration_data, _MAV_PAYLOAD(msg), len);
#endif
}
