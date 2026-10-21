# Modification Map: external/efivar

## Source: BlissOS android-x86 reference (external/efivar)
- BlissOS commits: 11 commits from fork history (merged into rhboot/efivar@39)
- UPSTREAM commit: 0c2ea84 (KhillOS port)
- Upstream base: rhboot/efivar@39 (tag c47820c)

## Modifications Applied to UPSTREAM/external_efivar (khillos-17 branch)

### 1. Android.bp Build System (NEW - replaces Android.mk)
**File:** `Android.bp` (entire file)
- Migrated from BlissOS Android.mk (make-based) to Soong Android.bp
- Single `libefivar` static library (merges upstream's 3 libs: libefivar, libefiboot, libefisec)
- `makeguids` host tool (`cc_binary_host`) + `genrule` for generating `efivar-guids.h` and `guid-symbols.c`
- `vendor_available: true` for vendor partition support
- Package-level license configuration (LGPL-2.1-only)

### 2. Portability Shims (NEW - BlissOS additions)
**Files:** `src/portable_fopencookie.c`, `src/portable_fopencookie.h`
- Replacement for `fopencookie()` (BSD) / `funopen()` (not available on Android)
- Provides `fopencookie()` compatible API for Android

**File:** `src/sort_r.h`
- Compatibility header for `qsort_r()` signature differences
- Android uses `qsort_r(void *, size_t, size_t, int (*)(void *, const void *, const void *), void *)`
- GNU uses `qsort_r(void *, size_t, size_t, int (*)(const void *, const void *, void *))`
- Provides `sort_r()` wrapper with consistent signature

### 3. AOSP 17 Compliance Metadata Files (NEW)
**Files:** `METADATA`, `NOTICE`, `MODULE_LICENSE_LGPL21`, `OWNERS`
- METADATA: Package metadata per AOSP external_updater format
- NOTICE: Short license notice
- MODULE_LICENSE_LGPL21: SPDX identifier for Soong license module
- OWNERS: Standard AOSP OWNERS file

### 4. SPDX Headers to Source Files
**Files:** 3 files newly added with SPDX (others already had)
- `src/portable_fopencookie.c`
- `src/portable_fopencookie.h`
- `src/sort_r.h`

## MISSING FROM BLISSOS REFERENCE (5 Source Patches NOT Applied)
Per KHILLOS_PROGRESS.md, the following 5 source patches from BlissOS are NOT yet applied:
1. `secure_getenv()` → `getenv()` replacement (Android doesn't have secure_getenv)
2. `qsort_r()` → `sort_r()` replacement (signature differences)
3. `-DANDROID` define for Android-specific code paths
4. Additional portability fixes for Android build
5. One more patch (details in BlissOS fork history)

These need to be applied in Step 4 before marking VERIFIED.

## Summary
- **Total files modified:** 10 (4 new metadata + 3 shims + 1 Android.bp + 2 SPDX on new files)
- **Source files unchanged:** Yes (upstream sources identical, only shims added)
- **Logic/behavior changes:** Portability shims added for Android compatibility
- **Build system changes:** Android.mk → Android.bp migration (functional equivalent + shims)