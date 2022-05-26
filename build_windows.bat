rd /s/q build_ninja
mkdir build_ninja


cd build_ninja
@REM cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=%cd%/install -Dprotobuf_BUILD_TESTS=OFF -Dprotobuf_MSVC_STATIC_RUNTIME=OFF ../cmake
@REM cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=%cd%/install -DProtobuf_INCLUDE_DIR=<protobuf-root-dir>/build/install/include -DProtobuf_LIBRARIES=<protobuf-root-dir>/build/install/lib/libprotobuf.lib -DProtobuf_PROTOC_EXECUTABLE=<protobuf-root-dir>/build/install/bin/protoc.exe -DNCNN_VULKAN=ON ..
@REM cmake -GNinja .. -DOpenCV_DIR=D:\commonlib\opencv\opencv3416\opencv\build
cmake .. -DOpenCV_DIR=D:\commonlib\opencv\opencv3416\opencv\build -DProtobuf_INCLUDE_DIR=D:\commonlib\protobuf\include -DProtobuf_LIBRARIES=D:\commonlib\protobuf\lib\libprotobufd.lib -DProtobuf_PROTOC_EXECUTABLE=D:\commonlib\protobuf\bin\protoc.exe -DNCNN_VULKAN=OFF
