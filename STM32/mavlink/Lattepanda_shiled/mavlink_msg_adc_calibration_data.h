// MESSAGE ADC_CALIBRATION_Data PACKING

#define MAVLINK_MSG_ID_ADC_CALIBRATION_Data 220

MAVPACKED(
typedef struct __mavlink_adc_calibration_data_t {
 float Gain_ADC[2]; /*< 12bit ADC calibration gain*/
 float Offset_ADC_mV[2]; /*< 12bit ADC calibration offset[mV]*/
 float Vref_ADC_mV; /*<  12bit ADC Verf*/
 float Vref_SDADC_mV; /*<  16bit ADC Verf*/
}) mavlink_adc_calibration_data_t;

#define MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN 24
#define MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN 24
#define MAVLINK_MSG_ID_220_LEN 24
#define MAVLINK_MSG_ID_220_MIN_LEN 24

#define MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC 120
#define MAVLINK_MSG_ID_220_CRC 120

#define MAVLINK_MSG_ADC_CALIBRATION_Data_FIELD_GAIN_ADC_LEN 2
#define MAVLINK_MSG_ADC_CALIBRATION_Data_FIELD_OFFSET_ADC_MV_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ADC_CALIBRATION_Data { \
	220, \
	"ADC_CALIBRATION_Data", \
	4, \
	{  { "Gain_ADC", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_adc_calibration_data_t, Gain_ADC) }, \
         { "Offset_ADC_mV", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_adc_calibration_data_t, Offset_ADC_mV) }, \
         { "Vref_ADC_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_adc_calibration_data_t, Vref_ADC_mV) }, \
         { "Vref_SDADC_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_adc_calibration_data_t, Vref_SDADC_mV) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ADC_CALIBRATION_Data { \
	"ADC_CALIBRATION_Data", \
	4, \
	{  { "Gain_ADC", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_adc_calibration_data_t, Gain_ADC) }, \
         { "Offset_ADC_mV", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_adc_calibration_data_t, Offset_ADC_mV) }, \
         { "Vref_ADC_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_adc_calibration_data_t, Vref_ADC_mV) }, \
         { "Vref_SDADC_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_adc_calibration_data_t, Vref_SDADC_mV) }, \
         } \
}
#endif

