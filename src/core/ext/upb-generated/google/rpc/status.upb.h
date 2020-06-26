/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/rpc/status.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef GOOGLE_RPC_STATUS_PROTO_UPB_H_
#define GOOGLE_RPC_STATUS_PROTO_UPB_H_

#include "upb/msg.h"
#include "upb/decode.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct google_rpc_Status;
typedef struct google_rpc_Status google_rpc_Status;
extern const upb_msglayout google_rpc_Status_msginit;
struct google_protobuf_Any;
extern const upb_msglayout google_protobuf_Any_msginit;


/* google.rpc.Status */

UPB_INLINE google_rpc_Status *google_rpc_Status_new(upb_arena *arena) {
  return (google_rpc_Status *)_upb_msg_new(&google_rpc_Status_msginit, arena);
}
UPB_INLINE google_rpc_Status *google_rpc_Status_parse(const char *buf, size_t size,
                        upb_arena *arena) {
  google_rpc_Status *ret = google_rpc_Status_new(arena);
  return (ret && upb_decode(buf, size, ret, &google_rpc_Status_msginit, arena)) ? ret : NULL;
}
UPB_INLINE char *google_rpc_Status_serialize(const google_rpc_Status *msg, upb_arena *arena, size_t *len) {
  return upb_encode(msg, &google_rpc_Status_msginit, arena, len);
}

UPB_INLINE int32_t google_rpc_Status_code(const google_rpc_Status *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t); }
UPB_INLINE upb_strview google_rpc_Status_message(const google_rpc_Status *msg) { return *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_strview); }
UPB_INLINE bool google_rpc_Status_has_details(const google_rpc_Status *msg) { return _upb_has_submsg_nohasbit(msg, UPB_SIZE(12, 24)); }
UPB_INLINE const struct google_protobuf_Any* const* google_rpc_Status_details(const google_rpc_Status *msg, size_t *len) { return (const struct google_protobuf_Any* const*)_upb_array_accessor(msg, UPB_SIZE(12, 24), len); }

UPB_INLINE void google_rpc_Status_set_code(google_rpc_Status *msg, int32_t value) {
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t) = value;
}
UPB_INLINE void google_rpc_Status_set_message(google_rpc_Status *msg, upb_strview value) {
  *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_strview) = value;
}
UPB_INLINE struct google_protobuf_Any** google_rpc_Status_mutable_details(google_rpc_Status *msg, size_t *len) {
  return (struct google_protobuf_Any**)_upb_array_mutable_accessor(msg, UPB_SIZE(12, 24), len);
}
UPB_INLINE struct google_protobuf_Any** google_rpc_Status_resize_details(google_rpc_Status *msg, size_t len, upb_arena *arena) {
  return (struct google_protobuf_Any**)_upb_array_resize_accessor(msg, UPB_SIZE(12, 24), len, UPB_TYPE_MESSAGE, arena);
}
UPB_INLINE struct google_protobuf_Any* google_rpc_Status_add_details(google_rpc_Status *msg, upb_arena *arena) {
  struct google_protobuf_Any* sub = (struct google_protobuf_Any*)_upb_msg_new(&google_protobuf_Any_msginit, arena);
  bool ok = _upb_array_append_accessor(
      msg, UPB_SIZE(12, 24), UPB_SIZE(4, 8), UPB_TYPE_MESSAGE, &sub, arena);
  if (!ok) return NULL;
  return sub;
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* GOOGLE_RPC_STATUS_PROTO_UPB_H_ */
