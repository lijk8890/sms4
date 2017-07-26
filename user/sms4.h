#include <stddef.h>
#include <stdint.h>

#define SMS4_KEY_LENGTH     16
#define SMS4_BLOCK_SIZE     16
#define SMS4_NUM_ROUNDS     32
#define SMS4_ENCRYPT        1
#define SMS4_DECRYPT        0

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sms4_key_s {
    uint32_t rk[SMS4_NUM_ROUNDS];
} sms4_key_t;

void sms4_set_encrypt_key(sms4_key_t *key, const unsigned char *user_key);
void sms4_set_decrypt_key(sms4_key_t *key, const unsigned char *user_key);

void sms4_encrypt(const unsigned char *in, unsigned char *out, sms4_key_t *key);

void sms4_ecb_encrypt(const unsigned char *in, unsigned char *out,
    sms4_key_t *key, int encrypt);
void sms4_cbc_encrypt(const unsigned char *in, unsigned char *out, size_t len,
    sms4_key_t *key, unsigned char *ivec, int encrypt);

#define sms4_decrypt(in,out,key) sms4_encrypt(in,out,key)

#ifdef __cplusplus
}
#endif