/**
 * @brief Pack a adc_calibration_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Gain_ADC 12bit ADC calibration gain
 * @param Offset_ADC_mV 12bit ADC calibration offset[mV]
 * @param Vref_ADC_mV  12bit ADC Verf
 * @param Vref_SDADC_mV  16bit ADC Verf
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_adc_calibration_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const float *Gain_ADC, const float *Offset_ADC_mV, float Vref_ADC_mV, float Vref_SDADC_mV)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN];
	_mav_put_float(buf, 16, Vref_ADC_mV);
	_mav_put_float(buf, 20, Vref_SDADC_mV);
	_mav_put_float_array(buf, 0, Gain_ADC, 2);
	_mav_put_float_array(buf, 8, Offset_ADC_mV, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN);
#else
	mavlink_adc_calibration_data_t packet;
	packet.Vref_ADC_mV = Vref_ADC_mV;
	packet.Vref_SDADC_mV = Vref_SDADC_mV;
	mav_array_memcpy(packet.Gain_ADC, Gain_ADC, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_ADC_mV, Offset_ADC_mV, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ADC_CALIBRATION_Data;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
}

/**
 * @brief Pack a adc_calibration_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Gain_ADC 12bit ADC calibration gain
 * @param Offset_ADC_mV 12bit ADC calibration offset[mV]
 * @param Vref_ADC_mV  12bit ADC Verf
 * @param Vref_SDADC_mV  16bit ADC Verf
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_adc_calibration_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const float *Gain_ADC,const float *Offset_ADC_mV,float Vref_ADC_mV,float Vref_SDADC_mV)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN];
	_mav_put_float(buf, 16, Vref_ADC_mV);
	_mav_put_float(buf, 20, Vref_SDADC_mV);
	_mav_put_float_array(buf, 0, Gain_ADC, 2);
	_mav_put_float_array(buf, 8, Offset_ADC_mV, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN);
#else
	mavlink_adc_calibration_data_t packet;
	packet.Vref_ADC_mV = Vref_ADC_mV;
	packet.Vref_SDADC_mV = Vref_SDADC_mV;
	mav_array_memcpy(packet.Gain_ADC, Gain_ADC, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_ADC_mV, Offset_ADC_mV, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ADC_CALIBRATION_Data;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
}

/**
 * @brief Encode a adc_calibration_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param adc_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_adc_calibration_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_adc_calibration_data_t* adc_calibration_data)
{
	return mavlink_msg_adc_calibration_data_pack(system_id, component_id, msg, adc_calibration_data->Gain_ADC, adc_calibration_data->Offset_ADC_mV, adc_calibration_data->Vref_ADC_mV, adc_calibration_data->Vref_SDADC_mV);
}

/**
 * @brief Encode a adc_calibration_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param adc_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_adc_calibration_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_adc_calibration_data_t* adc_calibration_data)
{
	return mavlink_msg_adc_calibration_data_pack_chan(system_id, component_id, chan, msg, adc_calibration_data->Gain_ADC, adc_calibration_data->Offset_ADC_mV, adc_calibration_data->Vref_ADC_mV, adc_calibration_data->Vref_SDADC_mV);
}

/**
 * @brief Send a adc_calibration_data message
 * @param chan MAVLink channel to send the message
 *
 * @param Gain_ADC 12bit ADC calibration gain
 * @param Offset_ADC_mV 12bit ADC calibration offset[mV]
 * @param Vref_ADC_mV  12bit ADC Verf
 * @param Vref_SDADC_mV  16bit ADC Verf
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_adc_calibration_data_send(mavlink_channel_t chan, const float *Gain_ADC, const float *Offset_ADC_mV, float Vref_ADC_mV, float Vref_SDADC_mV)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN];
	_mav_put_float(buf, 16, Vref_ADC_mV);
	_mav_put_float(buf, 20, Vref_SDADC_mV);
	_mav_put_float_array(buf, 0, Gain_ADC, 2);
	_mav_put_float_array(buf, 8, Offset_ADC_mV, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_CALIBRATION_Data, buf, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
#else
	mavlink_adc_calibration_data_t packet;
	packet.Vref_ADC_mV = Vref_ADC_mV;
	packet.Vref_SDADC_mV = Vref_SDADC_mV;
	mav_array_memcpy(packet.Gain_ADC, Gain_ADC, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_ADC_mV, Offset_ADC_mV, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_CALIBRATION_Data, (const char *)&packet, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
#endif
}

/**
 * @brief Send a adc_calibration_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_adc_calibration_data_send_struct(mavlink_channel_t chan, const mavlink_adc_calibration_data_t* adc_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_adc_calibration_data_send(chan, adc_calibration_data->Gain_ADC, adc_calibration_data->Offset_ADC_mV, adc_calibration_data->Vref_ADC_mV, adc_calibration_data->Vref_SDADC_mV);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_CALIBRATION_Data, (const char *)adc_calibration_data, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
#endif
}

#if MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_adc_calibration_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *Gain_ADC, const float *Offset_ADC_mV, float Vref_ADC_mV, float Vref_SDADC_mV)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 16, Vref_ADC_mV);
	_mav_put_float(buf, 20, Vref_SDADC_mV);
	_mav_put_float_array(buf, 0, Gain_ADC, 2);
	_mav_put_float_array(buf, 8, Offset_ADC_mV, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_CALIBRATION_Data, buf, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
#else
	mavlink_adc_calibration_data_t *packet = (mavlink_adc_calibration_data_t *)msgbuf;
	packet->Vref_ADC_mV = Vref_ADC_mV;
	packet->Vref_SDADC_mV = Vref_SDADC_mV;
	mav_array_memcpy(packet->Gain_ADC, Gain_ADC, sizeof(float)*2);
	mav_array_memcpy(packet->Offset_ADC_mV, Offset_ADC_mV, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_CALIBRATION_Data, (const char *)packet, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_CRC);
#endif
}
#endif

#endif

// MESSAGE ADC_CALIBRATION_Data UNPACKING


/**
 * @brief Get field Gain_ADC from adc_calibration_data message
 *
 * @return 12bit ADC calibration gain
 */
static inline uint16_t mavlink_msg_adc_calibration_data_get_Gain_ADC(const mavlink_message_t* msg, float *Gain_ADC)
{
	return _MAV_RETURN_float_array(msg, Gain_ADC, 2,  0);
}

/**
 * @brief Get field Offset_ADC_mV from adc_calibration_data message
 *
 * @return 12bit ADC calibration offset[mV]
 */
static inline uint16_t mavlink_msg_adc_calibration_data_get_Offset_ADC_mV(const mavlink_message_t* msg, float *Offset_ADC_mV)
{
	return _MAV_RETURN_float_array(msg, Offset_ADC_mV, 2,  8);
}

/**
 * @brief Get field Vref_ADC_mV from adc_calibration_data message
 *
 * @return  12bit ADC Verf
 */
static inline float mavlink_msg_adc_calibration_data_get_Vref_ADC_mV(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field Vref_SDADC_mV from adc_calibration_data message
 *
 * @return  16bit ADC Verf
 */
static inline float mavlink_msg_adc_calibration_data_get_Vref_SDADC_mV(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a adc_calibration_data message into a struct
 *
 * @param msg The message to decode
 * @param adc_calibration_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_adc_calibration_data_decode(const mavlink_message_t* msg, mavlink_adc_calibration_data_t* adc_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_adc_calibration_data_get_Gain_ADC(msg, adc_calibration_data->Gain_ADC);
	mavlink_msg_adc_calibration_data_get_Offset_ADC_mV(msg, adc_calibration_data->Offset_ADC_mV);
	adc_calibration_data->Vref_ADC_mV = mavlink_msg_adc_calibration_data_get_Vref_ADC_mV(msg);
	adc_calibration_data->Vref_SDADC_mV = mavlink_msg_adc_calibration_data_get_Vref_SDADC_mV(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN? msg->len : MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN;
        memset(adc_calibration_data, 0, MAVLINK_MSG_ID_ADC_CALIBRATION_Data_LEN);
	memcpy(adc_calibration_data, _MAV_PAYLOAD(msg), len);
#endif
}
