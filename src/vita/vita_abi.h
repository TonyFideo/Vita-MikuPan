#pragma once

#include <cstddef>
#include <cstdint>
#include "typedefs.h"

namespace mikupan::vita {

using ps2_u8 = std::uint8_t;
using ps2_u16 = std::uint16_t;
using ps2_u32 = std::uint32_t;
using ps2_u64 = std::uint64_t;

static_assert(sizeof(void*) == 4, "Vita must use a 32-bit ABI");
static_assert(sizeof(long) == 4, "Vita long must be 32-bit");
static_assert(sizeof(ps2_u8) == 1);
static_assert(sizeof(ps2_u16) == 2);
static_assert(sizeof(ps2_u32) == 4);
static_assert(sizeof(ps2_u64) == 8);

static_assert(sizeof(u_long128) == 16, "PS2 qword storage must stay 16 bytes");
static_assert(sizeof(qword) == 16, "PS2 qword must stay 16 bytes");
static_assert(alignof(qword) >= 16, "PS2 qword must stay 16-byte aligned");
static_assert(sizeof(sceVu0FVECTOR) == 16, "VU vector layout changed");
static_assert(alignof(sceVu0FVECTOR) >= 16, "VU vector alignment changed");
static_assert(sizeof(sceVu0FMATRIX) == 64, "VU matrix layout changed");
static_assert(alignof(sceVu0FMATRIX) >= 16, "VU matrix alignment changed");
static_assert(sizeof(Q_WORDDATA) == 16, "Q_WORDDATA layout changed");

// Host u_long is intentionally not treated as a PS2 64-bit type on Vita.
// PS2 layout-sensitive code should migrate to ps2_u64 explicitly.
static_assert(sizeof(u_long) == 4, "Unexpected Vita u_long size");

} // namespace mikupan::vita
