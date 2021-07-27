# subdir('logging')
subdir('proto')
# subdir('sockets')
# subdir('message')

# proto_gen = generator(protoc,
#   output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
#   arguments : ['--proto_path=@CURRENT_SOURCE_DIR@', '--cpp_out=@BUILD_DIR@', '@INPUT@'])

# head_whisker_exchange_gened = proto_gen.process('proto/head_whisker_exchange.proto')

project_source_files = [
  base_gened, test_connection_gened, pubkey_exchange_gened,
  catnip_gened,
  'participant/participant.cpp',
  'participant/update_catstate.cpp',
  'participant/whisker_exchange.cpp',
  'registrar/registrar.cpp',
  'logging/log.cpp',
  'message/base.cpp',
  'message/catnip.cpp',
  'message/encrypt.cpp',
  'sockets/socket_compat.cpp',
  'sockets/tcp_client_socket.cpp',
  'sockets/tcp_server_socket.cpp',
  'sockets/tcp_socket.cpp',
  'sockets/udp_client_socket.cpp',
  'sockets/udp_server_socket.cpp',
  'sockets/udp_socket.cpp',
  'tun/tun.cpp'
]

logging_inc = include_directories('logging/include')
sockets_inc = include_directories('sockets/include')
message_inc = include_directories('message/include')
participant_inc = include_directories('participant/include')
registrar_inc = include_directories('registrar')
tun_inc = include_directories('tun/include')
# all_inc = include_directories('include')


project_dependencies = [
  thread_dep,
  sodium_dep,
  fmt_dep,
  cli11_dep,
  protobuf_dep,
  json_dep
]

build_args = [
]

inc_dirs = [
  cli11_inc,
  fmt_inc,
  spdlog_inc,

  logging_inc,
  sockets_inc,
  message_inc,
  participant_inc,
  registrar_inc,
  tun_inc
]

if build_machine.system() == 'linux'
  project_source_files += [
    'tun/linux/alloc.c',
    'tun/linux/up.c',
    'tun/linux/ip.c',
  ]
elif build_machine.system() == 'darwin'
  subdir('tun/darwin')

  project_source_files += macos_swift_tun
endif

# We compile into a library first because we need to
# link the test code with it first.
project_library_target = static_library(
  'catnet',
  project_source_files,
  cpp_pch : 'pch/pch.hpp',
  dependencies : project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

subdir('clients/cli')
subdir('docs')
