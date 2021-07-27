# Compile .proto files

# Very close to protogent. Werid flex, but ok
proto_gen = generator(protoc,
  output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
  arguments : ['--proto_path=@CURRENT_SOURCE_DIR@', '--cpp_out=@BUILD_DIR@', '@INPUT@'])

catnip_gened = proto_gen.process('catnip.proto')
base_gened = proto_gen.process('base.proto')
test_connection_gened = proto_gen.process('test_connection.proto')
pubkey_exchange_gened = proto_gen.process('pubkey_exchange.proto')

