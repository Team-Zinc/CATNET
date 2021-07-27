macos_swift_tun = custom_target(
    'tun.o',
    output : 'tun.o',
    input : 'tun.swift',
    command : ['swiftc', '-static', '-c', '@INPUT@', '-o', '@OUTPUT@' ],
)
