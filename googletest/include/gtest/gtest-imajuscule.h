// Copyright 2016 imajuscule
// All Rights Reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: Olivier Sohn

#pragma once

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif


#ifdef HAS_KILLED_BY_SIGNAL
#  error "redefining HAS_KILLED_BY_SIGNAL"
#endif

#if TARGET_OS_IOS || _WIN32
#  define HAS_KILLED_BY_SIGNAL 0
#else
#  define HAS_KILLED_BY_SIGNAL 1
#endif


#ifdef HAS_EXITED_WITH_CODE
#  error "redefining HAS_EXITED_WITH_CODE"
#endif

#if TARGET_OS_IOS
#  define HAS_EXITED_WITH_CODE 0
#else
#  define HAS_EXITED_WITH_CODE 1
#endif



#ifndef NDEBUG
// debug mode
#   if HAS_KILLED_BY_SIGNAL
#       define EXPECT_DEBUG_ASSERT(x) ASSERT_EXIT((x), ::testing::KilledBySignal(SIGABRT), "");
#   elif HAS_EXITED_WITH_CODE
#       define EXPECT_DEBUG_ASSERT(x) ASSERT_EXIT((x), ::testing::ExitedWithCode(3), "");
#   else
#       define EXPECT_DEBUG_ASSERT(x) do {} while( 0 );
#   endif
#else
// release mode
#   define EXPECT_DEBUG_ASSERT(x) do {} while( 0 );
#endif

#define EXPECT_QUAT_EQ( a, b )  EXPECT_TRUE(1.f - glm::dot(a,b) < FLOAT_EPSILON);
