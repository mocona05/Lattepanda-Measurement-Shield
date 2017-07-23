// MESSAGE SYSTEM_CONTROL_SET PACKING

#define MAVLINK_MSG_ID_SYSTEM_CONTROL_SET 230

MAVPACKED(
typedef struct __mavlink_system_control_set_t {
 uint8_t save_config; /*< save config value*/
 uint8_t Reboot; /*< System reboot control set*/
 uint8_t default_set; /*< setting data all default set*/
}) mavlink_system_control_set_t;

#define MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN 3
#define MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN 3
#define MAVLINK_MSG_ID_230_LEN 3
#define MAVLINK_MSG_ID_230_MIN_LEN 3

#define MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC 151
#define MAVLINK_MSG_ID_230_CRC 151



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_CONTROL_SET { \
	230, \
	"SYSTEM_CONTROL_SET", \
	3, \
	{  { "save_config", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_system_control_set_t, save_config) }, \
         { "Reboot", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_system_control_set_t, Reboot) }, \
         { "default_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_system_control_set_t, default_set) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_CONTROL_SET { \
	"SYSTEM_CONTROL_SET", \
	3, \
	{  { "save_config", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_system_control_set_t, save_config) }, \
         { "Reboot", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_system_control_set_t, Reboot) }, \
         { "default_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_system_control_set_t, default_set) }, \
         } \
}
#endif

/**
 * @brief Pack a system_control_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param save_config save config value
 * @param Reboot System reboot control set
 * @param default_set setting data all default set
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_control_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t save_config, uint8_t Reboot, uint8_t default_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN];
	_mav_put_uint8_t(buf, 0, save_config);
	_mav_put_uint8_t(buf, 1, Reboot);
	_mav_put_uint8_t(buf, 2, default_set);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN);
#else
	mavlink_system_control_set_t packet;
	packet.save_config = save_config;
	packet.Reboot = Reboot;
	packet.default_set = default_set;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SYSTEM_CONTROL_SET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
}

/**
 * @brief Pack a system_control_set message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param save_config save config value
 * @param Reboot System reboot control set
 * @param default_set setting data all default set
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_control_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t save_config,uint8_t Reboot,uint8_t default_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN];
	_mav_put_uint8_t(buf, 0, save_config);
	_mav_put_uint8_t(buf, 1, Reboot);
	_mav_put_uint8_t(buf, 2, default_set);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN);
#else
	mavlink_system_control_set_t packet;
	packet.save_config = save_config;
	packet.Reboot = Reboot;
	packet.default_set = default_set;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SYSTEM_CONTROL_SET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
}

/**
 * @brief Encode a system_control_set struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_control_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_control_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_control_set_t* system_control_set)
{
	return mavlink_msg_system_control_set_pack(system_id, component_id, msg, system_control_set->save_config, system_control_set->Reboot, system_control_set->default_set);
}

/**
 * @brief Encode a system_control_set struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_control_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_control_set_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_control_set_t* system_control_set)
{
	return mavlink_msg_system_control_set_pack_chan(system_id, component_id, chan, msg, system_control_set->save_config, system_control_set->Reboot, system_control_set->default_set);
}

/**
 * @brief Send a system_control_set message
 * @param chan MAVLink channel to send the message
 *
 * @param save_config save config value
 * @param Reboot System reboot control set
 * @param default_set setting data all default set
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_system_control_set_send(mavlink_channel_t chan, uint8_t save_config, uint8_t Reboot, uint8_t default_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN];
	_mav_put_uint8_t(buf, 0, save_config);
	_mav_put_uint8_t(buf, 1, Reboot);
	_mav_put_uint8_t(buf, 2, default_set);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET, buf, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
#else
	mavlink_system_control_set_t packet;
	packet.save_config = save_config;
	packet.Reboot = Reboot;
	packet.default_set = default_set;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET, (const char *)&packet, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
#endif
}

/**
 * @brief Send a system_control_set message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_system_control_set_send_struct(mavlink_channel_t chan, const mavlink_system_control_set_t* system_control_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_system_control_set_send(chan, system_control_set->save_config, system_control_set->Reboot, system_control_set->default_set);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET, (const char *)system_control_set, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_system_control_set_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t save_config, uint8_t Reboot, uint8_t default_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, save_config);
	_mav_put_uint8_t(buf, 1, Reboot);
	_mav_put_uint8_t(buf, 2, default_set);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET, buf, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
#else
	mavlink_system_control_set_t *packet = (mavlink_system_control_set_t *)msgbuf;
	packet->save_config = save_config;
	packet->Reboot = Reboot;
	packet->default_set = default_set;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET, (const char *)packet, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_CRC);
#endif
}
#endif

#endif

// MESSAGE SYSTEM_CONTROL_SET UNPACKING


/**
 * @brief Get field save_config from system_control_set message
 *
 * @return save config value
 */
static inline uint8_t mavlink_msg_system_control_set_get_save_config(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field Reboot from system_control_set message
 *
 * @return System reboot control set
 */
static inline uint8_t mavlink_msg_system_control_set_get_Reboot(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field default_set from system_control_set message
 *
 * @return setting data all default set
 */
static inline uint8_t mavlink_msg_system_control_set_get_default_set(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a system_control_set message into a struct
 *
 * @param msg The message to decode
 * @param system_control_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_control_set_decode(const mavlink_message_t* msg, mavlink_system_control_set_t* system_control_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	system_control_set->save_config = mavlink_msg_system_control_set_get_save_config(msg);
	system_control_set->Reboot = mavlink_msg_system_control_set_get_Reboot(msg);
	system_control_set->default_set = mavlink_msg_system_control_set_get_default_set(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN? msg->len : MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN;
        memset(system_control_set, 0, MAVLINK_MSG_ID_SYSTEM_CONTROL_SET_LEN);
	memcpy(system_control_set, _MAV_PAYLOAD(msg), len);
#endif
}
