/**
 * @author lijk@.infosec.com.cn
 * @version 0.0.1
 * @date 2017-5-26 18:18:58
 */
#ifndef _CRYPTO_SMS4_H
#define _CRYPTO_SMS4_H

#include <linux/types.h>
#include <linux/crypto.h>

#define SMS4_KEY_LENGTH     16
#define SMS4_BLOCK_SIZE     16
#define SMS4_NUM_ROUNDS     32

struct crypto_sms4_ctx {
    u32 key_enc[SMS4_NUM_ROUNDS];
    u32 key_dec[SMS4_NUM_ROUNDS];
};

#ifdef __cplusplus
extern "C" {
#endif

int crypto_sms4_set_key(struct crypto_tfm *tfm, const u8 *key, u32 keylen);

#ifdef __cplusplus
}
#endif

#endif
