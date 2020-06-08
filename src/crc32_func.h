#ifdef CRC32_FUNC_H
#error Already included
#else
#define CRC32_FUNC_H

extern "C" uint32_t crc32_8(uint32_t crc_iv, const void *p_data, size_t count);
extern "C" uint32_t crc32_16(uint32_t crc_iv, const void *p_data, size_t count);
extern "C" uint32_t crc32_32(uint32_t crc_iv, const void *p_data, size_t count);
extern "C" uint32_t crc32_64(uint32_t crc_iv, const void *p_data, size_t count);

#endif
