// MESSAGE MEASURING_DATA PACKING

#define MAVLINK_MSG_ID_MEASURING_DATA 201

MAVPACKED(
typedef struct __mavlink_measuring_data_t {
 float Reg; /*< 4 Wire Kelvin [mOhm]*/
 float Cap; /*<  Capacitance [pF]*/
 float Ind; /*<  inductance [nH]*/
 float TC; /*<  Temperature [degC*10]*/
 float kelvin_mV; /*< 4 Wire Kelvin [mV]*/
 float TC_mV; /*< 4 Wire TC mV [mV]*/
 uint16_t ADC_ch1; /*<  12bit ADC [mV]*/
 uint16_t ADC_ch2; /*<  12bit ADC [mV]*/
 uint8_t DI; /*<  Digital Input [High/Low]*/
 uint8_t Set_Status; /*<  Setting status bit*/
}) mavlink_measuring_data_t;

#define MAVLINK_MSG_ID_MEASURING_DATA_LEN 30
#define MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN 30
#define MAVLINK_MSG_ID_201_LEN 30
#define MAVLINK_MSG_ID_201_MIN_LEN 30

#define MAVLINK_MSG_ID_MEASURING_DATA_CRC 245
#define MAVLINK_MSG_ID_201_CRC 245



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MEASURING_DATA { \
	201, \
	"MEASURING_DATA", \
	10, \
	{  { "Reg", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_measuring_data_t, Reg) }, \
         { "Cap", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_measuring_data_t, Cap) }, \
         { "Ind", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_measuring_data_t, Ind) }, \
         { "TC", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_measuring_data_t, TC) }, \
         { "kelvin_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_measuring_data_t, kelvin_mV) }, \
         { "TC_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_measuring_data_t, TC_mV) }, \
         { "ADC_ch1", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_measuring_data_t, ADC_ch1) }, \
         { "ADC_ch2", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_measuring_data_t, ADC_ch2) }, \
         { "DI", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_measuring_data_t, DI) }, \
         { "Set_Status", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_measuring_data_t, Set_Status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MEASURING_DATA { \
	"MEASURING_DATA", \
	10, \
	{  { "Reg", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_measuring_data_t, Reg) }, \
         { "Cap", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_measuring_data_t, Cap) }, \
         { "Ind", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_measuring_data_t, Ind) }, \
         { "TC", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_measuring_data_t, TC) }, \
         { "kelvin_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_measuring_data_t, kelvin_mV) }, \
         { "TC_mV", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_measuring_data_t, TC_mV) }, \
         { "ADC_ch1", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_measuring_data_t, ADC_ch1) }, \
         { "ADC_ch2", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_measuring_data_t, ADC_ch2) }, \
         { "DI", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_measuring_data_t, DI) }, \
         { "Set_Status", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_measuring_data_t, Set_Status) }, \
         } \
}
#endif

/**
 * @brief Pack a measuring_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Reg 4 Wire Kelvin [mOhm]
 * @param Cap  Capacitance [pF]
 * @param Ind  inductance [nH]
 * @param TC  Temperature [degC*10]
 * @param kelvin_mV 4 Wire Kelvin [mV]
 * @param TC_mV 4 Wire TC mV [mV]
 * @param ADC_ch1  12bit ADC [mV]
 * @param ADC_ch2  12bit ADC [mV]
 * @param DI  Digital Input [High/Low]
 * @param Set_Status  Setting status bit
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_measuring_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float Reg, float Cap, float Ind, float TC, float kelvin_mV, float TC_mV, uint16_t ADC_ch1, uint16_t ADC_ch2, uint8_t DI, uint8_t Set_Status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASURING_DATA_LEN];
	_mav_put_float(buf, 0, Reg);
	_mav_put_float(buf, 4, Cap);
	_mav_put_float(buf, 8, Ind);
	_mav_put_float(buf, 12, TC);
	_mav_put_float(buf, 16, kelvin_mV);
	_mav_put_float(buf, 20, TC_mV);
	_mav_put_uint16_t(buf, 24, ADC_ch1);
	_mav_put_uint16_t(buf, 26, ADC_ch2);
	_mav_put_uint8_t(buf, 28, DI);
	_mav_put_uint8_t(buf, 29, Set_Status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MEASURING_DATA_LEN);
#else
	mavlink_measuring_data_t packet;
	packet.Reg = Reg;
	packet.Cap = Cap;
	packet.Ind = Ind;
	packet.TC = TC;
	packet.kelvin_mV = kelvin_mV;
	packet.TC_mV = TC_mV;
	packet.ADC_ch1 = ADC_ch1;
	packet.ADC_ch2 = ADC_ch2;
	packet.DI = DI;
	packet.Set_Status = Set_Status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MEASURING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MEASURING_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
}

/**
 * @brief Pack a measuring_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Reg 4 Wire Kelvin [mOhm]
 * @param Cap  Capacitance [pF]
 * @param Ind  inductance [nH]
 * @param TC  Temperature [degC*10]
 * @param kelvin_mV 4 Wire Kelvin [mV]
 * @param TC_mV 4 Wire TC mV [mV]
 * @param ADC_ch1  12bit ADC [mV]
 * @param ADC_ch2  12bit ADC [mV]
 * @param DI  Digital Input [High/Low]
 * @param Set_Status  Setting status bit
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_measuring_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float Reg,float Cap,float Ind,float TC,float kelvin_mV,float TC_mV,uint16_t ADC_ch1,uint16_t ADC_ch2,uint8_t DI,uint8_t Set_Status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASURING_DATA_LEN];
	_mav_put_float(buf, 0, Reg);
	_mav_put_float(buf, 4, Cap);
	_mav_put_float(buf, 8, Ind);
	_mav_put_float(buf, 12, TC);
	_mav_put_float(buf, 16, kelvin_mV);
	_mav_put_float(buf, 20, TC_mV);
	_mav_put_uint16_t(buf, 24, ADC_ch1);
	_mav_put_uint16_t(buf, 26, ADC_ch2);
	_mav_put_uint8_t(buf, 28, DI);
	_mav_put_uint8_t(buf, 29, Set_Status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MEASURING_DATA_LEN);
#else
	mavlink_measuring_data_t packet;
	packet.Reg = Reg;
	packet.Cap = Cap;
	packet.Ind = Ind;
	packet.TC = TC;
	packet.kelvin_mV = kelvin_mV;
	packet.TC_mV = TC_mV;
	packet.ADC_ch1 = ADC_ch1;
	packet.ADC_ch2 = ADC_ch2;
	packet.DI = DI;
	packet.Set_Status = Set_Status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MEASURING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MEASURING_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
}

/**
 * @brief Encode a measuring_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param measuring_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_measuring_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_measuring_data_t* measuring_data)
{
	return mavlink_msg_measuring_data_pack(system_id, component_id, msg, measuring_data->Reg, measuring_data->Cap, measuring_data->Ind, measuring_data->TC, measuring_data->kelvin_mV, measuring_data->TC_mV, measuring_data->ADC_ch1, measuring_data->ADC_ch2, measuring_data->DI, measuring_data->Set_Status);
}

/**
 * @brief Encode a measuring_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param measuring_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_measuring_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_measuring_data_t* measuring_data)
{
	return mavlink_msg_measuring_data_pack_chan(system_id, component_id, chan, msg, measuring_data->Reg, measuring_data->Cap, measuring_data->Ind, measuring_data->TC, measuring_data->kelvin_mV, measuring_data->TC_mV, measuring_data->ADC_ch1, measuring_data->ADC_ch2, measuring_data->DI, measuring_data->Set_Status);
}

/**
 * @brief Send a measuring_data message
 * @param chan MAVLink channel to send the message
 *
 * @param Reg 4 Wire Kelvin [mOhm]
 * @param Cap  Capacitance [pF]
 * @param Ind  inductance [nH]
 * @param TC  Temperature [degC*10]
 * @param kelvin_mV 4 Wire Kelvin [mV]
 * @param TC_mV 4 Wire TC mV [mV]
 * @param ADC_ch1  12bit ADC [mV]
 * @param ADC_ch2  12bit ADC [mV]
 * @param DI  Digital Input [High/Low]
 * @param Set_Status  Setting status bit
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_measuring_data_send(mavlink_channel_t chan, float Reg, float Cap, float Ind, float TC, float kelvin_mV, float TC_mV, uint16_t ADC_ch1, uint16_t ADC_ch2, uint8_t DI, uint8_t Set_Status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASURING_DATA_LEN];
	_mav_put_float(buf, 0, Reg);
	_mav_put_float(buf, 4, Cap);
	_mav_put_float(buf, 8, Ind);
	_mav_put_float(buf, 12, TC);
	_mav_put_float(buf, 16, kelvin_mV);
	_mav_put_float(buf, 20, TC_mV);
	_mav_put_uint16_t(buf, 24, ADC_ch1);
	_mav_put_uint16_t(buf, 26, ADC_ch2);
	_mav_put_uint8_t(buf, 28, DI);
	_mav_put_uint8_t(buf, 29, Set_Status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_DATA, buf, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
#else
	mavlink_measuring_data_t packet;
	packet.Reg = Reg;
	packet.Cap = Cap;
	packet.Ind = Ind;
	packet.TC = TC;
	packet.kelvin_mV = kelvin_mV;
	packet.TC_mV = TC_mV;
	packet.ADC_ch1 = ADC_ch1;
	packet.ADC_ch2 = ADC_ch2;
	packet.DI = DI;
	packet.Set_Status = Set_Status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_DATA, (const char *)&packet, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
#endif
}

/**
 * @brief Send a measuring_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_measuring_data_send_struct(mavlink_channel_t chan, const mavlink_measuring_data_t* measuring_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_measuring_data_send(chan, measuring_data->Reg, measuring_data->Cap, measuring_data->Ind, measuring_data->TC, measuring_data->kelvin_mV, measuring_data->TC_mV, measuring_data->ADC_ch1, measuring_data->ADC_ch2, measuring_data->DI, measuring_data->Set_Status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_DATA, (const char *)measuring_data, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_MEASURING_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_measuring_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float Reg, float Cap, float Ind, float TC, float kelvin_mV, float TC_mV, uint16_t ADC_ch1, uint16_t ADC_ch2, uint8_t DI, uint8_t Set_Status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, Reg);
	_mav_put_float(buf, 4, Cap);
	_mav_put_float(buf, 8, Ind);
	_mav_put_float(buf, 12, TC);
	_mav_put_float(buf, 16, kelvin_mV);
	_mav_put_float(buf, 20, TC_mV);
	_mav_put_uint16_t(buf, 24, ADC_ch1);
	_mav_put_uint16_t(buf, 26, ADC_ch2);
	_mav_put_uint8_t(buf, 28, DI);
	_mav_put_uint8_t(buf, 29, Set_Status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_DATA, buf, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
#else
	mavlink_measuring_data_t *packet = (mavlink_measuring_data_t *)msgbuf;
	packet->Reg = Reg;
	packet->Cap = Cap;
	packet->Ind = Ind;
	packet->TC = TC;
	packet->kelvin_mV = kelvin_mV;
	packet->TC_mV = TC_mV;
	packet->ADC_ch1 = ADC_ch1;
	packet->ADC_ch2 = ADC_ch2;
	packet->DI = DI;
	packet->Set_Status = Set_Status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_DATA, (const char *)packet, MAVLINK_MSG_ID_MEASURING_DATA_MIN_LEN, MAVLINK_MSG_ID_MEASURING_DATA_LEN, MAVLINK_MSG_ID_MEASURING_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE MEASURING_DATA UNPACKING


/**
 * @brief Get field Reg from measuring_data message
 *
 * @return 4 Wire Kelvin [mOhm]
 */
static inline float mavlink_msg_measuring_data_get_Reg(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field Cap from measuring_data message
 *
 * @return  Capacitance [pF]
 */
static inline float mavlink_msg_measuring_data_get_Cap(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field Ind from measuring_data message
 *
 * @return  inductance [nH]
 */
static inline float mavlink_msg_measuring_data_get_Ind(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field TC from measuring_data message
 *
 * @return  Temperature [degC*10]
 */
static inline float mavlink_msg_measuring_data_get_TC(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field kelvin_mV from measuring_data message
 *
 * @return 4 Wire Kelvin [mV]
 */
static inline float mavlink_msg_measuring_data_get_kelvin_mV(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field TC_mV from measuring_data message
 *
 * @return 4 Wire TC mV [mV]
 */
static inline float mavlink_msg_measuring_data_get_TC_mV(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field ADC_ch1 from measuring_data message
 *
 * @return  12bit ADC [mV]
 */
static inline uint16_t mavlink_msg_measuring_data_get_ADC_ch1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field ADC_ch2 from measuring_data message
 *
 * @return  12bit ADC [mV]
 */
static inline uint16_t mavlink_msg_measuring_data_get_ADC_ch2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field DI from measuring_data message
 *
 * @return  Digital Input [High/Low]
 */
static inline uint8_t mavlink_msg_measuring_data_get_DI(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field Set_Status from measuring_data message
 *
 * @return  Setting status bit
 */
static inline uint8_t mavlink_msg_measuring_data_get_Set_Status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Decode a measuring_data message into a struct
 *
 * @param msg The message to decode
 * @param measuring_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_measuring_data_decode(const mavlink_message_t* msg, mavlink_measuring_data_t* measuring_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	measuring_data->Reg = mavlink_msg_measuring_data_get_Reg(msg);
	measuring_data->Cap = mavlink_msg_measuring_data_get_Cap(msg);
	measuring_data->Ind = mavlink_msg_measuring_data_get_Ind(msg);
	measuring_data->TC = mavlink_msg_measuring_data_get_TC(msg);
	measuring_data->kelvin_mV = mavlink_msg_measuring_data_get_kelvin_mV(msg);
	measuring_data->TC_mV = mavlink_msg_measuring_data_get_TC_mV(msg);
	measuring_data->ADC_ch1 = mavlink_msg_measuring_data_get_ADC_ch1(msg);
	measuring_data->ADC_ch2 = mavlink_msg_measuring_data_get_ADC_ch2(msg);
	measuring_data->DI = mavlink_msg_measuring_data_get_DI(msg);
	measuring_data->Set_Status = mavlink_msg_measuring_data_get_Set_Status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MEASURING_DATA_LEN? msg->len : MAVLINK_MSG_ID_MEASURING_DATA_LEN;
        memset(measuring_data, 0, MAVLINK_MSG_ID_MEASURING_DATA_LEN);
	memcpy(measuring_data, _MAV_PAYLOAD(msg), len);
#endif
}
