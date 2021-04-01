// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MANUAL_COMPOSITION_PACKAGE__VISIBILITY_CONTROL_H_
#define MANUAL_COMPOSITION_PACKAGE__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MANUAL_COMPOSITION_PACKAGE_EXPORT __attribute__ ((dllexport))
    #define MANUAL_COMPOSITION_PACKAGE_IMPORT __attribute__ ((dllimport))
  #else
    #define MANUAL_COMPOSITION_PACKAGE_EXPORT __declspec(dllexport)
    #define MANUAL_COMPOSITION_PACKAGE_IMPORT __declspec(dllimport)
  #endif
  #ifdef MANUAL_COMPOSITION_PACKAGE_BUILDING_DLL
    #define MANUAL_COMPOSITION_PACKAGE_PUBLIC MANUAL_COMPOSITION_PACKAGE_EXPORT
  #else
    #define MANUAL_COMPOSITION_PACKAGE_PUBLIC MANUAL_COMPOSITION_PACKAGE_IMPORT
  #endif
  #define MANUAL_COMPOSITION_PACKAGE_PUBLIC_TYPE MANUAL_COMPOSITION_PACKAGE_PUBLIC
  #define MANUAL_COMPOSITION_PACKAGE_LOCAL
#else
  #define MANUAL_COMPOSITION_PACKAGE_EXPORT __attribute__ ((visibility("default")))
  #define MANUAL_COMPOSITION_PACKAGE_IMPORT
  #if __GNUC__ >= 4
    #define MANUAL_COMPOSITION_PACKAGE_PUBLIC __attribute__ ((visibility("default")))
    #define MANUAL_COMPOSITION_PACKAGE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MANUAL_COMPOSITION_PACKAGE_PUBLIC
    #define MANUAL_COMPOSITION_PACKAGE_LOCAL
  #endif
  #define MANUAL_COMPOSITION_PACKAGE_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // MANUAL_COMPOSITION_PACKAGE__VISIBILITY_CONTROL_H_
