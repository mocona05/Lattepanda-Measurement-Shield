// MESSAGE CAN_BUS_CONFIG_SETTING_DATA PACKING

#define MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA 205

MAVPACKED(
typedef struct __mavlink_can_bus_config_setting_data_t {
 uint32_t Base_ID; /*<  CAN Base ID */
 uint8_t Baud; /*<  CAN Baud speed */
 uint8_t Protocol_set; /*<  CAN Rx/Tx to uart Protocol setting */
}) mavlink_can_bus_config_setting_data_t;

#define MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN 6
#define MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN 6
#define MAVLINK_MSG_ID_205_LEN 6
#define MAVLINK_MSG_ID_205_MIN_LEN 6

#define MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC 22
#define MAVLINK_MSG_ID_205_CRC 22



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAN_BUS_CONFIG_SETTING_DATA { \
	205, \
	"CAN_BUS_CONFIG_SETTING_DATA", \
	3, \
	{  { "Base_ID", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_can_bus_config_setting_data_t, Base_ID) }, \
         { "Baud", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_can_bus_config_setting_data_t, Baud) }, \
         { "Protocol_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_can_bus_config_setting_data_t, Protocol_set) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAN_BUS_CONFIG_SETTING_DATA { \
	"CAN_BUS_CONFIG_SETTING_DATA", \
	3, \
	{  { "Base_ID", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_can_bus_config_setting_data_t, Base_ID) }, \
         { "Baud", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_can_bus_config_setting_data_t, Baud) }, \
         { "Protocol_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_can_bus_config_setting_data_t, Protocol_set) }, \
         } \
}
#endif

/**
 * @brief Pack a can_bus_config_setting_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Base_ID  CAN Base ID 
 * @param Baud  CAN Baud speed 
 * @param Protocol_set  CAN Rx/Tx to uart Protocol setting 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_can_bus_config_setting_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t Base_ID, uint8_t Baud, uint8_t Protocol_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN];
	_mav_put_uint32_t(buf, 0, Base_ID);
	_mav_put_uint8_t(buf, 4, Baud);
	_mav_put_uint8_t(buf, 5, Protocol_set);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN);
#else
	mavlink_can_bus_config_setting_data_t packet;
	packet.Base_ID = Base_ID;
	packet.Baud = Baud;
	packet.Protocol_set = Protocol_set;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
}

/**
 * @brief Pack a can_bus_config_setting_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Base_ID  CAN Base ID 
 * @param Baud  CAN Baud speed 
 * @param Protocol_set  CAN Rx/Tx to uart Protocol setting 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_can_bus_config_setting_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t Base_ID,uint8_t Baud,uint8_t Protocol_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN];
	_mav_put_uint32_t(buf, 0, Base_ID);
	_mav_put_uint8_t(buf, 4, Baud);
	_mav_put_uint8_t(buf, 5, Protocol_set);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN);
#else
	mavlink_can_bus_config_setting_data_t packet;
	packet.Base_ID = Base_ID;
	packet.Baud = Baud;
	packet.Protocol_set = Protocol_set;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
}

/**
 * @brief Encode a can_bus_config_setting_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param can_bus_config_setting_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_can_bus_config_setting_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_can_bus_config_setting_data_t* can_bus_config_setting_data)
{
	return mavlink_msg_can_bus_config_setting_data_pack(system_id, component_id, msg, can_bus_config_setting_data->Base_ID, can_bus_config_setting_data->Baud, can_bus_config_setting_data->Protocol_set);
}

/**
 * @brief Encode a can_bus_config_setting_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param can_bus_config_setting_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_can_bus_config_setting_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_can_bus_config_setting_data_t* can_bus_config_setting_data)
{
	return mavlink_msg_can_bus_config_setting_data_pack_chan(system_id, component_id, chan, msg, can_bus_config_setting_data->Base_ID, can_bus_config_setting_data->Baud, can_bus_config_setting_data->Protocol_set);
}

/**
 * @brief Send a can_bus_config_setting_data message
 * @param chan MAVLink channel to send the message
 *
 * @param Base_ID  CAN Base ID 
 * @param Baud  CAN Baud speed 
 * @param Protocol_set  CAN Rx/Tx to uart Protocol setting 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_can_bus_config_setting_data_send(mavlink_channel_t chan, uint32_t Base_ID, uint8_t Baud, uint8_t Protocol_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN];
	_mav_put_uint32_t(buf, 0, Base_ID);
	_mav_put_uint8_t(buf, 4, Baud);
	_mav_put_uint8_t(buf, 5, Protocol_set);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA, buf, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
#else
	mavlink_can_bus_config_setting_data_t packet;
	packet.Base_ID = Base_ID;
	packet.Baud = Baud;
	packet.Protocol_set = Protocol_set;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA, (const char *)&packet, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
#endif
}

/**
 * @brief Send a can_bus_config_setting_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_can_bus_config_setting_data_send_struct(mavlink_channel_t chan, const mavlink_can_bus_config_setting_data_t* can_bus_config_setting_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_can_bus_config_setting_data_send(chan, can_bus_config_setting_data->Base_ID, can_bus_config_setting_data->Baud, can_bus_config_setting_data->Protocol_set);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA, (const char *)can_bus_config_setting_data, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_can_bus_config_setting_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t Base_ID, uint8_t Baud, uint8_t Protocol_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, Base_ID);
	_mav_put_uint8_t(buf, 4, Baud);
	_mav_put_uint8_t(buf, 5, Protocol_set);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA, buf, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
#else
	mavlink_can_bus_config_setting_data_t *packet = (mavlink_can_bus_config_setting_data_t *)msgbuf;
	packet->Base_ID = Base_ID;
	packet->Baud = Baud;
	packet->Protocol_set = Protocol_set;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA, (const char *)packet, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE CAN_BUS_CONFIG_SETTING_DATA UNPACKING


/**
 * @brief Get field Base_ID from can_bus_config_setting_data message
 *
 * @return  CAN Base ID 
 */
static inline uint32_t mavlink_msg_can_bus_config_setting_data_get_Base_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field Baud from can_bus_config_setting_data message
 *
 * @return  CAN Baud speed 
 */
static inline uint8_t mavlink_msg_can_bus_config_setting_data_get_Baud(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field Protocol_set from can_bus_config_setting_data message
 *
 * @return  CAN Rx/Tx to uart Protocol setting 
 */
static inline uint8_t mavlink_msg_can_bus_config_setting_data_get_Protocol_set(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Decode a can_bus_config_setting_data message into a struct
 *
 * @param msg The message to decode
 * @param can_bus_config_setting_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_can_bus_config_setting_data_decode(const mavlink_message_t* msg, mavlink_can_bus_config_setting_data_t* can_bus_config_setting_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	can_bus_config_setting_data->Base_ID = mavlink_msg_can_bus_config_setting_data_get_Base_ID(msg);
	can_bus_config_setting_data->Baud = mavlink_msg_can_bus_config_setting_data_get_Baud(msg);
	can_bus_config_setting_data->Protocol_set = mavlink_msg_can_bus_config_setting_data_get_Protocol_set(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN? msg->len : MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN;
        memset(can_bus_config_setting_data, 0, MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA_LEN);
	memcpy(can_bus_config_setting_data, _MAV_PAYLOAD(msg), len);
#endif
}
