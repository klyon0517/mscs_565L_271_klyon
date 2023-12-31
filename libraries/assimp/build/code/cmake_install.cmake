# Install script for directory: C:/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.3.0-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/assimp/build/lib/Debug/assimp-vc143-mtd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/assimp/build/lib/Release/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/assimp/build/lib/MinSizeRel/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/assimp/build/lib/RelWithDebInfo/assimp-vc143-mt.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.3.0" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/assimp/build/bin/Debug/assimp-vc143-mtd.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/assimp/build/bin/Release/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/assimp/build/bin/MinSizeRel/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/assimp/build/bin/RelWithDebInfo/assimp-vc143-mt.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/assimp/code/../include/assimp/anim.h"
    "C:/assimp/code/../include/assimp/aabb.h"
    "C:/assimp/code/../include/assimp/ai_assert.h"
    "C:/assimp/code/../include/assimp/camera.h"
    "C:/assimp/code/../include/assimp/color4.h"
    "C:/assimp/code/../include/assimp/color4.inl"
    "C:/assimp/build/code/../include/assimp/config.h"
    "C:/assimp/code/../include/assimp/ColladaMetaData.h"
    "C:/assimp/code/../include/assimp/commonMetaData.h"
    "C:/assimp/code/../include/assimp/defs.h"
    "C:/assimp/code/../include/assimp/cfileio.h"
    "C:/assimp/code/../include/assimp/light.h"
    "C:/assimp/code/../include/assimp/material.h"
    "C:/assimp/code/../include/assimp/material.inl"
    "C:/assimp/code/../include/assimp/matrix3x3.h"
    "C:/assimp/code/../include/assimp/matrix3x3.inl"
    "C:/assimp/code/../include/assimp/matrix4x4.h"
    "C:/assimp/code/../include/assimp/matrix4x4.inl"
    "C:/assimp/code/../include/assimp/mesh.h"
    "C:/assimp/code/../include/assimp/ObjMaterial.h"
    "C:/assimp/code/../include/assimp/pbrmaterial.h"
    "C:/assimp/code/../include/assimp/GltfMaterial.h"
    "C:/assimp/code/../include/assimp/postprocess.h"
    "C:/assimp/code/../include/assimp/quaternion.h"
    "C:/assimp/code/../include/assimp/quaternion.inl"
    "C:/assimp/code/../include/assimp/scene.h"
    "C:/assimp/code/../include/assimp/metadata.h"
    "C:/assimp/code/../include/assimp/texture.h"
    "C:/assimp/code/../include/assimp/types.h"
    "C:/assimp/code/../include/assimp/vector2.h"
    "C:/assimp/code/../include/assimp/vector2.inl"
    "C:/assimp/code/../include/assimp/vector3.h"
    "C:/assimp/code/../include/assimp/vector3.inl"
    "C:/assimp/code/../include/assimp/version.h"
    "C:/assimp/code/../include/assimp/cimport.h"
    "C:/assimp/code/../include/assimp/AssertHandler.h"
    "C:/assimp/code/../include/assimp/importerdesc.h"
    "C:/assimp/code/../include/assimp/Importer.hpp"
    "C:/assimp/code/../include/assimp/DefaultLogger.hpp"
    "C:/assimp/code/../include/assimp/ProgressHandler.hpp"
    "C:/assimp/code/../include/assimp/IOStream.hpp"
    "C:/assimp/code/../include/assimp/IOSystem.hpp"
    "C:/assimp/code/../include/assimp/Logger.hpp"
    "C:/assimp/code/../include/assimp/LogStream.hpp"
    "C:/assimp/code/../include/assimp/NullLogger.hpp"
    "C:/assimp/code/../include/assimp/cexport.h"
    "C:/assimp/code/../include/assimp/Exporter.hpp"
    "C:/assimp/code/../include/assimp/DefaultIOStream.h"
    "C:/assimp/code/../include/assimp/DefaultIOSystem.h"
    "C:/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/assimp/code/../include/assimp/SceneCombiner.h"
    "C:/assimp/code/../include/assimp/fast_atof.h"
    "C:/assimp/code/../include/assimp/qnan.h"
    "C:/assimp/code/../include/assimp/BaseImporter.h"
    "C:/assimp/code/../include/assimp/Hash.h"
    "C:/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "C:/assimp/code/../include/assimp/ParsingUtils.h"
    "C:/assimp/code/../include/assimp/StreamReader.h"
    "C:/assimp/code/../include/assimp/StreamWriter.h"
    "C:/assimp/code/../include/assimp/StringComparison.h"
    "C:/assimp/code/../include/assimp/StringUtils.h"
    "C:/assimp/code/../include/assimp/SGSpatialSort.h"
    "C:/assimp/code/../include/assimp/GenericProperty.h"
    "C:/assimp/code/../include/assimp/SpatialSort.h"
    "C:/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/assimp/code/../include/assimp/SmallVector.h"
    "C:/assimp/code/../include/assimp/SmoothingGroups.h"
    "C:/assimp/code/../include/assimp/SmoothingGroups.inl"
    "C:/assimp/code/../include/assimp/StandardShapes.h"
    "C:/assimp/code/../include/assimp/RemoveComments.h"
    "C:/assimp/code/../include/assimp/Subdivision.h"
    "C:/assimp/code/../include/assimp/Vertex.h"
    "C:/assimp/code/../include/assimp/LineSplitter.h"
    "C:/assimp/code/../include/assimp/TinyFormatter.h"
    "C:/assimp/code/../include/assimp/Profiler.h"
    "C:/assimp/code/../include/assimp/LogAux.h"
    "C:/assimp/code/../include/assimp/Bitmap.h"
    "C:/assimp/code/../include/assimp/XMLTools.h"
    "C:/assimp/code/../include/assimp/IOStreamBuffer.h"
    "C:/assimp/code/../include/assimp/CreateAnimMesh.h"
    "C:/assimp/code/../include/assimp/XmlParser.h"
    "C:/assimp/code/../include/assimp/BlobIOSystem.h"
    "C:/assimp/code/../include/assimp/MathFunctions.h"
    "C:/assimp/code/../include/assimp/Exceptional.h"
    "C:/assimp/code/../include/assimp/ByteSwapper.h"
    "C:/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "C:/assimp/code/../include/assimp/Compiler/poppack1.h"
    "C:/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/assimp/build/bin/Debug/assimp-vc143-mtd.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/assimp/build/bin/Release/assimp-vc143-mt.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/assimp/build/bin/MinSizeRel/assimp-vc143-mt.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/assimp/build/bin/RelWithDebInfo/assimp-vc143-mt.pdb")
  endif()
endif()

